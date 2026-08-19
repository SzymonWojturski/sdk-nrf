#!/usr/bin/env python3
#
# Copyright (c) 2026 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
"""Compare a doxygen reviewer run against the expectations of a test pull request.

The expectations are hand written, one file per test pull request, and anchored to a substring of
the defective line instead of to a line number. This script resolves the anchors against the
working tree, then checks three things:

* every case that expects a finding has one, on the anchored line, from the expected branch and
  with the expected severity and content,
* every case that expects silence has no finding on the anchored line,
* no finding lands outside the ranges that the pull request edits.
"""

import argparse
import json
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

BRANCH_KEYS = ("branch", "category", "agent", "source")


def normalize_findings(payload):
    """Flatten a --pipeline-output payload into a list of comparable findings.

    This is the only function that knows the reviewer output schema. Adjust it here if the
    pipeline output changes shape.
    """
    if isinstance(payload, list):
        raw = payload
    else:
        raw = payload.get("findings") or payload.get("comments") or []

    findings = []
    for item in raw:
        branch = next((item[key] for key in BRANCH_KEYS if item.get(key)), "")
        findings.append(
            {
                "file": (item.get("file") or item.get("path") or "").lstrip("./"),
                "line": int(item.get("line") or item.get("line_number") or 0),
                "severity": (item.get("severity") or item.get("level") or "").upper(),
                "branch": str(branch).lower(),
                "message": item.get("message") or item.get("body") or "",
            }
        )
    return findings


def resolve_anchor(repo_root, path, anchor):
    """Return the 1-based line number of the single line that holds the anchor."""
    text = (repo_root / path).read_text().splitlines()
    hits = [nr for nr, line in enumerate(text, start=1) if anchor in line]
    if not hits:
        raise SystemExit(f"anchor not found in {path}: {anchor!r}")
    if len(hits) > 1:
        raise SystemExit(f"anchor is not unique in {path} (lines {hits}): {anchor!r}")
    return hits[0]


def edited_ranges(base):
    """Return the added lines per file of the diff against the base revision."""
    diff = subprocess.run(
        ["git", "diff", "-U0", f"{base}...HEAD"],
        check=True,
        capture_output=True,
        text=True,
    ).stdout

    added = defaultdict(set)
    current = None
    for line in diff.splitlines():
        if line.startswith("+++ b/"):
            current = line[len("+++ b/") :]
        elif line.startswith("@@") and current:
            span = line.split("+")[1].split("@@")[0].strip()
            start, _, count = span.partition(",")
            count = int(count or 1)
            added[current].update(range(int(start), int(start) + count))
    return added


def matches(finding, case, line):
    if finding["file"] != case["file"] or finding["line"] != line:
        return False
    if case.get("branch") and finding["branch"] != case["branch"].lower():
        return False
    if case.get("severity") and finding["severity"] != case["severity"].upper():
        return False
    return all(text.lower() in finding["message"].lower() for text in case.get("message_contains", []))


def forbidden(finding, rule, case, line):
    if finding["file"] != case["file"] or finding["line"] != line:
        return False
    if rule.get("branch") and finding["branch"] != rule["branch"].lower():
        return False
    if rule.get("severity") and finding["severity"] != rule["severity"].upper():
        return False
    texts = rule.get("message_contains", [])
    return all(text.lower() in finding["message"].lower() for text in texts)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--expected", required=True, type=Path)
    parser.add_argument("--actual", required=True, type=Path)
    parser.add_argument("--base", default="main", help="revision the pull request is based on")
    parser.add_argument("--repo-root", type=Path, default=Path.cwd())
    parser.add_argument(
        "--merged-baseline",
        action="store_true",
        help="the baseline pull request is already merged into the base revision",
    )
    args = parser.parse_args()

    expected = json.loads(args.expected.read_text())
    findings = normalize_findings(json.loads(args.actual.read_text()))

    failures = []
    gaps = []
    skipped = []
    passed = 0

    for case in expected.get("cases", []):
        if case.get("requires_merged_baseline") and not args.merged_baseline:
            skipped.append(f"{case['id']}: needs the baseline merged into {args.base}")
            continue

        line = resolve_anchor(args.repo_root, case["file"], case["anchor"])
        hits = [f for f in findings if matches(f, case, line)]
        label = f"{case['id']} ({case['file']}:{line})"

        if case.get("expect_finding", True):
            problem = None if hits else f"{label}: expected a finding, got none"
        else:
            same_line = [f for f in findings if f["file"] == case["file"] and f["line"] == line]
            problem = None if not same_line else f"{label}: expected silence, got {same_line}"

        if problem is None:
            for rule in case.get("must_not_report", []):
                banned = [f for f in findings if forbidden(f, rule, case, line)]
                if banned:
                    problem = f"{label}: forbidden finding reported: {banned}"
                    break

        if problem is None:
            passed += 1
        elif case.get("known_gap"):
            gaps.append(f"{problem} [known gap: {case.get('note', '')}]")
        else:
            failures.append(problem)

    assertions = expected.get("assertions", {})

    if assertions.get("no_findings_outside_edited_ranges"):
        added = edited_ranges(args.base)
        for finding in findings:
            if finding["line"] not in added.get(finding["file"], set()):
                failures.append(
                    f"finding outside the edited ranges: {finding['file']}:{finding['line']} "
                    f"({finding['branch']}) {finding['message'][:80]}"
                )

    for prefix in assertions.get("zero_finding_paths", []):
        stray = [f for f in findings if f["file"].startswith(prefix)]
        if stray:
            failures.append(f"{prefix} must stay free of findings, got {stray}")

    if assertions.get("deduplicated"):
        seen = defaultdict(int)
        for finding in findings:
            seen[(finding["file"], finding["line"], finding["branch"])] += 1
        for key, count in seen.items():
            if count > 1:
                failures.append(f"duplicated findings for {key}: {count} entries")

    for skip in skipped:
        print(f"SKIP {skip}")
    for gap in gaps:
        print(f"GAP  {gap}")
    for failure in failures:
        print(f"FAIL {failure}")
    print(
        f"\n{passed} passed, {len(failures)} failed, {len(gaps)} known gaps, "
        f"{len(skipped)} skipped"
    )

    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())

# Doxygen pull request reviewer testbed

Fixtures for the doxygen documentation reviewer. The tree gives the reviewer a small but complete
public API surface: a doxyfile that covers it, an RST page that renders every group, headers with
implementations next to them, and a directory that is deliberately out of scope.

Every later test pull request builds on this baseline. A defect is only reportable when it sits on
a line that the pull request adds, so the defects live in the pull requests, not here.

## Layout

| Path | Role |
| - | - |
| `include/good/` | Reference headers. Zero findings from every branch of the reviewer. |
| `include/bad/` | Scaffolding that later pull requests mutate to inject defects. |
| `include/bad/preexisting.h` | Carries defects from the baseline, to prove pre-existing filtering. |
| `include/excluded/` | Inside the doxyfile `INPUT` tree, listed in `EXCLUDE`. |
| `internal/` | Outside `INPUT`, no doxygen group, therefore outside the public API. |
| `src/` | Implementations paired with the headers, so the semantic branch can read behaviour. |
| `doc/api.rst` | `API documentation` section with a `.. doxygengroup::` for every baseline group. |
| `expected/` | Hand-written expectations, one file per test pull request. |
| `scripts/check_expected.py` | Compares a reviewer run against the expectations. |

`include/good/model_lib.h` follows the example in
`doc/nrf/dev_model_and_contributions/documentation/styleguide.rst` line by line: license banner,
then `/** @file` with `@defgroup`, `@{` and `@brief`, and `/** @} */` at the end of the file.

## Scope wiring

* `doc/nrf/nrf.doxyfile.in` adds `@NRF_BASE@/tests/doxygen_pr_reviewer/include` to `INPUT` and
  `@NRF_BASE@/tests/doxygen_pr_reviewer/include/excluded` to `EXCLUDE`.
* `tests/` is a private directory. Headers under `include/` are still public API, because they
  declare an explicit doxygen group, and a group pulls a file into the public API on its own.
* `internal/` declares no group and is outside `INPUT`, so it is the negative control for scope.

Adding intentionally broken fixtures to `INPUT` means the real `nrf` doxygen build parses them, so
the doxygen build of this branch reports warnings for the injected defects. That is inherent to
testing the `INPUT` rules against the real doxyfile.

## Expectation files

`expected/PR-<n>.expected.json`:

```json
{
  "pull_request": 3,
  "title": "syntactic deterministic rules",
  "requires_merged_baseline": false,
  "cases": [
    {
      "id": "sy-returns-tag",
      "row": "@returns instead of @return",
      "file": "tests/doxygen_pr_reviewer/include/bad/syntactic_tags.h",
      "anchor": "@returns Number of pending transfers",
      "expect_finding": true,
      "branch": "syntactic",
      "severity": "WARNING",
      "message_contains": ["@return"],
      "must_not_report": [{ "branch": "semantic" }],
      "known_gap": false,
      "note": ""
    }
  ],
  "assertions": {
    "no_findings_outside_edited_ranges": true,
    "zero_finding_paths": ["tests/doxygen_pr_reviewer/include/good"],
    "deduplicated": true
  }
}
```

* `anchor` is a substring that occurs exactly once in `file`. The checker resolves it to a line
  number, so the expectations survive edits above the defect.
* `expect_finding: false` states that a change must stay silent. `must_not_report` states which
  findings must not appear on the anchored line even when another finding is expected there.
* `known_gap: true` marks a row from the plan whose rule does not exist yet in the reviewer. The
  checker reports those separately and does not fail on them.
* `severity` follows the plan: a missing required tag is `WARNING`, style is `COMMENT`, and `ERROR`
  is reserved for a contradiction with the declaration.

## Running

```shell
# 1. Run the reviewer on the pull request under test.
<reviewer> --pipeline-output actual.json

# 2. Compare against the expectations.
python3 tests/doxygen_pr_reviewer/scripts/check_expected.py \
    --expected tests/doxygen_pr_reviewer/expected/PR-3.expected.json \
    --actual actual.json \
    --base main
```

The checker assumes the pipeline output is a JSON object with a `findings` list, each entry holding
`file`, `line`, `severity`, `category` or `branch`, and `message`. Adjust `normalize_findings()` in
the checker if the real schema differs; that function is the only place that knows the shape.

Pull requests whose branches use the LLM (semantic, and the fallback cases) are run three times.
Rows that do not reproduce in all three runs are unstable and feed back into the prompts rather
than into the expectations.

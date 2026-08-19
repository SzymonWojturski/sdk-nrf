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
| `include/bad/structural/` | Fixtures of the structural branch. |
| `include/bad/syntactic/` | Fixtures of the deterministic syntactic branch. |
| `include/bad/semantic/` | Fixtures of the semantic branch. |
| `include/bad/fallback/` | Fixtures that defeat the parser, so a fallback has to run. |
| `include/bad/scope/` | Group that no RST page renders. |
| `extra/` | Header outside `INPUT`, with a group, and without a doxyfile entry. |
| `api/` | Header whose directory is added to `INPUT` in the same pull request. |
| `private/` | Private directory: with a group, without a group, and `*_internal.h`. |
| `doc/scope.rst` | RST markup fixtures for the doxybridge roles. |
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

## Test pull requests

| Pull request | Scope |
| - | - |
| 1 | Baseline. Merge it first, so that the later diffs are small. |
| 2 | Structural rules and new files. |
| 3 | Deterministic syntactic rules, descriptions and briefs. |
| 4 | Semantic branch. |
| 5 | Fallback and parser failures. |
| 6 | Scope, `EXCLUDE`, private directories and RST markup. |

Rules that hold for every case:

* A defect has to sit on a line that the pull request adds, otherwise no branch may report it.
* An untouched `.h` file forms no pair, so the syntactic and the semantic branch do not see it.
* A `.c` file is only seen by the semantic branch.
* The header rules are tested on added files. For a modified file they only apply when the diff
  removes doc markup.
* The fallback of the structural and the syntactic branch runs only when parsing fails.
* The doxyfile and the doxyfile input categories always pass the scope filter.
* No finding may claim that the code does not compile because of a parser failure.
* No branch takes over or repeats a finding of another branch.

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

## Known gaps

Cases marked `known_gap` describe a rule that the style guide asks for but the reviewer does not
implement yet:

* the imperative form of `@brief`,
* full sentences with a period in every description, with fragments allowed only for variables,
  structs and enums,
* `@p` for references to parameters in prose,
* `@warning` for personal injury and loss of life, where the semantic prompt only talks about
  bricking the device,
* `@note` only when it is really needed for emphasis, where only the placement is checked today,
* `@param` for the arguments of function-like macros,
* membership of every documented element in the right group, not only the presence of a group,
* the doxybridge roles beyond `:c:func:` and `:c:macro:`,
* the license rule, which exists in neither the rules nor the prompts,
* `EXCLUDE`, which is parsed but not applied to the public API scope,
* a change in a `.c` file alone, which does not unlock a comment on an untouched doc block in the
  matching `.h` file.

`sp-excluded-file-with-defect` carries a `target_behaviour` field instead, because the current
behaviour and the wanted behaviour differ: the finding is reported today and has to disappear once
`EXCLUDE` is honoured.

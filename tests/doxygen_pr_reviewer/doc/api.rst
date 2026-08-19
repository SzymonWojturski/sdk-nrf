.. _dpr_testbed_api:

Doxygen PR reviewer testbed API
###############################

.. contents::
   :local:
   :depth: 2

The headers in this directory are fixtures of the doxygen pull request reviewer testbed.
They are documented here so that every doxygen group of the testbed is rendered on a page, the
same way as the groups of the public |NCS| API.

API documentation
*****************

| Header file: :file:`tests/doxygen_pr_reviewer/include/good/model_lib.h`
| Source file: :file:`tests/doxygen_pr_reviewer/src/good_lib.c`

.. doxygengroup:: dpr_model

| Header file: :file:`tests/doxygen_pr_reviewer/include/good/good_types.h`

.. doxygengroup:: dpr_types

.. doxygengroup:: dpr_types_util

| Header file: :file:`tests/doxygen_pr_reviewer/include/bad/bad_lib.h`
| Source file: :file:`tests/doxygen_pr_reviewer/src/bad_lib.c`

.. doxygengroup:: dpr_mutable

| Header file: :file:`tests/doxygen_pr_reviewer/include/bad/preexisting.h`

.. doxygengroup:: dpr_preexisting

| Header file: :file:`tests/doxygen_pr_reviewer/include/excluded/excluded_lib.h`

.. doxygengroup:: dpr_excluded

Structural fixtures
*******************

| Header file: :file:`tests/doxygen_pr_reviewer/include/bad/structural/structural_group.h`

.. doxygengroup:: dpr_structural

.. doxygengroup:: dpr_no_license

.. doxygengroup:: dpr_file_late

.. doxygengroup:: dpr_group_late

.. doxygengroup:: dpr_group_second

.. doxygengroup:: dpr_group_no_brief

.. doxygengroup:: dpr_group_brief_only

.. doxygengroup:: dpr_group_no_open

.. doxygengroup:: dpr_group_no_close

.. doxygengroup:: dpr_group_unbalanced

.. doxygengroup:: dpr_group_unbalanced_inner

.. doxygengroup:: dpr_group_unbalanced_leaf

.. doxygengroup:: dpr_fn_outside

.. doxygengroup:: dpr_dedupe

.. doxygengroup:: dpr_ignored

| Header file: :file:`tests/doxygen_pr_reviewer/extra/outside_input.h`

.. doxygengroup:: dpr_outside_input

| Header file: :file:`tests/doxygen_pr_reviewer/api/new_in_input.h`

.. doxygengroup:: dpr_new_in_input

Syntactic fixtures
******************

| Header file: :file:`tests/doxygen_pr_reviewer/include/bad/syntactic/brief_forms.h`

.. doxygengroup:: dpr_syntactic

Semantic fixtures
*****************

| Header file: :file:`tests/doxygen_pr_reviewer/include/bad/semantic/directions.h`
| Source file: :file:`tests/doxygen_pr_reviewer/src/semantic_lib.c`

.. doxygengroup:: dpr_semantic

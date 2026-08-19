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

.. _dpr_testbed_scope:

Doxygen PR reviewer testbed markup
##################################

.. contents::
   :local:
   :depth: 2

This page holds the RST markup fixtures of the testbed. Every reference below uses plain backticks
where a doxybridge role is required, so the reviewer has to ask for the role.

API documentation
*****************

Call `dpr_unregistered_count()` to read the counter of the unregistered groups.

The counter is only built when `CONFIG_DPR_TESTBED_SCOPE` is enabled.

The report is described by `struct dpr_types_report`, which the transport fills in.

The callback type is `dpr_model_state_handler_t`, the state is `enum dpr_model_state`, the idle
state is `DPR_MODEL_STATE_OFF` and the sample length is `dpr_model_sample.length`.

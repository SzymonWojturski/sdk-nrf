/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_types Doxygen reviewer type API
 * @{
 * @brief Types documented in the forms that the style guide accepts without a tag.
 * @details The file is split into two groups on purpose, because a single file is allowed to
 *          define more than one group.
 */

#ifndef DPR_GOOD_TYPES_H_
#define DPR_GOOD_TYPES_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Maximum number of entries that a single report can carry. */
#define DPR_TYPES_REPORT_MAX 8

/** Report of the entries collected during one sampling window. */
struct dpr_types_report {
	/** Number of valid entries in @ref dpr_types_report.entries. */
	size_t count;

	/** Collected entries, oldest first. */
	uint16_t entries[DPR_TYPES_REPORT_MAX];
};

/** Transport used to deliver a report. */
enum dpr_types_transport {
	DPR_TYPES_TRANSPORT_UART,	/**< Report is delivered over UART. */
	DPR_TYPES_TRANSPORT_RADIO,	/**< Report is delivered over the radio. */
};

/** @} */

/**
 * @defgroup dpr_types_util Doxygen reviewer type utilities
 * @{
 * @brief Helpers that operate on @ref dpr_types_report.
 */

/** @brief Reset a report to the empty state.
 *
 * @param[out] report Report to reset.
 */
void dpr_types_report_reset(struct dpr_types_report *report);

/** @brief Append an entry to a report.
 *
 * The entry is dropped when the report already holds @ref DPR_TYPES_REPORT_MAX entries.
 *
 * @param[in,out] report Report to append to.
 * @param[in]     entry  Entry to append.
 *
 * @retval true  If the entry was appended.
 * @retval false If the report was already full.
 */
bool dpr_types_report_append(struct dpr_types_report *report, uint16_t entry);

/** @brief Select the transport for the reports.
 *
 * @param[in] transport Transport to use for the following reports.
 *
 * @retval 0       If the transport was selected.
 * @retval -ENOTSUP If the build does not support @p transport.
 */
int dpr_types_transport_select(enum dpr_types_transport transport);

#ifdef __cplusplus
}
#endif

#endif /* DPR_GOOD_TYPES_H_ */

/** @} */

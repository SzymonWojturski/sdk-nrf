/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_semantic Doxygen reviewer semantic API
 * @{
 * @brief API whose documentation contradicts the behaviour that the implementation shows.
 */

#ifndef DPR_SEMANTIC_DIRECTIONS_H_
#define DPR_SEMANTIC_DIRECTIONS_H_

#include <stddef.h>
#include <stdint.h>

/** Statistics of the semantic fixture. */
struct dpr_semantic_stats {
	/** Number of collected samples. */
	size_t samples;

	/** Number of dropped samples. */
	size_t dropped;
};

/** @brief Fill the statistics of the semantic fixture.
 *
 * @param[in] stats Statistics to fill.
 *
 * @retval 0 If the statistics were filled.
 */
int dpr_semantic_stats_get(struct dpr_semantic_stats *stats);

/** @brief Accumulate the statistics of the semantic fixture.
 *
 * @param[out] stats Statistics to read the previous totals from and to update.
 *
 * @retval 0 If the statistics were accumulated.
 */
int dpr_semantic_stats_accumulate(struct dpr_semantic_stats *stats);

#endif /* DPR_SEMANTIC_DIRECTIONS_H_ */

/** @} */

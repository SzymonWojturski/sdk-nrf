/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 */

/** @brief Get the number of deduplicated findings.
 *
 * @return Number of deduplicated findings.
 */
unsigned int dpr_dedupe_count(void);

/**
 * @defgroup dpr_dedupe Doxygen reviewer deduplication API
 * @{
 */

/** @brief Reset the deduplication counter. */
void dpr_dedupe_reset(void);

/** @} */

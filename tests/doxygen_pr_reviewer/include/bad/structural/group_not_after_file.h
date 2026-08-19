/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 */

/** @brief Get the number of detached groups.
 *
 * @return Number of detached groups.
 */
unsigned int dpr_group_late_count(void);

/**
 * @defgroup dpr_group_late Doxygen reviewer detached group API
 * @{
 * @brief Group that does not follow the @file tag.
 */

/** @brief Reset the detached group counter. */
void dpr_group_late_reset(void);

/** @} */

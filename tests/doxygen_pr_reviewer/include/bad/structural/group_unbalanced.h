/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_group_unbalanced Doxygen reviewer unbalanced group API
 * @{
 * @brief Group that opens three scopes and closes two of them.
 */

/** @brief Get the number of unbalanced groups.
 *
 * @return Number of unbalanced groups.
 */
unsigned int dpr_group_unbalanced_count(void);

/**
 * @defgroup dpr_group_unbalanced_inner Doxygen reviewer inner unbalanced group
 * @{
 * @brief Inner group of the unbalanced fixture.
 */

/** @brief Reset the unbalanced group counter. */
void dpr_group_unbalanced_reset(void);

/**
 * @defgroup dpr_group_unbalanced_leaf Doxygen reviewer leaf unbalanced group
 * @{
 * @brief Leaf group of the unbalanced fixture.
 */

/** @brief Flush the unbalanced group counter. */
void dpr_group_unbalanced_flush(void);

/** @} */

/** @} */

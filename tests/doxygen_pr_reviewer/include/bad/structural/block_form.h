/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_structural
 * @{
 */

/* @brief Get the number of plain comment blocks.
 *
 * @return Number of plain comment blocks.
 */
unsigned int dpr_block_form_plain(void);

/// @brief Get the number of triple slash blocks.
///
/// @return Number of triple slash blocks.
unsigned int dpr_block_form_slashes(void);

/** @fn unsigned int dpr_block_form_fn(void)
 * @brief Get the number of blocks that name their function.
 *
 * @return Number of blocks that name their function.
 */
unsigned int dpr_block_form_fn(void);

/** @} */

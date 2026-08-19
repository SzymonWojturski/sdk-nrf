/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_structural
 * @{
 */

unsigned int dpr_block_position_late(void);
/** @brief Get the number of late blocks.
 *
 * @return Number of late blocks.
 */

enum dpr_block_position_state {
	DPR_BLOCK_POSITION_IDLE,
	DPR_BLOCK_POSITION_BUSY,
};
/** State of the late documented enum. */

typedef void (*dpr_block_position_cb_t)(void);
/** @brief Callback of the late documented typedef. */

/** @} */

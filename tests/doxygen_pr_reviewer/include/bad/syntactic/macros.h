/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_syntactic
 * @{
 */

/** @brief Build a slot descriptor of the macro fixture. */
#define DPR_MACRO_SLOT_GET(_id, _len)   \
{                                       \
	.id = (_id),                    \
	.len = (_len),                  \
}

/** @} */

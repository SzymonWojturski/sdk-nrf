/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_fallback
 * @{
 */

#include <stddef.h>
#include <stdint.h>

/** Expand to the argument list of the fallback transport. */
#define DPR_FALLBACK_ARGS(...) __VA_ARGS__

/** @brief Send a payload through the fallback transport.
 *
 * @param[in] buffer Buffer that holds the payload.
 * @param[in] len    Size of @p buffer in bytes.
 *
 * @retval 0       If the payload was sent.
 * @retval -EAGAIN If the transport is busy.
 */
int dpr_fallback_send(DPR_FALLBACK_ARGS(const uint8_t *buffer, size_t len));

/** @} */

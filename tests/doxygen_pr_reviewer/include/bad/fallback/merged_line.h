/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_fallback
 * @{
 */

#include <stdint.h>

/** @brief Queue a payload in the fallback transport.
 *
 * @param buffer buffer
 *
 * @retval 0 If the payload was queued.
 */
int dpr_fallback_queue(const uint8_t *buffer);

/** @} */

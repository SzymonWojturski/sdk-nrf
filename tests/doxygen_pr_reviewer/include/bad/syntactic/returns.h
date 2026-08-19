/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_syntactic
 * @{
 */

#include <stddef.h>

/** @brief Reset the return fixture.
 *
 * @return Nothing, because the fixture has no state to report.
 */
void dpr_returns_reset(void);

/** @brief Get the number of resets of the return fixture. */
size_t dpr_returns_count(void);

/** @} */

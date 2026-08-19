/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_fn_outside Doxygen reviewer out of scope function API
 * @{
 * @brief Group that closes before a public function is declared.
 */

/** @brief Get the number of scoped functions.
 *
 * @return Number of scoped functions.
 */
unsigned int dpr_fn_outside_scoped(void);

/** @} */

/** @brief Get the number of unscoped functions.
 *
 * @return Number of unscoped functions.
 */
unsigned int dpr_fn_outside_unscoped(void);

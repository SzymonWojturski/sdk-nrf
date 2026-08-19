/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_fallback Doxygen reviewer fallback API
 * @{
 * @brief API whose blocks defeat the parser, so the fallback of the branch has to take over.
 */

/** @brief Start the fallback fixture.
 *
 * @returns 0 on success
 *
int dpr_fallback_start(void);

/** @brief Stop the fallback fixture.
 *
 * @retval 0 If the fixture was stopped.
 */
int dpr_fallback_stop(void);

/** @} */

/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_semantic
 * @{
 */

/** @brief Arm the return fixture.
 *
 * @return 0 when the fixture was armed.
 */
int dpr_return_arm(void);

/** @brief Disarm the return fixture.
 *
 * @return Number of pending requests.
 * @return Negative error code when the fixture is not armed.
 */
int dpr_return_disarm(void);

/** @brief Flush the return fixture.
 *
 * @retval otherwise A negative error code is returned.
 */
int dpr_return_flush(void);

/** @brief Rearm the return fixture.
 *
 * @retval -EAGAIN
 * @retval 0 If the fixture was rearmed.
 */
int dpr_return_rearm(void);

/** @brief Drain the return fixture.
 *
 * @retval 0 If every pending request was drained.
 *           Otherwise, a negative error code is returned.
 */
int dpr_return_drain(void);

/** @} */

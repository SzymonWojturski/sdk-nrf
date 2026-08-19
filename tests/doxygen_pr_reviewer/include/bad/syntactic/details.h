/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_syntactic
 * @{
 */

/** @brief Arm the details fixture.
 *
 * @details The fixture stays armed until it is disarmed, and it ignores every further arm request.
 *
 * @retval 0 If the fixture was armed.
 */
int dpr_details_arm(void);

/** @brief Disarm the details fixture.
 *
 * The fixture drops the pending requests when it is disarmed.
 *
 * @retval 0 If the fixture was disarmed.
 */
int dpr_details_disarm(void);

/** @} */

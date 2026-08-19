/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_semantic
 * @{
 */

/** @brief Reset the Style Fixture Of The Doxygen Reviewer Testbed.
 *
 * @retval 0 If the fixture was reset.
 */
int dpr_style_reset(void);

/** @brief Suspend the style fixture.
 *
 * @details Suspend the style fixture.
 *
 * @retval 0 If the fixture was suspended.
 */
int dpr_style_suspend(void);

/** @brief Resume the style fixture.
 *
 * @details The function is called dpr_style_resume, takes no argument and returns an int.
 *
 * @retval 0 If the fixture was resumed.
 */
int dpr_style_resume(void);

/** @brief Trim the style fixture.
 *
 * @details Internally the function iterates the slot array with a signed loop counter and reuses
 *          the scratch buffer of the transport layer.
 *
 * @retval 0 If the fixture was trimmed.
 */
int dpr_style_trim(void);

/** @brief Purge the style fixture.
 *
 * @details The call never blocks and it is safe to use from an interrupt handler.
 *
 * @retval 0 If the fixture was purged.
 */
int dpr_style_purge(void);

/** @brief Seal the style fixture.
 *
 * @note The call is irreversible.
 *
 * @retval 0 If the fixture was sealed.
 */
int dpr_style_seal(void);

/** @} */

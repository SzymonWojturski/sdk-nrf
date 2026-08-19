/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_syntactic
 * @{
 */

/** \brief Start the tag fixture.
 *
 * \param[in] slots Number of slots to reserve.
 *
 * \retval 0 If the fixture was started.
 */
int dpr_tags_start(unsigned int slots);

/** @brief Stop the tag fixture.
 *
 * @note The call is asynchronous, so the fixture may still be running when it returns.
 *
 * @retval 0 If the stop request was accepted.
 */
int dpr_tags_stop(void);

/** @brief Flush the tag fixture.
 *
 * @details The call blocks until every pending slot is written out.
 *
 * @note The fixture uses a static buffer, so it must not be called from two threads.
 *
 * @retval 0 If the fixture was flushed.
 */
int dpr_tags_flush(void);

/** @brief Get the number of pending slots.
 *
 * @details The count is a snapshot taken while the fixture is stopped, and the caller has to treat it as a hint only.
 *
 * @returns Number of pending slots.
 */
unsigned int dpr_tags_pending(void);

/** @} */

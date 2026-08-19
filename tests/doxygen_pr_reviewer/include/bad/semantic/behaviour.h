/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_semantic
 * @{
 */

#include <stdint.h>

/** @brief Start the behaviour fixture.
 *
 * @details The call takes the module mutex, walks the static slot array from index zero, marks the
 *          first free entry with the magic value 0xAB and releases the mutex.
 *
 * @retval 0 If the fixture was started.
 */
int dpr_behaviour_start(void);

/** @brief Stop the behaviour fixture.
 *
 * @details The function returns nothing and only clears the internal state.
 *
 * @retval 0 If the fixture was stopped.
 */
int dpr_behaviour_stop(void);

/** @brief Set the slot identifier of the behaviour fixture.
 *
 * @param[in] id The id.
 *
 * @retval 0 If the identifier was set.
 */
int dpr_behaviour_id_set(uint8_t id);

/** @brief Get the slot identifier of the behaviour fixture.
 *
 * @param[out] id Identifier of the active slot, valid only when the call succeeds.
 *
 * @retval 0 If the identifier was read.
 */
int dpr_behaviour_id_get(uint8_t *id);

/** @} */

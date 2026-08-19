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
#include <stdint.h>

/** @brief Copy the slot contents into a buffer.
 *
 * @param buffer Buffer that receives the slot contents.
 * @param[in] len Size of @p buffer in bytes.
 *
 * @retval 0 If the contents were copied.
 */
int dpr_params_copy(uint8_t *buffer, size_t len);

/** @brief Reserve a slot for the given position.
 *
 * @param[in] position
 *
 * @retval 0 If the slot was reserved.
 */
int dpr_params_reserve(uint8_t position);

/** @brief Release a slot.
 *
 * @param[in] identifier Identifier of the slot to release.
 *
 * @retval 0 If the slot was released.
 */
int dpr_params_release(uint8_t id);

/** @brief Move a slot to another position.
 *
 * @param[in] from Position to move the slot from.
 *
 * @retval 0 If the slot was moved.
 */
int dpr_params_move(uint8_t from, uint8_t to);

/** @brief Rename a slot.
 *
 * @param[in] id   Identifier of the slot to rename
 * @param[in] name New name of the slot.
 *
 * @retval 0 If the slot was renamed.
 */
int dpr_params_rename(uint8_t id, const char *name);

/** @brief Read the name of a slot.
 *
 * @param[out] id Identifier of the slot to read the name of.
 *
 * @return Name of the slot, or NULL if the slot is free.
 */
const char *dpr_params_name(uint8_t id);

/** @brief Swap two slots.
 *
 * @param[in] first Position of the first slot.
 * @param second    Position of the second slot.
 *
 * @retval 0 If the slots were swapped.
 */
int dpr_params_swap(uint8_t first, uint8_t second);

/** @brief Truncate a slot to the given length.
 *
 * The call keeps the first len bytes of the slot and drops the rest of `len`.
 *
 * @param[in] id  Identifier of the slot to truncate.
 * @param[in] len New length of the slot in bytes.
 *
 * @retval 0 If the slot was truncated.
 */
int dpr_params_truncate(uint8_t id, size_t len);

/** @} */

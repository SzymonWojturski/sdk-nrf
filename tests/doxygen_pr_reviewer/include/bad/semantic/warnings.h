/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_semantic
 * @{
 */

/** @brief Drive the motor of the test rig at full torque.
 *
 * @details The rig starts moving immediately and does not stop until the call is repeated with a
 *          zero speed, so the operator has to stay clear of the moving parts.
 *
 * @param[in] speed Speed of the motor in revolutions per minute.
 *
 * @retval 0 If the motor was started.
 */
int dpr_warning_motor_drive(unsigned int speed);

/** @brief Write the permanent lock bits of the device.
 *
 * @details The lock bits cannot be cleared again, and the debug interface stays disabled for the
 *          rest of the lifetime of the device.
 *
 * @retval 0 If the lock bits were written.
 */
int dpr_warning_lock_write(void);

/** @brief Switch the transport of the test rig to the slow profile.
 *
 * @details The profile is stored in RAM only, so the previous profile is restored by a reset.
 *
 * @retval 0 If the profile was switched.
 */
int dpr_warning_profile_switch(void);

/** @} */

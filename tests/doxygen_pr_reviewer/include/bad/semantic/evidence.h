/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_semantic
 * @{
 */

#include <stddef.h>
#include <stdint.h>

/** @brief Measure the temperature of the test rig.
 *
 * @details The value is returned in millidegrees Celsius, the call powers down the radio as a side
 *          effect, and the caller takes the ownership of the returned buffer.
 *
 * @param[out] buffer Buffer that receives the measurement.
 * @param[in]  len    Size of @p buffer in bytes.
 *
 * @retval 0 If the temperature was measured.
 */
int dpr_evidence_temperature_get(uint8_t *buffer, size_t len);

/** @brief Calibrate the test rig.
 *
 * @param[in] rounds Number of calibration rounds to run.
 *
 * @retval 0 If the rig was calibrated.
 */
int dpr_evidence_calibrate(unsigned int rounds);

/** @} */

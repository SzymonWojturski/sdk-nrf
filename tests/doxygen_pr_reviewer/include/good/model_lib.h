/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_model Doxygen reviewer model API
 * @{
 * @brief Reference API used as the zero-finding baseline of the reviewer testbed.
 */

#ifndef DPR_MODEL_LIB_H_
#define DPR_MODEL_LIB_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Build a sample descriptor.
 *
 * @param _id   Identifier of the sample source.
 * @param _len  Length of the sample in bytes.
 */
#define DPR_MODEL_SAMPLE_GET(_id, _len)   \
{                                         \
	.source_id = (_id),               \
	.length = (_len),                 \
}

/** Reference sensor state. */
enum dpr_model_state {
	/** Sensor is powered down. */
	DPR_MODEL_STATE_OFF,

	/** Sensor is sampling. */
	DPR_MODEL_STATE_ACTIVE,

	/** Sensor reported an unrecoverable failure. */
	DPR_MODEL_STATE_FAULT,
};

/** Sample descriptor. */
struct dpr_model_sample {
	/** Identifier of the sample source. */
	uint8_t source_id;

	/** Length of the sample in bytes. */
	size_t length;
};

/**
 * @brief Handle a state change of the reference sensor.
 *
 * The handler runs in the context of the caller of @ref dpr_model_sensor_read.
 *
 * @param[in] state New state of the sensor.
 */
typedef void (*dpr_model_state_handler_t)(enum dpr_model_state state);

/** @brief Read a sample from the reference sensor.
 *
 * The call blocks until the sensor reports a new sample or until the sensor is powered down.
 *
 * @param[out] sample Buffer that receives the sample. Must be at least @p len bytes long.
 * @param[in]  len    Size of @p sample in bytes.
 * @param[out] olen   Number of bytes written to @p sample.
 *
 * @sa dpr_model_state_get
 * @sa dpr_model_handler_set
 *
 * @retval 0       If the sample was read successfully.
 * @retval -EINVAL If @p len is zero.
 * @retval -EAGAIN If no sample is available yet.
 */
int dpr_model_sensor_read(uint8_t *sample, size_t len, size_t *olen);

/** @brief Get the current state of the reference sensor.
 *
 * @return Current state of the sensor.
 */
enum dpr_model_state dpr_model_state_get(void);

/** @brief Register a state change handler.
 *
 * @details Only one handler can be registered at a time. Registering a new handler replaces
 *          the previous one.
 *
 * @note The handler is called from the context that reads the samples, so it must not block.
 *
 * @param[in] handler Handler to register, or NULL to remove the current handler.
 */
void dpr_model_handler_set(dpr_model_state_handler_t handler);

#ifdef __cplusplus
}
#endif

#endif /* DPR_MODEL_LIB_H_ */

/**
 * @}
 */

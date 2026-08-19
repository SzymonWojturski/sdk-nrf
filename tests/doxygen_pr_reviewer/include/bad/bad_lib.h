/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_mutable Doxygen reviewer mutable API
 * @{
 * @brief API that later test pull requests mutate to inject defects.
 */

#ifndef DPR_BAD_LIB_H_
#define DPR_BAD_LIB_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Configuration of the mutable transport. */
struct dpr_mutable_config {
	/** Size of the transport window in bytes. */
	size_t window;

	/** Number of retries before the transfer is abandoned. */
	uint8_t retries;
};

/** @brief Configure the mutable transport.
 *
 * @param[in] config Configuration to apply to the transport.
 *
 * @retval 0       If the configuration was applied.
 * @retval -EINVAL If the window size in @p config is zero.
 */
int dpr_mutable_configure(struct dpr_mutable_config *config);

/** @brief Normalize a transport window.
 *
 * @param[in] config Configuration to read the window from.
 *
 * @return Window size rounded down to the nearest power of two.
 */
size_t dpr_mutable_window_normalize(const struct dpr_mutable_config *config);

/** @brief Copy the pending payload out of the transport.
 *
 * @param[out] payload Buffer that receives the payload. Must be at least @p len bytes long.
 * @param[in]  len     Size of @p payload in bytes.
 *
 * @retval 0       If the payload was copied.
 * @retval -ENOMEM If @p len is smaller than the pending payload.
 */
int dpr_mutable_payload_get(uint8_t *payload, size_t len);

/** Erase the transport state.
 *
 * @details The call drops the pending payload and restores the default configuration.
 */
void dpr_mutable_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* DPR_BAD_LIB_H_ */

/**
 * @}
 */

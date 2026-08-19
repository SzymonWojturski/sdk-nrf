/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/*
 * Internal header of the reviewer testbed.
 *
 * The directory is outside the INPUT of nrf.doxyfile.in and the file declares no doxygen group,
 * so nothing declared here belongs to the public API.
 */

#ifndef DPR_INTERNAL_LIB_H_
#define DPR_INTERNAL_LIB_H_

#include <stddef.h>

/* Round the value down to the nearest power of two. */
size_t dpr_internal_floor_pow2(size_t value);

#endif /* DPR_INTERNAL_LIB_H_ */

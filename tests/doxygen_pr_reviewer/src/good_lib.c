/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <string.h>

#include "model_lib.h"

static enum dpr_model_state sensor_state = DPR_MODEL_STATE_OFF;
static dpr_model_state_handler_t state_handler;
static const uint8_t canned_sample[] = { 0x01, 0x02, 0x03, 0x04 };

int dpr_model_sensor_read(uint8_t *sample, size_t len, size_t *olen)
{
	if (len == 0) {
		return -EINVAL;
	}

	if (sensor_state != DPR_MODEL_STATE_ACTIVE) {
		return -EAGAIN;
	}

	/* The canned sample is truncated to the size of the caller buffer. */
	size_t copied = MIN(len, sizeof(canned_sample));

	memcpy(sample, canned_sample, copied);
	*olen = copied;

	return 0;
}

enum dpr_model_state dpr_model_state_get(void)
{
	return sensor_state;
}

void dpr_model_handler_set(dpr_model_state_handler_t handler)
{
	state_handler = handler;
}

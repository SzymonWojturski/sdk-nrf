/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <string.h>

#include "bad_lib.h"

static struct dpr_mutable_config active_config;
static uint8_t pending_payload[16];
static size_t pending_len;

int dpr_mutable_configure(const struct dpr_mutable_config *config)
{
	if (config->window == 0) {
		return -EINVAL;
	}

	active_config = *config;

	return 0;
}

size_t dpr_mutable_window_normalize(const struct dpr_mutable_config *config)
{
	size_t window = 1;

	while ((window << 1) <= config->window) {
		window <<= 1;
	}

	return window;
}

int dpr_mutable_payload_get(uint8_t *payload, size_t len)
{
	if (len < pending_len) {
		return -ENOMEM;
	}

	memcpy(payload, pending_payload, pending_len);

	return 0;
}

void dpr_mutable_reset(void)
{
	memset(&active_config, 0, sizeof(active_config));
	pending_len = 0;
}

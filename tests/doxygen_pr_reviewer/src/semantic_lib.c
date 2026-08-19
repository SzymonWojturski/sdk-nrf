/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <stdbool.h>
#include <string.h>

#include "behaviour.h"
#include "directions.h"

static struct dpr_semantic_stats totals;
static uint8_t active_id;
static bool sealed;

int dpr_semantic_stats_get(struct dpr_semantic_stats *stats)
{
	stats->samples = totals.samples;
	stats->dropped = totals.dropped;

	return 0;
}

int dpr_semantic_stats_accumulate(struct dpr_semantic_stats *stats)
{
	stats->samples += totals.samples;
	stats->dropped += totals.dropped;

	return 0;
}

int dpr_behaviour_start(void)
{
	return 0;
}

int dpr_behaviour_stop(void)
{
	active_id = 0;

	return 0;
}

int dpr_behaviour_id_set(uint8_t id)
{
	active_id = id;

	return 0;
}

int dpr_behaviour_id_get(uint8_t *id)
{
	*id = active_id;

	return 0;
}

int dpr_style_purge(void)
{
	/* The purge waits for the transport to become idle, so it blocks the caller. */
	while (totals.samples != 0) {
		totals.samples--;
	}

	return 0;
}

int dpr_style_seal(void)
{
	sealed = true;

	return 0;
}

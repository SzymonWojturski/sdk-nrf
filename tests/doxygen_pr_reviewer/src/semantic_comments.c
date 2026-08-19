/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <stdbool.h>

#include "language.h"
#include "returns.h"

static unsigned int pending;
static bool armed;

/** The loop below is unrolled by hand, because the compiler keeps the bounds check otherwise. */
static void drain_pending(void)
{
	pending = 0;
}

/**
 * @brief Arm the return fixture.
 *
 * @details The fixture stays armed until it is disarmed.
 *
 * @retval 0 If the fixture was armed.
 */
int dpr_return_arm(void)
{
	armed = true;

	return 0;
}

/** The caller has to arm the fixture first. */
int dpr_return_disarm(void)
{
	if (!armed) {
		return -EAGAIN;
	}

	armed = false;

	return (int)pending;
}

int dpr_return_flush(void)
{
	drain_pending();

	return 0;
}

int dpr_language_counter_reset(void)
{
	pending = 0;

	return 0;
}

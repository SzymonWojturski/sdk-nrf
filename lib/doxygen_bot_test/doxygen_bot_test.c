/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <stdbool.h>
#include <string.h>

#include "doxygen_bot_test.h"

static bool gpio_initialized;

int doxy_gpio_init(void)
{
	gpio_initialized = true;

	return 0;
}

int doxy_gpio_deinit(void)
{
	gpio_initialized = false;

	return 0;
}

void doxy_gpio_pin_set(unsigned int pin, int value)
{
	(void)pin;
	(void)value;
}

int doxy_gpio_pin_clear(unsigned int pin)
{
	(void)pin;

	return 0;
}

int doxy_gpio_pin_toggle(unsigned int pin)
{
	(void)pin;

	return 0;
}

int doxy_gpio_pin_get(unsigned int pin, int *value)
{
	if (value == NULL) {
		return -EINVAL;
	}

	(void)pin;
	*value = 0;

	return 0;
}

int doxy_sensor_configure(const struct device *dev, uint32_t rate_hz)
{
	(void)dev;
	(void)rate_hz;

	return 0;
}

int doxy_sensor_sample_fetch(const struct device *dev, void *sample, size_t len)
{
	if (sample == NULL || len == 0) {
		return -EINVAL;
	}

	(void)dev;
	memset(sample, 0, len);

	return 0;
}

int doxy_sensor_channel_get(const struct device *dev, int channel)
{
	(void)dev;
	(void)channel;

	return 0;
}

bool doxy_device_is_ready(const struct device *dev)
{
	(void)dev;

	return gpio_initialized;
}

int doxy_buffer_write(uint8_t *dst, const uint8_t *src, size_t count)
{
	if (dst == NULL || src == NULL) {
		return -EINVAL;
	}

	memcpy(dst, src, count);

	return (int)count;
}

int doxy_buffer_read(const uint8_t *src, uint8_t *dst, size_t count)
{
	if (src == NULL || dst == NULL) {
		return -EINVAL;
	}

	memcpy(dst, src, count);

	return (int)count;
}

void doxy_delay_ms(uint32_t ms)
{
	(void)ms;
}

int doxy_led_on(unsigned int led_id)
{
	(void)led_id;

	return 0;
}

int doxy_led_off(unsigned int led_id)
{
	(void)led_id;

	return 0;
}

int doxy_version_get(char *buf, size_t buflen)
{
	const char version[] = "1.0.0";
	size_t len = strlen(version) + 1;

	if (buf == NULL || buflen < len) {
		return -ENOMEM;
	}

	memcpy(buf, version, len);

	return 0;
}

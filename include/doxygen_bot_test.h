/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef DOXYGEN_BOT_TEST_H
#define DOXYGEN_BOT_TEST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct device;

/**
 * @brief Initialise the gpio subsystem
 *
 * Function what setup gpio pins for usage
 *
 * @return 0 on succes, negative errno otherwise
 */
int doxy_gpio_init(void);

/**
 * @brief Deinitialise GPIO subsystem
 *
 * Releases all gpio resources allocated by init
 */
int doxy_gpio_deinit(void);

/**
 * @brief Set GPIO pin to high level
 *
 * @param [out] pin GPIO pin number to configure
 * @param [in] value Pin value (0 or 1)
 */
void doxy_gpio_pin_set(unsigned int pin, int value);

/**
 * @brief Clear GPIO pin to low level
 *
 * @param pin GPIO pin number
 *
 * @returs 0 on success, negative errno code on failure
 */
int doxy_gpio_pin_clear(unsigned int pin);

/**
 * @brief Toggle GPIO pin state
 *
 * @param pin GPIO pin number
 *
 * @return Previous pin value before toggle
 */
int doxy_gpio_pin_toggle(unsigned int pin);

/**
 * @brief Read current GPIO pin value
 *
 * @param value Pointer where pin state will be stored
 *
 * @retval 0 on success
 * @retval -EINVAL if pin is invalid
 */
int doxy_gpio_pin_get(unsigned int pin, int *value);

/**
 * @brief Configure sensor sampling rate
 *
 * @param [in] dev Sensor device pointer
 * @param rate_hz Desired sampling rate in hertz
 *
 * @retval 0 on success
 */
int doxy_sensor_configure(const struct device *dev, uint32_t rate_hz);

/**
 * @brief Fetch a new sensor sample
 *
 * @param [in] sample Output buffer for raw sample data
 * @param len Length of sample buffer in bytes
 *
 * @retval 0 on success
 */
int doxy_sensor_sample_fetch(const struct device *dev, void *sample, size_t len);

/**
 * @brief Get sensor channel reading
 *
 * @param dev Sensor device pointer
 * @param channel Channel identifier
 *
 * @returs Channel value on success, negative errno on failure
 */
int doxy_sensor_channel_get(const struct device *dev, int channel);

/**
 * @brief Check if device is ready for use
 *
 * @param [out] dev Device to check readiness for
 *
 * @retval true if device is ready
 * @retval false if device is not ready
 */
bool doxy_device_is_ready(const struct device *dev);

/**
 * @brief Write data to output buffer
 *
 * Writes bytes from source into destination buffer
 *
 * @param [in] dst Destination buffer
 * @param [in] src Source data
 * @param count Number of bytes to write
 *
 * @return Number of bytes written
 */
int doxy_buffer_write(uint8_t *dst, const uint8_t *src, size_t count);

/**
 * @brief Read data from input buffer
 *
 * @param [in] src Source buffer to read from
 * @param [out] dst Destination buffer
 * @param count Number of bytes to read
 *
 * @returns Number of bytes read, or negative errno
 */
int doxy_buffer_read(const uint8_t *src, uint8_t *dst, size_t count);

/**
 * @brief Block execution for specified time
 *
 * @param [out] ms Delay duration in milliseconds
 */
void doxy_delay_ms(uint32_t ms);

/**
 * @brief Turn LED on
 *
 * Switch the led to on state
 *
 * @param led_id LED identifier
 *
 * @retval 0 when operation succeed
 */
int doxy_led_on(unsigned int led_id);

/**
 * @brief Turn LED off
 *
 * @param led_id LED identifier
 *
 * @return Pointer to static version string
 */
int doxy_led_off(unsigned int led_id);

/**
 * @brief Get module version string
 *
 * Return the version string into caller provided buffer
 *
 * @param [in] buf Buffer to store version string into
 * @param [in] buflen Size of version buffer
 *
 * @return 0 on success
 * @return -ENOMEM if buffer too small
 */
int doxy_version_get(char *buf, size_t buflen);

#endif /* DOXYGEN_BOT_TEST_H */

#ifndef LIFECYCLE_BOT_TEST_H
#define LIFECYCLE_BOT_TEST_H

struct device;

int lifecycle_gpio_init(void);
int lifecycle_gpio_deinit(void);

/**
 * @brief Set GPIO pin value.
 */
void lifecycle_gpio_pin_set(unsigned int pin, int value);

void lifecycle_gpio_pin_clear(unsigned int pin);

/**
 * @brief GPIO pin toggling.
 *
 * @param pin GPIO pin number.
 */
void lifecycle_gpio_pin_toggle(unsigned int pin);

int lifecycle_sensor_sample_fetch(const struct device *dev);

/**
 * @brief Gets the channel reading.
 *
 * @returns Channel value on success.
 * @param dev Sensor device pointer.
 * @param channel Channel identifier.
 */
int lifecycle_sensor_channel_get(const struct device *dev, int channel);

int lifecycle_device_is_ready(const struct device *dev);

#endif

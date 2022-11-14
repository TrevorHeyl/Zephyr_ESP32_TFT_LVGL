/*
 * Copyright (c) 2021 Espressif Systems (Shanghai) Co., Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <drivers/gpio.h>

#define LED_R_PIN  DT_GPIO_PIN(DT_ALIAS(led2), gpios)
#define LED_G_PIN  DT_GPIO_PIN(DT_ALIAS(led1), gpios)
#define LED_B_PIN  DT_GPIO_PIN(DT_ALIAS(led0), gpios)

static int powerbot_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	const struct device *gpio;

	gpio = device_get_binding(DT_LABEL(DT_NODELABEL(gpio0)));
	if (!gpio) {
		return -ENODEV;
	}

	/* turns red LED off */
	gpio_pin_configure(gpio, LED_R_PIN, GPIO_OUTPUT);
	gpio_pin_set(gpio, LED_R_PIN, GPIO_OUTPUT_INACTIVE);

	/* turns green LED off */
	gpio_pin_configure(gpio, LED_G_PIN, GPIO_OUTPUT);
	gpio_pin_set(gpio, LED_G_PIN, GPIO_OUTPUT_INACTIVE);

	/* turns blue LED off */
	gpio_pin_configure(gpio, LED_B_PIN, GPIO_OUTPUT);
	gpio_pin_set(gpio, LED_B_PIN, GPIO_OUTPUT_INACTIVE);

	return 0;
}

SYS_INIT(board_esp_wrover_kit_init, PRE_KERNEL_2, CONFIG_PINMUX_INIT_PRIORITY);

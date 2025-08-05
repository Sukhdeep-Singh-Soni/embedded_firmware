/*
 * Filename   : stm32f429xx.h
 * Created on : Jul 30, 2025
 * Author     : Sukhdeep Singh
 * Note		  : This file contains the gpio driver api's for stm32f429xx
 * 				microcontroller
 */

#include "stm32f429xx_gpio.h"

void gpio_init(gpio_handle_t *pgpiohandle) {
	uint32_t tempreg = 0;

	if (pgpiohandle->gpio_config.gpio_mode < GPIO_MODE_ANALOG) {
		//configure mode
		tempreg = pgpiohandle->gpio_config.gpio_mode << (2 * pgpiohandle->gpio_config.gpio_pin);
		pgpiohandle->pgpio->moder |= tempreg;
		if (pgpiohandle->gpio_config.gpio_mode == GPIO_MODE_ALTERNATE) {
			// configure alternate function selection number
			uint8_t idx = pgpiohandle->gpio_config.gpio_pin / 8;
			uint8_t shift = (pgpiohandle->gpio_config.gpio_pin % 8) * 4;
			pgpiohandle->pgpio->afr[idx] = pgpiohandle->gpio_config.gpio_alternate << shift;
		}
	}

	tempreg = 0;
	if (pgpiohandle->gpio_config.gpio_mode == GPIO_MODE_OUTPUT) {
		// configure output type
		tempreg = pgpiohandle->gpio_config.gpio_optype << pgpiohandle->gpio_config.gpio_pin;
		pgpiohandle->pgpio->optype |= tempreg;

		tempreg = 0;
		//configure output speed
		tempreg = pgpiohandle->gpio_config.gpio_opspeed << (2 * pgpiohandle->gpio_config.gpio_pin);
		pgpiohandle->pgpio->ospeed |= tempreg;
	}

	//configure pull up / pull down
	tempreg = 0;
	tempreg = pgpiohandle->gpio_config.gpio_opspeed << (2 * pgpiohandle->gpio_config.gpio_pin);
	pgpiohandle->pgpio->ospeed |= tempreg;
}

void gpio_write_pin(gpio_regdef_t *pgpio, uint8_t gpio_pin_number, uint8_t gpio_val) {
	if (gpio_val == GPIO_HIGH)
		pgpio->odr |= (1 << gpio_pin_number);
	else
		pgpio->odr &= ~(1 << gpio_pin_number);
}

void gpio_write_pin_bsrr(void);

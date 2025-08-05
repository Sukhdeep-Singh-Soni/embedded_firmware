/*
 * Filename   : stm32f429xx.h
 * Created on : Jul 30, 2025
 * Author     : Sukhdeep Singh
 * Note		  : This file contains the gpio driver api headers for stm32f429xx
 * 				microcontroller
 */

#ifndef STM32F429XX_GPIO_H_
#define STM32F429XX_GPIO_H_

#include "stm32f429xx.h"


typedef struct {
	uint8_t gpio_pin;		// pin number to associate gpio pin to
	uint8_t gpio_mode;		// input/output/alternate/analog
	uint8_t gpio_optype;	// push pull/ open drain
	uint8_t gpio_opspeed;	// low/medium/high/very high
	uint8_t gpio_pupdr;		// pull up / pull down
	uint8_t gpio_alternate;  // alternate function selection
}gpio_config_t;

typedef struct {
	gpio_regdef_t *pgpio;
	gpio_config_t gpio_config;
}gpio_handle_t;

#define GPIO_MODE_INPUT		0x00
#define GPIO_MODE_OUTPUT	0x01
#define GPIO_MODE_ALTERNATE	0x02
#define GPIO_MODE_ANALOG	0x03

#define GPIO_OPTYPE_PP		0x00 //push pull
#define GPIO_OPTYPE_OD		0x01 // open drain

#define GPIO_OSPEED_LOW			0x00
#define GPIO_OSPEED_MEDIUM		0x01
#define GPIO_OSPEED_HIGH			0x02
#define GPIO_OSPEED_VERYHIGH		0x03

#define GPIO_PIN_0		0x00
#define GPIO_PIN_1		0x01
#define GPIO_PIN_2		0x02
#define GPIO_PIN_3		0x03
#define GPIO_PIN_4		0x04
#define GPIO_PIN_5		0x05
#define GPIO_PIN_6		0x06
#define GPIO_PIN_7		0x07
#define GPIO_PIN_8		0x08
#define GPIO_PIN_9		0x09
#define GPIO_PIN_10		0x0a
#define GPIO_PIN_11		0x0b
#define GPIO_PIN_12		0x0c
#define GPIO_PIN_13		0x0d
#define GPIO_PIN_14		0x0e
#define GPIO_PIN_15		0x0f

#define GPIO_PUPD_NO	0x00
#define GPIO_PUPD_PU	0x01
#define GPIO_PUPD_PD	0x02

#define GPIO_HIGH		1
#define GPIO_LOW		0
/*
 * API's provided
 * 1. gpio_init
 * 2. gpio_deinit
 * 3. gpio_write_pin
 * 4. gpio_read_pin
 * 5. gpio_write_port
 * 6. gpio_read_port
 * 7. gpio_bsrr_write_pin
 * 8. gpio_lock_pin_config
 * */
void gpio_init(gpio_handle_t *pgpiohandle);
void gpio_write_pin(gpio_regdef_t *pgpio, uint8_t gpio_pin_number, uint8_t gpio_val);

#endif /* STM32F429XX_GPIO_H_ */

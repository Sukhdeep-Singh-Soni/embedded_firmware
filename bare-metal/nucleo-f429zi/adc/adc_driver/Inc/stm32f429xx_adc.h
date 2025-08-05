/*
 * stm32f429xx_adc.h
 *
 *  Created on: Jul 30, 2025
 *      Author: sukhdeep.singh
 */

#ifndef STM32F429XX_ADC_H_
#define STM32F429XX_ADC_H_

#include "stm32f429xx.h"

typedef struct {
	uint8_t adc_alignment; // right / left
	uint8_t adc_resolution; // 12 bit/ 10/8/6 bit
	uint8_t eoc_on_each_or_seq;	// end of conversion on each conversion or after sequence of conversion
	uint8_t adc_mode;			// single ended / scan / continuous / dicontinuous
	uint8_t adc_trigger;			//software of external
	uint8_t adc_sampling_time;		// no of adc cycles to sample an input
}adc_config_t;

typedef struct {
	adc_regdef_t *padc;
	adc_config_t adc_config;
}adc_handle_t;

#define ADC_MODE_SCAN			0
#define ADC_MODE_CONTINUOUS		1
#define ADC_MODE_SINGLE_ENDED	3
#define ADC_MODE_DISCONT		4

/* API's provided
 * adc_init
 * adc_start
 * adc_pollforconversion
 * adc_stop
 * adc_get_regular_value
 *
 * */
void adc_init(adc_handle_t *padchandle);
void adc_poll_for_convesion(adc_handle_t *padchandle);
uint16_t adc_get_regular_val(adc_handle_t *padchandle);
void adc_channel_config(adc_handle_t *padchandle);
#endif /* STM32F429XX_ADC_H_ */

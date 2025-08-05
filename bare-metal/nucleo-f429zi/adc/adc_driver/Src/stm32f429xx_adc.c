/*
 * stm32f429xx_adc.c
 *
 *  Created on: Jul 30, 2025
 *      Author: sukhdeep.singh
 */

#include "stm32f429xx_adc.h"

void adc_init(adc_handle_t *padchandle) {
	if (padchandle->adc_config.adc_mode == ADC_MODE_SINGLE_ENDED) {
		//enable adc
		padchandle->padc->cr2 |= (1 << 0);
		//software start conversion
		padchandle->padc->cr2 |= (1 << 30);
	}
}

void adc_poll_for_convesion(adc_handle_t *padchandle) {

	while (!padchandle->padc->sr & (1 << 0));
}

uint16_t adc_get_regular_val(adc_handle_t *padchandle) {
	return padchandle->padc->dr;
}

void adc_channel_config(adc_handle_t *padchandle) {
	// number of channles to configure is 1
	padchandle->padc->sqr1 |= (1 << 20);

//	//channel number 0
//	padchandle->padc->sqr3 &= ~(1 << 0);
}

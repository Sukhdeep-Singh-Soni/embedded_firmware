/*
 * it.c
 *
 *  Created on: Jul 27, 2025
 *      Author: sukhdeep.singh
 */

#include "main_app.h"

void SysTick_Handler(void) {
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}



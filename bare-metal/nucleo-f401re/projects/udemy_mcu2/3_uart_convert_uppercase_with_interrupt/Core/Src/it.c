/*
 * it.c
 *
 *  Created on: Jul 27, 2025
 *      Author: sukhdeep.singh
 */

#include "main_app.h"
extern UART_HandleTypeDef huart2;

void SysTick_Handler(void) {
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void) {
	HAL_UART_IRQHandler(&huart2);
}


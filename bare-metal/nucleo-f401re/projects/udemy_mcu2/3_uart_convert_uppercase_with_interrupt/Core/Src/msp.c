/*
 * msp.c
 *
 *  Created on: Jul 27, 2025
 *      Author: sukhdeep.singh
 */

#include "main_app.h"
extern void Error_Handler(void);

void HAL_MspInit(void)
{
	//low level processor specific initializations
	//1. set NVIC priority grouping
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	//2. enable system exceptions usage fault, memmanage fault, bus fault
	SCB->SHCSR |= (0x07 << 16);
	//3. set the NVIC priority for busfault, memmanagefault, usagefault
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	//low level uart configuration
	//1. enable clock for uart2 peripheral
	__HAL_RCC_USART2_CLK_ENABLE();
	//2. enable clock for gpioa peripheral
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//3. configure pins PA2 as USART_TX and PA3 as USART RX in alternate function mode
	GPIO_InitTypeDef gpio_uart;

	//PA2 as USART_TX
	gpio_uart.Pin = GPIO_PIN_2;
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &gpio_uart);

	//PA3 as USART_RX
	gpio_uart.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA, &gpio_uart);
	//4. enable USART2 IRQ and set priority for NVIC
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
}

/*
 * main_app.c
 *
 *  Created on: Jul 27, 2025
 *      Author: sukhdeep.singh
 */


#include "main_app.h"
#include <string.h>

void SystemClock_Config(void);
void UART_Init(void);
void Error_Handler(void);
uint8_t convert_to_capital(uint8_t data);

UART_HandleTypeDef huart2;

int main(void) {

	char *sendstr = "Basic UART application to convert lower case alphabets to upper case\r\n";

	HAL_Init();

	SystemClock_Config();

	UART_Init();

	uint8_t len = strlen(sendstr);
	HAL_UART_Transmit(&huart2, (uint8_t*)sendstr, len, HAL_MAX_DELAY);
	uint8_t recv_data;
	uint8_t data_buffer[100];
	uint32_t count = 0;
	while(1) {
		HAL_UART_Receive(&huart2, &recv_data, 1, HAL_MAX_DELAY);
		if (recv_data == '\r') {
			data_buffer[count++] = recv_data;
			break;
		} else {
			data_buffer[count++] = convert_to_capital(recv_data);
		}
	}
	HAL_UART_Transmit(&huart2, data_buffer, count, HAL_MAX_DELAY);
	while(1);
}

uint8_t convert_to_capital(uint8_t data) {
	if (data >= 'a' && data <= 'z')
		data = data - ('a' - 'A');
	return data;
}
void SystemClock_Config(void) {
	// not implementing it yet, by default using 16MHz internal HSI
}

void UART_Init(void) {
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
		Error_Handler();
	}
}

void Error_Handler(void) {
	while(1);
}

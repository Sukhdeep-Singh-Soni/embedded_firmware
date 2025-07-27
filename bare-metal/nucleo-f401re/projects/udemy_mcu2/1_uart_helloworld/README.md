# Test Code to check UART send string to PC  

- Here we defined a string variable and passed it to HAL_UART_Transmit() api  
- The HAL_UART_Transmit() api required 4 arguments namely  
	- handle to uart configuration structure variable "UART_HandleTypeDef"
	- pointer to the string of type "const uint8_t*"  
	- length of the string  
	- delay to wait for if some errors or problems occcur. (HAL_MAX_DELAY)  
- We used HAL_MAX_DELAY to wait for a very long time (0xFFFFFFFFU)  
- We used strlen() api to get the string length and included string.h header for that. 
- UART configuration is 115200, 8N1 and this initialization is done in MX_USART2_UART_Init().  
- On every reset the controller sends the Hello World string once.  
 


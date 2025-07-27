# Code to get the converted uppecase string from uart interrupt

- including the points from 2_uart_convert_uppercase_blocking README.md file.
- here we are receiving characters byte by byte and converting the alphabets to capital if lower case with uart receive interrupt
- calling the UART_IRQHandler inside USART2_IRQHandler and implementing the Rx complete callback
- in the rx complete callback we converted the characters byte by byte and again putting the uart in rx interrupt mode in main function
- we are using a flag mechanism to indicate to main that stop uart_rx in interrupt when data is complete by a '\r' received byte(end character)

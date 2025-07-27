# Code to get the converted uppecase string from uart

- we first excluded main.c stm32f4xx_it.c and stm32f4xx_hal_msp.c, main.h, stm32f4xx_it.h.
- then we created new files main_app.c main_app.h it.c it.h msp.c.
- we created the code which was created by cubemx from scratch.
- we included stm32f4xx.h stm32f4xx_hal.h headers, called HAL_Init(), SystemClock_Config() functions.
- we did high level initialization of UART peripheral and the low level initialization is done in msp.c 
- we defined the systick handler and usart2 handler in it.c.
- without systick handler definition the code was misbehaving because HAL layer need systick for its timing related tasks.
- the string was not printing entirely inlt some characters were printed not while string without systick handler definition.
- here we are receiving characters byte by byte and converting the alphabets to capital if lower case



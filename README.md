# Directory Structure

## conventions
 - brd_xxx - board specific folder or file.
 - sch_xxx - schematic file
 - um_xxx  - user manual file
 - ds_xxx  - datasheet file
 - rm_xxx  - reference manual file
 - trm_xxx - technical reference manual
 - gug_xxx - generic user guide file
 - archarm_xxx - architecture reference manual
 - uc_xxx  - microcontroller specific folder or file
 - proc_xxx - processor specific folder or file

## directory structure

```
embedded_firmware/    
	|_ bare-metal/ 					"all driver codes and ide codes for bare metal"  
	|	|_ nucleo-f401re/ 						              
	|		|_ gpio/ 							          
	|		|_ spi/ 							  
	|		|_ i2c/ 							  
	|		|_ uart/ 						  
	|		|_ adc/ 							  
	|		|_ rtc/ 							  
	|		|_ timer/ 							  
	|		|_ rcc/ 							  
	|		|_ syscfg/ 							  
	|		|_ exti/ 							  
	|		|_ pwr_controller/ 					  
	|		|_ dma/ 							  
	|		|_ projects/						                "bare metal projects, mostly application based not core driver development"    
	|			|_ udemy_mcu2/                                  "projects related to udemy course mastering microcontroller timers, pwm, can, low power(mcu2)"    
                    |_ 1_uart_helloworld                        "send a Hello World\n" string to PC from uart peripheral  
                    |_ 2_uart_convert_uppercase_blocking        "receive string from PC in blocking mode and returns the string in all capital letters"  
                    |_ 3_uart_convert_uppercase_with_interrupt  "receive string from PC in interript mode and returns the upper case converted string"  
	|_ rtos/  
	|_ linux/  
	|_ docs/  
		|_ board_nucleo-f401re/  
		|	|_ sch_mb1136-default-c04.pdf  
		|	|_ um_1724.pdf  
		|	|_ um_1727-getting-started.pdf  
		|_ uc_stm32f401re/  
		|	|_ ds_stm32f401re.pdf  
		|	|_ rm_stm32f401re.pdf  
		|_ proc_arm-cortex-m4/  
			|_ archrm_armv7m.pdf  
			|_ gug_cortex_m4.pdf  
			|_ trm_arm_cortexm4_processor.pdf  
```

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
embedded_firmware/ 								"root directory"  
	|_ bare-metal/ 								"all driver codes and ide codes for bare metal"  
	|	|_ nucleo-f401re/ 						"all driver and ide codes for nucleo-f401re board"  
	|		|_ gpio/ 							"gpio driver"  
	|		|_ spi/ 							"spi driver, both driver and ide codes"  
	|		|_ i2c/ 							"i2c driver, both driver and ide codes"  
	|		|_ uart/ 							"uart driver, both driver and ide codes"  
	|		|_ adc/ 							"adc driver, both driver and ide codes"  
	|		|_ rtc/ 							"rtc driver, both driver and ide codes"  
	|		|_ timer/ 							"timer driver, both driver and ide codes"  
	|		|_ rcc/ 							"rcc driver, both driver and ide codes"  
	|		|_ syscfg/ 							"syscfg driver, both driver and ide codes"  
	|		|_ exti/ 							"external interrupt controller driver, both driver and ide codes"  
	|		|_ pwr_controller/ 					"power controller, both driver and ide codes"  
	|		|_ dma/ 							"dma driver, both driver and ide codes"  
	|		|_ projects/						"projects/applications created on the drivers like gpio, spi, i2c, device configuration tool etc"  
	|			|_   
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

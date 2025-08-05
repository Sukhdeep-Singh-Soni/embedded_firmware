/*
 * Filename   : stm32f429xx.h
 * Created on : Jul 30, 2025
 * Author     : Sukhdeep Singh
 * Note		  : This file contains the stm32f429xx microcontroller specific
 *  			headers
 */

#ifndef STM32F429XX_H_
#define STM32F429XX_H_

#include <stdint.h>

#define volatile 	__io

#define PERIPHERAL_BASE_ADDR	(0x40000000UL)

#define AHB1_OFFSET				(0x00020000UL)

#define AHB1_BASE_ADDR			(PERIPHERAL_BASE_ADDR + AHB1_OFFSET)

#define GPIOA_OFFSET_FROM_AHB1	(0x00000000UL)
#define GPIOB_OFFSET_FROM_AHB1	(0x00000400UL)
#define GPIOC_OFFSET_FROM_AHB1	(0x00000800UL)
#define GPIOD_OFFSET_FROM_AHB1	(0x00000C00UL)
#define GPIOE_OFFSET_FROM_AHB1	(0x00001000UL)
#define GPIOF_OFFSET_FROM_AHB1	(0x00001400UL)
#define GPIOG_OFFSET_FROM_AHB1	(0x00001800UL)
#define GPIOH_OFFSET_FROM_AHB1	(0x00001C00UL)
#define GPIOI_OFFSET_FROM_AHB1	(0x00002000UL)
#define GPIOJ_OFFSET_FROM_AHB1	(0x00002400UL)
#define GPIOK_OFFSET_FROM_AHB1	(0x00002800UL)

#define RCC_OFFSET_FROM_AHB1	(0x00003800UL)

#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + GPIOA_OFFSET_FROM_AHB1)
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + GPIOB_OFFSET_FROM_AHB1)
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + GPIOC_OFFSET_FROM_AHB1)
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + GPIOD_OFFSET_FROM_AHB1)
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + GPIOE_OFFSET_FROM_AHB1)
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + GPIOF_OFFSET_FROM_AHB1)
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + GPIOG_OFFSET_FROM_AHB1)
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + GPIOH_OFFSET_FROM_AHB1)
#define GPIOI_BASE_ADDR			(AHB1_BASE_ADDR + GPIOI_OFFSET_FROM_AHB1)
#define GPIOJ_BASE_ADDR			(AHB1_BASE_ADDR + GPIOJ_OFFSET_FROM_AHB1)
#define GPIOK_BASE_ADDR			(AHB1_BASE_ADDR + GPIOK_OFFSET_FROM_AHB1)

#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + RCC_OFFSET_FROM_AHB1)



typedef struct {
	uint32_t cr;
	uint32_t pllcfgr;
	uint32_t cfgr;
	uint32_t cir;
	uint32_t ahb1rstr;
	uint32_t ahb2rstr;
	uint32_t ahb3rstr;
	uint32_t reserved1;
	uint32_t apb1rstr;
	uint32_t apb2rstr;
	uint32_t reserved2[2];
	uint32_t ahb1enr;
	uint32_t ahb2enr;
	uint32_t ahb3enr;
	uint32_t reserved3;
	uint32_t apb1enr;
	uint32_t apb2enr;
	uint32_t reserved4[2];
	uint32_t ahb1lpenr;
	uint32_t ahb2lpenr;
	uint32_t ahb3lpenr;
	uint32_t reserved5;
	uint32_t apb1lpenr;
	uint32_t apb2lpenr;
	uint32_t reserved6[2];
	uint32_t bdcr;
	uint32_t csr;
	uint32_t reserved7[2];
	uint32_t sscgr;
	uint32_t plli2scfgr;
}rcc_regdef_t;

typedef struct {
	uint32_t moder;
	uint32_t optype;
	uint32_t ospeed;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
	uint32_t lckr;
	uint32_t afr[0];
}gpio_regdef_t;


#define RCC					((rcc_regdef_t*)RCC_BASE_ADDR)

#define GPIOA				(gpio_regdef_t*)GPIOA_BASE_ADDR
#define GPIOB				(gpio_regdef_t*)GPIOB_BASE_ADDR
#define GPIOC				(gpio_regdef_t*)GPIOC_BASE_ADDR
#define GPIOD				(gpio_regdef_t*)GPIOD_BASE_ADDR
#define GPIOE				(gpio_regdef_t*)GPIOE_BASE_ADDR
#define GPIOF				(gpio_regdef_t*)GPIOF_BASE_ADDR
#define GPIOG				(gpio_regdef_t*)GPIOG_BASE_ADDR
#define GPIOH				(gpio_regdef_t*)GPIOH_BASE_ADDR
#define GPIOI				(gpio_regdef_t*)GPIOI_BASE_ADDR
#define GPIOJ				(gpio_regdef_t*)GPIOJ_BASE_ADDR
#define GPIOK				(gpio_regdef_t*)GPIOK_BASE_ADDR


#define RCC_GPIOA_CLK_EN()		(RCC->ahb1enr |= (1 << 0))
#define RCC_GPIOB_CLK_EN()		(RCC->ahb1enr |= (1 << 1))
#define RCC_GPIOC_CLK_EN()		(RCC->ahb1enr |= (1 << 2))
#define RCC_GPIOD_CLK_EN()		(RCC->ahb1enr |= (1 << 3))
#define RCC_GPIOE_CLK_EN()		(RCC->ahb1enr |= (1 << 4))
#define RCC_GPIOF_CLK_EN()		(RCC->ahb1enr |= (1 << 5))
#define RCC_GPIOG_CLK_EN()		(RCC->ahb1enr |= (1 << 6))
#define RCC_GPIOH_CLK_EN()		(RCC->ahb1enr |= (1 << 7))
#define RCC_GPIOI_CLK_EN()		(RCC->ahb1enr |= (1 << 8))



#endif /* STM32F429XX_H_ */

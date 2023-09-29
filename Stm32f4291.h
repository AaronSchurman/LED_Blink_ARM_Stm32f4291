/*
 * STM32F429i.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */

#ifndef STM32F4291_H_
#define STM32F4291_H_

#include <stdint.h>

#define AHB1_BASE_ADDR 0x40020000
#define RCC_BASE_ADDR (AHB1_BASE_ADDR + 0x3800)
#define GPIOG_BASE_ADDR (AHB1_BASE_ADDR + 0x1800)



// Ports for GPIO LED PINS
// LED_STLINK
// RED -> PA 9 (Its on pin 30)
// GREEN -> PA 9


typedef struct {

volatile uint32_t MODER;
volatile uint32_t OTYPER;
volatile uint32_t OSPEEDR;
volatile uint32_t PUPDR;
volatile uint32_t IDR;
volatile uint32_t ODR;
volatile uint32_t BSRR;
volatile uint32_t LCKR;
volatile uint32_t AFR[2];

}GPIO_RegDef_t;




typedef struct {

volatile uint32_t CR;
volatile uint32_t PLLCFGR;
volatile uint32_t CFGR;
volatile uint32_t CIR;
volatile uint32_t AHB1RSTR;
volatile uint32_t AHB2RSTR;
volatile uint32_t AHB3RSTR;
volatile uint32_t Reserve1;
volatile uint32_t APB1RSTR;
volatile uint32_t APB2RSTR;
volatile uint32_t Reserved_Arr[2];
volatile uint32_t AHB1ENR;
volatile uint32_t AHB2ENR;
volatile uint32_t AHB3ENR;
volatile uint32_t Reserved4;
volatile uint32_t APB1ENR;
volatile uint32_t APB2ENR;
volatile uint32_t Reserved_Arr2[2];
volatile uint32_t AHB1LPENR;
volatile uint32_t AHB2LPENR;
volatile uint32_t AHB3LPENR;
volatile uint32_t Reserevd7;
volatile uint32_t APB1LPENR;
volatile uint32_t APB2LPENR;
volatile uint32_t Reserved_Arr3[2];
volatile uint32_t BDCR;
volatile uint32_t CSR;
volatile uint32_t Reserved_Arr4[2];
volatile uint32_t SSCGR;
volatile uint32_t PLLI2SCFGR;



}RCC_RegDef_t;



#define RCC ((RCC_RegDef_t*)RCC_BASE_ADDR)
#define GPIOG ((GPIO_RegDef_t*) GPIOG_BASE_ADDR)

#define GPIOG_ENABLE() (RCC -> AHB1ENR |= (1 << 6)) // this is clock controll
#define GPIOG_DISABLE() (RCC -> AHB1ENR &= ~(1 << 6))

#define ACTIVE 1
#define NON_ACTIVE 0
#define SET 1
#define RESET 0
#define ENABLE SET
#define DISABLE RESET




#endif /* STM32F4291_H_ */

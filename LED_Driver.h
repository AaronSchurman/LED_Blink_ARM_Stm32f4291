/*
 * LED_Driver.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "Stm32f4291.h"
#include "GPIO_Driver.h"

#define LED_DRIVER_GREEN_LED 0 //13
#define LED_DRIVER_RED_LED 1 //14

#define LED_DRIVER_GREEN_LED_PIN GPIO_PIN13 //13
#define LED_DRIVER_RED_LED_PIN  GPIO_PIN14 //14



void Init(uint8_t LED);

void Clock(uint8_t Enabler);

void Enable(uint8_t LED);

void Disable(uint8_t LED);

void Toggle(uint8_t LED);



#endif /* LED_DRIVER_H_ */

/*
 * GPIO_Driver.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "Stm32f4291.h"



typedef struct {
	uint8_t PinNumber; // Pin Number
	uint8_t PinMode; // Pin Mode
	uint8_t OPType; // Output Type
	uint8_t PinSpeed; // Pin Speed
	uint8_t PinPuPdControl; // Pin Push up/ Pull Down Control
	uint8_t PinAltFunMode; // Alternate Function mode
	}GPIO_PinConfig_t;

typedef struct {
		GPIO_RegDef_t *pGPIOx; // GPIO port
		GPIO_PinConfig_t GPIO_PinConfig; // The pin configuraitons


}GPIO_Handle_t;


#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15


#define GPIO_INPUT_MODE 0
#define GPIO_OUTPUT_MODE 1
#define GPIO_ALT_FUNCTION 2
#define GPIO_ANALOG_MODE 3

#define GPIO_OPT_PUSH_PULL 0
#define GPIO_OPT_OPEN_DRAIN 1

#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MED 1
#define GPIO_SPEED_HIGH 2
#define GPIO_SPEED_VERY_HIGH 3

#define GPIO_NOPUSH_UPDOWN 0
#define GPIO_PULL_UP 1
#define GPIO_PULL_DOWN 2
#define GPIO_PUSHPULL_Reserved 3

void GPIO_Init(GPIO_Handle_t *GPIOx);

void GPIO_Clock_Config(GPIO_RegDef_t *Reg, uint8_t Enabler);

void GPIO_Toggle(GPIO_RegDef_t *Reg, uint8_t Pin);

void GPIO_Write(GPIO_RegDef_t *Reg, uint8_t Pin, uint8_t Value);


#endif /* GPIO_DRIVER_H_ */

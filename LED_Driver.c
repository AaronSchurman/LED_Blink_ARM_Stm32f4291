/*
 * LED_Driver.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */


	#include "LED_Driver.h"

	static GPIO_Handle_t redLED;
	static GPIO_Handle_t greenLED;




void Init(uint8_t LED){

		switch(LED){

	case 0x0: //green LED

		greenLED.pGPIOx = GPIOG;
		//configering the pin number that the green LED is on. This is found in schematic on page 6
		greenLED.GPIO_PinConfig.PinNumber = LED_DRIVER_GREEN_LED_PIN;
		//this sets the output mode of the LED to out
		greenLED.GPIO_PinConfig.PinMode = GPIO_OUTPUT_MODE;
		//this sets the speed of the output
		greenLED.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;
		//this sets the output type of the pin to push pull
		greenLED.GPIO_PinConfig.OPType = GPIO_OPT_PUSH_PULL;
		// this ensures there is no push up of pull down controll
		greenLED.GPIO_PinConfig.PinPuPdControl = GPIO_NOPUSH_UPDOWN;

		GPIO_Init(&greenLED); // passes the struct by reference to the inti function

		break;


	case 0x1: // red LED

		redLED.pGPIOx = GPIOG;

		redLED.GPIO_PinConfig.PinNumber = LED_DRIVER_RED_LED_PIN;

		redLED.GPIO_PinConfig.PinMode = GPIO_OUTPUT_MODE;

		redLED.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;

		redLED.GPIO_PinConfig.OPType = GPIO_OPT_PUSH_PULL;

		redLED.GPIO_PinConfig.PinPuPdControl = GPIO_NOPUSH_UPDOWN;

		GPIO_Init(&redLED);

		break;
	}
}

void Toggle(uint8_t LED){

	switch(LED){

	case 0x0:
		//this toggles the apropriote LED with the apropriot pin
		GPIO_Toggle(greenLED.pGPIOx, greenLED.GPIO_PinConfig.PinNumber);


		break;


	case 0x1:


		GPIO_Toggle(redLED.pGPIOx, redLED.GPIO_PinConfig.PinNumber);

		break;

	}
}

void Enable(uint8_t LED){

	switch(LED){

		case 0x0:

			GPIO_Write(greenLED.pGPIOx, greenLED.GPIO_PinConfig.PinNumber, ENABLE);

			break;


		case 0x1:


			GPIO_Write(redLED.pGPIOx, redLED.GPIO_PinConfig.PinNumber, ENABLE);

			break;

		}
}

void Disable(uint8_t LED){

	switch(LED){

		case 0x0:

			GPIO_Write(greenLED.pGPIOx, greenLED.GPIO_PinConfig.PinNumber, DISABLE);

			break;


		case 0x1:


			GPIO_Write(redLED.pGPIOx, redLED.GPIO_PinConfig.PinNumber, DISABLE);

			break;

		}
}













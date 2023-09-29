/*
 * GPIO_Driver.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */


#include "GPIO_Driver.h"

//In the function responsible for clock control:
//i.
//You must check if you are enabling or disabling a clock
//ii.
//Then you must determine which GPIO clock you are operating on based on the input argument of type ‘GPIO_RegDef_t’
//1.
//Hint, the GPIO_RegDef_t will be the same type of one of the Macros you created in “Stm32f429i.h” file
//iii.
//Then do the appropriate operation (enabling or disabling the clock)

void GPIO_Clock_Config(GPIO_RegDef_t *Reg, uint8_t Enabler){

	if(Enabler == 1){ // enable clock
		if(Reg == GPIOG){ // this checks if I am effecting port G

		GPIOG_ENABLE();
		}
	}
	else{
		if(Reg == GPIOG){ // this checks if I am effecting port G
				GPIOG_DISABLE(); // disable clock
		}
	}
}

//In the function responsible for writing a value to a pin:
//i.
//You must first determine which value (1 or 0) is getting written to the pin
//ii.
//Then you must set or clear a bit in the Output Data Register of the provided port
//1.
//This means you will need to use the shift operator to properly set/clear the proper bit
//2.
//Refer to the Reference Manual if needed

void GPIO_Write(GPIO_RegDef_t *Reg, uint8_t Pin, uint8_t Value){


	if(Value == 1){
		Reg->ODR |= (0x1 << Pin); // this sets the bit in the pin pposituin
	}
	else{
		Reg->ODR &= ~(0x1 << Pin); // this sets the pin to 0
	}
	return;
}

void GPIO_Toggle(GPIO_RegDef_t *Reg, uint8_t Pin){

	if(Reg->ODR & (0x1 << Pin)){ // will be true if there is a 1 in the position
		Reg->ODR &= ~(0x1 << Pin); // since there is a 1 i toggle it to zero
		return;
	}
	Reg->ODR |= (0x1 << Pin);// the if isnt true so there is a zero so we or in a 1
	return;
}


/*
 * In the function responsible for initializing the GPIO:
i.
Remember, the handle struct will refer to this function's input argument, which is of type GPIO_Handle_t
ii.
Create a local variable of type uint32_t that will be used as a ‘temporary” (temp) variable
iii.
Configure the port mode (MODER) register with the appropriate mode from the handle struct
iv.
Configure the output speed register
v.
Configure the pull-up/pull-down register
vi.
Configure the output type register
Configure the alternate function register only if the pin mode is configured to use the alternate function


 */

void GPIO_Init(GPIO_Handle_t *GPIOx){

	GPIO_Clock_Config(GPIOx->pGPIOx , ENABLE);

	uint32_t temp;

	//Configure the port mode (MODER) register with the appropriate mode from the handle struct
	temp = (GPIOx ->GPIO_PinConfig.PinMode << (2 * GPIOx ->GPIO_PinConfig.PinNumber));

	//Clear the bits in the port mode register that ONLY correspond to the appropriate pin number
	GPIOx->pGPIOx->MODER &= ~(0x3 << (2 * GPIOx->GPIO_PinConfig.PinNumber));

	//Set the appropriate bits in the port mode register using the temp value
	GPIOx->pGPIOx->MODER |= temp;


	//Configure the output speed register

	temp = (GPIOx ->GPIO_PinConfig.PinSpeed << (2 * GPIOx ->GPIO_PinConfig.PinNumber));

	//Clear the bits in the port mode register that ONLY correspond to the appropriate pin number
	GPIOx->pGPIOx->OSPEEDR &= ~(0x3 << (2 * GPIOx->GPIO_PinConfig.PinNumber));

	//Set the appropriate bits in the port mode register using the temp value
	GPIOx->pGPIOx->OSPEEDR |= temp;


	//Configure the pull-up/pull-down register
	temp = (GPIOx ->GPIO_PinConfig.PinPuPdControl << (2 * GPIOx ->GPIO_PinConfig.PinNumber));

	//Clear the bits in the PUPDR register that ONLY correspond to the appropriate pin number
	GPIOx->pGPIOx->PUPDR &= ~(0x3 << (2 * GPIOx->GPIO_PinConfig.PinNumber));

	//Set the appropriate bits in the port mode register using the temp value
	GPIOx->pGPIOx->PUPDR |= temp;

	//Configure the output type register
	temp = (GPIOx ->GPIO_PinConfig.OPType << (GPIOx ->GPIO_PinConfig.PinNumber));

	//Clear the one bit
	GPIOx->pGPIOx->OTYPER &= ~(0x1 << (GPIOx->GPIO_PinConfig.PinNumber));

	//Set the appropriate bits in the port mode register using the temp value
	GPIOx->pGPIOx->OTYPER |= temp;



//	Configure the alternate function register only if the pin mode is configured to use the alternate function
	if(GPIOx->GPIO_PinConfig.PinAltFunMode == GPIO_ALT_FUNCTION ){ //Use an if statement to check this condition

		//So doing that division will either result in a 1 or 0, which then will dictate which register (high or low, AFR[1] or AFR[0]) we will access
		uint32_t select = (GPIOx->GPIO_PinConfig.PinNumber)/8;
//		Create a variable of type uint32_t that will be responsible for accessing the correct bit fields
		uint32_t acess = (GPIOx->GPIO_PinConfig.PinNumber)%8;

		temp = 4 * acess;

		temp = GPIOx->GPIO_PinConfig.PinAltFunMode << temp;

		//clear the bits
		GPIOx->pGPIOx->AFR[select] &= ~ (0xf << (acess*4));

		//now we or in the correct value into the correct register
		GPIOx->pGPIOx->AFR[select] |= temp;

	}



}






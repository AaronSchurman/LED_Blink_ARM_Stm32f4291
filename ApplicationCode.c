/*
 * ApplicationCode.c
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */


#include "ApplicationCode.h"


void Init_Green(){
	Init(LED_DRIVER_GREEN_LED);
}

void Init_Red(){
	Init(LED_DRIVER_RED_LED);
}

void Init_Green_Red(){
	Init(LED_DRIVER_GREEN_LED);
	Init(LED_DRIVER_RED_LED);
}

void Toggel_Red(){
	Toggle(LED_DRIVER_RED_LED);
}

void Toggel_Green(){
	Toggle(LED_DRIVER_GREEN_LED);
}

void Activate_Green(){
	Enable(LED_DRIVER_GREEN_LED);
}

void Activate_Red(){
	Enable(LED_DRIVER_RED_LED);
}

void Kill_Red(){
	Disable(LED_DRIVER_RED_LED);
}

void Kill_Green(){
	Disable(LED_DRIVER_GREEN_LED);
}

void Delay(uint32_t Time_Delay){
	char MyName[LENGTH_NAME] = {"Aaron"};

	char Destinatoin[LENGTH_NAME];

	for(int i =0 ; i < (Time_Delay); i++){
		for(int j = 0; j < LENGTH_NAME ; j++){
			Destinatoin[j] = MyName[j];
		}
	}
}

void Application_Init(){
	Init_Green();
	addSchedulerEvent(SCHEDULER_TOGGE_ZERO);
	addSchedulerEvent(SCHEDULER_DELAY);

}








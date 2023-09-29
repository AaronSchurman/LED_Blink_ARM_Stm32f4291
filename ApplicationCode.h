/*
 * ApplicationCode.h
 *
 *  Created on: Sep 5, 2023
 *      Author: aaron
 */

#ifndef APPLICATIONCODE_H_
#define APPLICATIONCODE_H_

#include "Scheduler.h"
#include "LED_Driver.h"


#define LENGTH_NAME 5
#define MAGNIFY_DELAY 250000


void Application_Init();

void Init_Green();

void Init_Red();

void Init_Green_Red();

void Toggel_Red();

void Toggel_Green();

void Activate_Green();

void Activate_Red();

void Kill_Red();

void Kill_Green();

void Delay(uint32_t Time_Delay);


#endif /* APPLICATIONCODE_H_ */

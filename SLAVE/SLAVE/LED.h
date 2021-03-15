/*
 * LED.h
 *
 * Created: 04-Mar-21 2:24:10 PM
 *  Author: dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_CONFIG.h"

void LED_Init();
void LED_ON(Uint8 ledPin);
void LED_OFF(Uint8 ledPin);
void LED_TGL(Uint8 ledPin);






#endif /* LED_H_ */
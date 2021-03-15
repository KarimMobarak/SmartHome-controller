/*
 * LED.c
 *
 * Created: 04-Mar-21 2:23:59 PM
 *  Author: dell
 */ 


#include "LED.h"

void LED_Init(){
	pin_config(LED_PORT,LED0_PIN,DIO_OUTPUT);
	pin_config(LED_PORT,LED1_PIN,DIO_OUTPUT);

}
void LED_ON(Uint8 ledPin){
	pin_value(LED_PORT,ledPin,HIGH);
}
void LED_OFF(Uint8 ledPin){
	pin_value(LED_PORT,ledPin,LOW);
}
void LED_TGL(Uint8 ledPin){
	pin_toggle(LED_PORT,ledPin);
}

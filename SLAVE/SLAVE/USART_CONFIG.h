/*
 * SERIAL_CONFIG.h
 *
 * Created: 17-Feb-21 6:53:35 PM
 *  Author: dell
 */ 


#ifndef SERIAL_CONFIG_H_
#define SERIAL_CONFIG_H_

#include "CPU_CONFIG.h"
#define FRQ 16000000UL

#define UDR   *( (volatile Uint8*) 0x2C)
#define UCSRA *( (volatile Uint8*) 0x2B)
#define UCSRB *( (volatile Uint8*) 0x2A)
#define UBRRL *( (volatile Uint8*) 0x29)






#endif /* SERIAL_CONFIG_H_ */
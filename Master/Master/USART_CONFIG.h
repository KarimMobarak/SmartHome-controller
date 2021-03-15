/*
 * USART_CONFIG.h
 *
 * Created: 17-Feb-21 6:53:35 PM
 *  Author: dell
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#include "STD_TYPES.h"
#include "BitMath.h"
#include <avr/io.h>
#include <avr/interrupt.h>



#define UDR   *( (volatile Uint8*) 0x2C)
#define UCSRA *( (volatile Uint8*) 0x2B)
#define UCSRB *( (volatile Uint8*) 0x2A)
#define UBRRL *( (volatile Uint8*) 0x29)






#endif /* SERIAL_CONFIG_H_ */
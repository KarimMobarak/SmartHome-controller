/*
 * DIO_CONFIG.h
 *
 * Created: 17-Feb-21 10:41:19 AM
 *  Author: Karim
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "CPU_CONFIG.h"

#define PORTA  *((volatile Uint8*) 0x3B)
#define DDRA   *((volatile Uint8*) 0x3A)
#define PINA   *((volatile Uint8*) 0x39)
#define PORTB  *((volatile Uint8*) 0x38)
#define DDRB   *((volatile Uint8*) 0x37)
#define PINB   *((volatile Uint8*) 0x36)
#define PORTC  *((volatile Uint8*) 0x35)
#define DDRC   *((volatile Uint8*) 0x34)
#define PINC   *((volatile Uint8*) 0x33)
#define PORTD  *((volatile Uint8*) 0x32)
#define DDRD   *((volatile Uint8*) 0x31)
#define PIND   *((volatile Uint8*) 0x30)

/* pin directions */
#define DIO_INPUT 1
#define DIO_OUTPUT 0

/*Ports*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/*Pins*/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7











#endif /* DIO_CONFIG_H_ */
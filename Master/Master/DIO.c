/*
 * DIO.c
 *
 * Created: 17-Feb-21 10:40:41 AM
 *  Author: Karim
 */ 

#include "DIO.h"


void pin_config (Uint8 port, Uint8 pin, Uint8 direction){
	switch (direction)
	{
		case DIO_INPUT:
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD,pin);
			break;
		}
		break;
		case DIO_OUTPUT:
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD,pin);
			break;
		}
		break;
	}
}


void pin_value(Uint8 port, Uint8 pin, state value){
	switch (value)
	{
		case LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}

Uint8 pin_read(Uint8 port, Uint8 pin){
	Uint8 reading = 0;
	switch (port)
	{
		case DIO_PORTA:
		reading = GET_BIT(PINA,pin);
		break;
		case DIO_PORTB:
		reading = GET_BIT(PINB,pin);
		break;
		case DIO_PORTC:
		reading = GET_BIT(PINC,pin);
		break;
		case DIO_PORTD:
		reading = GET_BIT(PIND,pin);
		break;
	}
	return reading;
}
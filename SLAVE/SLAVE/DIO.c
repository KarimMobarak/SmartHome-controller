/*
 * DIO.c
 *
 * Created: 17-Feb-21 10:40:41 AM
 *  Author: Karim
 */ 

#include "DIO.h"

/********************************************************************************
 * [Function Name]: pin_direction
 *
 * [Description]:  Set the pin direction
 *
 * [Args]:         port, pin, direction
 *
 * [In]             - port: The Port of the pin
 *
 *					- pin: The pin to be directed
 *
 *					- direction: the direction whether input or output
 *
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *******************************************************************************/
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

/********************************************************************************
 * [Function Name]: pin_value
 *
 * [Description]:  Set the output pin value, after setting the pin direction to output
 *				   using the pin_direction function
 *
 * [Args]:         port, pin, value
 *
 * [In]             - port: The Port of the pin
 *
 *					- pin: The desired pin
 *
 *					- value: HIGH or LOW
 *
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *******************************************************************************/

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

void pin_toggle(Uint8 port, Uint8 pin){
	
	switch(port){
		case DIO_PORTA:
			TGL_BIT(PORTA,pin);
			break;
		case DIO_PORTB:
			TGL_BIT(PORTB,pin);
			break;
		case DIO_PORTC:
			TGL_BIT(PORTC,pin);
			break;
		case DIO_PORTD:
			TGL_BIT(PORTD,pin);
			break;
	}
}
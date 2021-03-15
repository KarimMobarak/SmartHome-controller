/*
 * USART.c
 *
 * Created: 17-Feb-21 6:53:57 PM
 *  Author: dell
 */ 

#include "USART.h"


static Uint16 UBRR_value(Uint16 baudRate, OperatingMode operatingMode);

#define fosc 16000000UL
#define BAUD_RATE 9600
#define UBRR_VALUE  (fosc/(16UL*BAUD_RATE))-1

void USART_Init( USART_config* usart_config )
{
	Uint16 UBRR = UBRR_VALUE;
	
	/* Set baud rate */
	UBRRH = (unsigned char)(UBRR>>8);
	UBRRL = (unsigned char) UBRR;
	/* Enable receiver and transmitter */
	
	switch (usart_config -> operatingMode)
	{
		case asynchronousDoubleSpeedMode :
			SET_BIT(UCSRA,U2X);
		case asynchronousNormalMode:
			CLR_BIT(UCSRC,UMSEL);
			break;
		case synchronousMode:
			SET_BIT(UCSRC,UMSEL);
			break;
	}
	
	switch (usart_config -> interrupt1Status)
	{
		case receivedInterrupt:
			SET_BIT(UCSRB,RXCIE);
			sei();
			break;
		case transmitttedInterrupt:
			SET_BIT(UCSRB,TXCIE);
			sei();
			break;
		case dataRegisterReadyInterrupt:
			SET_BIT(UCSRB,UDRIE);
			sei();
			break;
	}
	
	switch (usart_config -> interrupt2Status)
	{
		case receivedInterrupt:
		SET_BIT(UCSRB,RXCIE);
		sei();
		break;
		case transmitttedInterrupt:
		SET_BIT(UCSRB,TXCIE);
		sei();
		break;
		case dataRegisterReadyInterrupt:
		SET_BIT(UCSRB,UDRIE);
		sei();
		break;
	}
	
	switch (usart_config -> interrupt3Status)
	{
		case receivedInterrupt:
		SET_BIT(UCSRB,RXCIE);
		sei();
		break;
		case transmitttedInterrupt:
		SET_BIT(UCSRB,TXCIE);
		sei();
		break;
		case dataRegisterReadyInterrupt:
		SET_BIT(UCSRB,UDRIE);
		sei();
		break;
	}
	
	switch (usart_config->dataBitNum)
	{
		case fiveBits:
			break;
		case sixBits:
			UCSRC |= (1<<URSEL) | (1<<UCSZ0);
			break;
		case sevenBits:
			UCSRC |= (1<<URSEL) | (1<<UCSZ1);
			break;
		case eightBits:
			UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
			break;
		case nineBits:
			UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
			SET_BIT(UCSRB,UCSZ2);
			break;
	}
	
	if(usart_config -> stopBitNum == twoBits){
		UCSRC |= (1<<URSEL) | (1<<USBS);
	}
	
	switch(usart_config -> parityMode){
		case disabledParity:
			break;
		case evenParityEnabled:
			UCSRC |= (1<<URSEL) | (1<<UPM1);
			break;
		case oddParityEnabled:
			UCSRC |= (1<<URSEL) | (1<<UPM1) | (1<<UPM0);
			break;
	}
	
	switch (usart_config -> polarity)
	{
		case transmitRising:
			break;
		case transmitFalling:
			UCSRC |= (1<<URSEL) | (1<<UCPOL);
			break;
	}
	
		UCSRB = (1<<RXEN)|(1<<TXEN);

	
}

void USART_send_char(Uint8 data){
	while(!(UCSRA & (1<<UDRE)));
	UDR=data;
	while(!(UCSRA & (1<<TXC)));
}

void USART_Tx_msg(string msg){
	while(*msg != '\0'){
		USART_send_char(*msg);
		msg++;
	}
	USART_send_char('\0');
}

Uint8 USART_receive_char(void){
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}

void USART_Rx_msg(char* msg){
	char string_received[20];
	ptr current_char = string_received;
	*current_char = USART_receive_char();
	
	while (*current_char != '\0')
	{
		current_char++;
		*current_char = USART_receive_char();
		
	}
	msg = string_received;
}

Uint16 UBRR_value(Uint16 baudRate, OperatingMode operatingMode){
	switch(operatingMode){
		case asynchronousNormalMode:
			return ((F_CPU/(16*baudRate))-1);
		case asynchronousDoubleSpeedMode:
			return ((F_CPU/(8*baudRate))-1);
		case synchronousMode:
			return ((F_CPU/(2*baudRate))-1);
	}
}
/*
 * USART.c
 *
 * Created: 17-Feb-21 6:53:57 PM
 *  Author: dell
 */ 

#include "USART.h"


static Uint16 UBRR_value(Uint16 baudRate,OperatingMode operatingMode);

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
	
		UCSRB = (1<<RXEN)|(1<<TXEN);

	
	switch (usart_config -> interrupt1Status)
	{
		case receivedInterrupt:
		SET_BIT(UCSRB,RXCIE);
		sei();
		break;
		case transmitttedInterrupt:
		sei();
		SET_BIT(UCSRB,TXCIE);
		break;
		case dataRegisterReadyInterrupt:
		sei();
		SET_BIT(UCSRB,UDRIE);
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
		sei();
		SET_BIT(UCSRB,RXCIE);
		break;
		case transmitttedInterrupt:
		sei();
		SET_BIT(UCSRB,TXCIE);
		break;
		case dataRegisterReadyInterrupt:
		sei();
		SET_BIT(UCSRB,UDRIE);
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
	

	
}



void USART_send_char(Uint8 data){
	while(!(UCSRA & (1<<UDRE)));
	UDR=data; 
	while(!(UCSRA & (1<<TXC)));
}

void USART_Tx_msg(ptr msg){
	
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

void USART_Rx_msg(ptr Msg){
	//char i = 0;
	Msg = buffer;
	*Msg = USART_receive_char();
	while(*Msg != '#'){
		Msg++;
		*Msg = USART_receive_char();
	}
	*Msg = '\0';
	Msg=buffer;
	USART_send_char(*Msg);
	
}

inline Uint16 UBRR_value(Uint16 baudRate, OperatingMode operatingMode){
	switch(operatingMode){
		case asynchronousNormalMode:
		return ((fosc/(16*baudRate)) -1);
		case asynchronousDoubleSpeedMode:
		return ((fosc/( 8*baudRate)) -1);
		case synchronousMode:
		return ((fosc/( 2*baudRate)) -1);
		default:
		return 0;
	}
}
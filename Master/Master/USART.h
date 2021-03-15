/*
 * USART.h
 *
 * Created: 17-Feb-21 6:53:14 PM
 *  Author: dell
 */ 


#ifndef USART_H_
#define USART_H_

#include "USART_CONFIG.h"

#define fosc 16000000UL

/*buffer variable to store the incoming bytes*/
unsigned char buffer[20];


typedef enum {
	disabledInterrupt,
	receivedInterrupt,
	transmitttedInterrupt,
	dataRegisterReadyInterrupt
	}InterruptStatus;

typedef enum{
	asynchronousNormalMode,
	asynchronousDoubleSpeedMode,
	synchronousMode
	}OperatingMode;

typedef enum{
	disabledParity,
	evenParityEnabled = 0b10,
	oddParityEnabled,
	}ParityMode;

typedef enum{
	oneBit,
	twoBits
	}StopBitNumber;

typedef enum{
	fiveBits,
	sixBits,
	sevenBits,
	eightBits,
	nineBits
	}DataBits;
	
typedef enum{
	transmitRising,
	transmitFalling
}ClockPolarity;


typedef struct  
{
	OperatingMode   operatingMode;
	
	/*As there are 3 possible interrupts,
	they can be configured by the 3 variables
	 interruptXStatus*/
	InterruptStatus interrupt1Status; 
	InterruptStatus interrupt2Status;
	InterruptStatus interrupt3Status;
	
	StopBitNumber   stopBitNum;
	DataBits	    dataBitNum;
	ClockPolarity   polarity;
	ParityMode      parityMode;
	Uint16          baudRate;
	
}USART_config;

void USART_Init( USART_config* usart_config );
void USART_send_char(Uint8 data);
Uint8 USART_receive_char(void);
void USART_Tx_msg(string msg);
void USART_Rx_msg(string msg);

#endif /* USART_H_ */
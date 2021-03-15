/*
 * SPI_CONFIG.h
 *
 * Created: 27-Feb-21 9:49:07 AM
 *  Author: karim
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "CPU_CONFIG.h"

#define SPCR *((volatile Uint8*)0x2D)
#define SPSR *((volatile Uint8*)0X2E)
#define SPDR *((volatile Uint8*)0x2F)

#define SPI_PORT DIO_PORTB

#define MISO_PIN DIO_PIN6
#define MOSI_PIN DIO_PIN5
#define SCK_PIN  DIO_PIN7
#define SS_PIN   DIO_PIN4

typedef enum{
	slave,
	master
	} SPI_mode;
	
typedef enum{
	disable,
	enable
	}SPI_interrupt_status;

typedef enum{
	 over_4,
	 over_16,
	 over_64,
	 over_128,
	 over_2,
	 over_8,
	 over_32,
	 over_64_2 //repeated over 64
	}SPI_Clock;


#endif /* SPI_CONFIG_H_ */
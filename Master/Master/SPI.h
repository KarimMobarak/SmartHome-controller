/*
 * SPI.h
 *
 * Created: 27-Feb-21 9:10:13 AM
 *  Author: dell
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_CONFIG.h"



void SPI_init(SPI_mode mode, SPI_interrupt_status int_status);
Uint8 SPI_receive_byte(void);
void SPI_send_byte(Uint8 msg);

void SPI_receive_String(string received);
void SPI_Send_String(string msg);




#endif /* SPI_H_ */
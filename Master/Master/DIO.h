/*
 * DIO.h
 *
 * Created: 17-Feb-21 10:40:54 AM
 *  Author: Karim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_CONFIG.h"

void pin_config (Uint8 port, Uint8 pin, Uint8 direction);
void pin_value(Uint8 port, Uint8 pin, state value);
Uint8 pin_read(Uint8 port, Uint8 pin);


#endif /* DIO_H_ */
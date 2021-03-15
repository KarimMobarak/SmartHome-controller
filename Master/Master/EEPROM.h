/*
 * EEPROM.h
 *
 * Created: 08-Mar-21 4:17:51 PM
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "EEPROM_CONFIG.h"



typedef unsigned int Address;


Uint8 readEEPROM(Address address);
void writeEEPROM(Uint8 data, Address address);
void clearEEPROM(Address address);



#endif /* EEPROM_H_ */
/*
 * EEPROM.c
 *
 * Created: 08-Mar-21 4:18:02 PM
 *  Author: dell
 */ 

#include "EEPROM.h"

Uint8 readEEPROM(Address address){
	
	/*check whether there is already
	 writing operation in progress*/
	while(GET_BIT(EECR,EEWE));
	
	EEAR = address;
	
	//Read enable
	SET_BIT(EECR,EERE);
	
	return EEDR;
	
}

void writeEEPROM(Uint8 data, Address address){
	
	/*check whether there is already
	 writing operation in progress*/
	while(GET_BIT(EECR,EEWE));
	
	EEDR = data;
	EEAR = address;
	
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR, EEWE);
}

void clearEEPROM(Address address){
	while(GET_BIT(EECR,EEWE));
	EEDR = 0X00;
	EEAR = address;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR, EEWE);
}
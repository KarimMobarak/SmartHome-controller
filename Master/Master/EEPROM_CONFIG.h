/*
 * EEPROM_CONFIG.h
 *
 * Created: 08-Mar-21 4:30:20 PM
 *  Author: dell
 */ 


#ifndef EEPROM_CONFIG_H_
#define EEPROM_CONFIG_H_


#include "CPU_CONFIG.h"

#define EEARL *((volatile Uint8*)0x3E)
#define EEARH *((volatile Uint8*)0x3F)
#define EEAR  *((volatile Uint16*)0x3F)
#define EEDR  *((volatile Uint8*)0x3D)
#define EECR  *((volatile Uint8*)0x3C)






#endif /* EEPROM_CONFIG_H_ */
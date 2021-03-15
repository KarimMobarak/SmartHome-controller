/*
 * STD_TYPES.h
 *
 * Created: 17-Feb-21 11:01:00 AM
 *  Author: dell
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef enum{
	false,
	true
	} boolean ;
	
typedef enum{
	LOW,
	HIGH
}state;
	
typedef unsigned char Uint8;
typedef unsigned int  Uint16;
typedef unsigned long Uint32;
typedef unsigned char Sint8;
typedef unsigned int  Sint16;
typedef unsigned long Sint32;
typedef unsigned char* string; 
typedef unsigned char* ptr;





#endif /* STD_TYPES_H_ */
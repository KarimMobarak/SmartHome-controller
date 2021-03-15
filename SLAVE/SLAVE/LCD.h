/*
 * LCD.h
 *
 * Created: 1/22/2021 7:00:44 PM
 *  Author: karim
 */ 


#ifndef LCD_H_
#define LCD_H_

/*
What should i write here!
1- Macros
2- User defined data types (Structure - Union - Enumeration)
3- Global variables (if Exist)
4- Functions prototypes
*/

#include "LCD_CONFIG.h"

void LCD_Init(void);/*Initialize LCD*/
void LCD_WRITE_CMD(Uint8 cmd);/*Write command inside control register*/
void LCD_WRITE_DTA(Uint8 dta);/*write data inside data register*/
void LCD_WRITE_STR(Uint8* str);/*write string on screen*/
void LCD_WRITE_NBR(Uint32 numbr);
void LCD_CLEAR(void);/*Clear data display on screen*/

#endif /* LCD_H_ */
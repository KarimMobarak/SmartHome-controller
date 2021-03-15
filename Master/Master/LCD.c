/*
* LCD.c
*
* Created: 1/22/2021 7:00:54 PM
*  Author: karim
*/

/*
1- Macros
2- Implementation of functions
*/


#include "LCD.h"

void LCD_Init(void)/*Initialize LCD*/
{
	/*Define direction for command pins*/
	pin_config(LCD_CMD_PORT, LCD_RS, DIO_OUTPUT);
	pin_config(LCD_CMD_PORT, LCD_RW, DIO_OUTPUT);
	pin_config(LCD_CMD_PORT, LCD_EN, DIO_OUTPUT);
	/*Define direction for data pins*/	
	pin_config(LCD_DTA_PORT, LCD_D4, DIO_OUTPUT);
	pin_config(LCD_DTA_PORT, LCD_D5, DIO_OUTPUT);
	pin_config(LCD_DTA_PORT, LCD_D6, DIO_OUTPUT);
	pin_config(LCD_DTA_PORT, LCD_D7, DIO_OUTPUT);
	/*LCD controller is slower than MC speed*/
	_delay_ms(100);
	LCD_WRITE_CMD(0x02);
	LCD_WRITE_CMD(0x33);
	LCD_WRITE_CMD(0x32);
	LCD_WRITE_CMD(0x28);
	LCD_WRITE_CMD(0x0C);
	LCD_WRITE_CMD(0x01);
	LCD_WRITE_CMD(0x06);
}
void LCD_WRITE_CMD(Uint8 cmd)/*Write command inside control register*/
{
	/*RS is logic(0) to write inside control register*/
	pin_value(LCD_CMD_PORT, LCD_RS, LOW);
	/*RW is logic(0) to write on LCD*/
	pin_value(LCD_CMD_PORT, LCD_RW, LOW);
	/*To be sure of enable state before start operation*/
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*Send high nibble of command*/
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F);
	pin_value(LCD_CMD_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*send low nibble of command*/
	PORTA = (cmd << 4) | (PORTA & 0x0F);
	pin_value(LCD_CMD_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*Delay for 2 millisecond*/
	_delay_ms(2);
}
void LCD_WRITE_DTA(Uint8 dta)/*write data inside data register*/
{
	/*RS is logic(0) to write inside data register*/
	pin_value(LCD_CMD_PORT, LCD_RS, HIGH);
	/*RW is logic(0) to write on LCD*/
	pin_value(LCD_CMD_PORT, LCD_RW, LOW);
	/*To be sure of enable state before start operation*/
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*Send high nibble of command*/
	PORTA = (dta & 0xF0) | (PORTA & 0x0F);
	pin_value(LCD_CMD_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*send low nibble of command*/
	PORTA = (dta << 4) | (PORTA & 0x0F);
	pin_value(LCD_CMD_PORT, LCD_EN, HIGH);
	_delay_ms(1);
	pin_value(LCD_CMD_PORT, LCD_EN, LOW);
	/*Delay for 2 millisecond*/
	_delay_ms(2);
}
void LCD_WRITE_STR(ptr str)/*write string on screen*/
{
	ptr pointer = str;
	while(*pointer != '\0')
	{
		LCD_WRITE_DTA(*pointer);
		pointer++;
	}
}
void LCD_WRITE_NBR(Uint32 numbr)
{
	Uint8 num[10];
	ltoa(numbr, (Uint8*)num, 10);
	LCD_WRITE_STR(num);
}
void LCD_CLEAR(void)/*Clear data display on screen*/
{
	LCD_WRITE_CMD(0x01);
}
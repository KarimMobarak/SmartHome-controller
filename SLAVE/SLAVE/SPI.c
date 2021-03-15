/*
 * SPI.c
 *
 * Created: 27-Feb-21 9:10:36 AM
 *  Author: dell
 */ 

#include "SPI.h"


void inline Master_pin_config();
void inline slave_pin_config();

void SPI_init(SPI_mode mode, SPI_interrupt_status int_status){
	switch (mode)
	{
		case master:
			master_pin_config();
			SET_BIT(SPCR,MSTR); // Select master mode
			pin_value(SPI_PORT,SS_PIN,LOW);
			break;
		case slave:
			slave_pin_config();
			break;
		
	}
	if (int_status == enable)
	{
		sei(); // enable global interrupt
		SET_BIT(SPCR,SPIE); //enable SPI interrupt
}
	SET_BIT(SPCR,SPE);
}

void inline master_pin_config(){
	pin_config(SPI_PORT,MOSI_PIN, DIO_OUTPUT);
	pin_config(SPI_PORT,MISO_PIN,DIO_INPUT);
	pin_config(SPI_PORT,SS_PIN,DIO_OUTPUT);
	pin_config(SPI_PORT,SCK_PIN,DIO_OUTPUT);
}

void inline slave_pin_config(){
	pin_config(SPI_PORT,MOSI_PIN, DIO_INPUT);
	pin_config(SPI_PORT,MISO_PIN,DIO_OUTPUT);
	pin_config(SPI_PORT,SS_PIN,DIO_INPUT);
	pin_config(SPI_PORT,SCK_PIN,DIO_INPUT);
}

void SPI_send_byte(Uint8 msg){
	SPDR = msg;
	while(GET_BIT(SPSR,SPIF) != 1);
		
}

Uint8 SPI_receive_byte(){
	
	while(GET_BIT(SPSR,SPIF) != 1);
	return SPDR;
}

void SPI_Send_String(string msg){
	while(*msg != '\0'){
		SPI_send_byte(*msg);
		msg++;
	}
	SPI_send_byte('\0');
}

void SPI_receive_String(string received){
	
	char buffer[20];
	received = buffer;
	*received = SPI_receive_byte();
	
	while( *received != '\0'){
		received++;
		*received = SPI_receive_byte();
	}
}

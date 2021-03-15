/*
 * SLAVE.c
 *
 * Created: 27-Feb-21 2:43:38 PM
 * Author : dell
 */ 

#include "CPU_CONFIG.h"


volatile Uint8 operation_ID = 0 ;

int main(void)
{
	LED_Init();
	SPI_init(slave,enable); //spi mode is set to slave mode and interrupt is enabled
	
	while (1)
	{
	
	}


	
}

ISR(SPI_STC_vect){
	
	
	operation_ID = SPDR;
		
	switch (operation_ID)
	{
		case 'L':
		LED_ON(LIVING_ROOM_LIGHTING);
		break;
		case 'l':
		LED_OFF(LIVING_ROOM_LIGHTING);
		break;
		case 'K':
		LED_ON(KITCHEN_LIGHTING);
		break;
		case 'k':
		LED_OFF(KITCHEN_LIGHTING);
		break;
	}

}
		

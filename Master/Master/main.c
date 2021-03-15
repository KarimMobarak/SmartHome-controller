
#include "CPU_CONFIG.h"




USART_config usart_config = {asynchronousNormalMode,
							 receivedInterrupt,
							 disabledInterrupt,
							 disabledInterrupt,
							 oneBit,
							 eightBits,
							 transmitRising,
							 disabledParity,
							 9600};


/*receivedByte is a variable to store the recieved
 data from the Bluetooth*/
volatile Uint8 receivedByte; 


int main(void)
{
	
	BLE_Init(&usart_config);
	
	LCD_Init();
	
	SPI_init(master,disable);
	
	/*Inform the user of the control keys*/
	USART_Tx_msg("\t \t WELCOME TO SMART HOME \r\n \r\n \t To control the light send the corresponding character: \r\n #'K' to turn on the kitchen light \r\n #'L' to turn on the living room \r\n #'k' to turn off the kitchen light \r\n #'l' to turn off the living room light \r\n INPUT:");
	
	
	while(1){
		
	}
}

ISR(USART_RXC_vect){
		
		/*Wait for the bluetooth to receive any commands*/
		receivedByte = UDR;
		
		/*Send the command to the slave*/
		SPI_send_byte(receivedByte);

		/*Keep the user updated through updating the LCD &
		 the Serial terminal*/
		switch(receivedByte){
			case 'k':
				LCD_CLEAR();
				LCD_WRITE_STR("Kitchen: OFF");
				USART_Tx_msg("Kitchen: OFF");
				break;
			case 'K':
				LCD_CLEAR();
				LCD_WRITE_STR("Kitchen: ON");
				USART_Tx_msg("Kitchen: ON");
				break;
			case 'l':
				LCD_CLEAR();
				LCD_WRITE_STR("Living room: OFF");
				USART_Tx_msg("Living room: OFF");
				break;
			case 'L':
				LCD_CLEAR();
				LCD_WRITE_STR("Living room: ON");
				USART_Tx_msg("Living room: ON");
				break;
		}

}


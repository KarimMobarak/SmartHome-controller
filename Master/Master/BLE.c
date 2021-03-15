/*
 * BLE.c
 *
 * Created: 21-Feb-21 10:42:58 PM
 *  Author: Karim Amr Mobarak
 */ 


#include "BLE.h"


/*Initialize bluetooth peripheral*/
void BLE_Init(USART_config* usart_config){
	
	USART_Init(usart_config);
}

/*BLE_receiveChar returns the received byte from bluetooth*/
Uint8 BLE_receiveChar(void){
	return USART_receive_char();
}

/*BLE_sendChar sends data variable over bluetooth*/
void BLE_sendChar(Uint8 data){
	USART_send_char(data);
}

/*BLE_sendMsg sends the string msg over bluetooth*/
void BLE_sendMsg(ptr msg){
	USART_Tx_msg(msg);
}

/*BLE_receiveMsg points receiver to the string received*/
void BLE_receiveMsg(ptr receiver){
	USART_Rx_msg(receiver);
}
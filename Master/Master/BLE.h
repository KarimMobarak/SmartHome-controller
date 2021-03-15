/*
 * BLE.h
 *
 * Created: 21-Feb-21 10:42:40 PM
 *  Author: dell
 */ 


#ifndef BLE_H_
#define BLE_H_


#include "BLE_CONFIG.h"



#define TEST_COMMAND AT
#define RESET_COMMAND AT+RESET
#define GET_VERSION_COMMAND AT+VERSION?
#define RESTORE_DEFAULT_COMMAND AT+ORGL
#define GET_ADDRESS AT+ADDR?
#define SET_NAME(NEW_NAME) AT+NAME=<NEW_NAME>
#define GET_NAME AT+NAME?
#define GET_BLE_DEVICE_NAME(THE_NAME) AT+RNAME?<THE_NAME>
#define SET_MODE(MODE) AT+ROLE=<MODE>
#define	GET_MODE AT+ROLE?
#define SET_PIN(PW) AT+PSWD=<PW>
#define GET_PIN AT+PSWD?
#define SET_SERIAL_PARAM(BAUD,STOP_BIT,PARITY) AT+UART=<BAUD>,<STOP_BIT>,<PARITY>
#define GET_SERIAL_PARAM AT+UART?
#define GET_STATE AT+STATE?
#define CONNECT_DEVICE(DEV_ADD) AT+LINK=<DEV_ADD

void BLE_Init(USART_config* usart_config);
Uint8 BLE_receiveChar(void);
void BLE_sendChar(Uint8 data);
void BLE_sendMsg(ptr msg);
void BLE_receiveMsg(ptr receiver);


#endif /* BLE_H_ */
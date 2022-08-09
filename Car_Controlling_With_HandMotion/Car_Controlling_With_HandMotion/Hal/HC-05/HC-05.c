/*
 * HC_05.c
 *
 * Created: 7/26/2022 4:55:41 PM
 *  Author: DELL G3
 */ 

#include "HC-05.h"

void H_HC05_Init(void){
	M_Uart_Init();
}

void H_HC05_Transmit(u8 Local_u8_Data){
	M_Uart_Transmit(Local_u8_Data);
}

u8   H_HC05_Receive(void){
	u8 Local_u8_Reading = M_Uart_Receive();
	return Local_u8_Reading;
}
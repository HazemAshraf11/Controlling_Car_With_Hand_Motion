/*
 * Uart.c
 *
 * Created: 7/16/2022 3:00:14 AM
 *  Author: DELL G3
 */ 

#include "Uart.h"

void (* Uart_void_CallBack)(void)=NULL_;

void M_Uart_Init(void){
	u8 Local_u8_UCSRC = 0b10000000;
	ClearBit(DDRD,0);  // to enable input  circuit for Rx pin
	SetBit(DDRD,1);    // to enable output circuit for Tx pin
	
	SetBit(SREG,7);
	
	//SetBit(Local_u8_UCSRC,7);  // ( UCSRC ) and ( UBRRH ) have the same address and this bit selects which register to work with
	
	// to select character size = 8 bit
	SetBit(Local_u8_UCSRC,1);
	SetBit(Local_u8_UCSRC,2);
	ClearBit(UCSRB,2);
	
	// to select asynchronous mode
	ClearBit(Local_u8_UCSRC,6);
	
	#if   PARITY_MODE == PARITY_DISABLE
	ClearBit(Local_u8_UCSRC,4);
	ClearBit(Local_u8_UCSRC,5);
	#elif PARITY_MODE == PARITY_ODD
	SetBit(Local_u8_UCSRC,4);
	SetBit(Local_u8_UCSRC,5);
	#elif PARITY_MODE == PARITY_EVEN
	ClearBit(Local_u8_UCSRC,4);
	SetBit(Local_u8_UCSRC,5);
	#endif
	
	ClearBit(Local_u8_UCSRC,3);   // to select stop bits = 1 bit
	
	UBRRL =( ((u32) F_OSC*1000000 ) / ((u32) 16 * BAUDRATE) ) - 1;    // to select baudrate
	UCSRC = Local_u8_UCSRC;
	SetBit(UCSRB,4);   // enable Rx
	SetBit(UCSRB,3);   // enable Tx
}

void M_Uart_Transmit(u8 Local_u8_Data){
	UDR = Local_u8_Data;
	while( ReadBit(UCSRA,6)==0 );
}

u8 M_Uart_Receive(void){
	while( ReadBit(UCSRA,7)==0 );
	return UDR;
}

void M_Uart_SetCallBack(void (*Local_void_ptr)(void))
{
	Uart_void_CallBack = Local_void_ptr;
}

ISR(USART_RXC_vect) {

	Uart_void_CallBack();
}
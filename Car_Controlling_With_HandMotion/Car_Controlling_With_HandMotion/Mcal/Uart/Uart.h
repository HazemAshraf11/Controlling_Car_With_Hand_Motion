/*
 * Uart.h
 *
 * Created: 7/16/2022 3:00:26 AM
 *  Author: DELL G3
 */ 


#ifndef UART_H_
#define UART_H_

#include "UartCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
#include <avr/interrupt.h>

#define PARITY_DISABLE   1
#define PARITY_ODD       2
#define PARITY_EVEN      3

#define NULL_            '\0'

void M_Uart_Init(void);
void M_Uart_Transmit(u8);
u8 M_Uart_Receive(void);
void M_Uart_SetCallBack(void (*)(void));



#endif /* UART_H_ */
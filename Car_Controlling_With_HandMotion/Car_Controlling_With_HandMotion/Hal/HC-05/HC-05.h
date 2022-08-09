/*
 * HC_05.h
 *
 * Created: 7/26/2022 4:54:57 PM
 *  Author: DELL G3
 */ 


#ifndef HC-05_H_
#define HC-05_H_

#include "Uart.h"

void H_HC05_Init(void);
void H_HC05_Transmit(u8);
u8   H_HC05_Receive(void);

#endif /* HC-05_H_ */
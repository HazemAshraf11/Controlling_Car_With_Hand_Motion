/*
 * Hbridge.h
 *
 * Created: 7/16/2022 2:52:37 AM
 *  Author: DELL G3
 */ 


#ifndef HBRIDGE_H_
#define HBRIDGE_H_

#include "Dio.h"
#include "HbridgeCfg.h"
#include "Timer0.h"
#include "Timer2.h"

void H_Hbridge_Init(void);
void H_Hbridge_MoveForward(void);
void H_Hbridge_Turn(u8,u8);
void H_Hbridge_TurnLeft(void);
void H_Hbridge_TurnRight(void);
void H_Hbridge_Stop(void);
void H_Hbridge_MoveBackward(void);



#endif /* HBRIDGE_H_ */
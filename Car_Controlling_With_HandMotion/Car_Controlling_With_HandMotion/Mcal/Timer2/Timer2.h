/*
 * Timer2.h
 *
 * Created: 7/16/2022 3:00:56 AM
 *  Author: DELL G3
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "Timer2Cfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
#include <avr/interrupt.h>

#define NULL_           '\0'

#define NORMAL_MODE        1
#define CTC_MODE           2

#define NON_INVERTED       1
#define INVERTED           2

#define FAST_PWM           1
#define PHASE_CORRECT_PWM  2

void M_Timer2_Init();
void M_Timer2_SetTime(u32);
void M_Timer2_Start();
void M_Timer2_Stop();
void M_Timer2_SetCallBack(void(*)(void));
void M_Timer2_Pwm_Init();
void M_Timer2_SetDutyCycle(u8);
void M_Timer2_Pwm_Start();
void M_Timer2_Pwm_Stop();



#endif /* TIMER2_H_ */
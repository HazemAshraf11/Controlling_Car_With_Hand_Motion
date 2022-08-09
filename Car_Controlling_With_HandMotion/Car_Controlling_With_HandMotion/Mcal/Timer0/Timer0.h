/*
 * Timer0.h
 *
 * Created: 7/16/2022 3:02:31 AM
 *  Author: DELL G3
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Timer0Cfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
#include <avr/interrupt.h>

#define NULL_           '\0'

#define NORMAL_MODE        1
#define CTC_MODE           2

#define NON_INVERTED      1
#define INVERTED          2

#define FAST_PWM           1
#define PHASE_CORRECT_PWM  2

void M_Timer0_Init();
void M_Timer0_SetTime(u32);
void M_Timer0_Start();
void M_Timer0_Stop();
void M_Timer0_SetCallBack(void(*)(void));
void M_Timer0_Pwm_Init();
void M_Timer0_SetDutyCycle(u8);
void M_Timer0_Pwm_Start();
void M_Timer0_Pwm_Stop();



#endif /* TIMER0_H_ */
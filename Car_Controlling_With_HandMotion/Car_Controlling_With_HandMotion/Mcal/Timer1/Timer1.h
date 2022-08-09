/*
 * Timer1.h
 *
 * Created: 7/16/2022 3:01:54 AM
 *  Author: DELL G3
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "Timer1Cfg.h"
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

void M_Timer1_Init();
void M_Timer1_SetTime(u32);
void M_Timer1_Start();
void M_Timer1_Stop();
void M_Timer1_SetCallBack(void(*)(void));
void M_Timer1A_Pwm_Init();
void M_Timer1B_Pwm_Init();
void M_Timer1_Pwm_SetFrequancy(u32);
void M_Timer1A_SetDutyCycle(u8);
void M_Timer1B_SetDutyCycle(u8);
void M_Timer1_Pwm_Start();
void M_Timer1_Pwm_Stop();



#endif /* TIMER1_H_ */
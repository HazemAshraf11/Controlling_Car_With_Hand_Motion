/*
 * Timer2.c
 *
 * Created: 7/16/2022 3:01:25 AM
 *  Author: DELL G3
 */ 

#include "Timer2.h"

void (*Timer2_void_CallBack)(void)=NULL_;

u32 Timer2_u32_NumOfOverFlows     = 0;
u8  Timer2_u8_RemTicks            = 0;
u32 Timer2_u32_NumOfCompareMatch  = 0;

void M_Timer2_Init(){
	#if TIMER2_MODE     ==     NORMAL_MODE
	ClearBit(TCCR2,6);
	ClearBit(TCCR2,3);
	SetBit(TIMSK,6);
	#elif TIMER2_MODE     ==     CTC_MODE
	ClearBit(TCCR2,6);
	SetBit(TCCR2,3);
	SetBit(TIMSK,7);
	#endif
	
	SetBit(SREG,7);
}

void M_Timer2_SetTime(u32 Local_u32_DesiredTime){
	#if TIMER2_MODE     ==     NORMAL_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER2_PRESCALER / F_OSC);
	Timer2_u32_NumOfOverFlows = Local_u32_NumOfTicks / 256 ;
	Timer2_u8_RemTicks        = Local_u32_NumOfTicks % 256 ;
	if ( Timer2_u8_RemTicks ) {
		Timer2_u32_NumOfOverFlows++;
		TCNT2 = 256 - Timer2_u8_RemTicks;
	}
	
	#elif TIMER2_MODE     ==     CTC_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER2_PRESCALER / F_OSC);
	u8 Local_u8_DevisionFactor = 255;
	while ( Local_u32_NumOfTicks % Local_u8_DevisionFactor ) Local_u8_DevisionFactor--;
	Timer2_u32_NumOfCompareMatch = Local_u32_NumOfTicks / Local_u8_DevisionFactor;
	OCR2 = Local_u8_DevisionFactor - 1 ;
	
	#endif
}

void M_Timer2_Start(){
	#if   TIMER2_PRESCALER   ==   1
	SetBit(TCCR2,0);
	ClearBit(TCCR2,1);
	ClearBit(TCCR2,2);
	#elif   TIMER2_PRESCALER   ==   1024
	SetBit(TCCR2,0);
	SetBit(TCCR2,1);
	SetBit(TCCR2,2);
	#elif TIMER2_PRESCALER   ==   256
	ClearBit(TCCR2,0);
	SetBit(TCCR2,1);
	SetBit(TCCR2,2);
	#endif
}

void M_Timer2_Stop(){
	ClearBit(TCCR2,0);
	ClearBit(TCCR2,1);
	ClearBit(TCCR2,2);
}

void M_Timer2_Pwm_Init(){
	SetBit(DDRD,7);
	
	#if     PWM_MODE == FAST_PWM
	SetBit(TCCR2,6);
	SetBit(TCCR2,3);
	#if FAST_PWM_MODE == NON_INVERTED
	SetBit(TCCR2,5);
	ClearBit(TCCR2,4);
	#elif FAST_PWM_MODE == INVERTED
	SetBit(TCCR2,5);
	SetBit(TCCR2,4);
	#endif
	#elif   PWM_MODE == PHASE_CORRECT_PWM
	SetBit(TCCR2,6);
	ClearBit(TCCR2,3);
	#if PHASE_CORRECT_PWM_MODE == NON_INVERTED
	SetBit(TCCR2,5);
	ClearBit(TCCR2,4);
	#elif PHASE_CORRECT_PWM_MODE == INVERTED
	SetBit(TCCR2,5);
	SetBit(TCCR2,4);
	#endif
	#endif
	
}

void M_Timer2_SetDutyCycle(u8 Local_u8_DutyCycle){
	#if    PWM_MODE == FAST_PWM
	#if FAST_PWM_MODE == NON_INVERTED
	OCR2 = ( ( Local_u8_DutyCycle * 256 ) / 100 ) - 1 ;
	#elif FAST_PWM_MODE == INVERTED
	OCR2 = 255 - ( ( Local_u8_DutyCycle * 256 ) / 100 ) ;
	#endif
	#elif PWM_MODE == PHASE_CORRECT_PWM
	#if   PHASE_CORRECT_PWM_MODE == NON_INVERTED
	OCR2 = ( Local_u8_DutyCycle * 255 ) / 100 ;
	#elif PHASE_CORRECT_PWM_MODE == INVERTED
	OCR2 = 255 - ( ( Local_u8_DutyCycle * 255 ) / 100 ) ;
	#endif
	#endif
}

void M_Timer2_Pwm_Start(){
	M_Timer2_Start();
}
void M_Timer2_Pwm_Stop(){
	M_Timer2_Stop();
}

void M_Timer2_SetCallBack(void (*Local_void_ptr)(void))
{
	Timer2_void_CallBack = Local_void_ptr;
}

#if   TIMER2_MODE   ==   NORMAL_MODE
ISR(TIMER2_OVF_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer2_u32_NumOfOverFlows)
	{
		Timer2_void_CallBack();
		Local_u32_Counter = 0;
		TCNT2             =   256 - Timer2_u8_RemTicks;
	}
}
#elif TIMER2_MODE   ==   CTC_MODE
ISR(TIMER2_COMP_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer2_u32_NumOfCompareMatch)
	{
		Timer2_void_CallBack();
		Local_u32_Counter = 0;
	}
}
#endif

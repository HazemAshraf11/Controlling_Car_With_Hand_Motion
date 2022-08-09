/*
 * Timer0.c
 *
 * Created: 7/16/2022 3:02:59 AM
 *  Author: DELL G3
 */ 

#include "Timer0.h"

void (*Timer0_void_CallBack)(void)=NULL_;

u32 Timer0_u32_NumOfOverFlows     = 0;
u8  Timer0_u8_RemTicks            = 0;
u32 Timer0_u32_NumOfCompareMatch  = 0;

void M_Timer0_Init(){
	#if TIMER0_MODE     ==     NORMAL_MODE
	ClearBit(TCCR0,6);
	ClearBit(TCCR0,3);
	SetBit(TIMSK,0);
	#elif TIMER0_MODE     ==     CTC_MODE
	ClearBit(TCCR0,6);
	SetBit(TCCR0,3);
	SetBit(TIMSK,1);
	#endif
	
	SetBit(SREG,7);
}

void M_Timer0_SetTime(u32 Local_u32_DesiredTime){
	#if TIMER0_MODE     ==     NORMAL_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER0_PRESCALER / F_OSC);
	Timer0_u32_NumOfOverFlows = Local_u32_NumOfTicks / 256 ;
	Timer0_u8_RemTicks        = Local_u32_NumOfTicks % 256 ;
	if ( Timer0_u8_RemTicks ) {
		Timer0_u32_NumOfOverFlows++;
		TCNT0 = 256 - Timer0_u8_RemTicks;
	}
	
	#elif TIMER0_MODE     ==     CTC_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER0_PRESCALER / F_OSC);
	u8 Local_u8_DevisionFactor = 255;
	while ( Local_u32_NumOfTicks % Local_u8_DevisionFactor ) Local_u8_DevisionFactor--;
	Timer0_u32_NumOfCompareMatch = Local_u32_NumOfTicks / Local_u8_DevisionFactor;
	OCR0 = Local_u8_DevisionFactor - 1 ;
	
	#endif
}

void M_Timer0_Start(){
	#if   TIMER0_PRESCALER   ==   1
	SetBit(TCCR0,0);
	ClearBit(TCCR0,1);
	ClearBit(TCCR0,2);
	#elif   TIMER0_PRESCALER   ==   1024
	SetBit(TCCR0,0);
	ClearBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif TIMER0_PRESCALER   ==   256
	ClearBit(TCCR0,0);
	ClearBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}

void M_Timer0_Stop(){
	ClearBit(TCCR0,0);
	ClearBit(TCCR0,1);
	ClearBit(TCCR0,2);
}

void M_Timer0_Pwm_Init(){
	SetBit(DDRB,3);
	
	#if     PWM_MODE == FAST_PWM
	SetBit(TCCR0,6);
	SetBit(TCCR0,3);
	#if FAST_PWM_MODE == NON_INVERTED
	SetBit(TCCR0,5);
	ClearBit(TCCR0,4);
	#elif FAST_PWM_MODE == INVERTED
	SetBit(TCCR0,5);
	SetBit(TCCR0,4);
	#endif
	#elif   PWM_MODE == PHASE_CORRECT_PWM
	SetBit(TCCR0,6);
	ClearBit(TCCR0,3);
	#if PHASE_CORRECT_PWM_MODE == NON_INVERTED
	SetBit(TCCR0,5);
	ClearBit(TCCR0,4);
	#elif PHASE_CORRECT_PWM_MODE == INVERTED
	SetBit(TCCR0,5);
	SetBit(TCCR0,4);
	#endif
	#endif
	
}

void M_Timer0_SetDutyCycle(u8 Local_u8_DutyCycle){
	#if    PWM_MODE == FAST_PWM
	#if FAST_PWM_MODE == NON_INVERTED
	OCR0 = ( ( Local_u8_DutyCycle * 256 ) / 100 ) - 1 ;
	#elif FAST_PWM_MODE == INVERTED
	OCR0 = 255 - ( ( Local_u8_DutyCycle * 256 ) / 100 ) ;
	#endif
	#elif PWM_MODE == PHASE_CORRECT_PWM
	#if   PHASE_CORRECT_PWM_MODE == NON_INVERTED
	OCR0 = ( Local_u8_DutyCycle * 255 ) / 100 ;
	#elif PHASE_CORRECT_PWM_MODE == INVERTED
	OCR0 = 255 - ( ( Local_u8_DutyCycle * 255 ) / 100 ) ;
	#endif
	#endif
}

void M_Timer0_Pwm_Start(){
	M_Timer0_Start();
}
void M_Timer0_Pwm_Stop(){
	M_Timer0_Stop();
}

void M_Timer0_SetCallBack(void (*Local_void_ptr)(void))
{
	Timer0_void_CallBack = Local_void_ptr;
}

#if   TIMER0_MODE   ==   NORMAL_MODE
ISR(TIMER0_OVF_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_u32_NumOfOverFlows)
	{
		Timer0_void_CallBack();
		Local_u32_Counter = 0;
		TCNT0             =   256 - Timer0_u8_RemTicks;
	}
}
#elif TIMER0_MODE   ==   CTC_MODE
ISR(TIMER0_COMP_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_u32_NumOfCompareMatch)
	{
		Timer0_void_CallBack();
		Local_u32_Counter = 0;
	}
}
#endif
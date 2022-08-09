/*
 * Timer1.c
 *
 * Created: 7/16/2022 3:01:42 AM
 *  Author: DELL G3
 */ 

#include "Timer1.h"

void (*Timer1_void_CallBack)(void)=NULL_;

u32 Timer1_u32_NumOfOverFlows     = 0;
u32  Timer1_u32_RemTicks          = 0;
u32 Timer1_u32_NumOfCompareMatch  = 0;

void M_Timer1_Init(){
	#if TIMER1_MODE     ==     NORMAL_MODE
	ClearBit(TCCR1A,0);
	ClearBit(TCCR1A,1);
	ClearBit(TCCR1B,3);
	ClearBit(TCCR1B,4);
	SetBit(TIMSK,2);
	#elif TIMER1_MODE     ==     CTC_MODE
	ClearBit(TCCR1A,0);
	ClearBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	ClearBit(TCCR1B,4);
	SetBit(TIMSK,4);
	#endif
	
	SetBit(SREG,7);
}

void M_Timer1_SetTime(u32 Local_u32_DesiredTime){
	#if TIMER1_MODE     ==     NORMAL_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER1_PRESCALER / F_OSC);
	Timer1_u32_NumOfOverFlows = Local_u32_NumOfTicks / 65536 ;
	Timer1_u32_RemTicks        = Local_u32_NumOfTicks % 65536 ;
	if ( Timer1_u32_RemTicks ) {
		Timer1_u32_NumOfOverFlows++;
		TCNT1 = 65536 - Timer1_u32_RemTicks;
	}
	
	#elif TIMER1_MODE     ==     CTC_MODE
	u32 Local_u32_NumOfTicks = (Local_u32_DesiredTime*1000) / ( TIMER1_PRESCALER / F_OSC);
	u32 Local_u32_DevisionFactor = 65535;
	while ( Local_u32_NumOfTicks % Local_u32_DevisionFactor ) Local_u32_DevisionFactor--;
	Timer1_u32_NumOfCompareMatch = Local_u32_NumOfTicks / Local_u32_DevisionFactor;
	OCR1A = Local_u32_DevisionFactor - 1 ;
	#endif
}

void M_Timer1_Start(){
	#if   TIMER1_PRESCALER   ==   1024
	SetBit(TCCR1B,0);
	ClearBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	#elif TIMER1_PRESCALER   ==   256
	ClearBit(TCCR1B,0);
	ClearBit(TCCR1B,1);
	SetBit(TCCR1B,2);
	#endif
}

void M_Timer1_Stop(){
	ClearBit(TCCR1B,0);
	ClearBit(TCCR1B,1);
	ClearBit(TCCR1B,2);
}

void M_Timer1A_Pwm_Init(){
	SetBit(DDRD,5);
	
	ClearBit(TCCR1A,0);
	SetBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	SetBit(TCCR1B,4);
	
	// non-inverted mode and generate pwm on OC1A
	ClearBit(TCCR1A,6);
	SetBit(TCCR1A,7);
}

void M_Timer1B_Pwm_Init(){
	SetBit(DDRD,4);
	
	// Fast PWM --------  TOP -> ICR1
	ClearBit(TCCR1A,0);
	SetBit(TCCR1A,1);
	SetBit(TCCR1B,3);
	SetBit(TCCR1B,4);
	
	// non-inverted mode and generate pwm on OC1B
	ClearBit(TCCR1A,4);
	SetBit(TCCR1A,5);
}

void M_Timer1_Pwm_SetFrequancy(u32 Local_u32_Frequancy){
	ICR1 = ( ( F_OSC * 1000000 ) / TIMER1_PRESCALER  ) / Local_u32_Frequancy ;   // Fpwm = Ftimer / ICR1 = (F_OSC*1000000 / Prescaler) / ICR1
}

void M_Timer1A_SetDutyCycle(u8 Local_u8_DutyCycle){
	OCR1A = ( ( Local_u8_DutyCycle * ICR1 ) / 100 ) - 1 ;
}

void M_Timer1B_SetDutyCycle(u8 Local_u8_DutyCycle){
	OCR1B = ( ( Local_u8_DutyCycle * ICR1 ) / 100 ) - 1 ;
}

void M_Timer1_Pwm_Start(){
	M_Timer1_Start();
}
void M_Timer1_Pwm_Stop(){
	M_Timer1_Stop();
}

void M_Timer1_SetCallBack(void (*Local_void_ptr)(void))
{
	Timer1_void_CallBack = Local_void_ptr;
}

#if   TIMER1_MODE   ==   NORMAL_MODE
ISR(TIMER1_OVF_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer1_u32_NumOfOverFlows)
	{
		Timer1_void_CallBack();
		Local_u32_Counter = 0;
		TCNT1             =   256 - Timer1_u32_RemTicks;
	}
}
#elif TIMER1_MODE   ==   CTC_MODE
ISR(TIMER1_COMPA_vect){
	static u32 Local_u32_Counter = 0 ;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer1_u32_NumOfCompareMatch)
	{
		Timer1_void_CallBack();
		Local_u32_Counter = 0;
	}
}
#endif
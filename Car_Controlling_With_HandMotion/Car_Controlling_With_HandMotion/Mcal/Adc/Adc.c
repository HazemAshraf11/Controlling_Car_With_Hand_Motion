/*
 * Adc.c
 *
 * Created: 7/16/2022 3:27:24 AM
 *  Author: DELL G3
 */ 

#include "Adc.h"

u16 Adc_u16_Reading=0;

void (*AdcInt_void_CallBack)(void)=NULL_;

void M_Adc_Init(void)
{
	#if   VREF   ==   AVCC
	SetBit(ADMUX,6);
	ClearBit(ADMUX,7);
	#elif VREF   ==   AREF_PIN
	ClearBit(ADMUX,6);
	ClearBit(ADMUX,7);
	#elif VREF   ==   _2V56
	SetBit(ADMUX,6);
	SetBit(ADMUX,7);
	#endif
	ClearBit(ADMUX,5);     // to select right adjust
	
	// to select 128 as devision factor -> ADC circuit -> 125 Khz
	ClearBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	
	SetBit(ADCSRA,5);   // to enable auto trigger
	#if    ADC_OPERATION_MODE   ==   ADC_INT
	SetBit(ADCSRA,3);   // to enable local int
	SetBit(SREG,7);     // to enable global int
	SetBit(ADCSRA,6);   // to start conversion
	#endif
	SetBit(ADCSRA,7);   // to enable ADC circuit
}

void M_Adc_SelectChannel(u8 Local_u8_AdcPin){
	// to select ADC channel
	if (Local_u8_AdcPin == Pa1){
		ClearBit(ADMUX,4);
		ClearBit(ADMUX,3);
		ClearBit(ADMUX,2);
		ClearBit(ADMUX,1);
		SetBit(ADMUX,0);
	}
	else if (Local_u8_AdcPin == Pa2){
		ClearBit(ADMUX,4);
		ClearBit(ADMUX,3);
		ClearBit(ADMUX,2);
		SetBit(ADMUX,1);
		ClearBit(ADMUX,0);
	}
}

#if   ADC_OPERATION_MODE   ==   ADC_POL
u16  M_Adc_Read(void)
{
	SetBit(ADCSRA,6);   // to start conversion (this bit is cleared after every conversion so we set it back to 1 to read again)
	while ((ReadBit(ADCSRA,4)) == 0);
	return ADC_VALUE;
}
#elif   ADC_OPERATION_MODE   ==   ADC_INT

void M_AdcInt_SetCallBack(void(*Local_void_ptr)(void)){
	AdcInt_void_CallBack=Local_void_ptr;
}

ISR(ADC_vect)
{
	Adc_u16_Reading = ADC_VALUE;
	if(Adc_u16_Reading >= 500){
		AdcInt_void_CallBack();
	}
}
#endif
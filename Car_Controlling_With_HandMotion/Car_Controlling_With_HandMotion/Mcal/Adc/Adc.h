/*
 * Adc.h
 *
 * Created: 7/16/2022 3:26:58 AM
 *  Author: DELL G3
 */ 


#ifndef ADC_H_
#define ADC_H_

/*************************************************_INCLUDES_********************************************/
#include "AdcCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define AVCC         1
#define AREF_PIN     2
#define _2V56        3
#define ADC_INT      1
#define ADC_POL      2
#define Pa1 11
#define Pa2 12
#define NULL_      '\0'
/************************************************_PROTOTYPES_********************************************/
void M_Adc_Init(void);
void M_Adc_SelectChannel(u8);
u16  M_Adc_Read(void);
void M_AdcInt_SetCallBack(void(*)(void));



#endif /* ADC_H_ */
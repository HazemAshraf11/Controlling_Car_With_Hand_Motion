/*
 * FlexSensor.c
 *
 * Created: 7/26/2022 12:23:47 PM
 *  Author: DELL G3
 */ 

#include "FlexSensor.h"

void H_FlexSensor_Init(void){
	M_Dio_PinMode(FLEX_SENSOR_PIN_1,INPUT);
	M_Dio_PinMode(FLEX_SENSOR_PIN_2,INPUT);
	M_Adc_Init();
	M_Uart_Init();
}

void H_FlexSensor_Transmit(u8 Local_u8_AdcPin){
	if (Local_u8_AdcPin == FLEX_SENSOR_PIN_1)        M_Adc_SelectChannel(Pa1);
	else if (Local_u8_AdcPin == FLEX_SENSOR_PIN_2)   M_Adc_SelectChannel(Pa2);
	
	u16 Local_u8_Reading = M_Adc_Read();
	u8  Local_u8_Value   = Local_u8_Reading * ( (f32) 255 / 360);  // convert the returned 10 bit reading to 8 bits (maximum reading = 360)
	/* when the sensor is bended in the reverse direction the value = 250 , when it's normal the value = 140:180 , when it's bended the value = 60:140 .
	   to differentiate between the two values' ranges we add 60 to the first to range from 120 to 240 and subtract 60 from the second to range from 0 to 120
	*/
	if (Local_u8_AdcPin == FLEX_SENSOR_PIN_1)        M_Uart_Transmit(Local_u8_Value + 60);
	else if (Local_u8_AdcPin == FLEX_SENSOR_PIN_2)   M_Uart_Transmit(Local_u8_Value - 60);
}
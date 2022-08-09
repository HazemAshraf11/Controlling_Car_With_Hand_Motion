/*
 * FlexSensor.h
 *
 * Created: 7/26/2022 12:23:06 PM
 *  Author: DELL G3
 */ 


#ifndef FLEXSENSOR_H_
#define FLEXSENSOR_H_

#include "FlexSensorCfg.h"
#include "Dio.h"
#include "Adc.h"
#include "Uart.h"

void H_FlexSensor_Init(void);
void H_FlexSensor_Transmit(u8);


#endif /* FLEXSENSOR_H_ */
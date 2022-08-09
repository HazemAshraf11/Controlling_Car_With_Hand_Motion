/*
 * Hbridge.c
 *
 * Created: 7/16/2022 2:52:51 AM
 *  Author: DELL G3
 */ 

#include "Hbridge.h"

void H_Hbridge_Init(void){
	M_Dio_PinMode(HBRIDGE_INPUT_1,OUTPUT);
	M_Dio_PinMode(HBRIDGE_INPUT_2,OUTPUT);
	M_Dio_PinMode(HBRIDGE_INPUT_3,OUTPUT);
	M_Dio_PinMode(HBRIDGE_INPUT_4,OUTPUT);
	M_Timer0_Pwm_Init();
	M_Timer2_Pwm_Init();
	M_Timer0_Start();
	M_Timer2_Start();
	}

void H_Hbridge_MoveForward(void){
	M_Timer0_SetDutyCycle(75);
	M_Timer2_SetDutyCycle(75);
	M_Dio_PinWrite(HBRIDGE_INPUT_1,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,LOW);
}

void H_Hbridge_Turn(u8 Local_u8_PWM1, u8 Local_u8_PWM2){  // To move left ->   PWM2 (Right wheel) > PWM1 (Left wheel)     To move Right ->   PWM2 (Right wheel) < PWM1 (Left wheel)
	M_Timer0_SetDutyCycle(Local_u8_PWM1);
	M_Timer2_SetDutyCycle(Local_u8_PWM2);
	
	M_Dio_PinWrite(HBRIDGE_INPUT_1,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,LOW);
}

void H_Hbridge_TurnLeft(){
	M_Timer0_SetDutyCycle(70);
	M_Timer2_SetDutyCycle(70);
	M_Dio_PinWrite(HBRIDGE_INPUT_1,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,HIGH);
}

void H_Hbridge_TurnRight(){
	M_Timer0_SetDutyCycle(70);
	M_Timer2_SetDutyCycle(70);
	M_Dio_PinWrite(HBRIDGE_INPUT_1,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,LOW);
}


void H_Hbridge_Stop(void){
	M_Dio_PinWrite(HBRIDGE_INPUT_1,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,HIGH);
}

void H_Hbridge_MoveBackward(void){
	M_Timer0_SetDutyCycle(75);
	M_Timer2_SetDutyCycle(75);
	M_Dio_PinWrite(HBRIDGE_INPUT_1,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_2,HIGH);
	M_Dio_PinWrite(HBRIDGE_INPUT_3,LOW);
	M_Dio_PinWrite(HBRIDGE_INPUT_4,HIGH);
}
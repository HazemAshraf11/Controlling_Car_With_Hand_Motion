/*
 * Dio.c
 *
 * Created: 7/16/2022 2:59:58 AM
 *  Author: DELL G3
 */ 

#include "Dio.h"

void M_Dio_PinMode(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	u8 Local_u8_Pin=Local_u8_Num%10;
	u8 Local_u8_Port=Local_u8_Num/10;
	if (Local_u8_Mode){
		switch (Local_u8_Port) {
			case 1 :DDRA=SetBit(DDRA,Local_u8_Pin);break;
			case 2 :DDRB=SetBit(DDRB,Local_u8_Pin);break;
			case 3 :DDRC=SetBit(DDRC,Local_u8_Pin);break;
			case 4 :DDRD=SetBit(DDRD,Local_u8_Pin);break;
			default:break;
		}
	}
	else{
		switch (Local_u8_Port) {
			case 1 :DDRA=ClearBit(DDRA,Local_u8_Pin);break;
			case 2 :DDRB=ClearBit(DDRB,Local_u8_Pin);break;
			case 3 :DDRC=ClearBit(DDRC,Local_u8_Pin);break;
			case 4 :DDRD=ClearBit(DDRD,Local_u8_Pin);break;
			default:break;
		}
	}
	
}

void M_Dio_PinWrite(u8 Local_u8_Num,u8 Local_u8_Mode){
	u8 Local_u8_Pin=Local_u8_Num%10;
	u8 Local_u8_Port=Local_u8_Num/10;
	if (Local_u8_Mode){
		switch (Local_u8_Port) {
			case 1 :PORTA=SetBit(PORTA,Local_u8_Pin);break;
			case 2 :PORTB=SetBit(PORTB,Local_u8_Pin);break;
			case 3 :PORTC=SetBit(PORTC,Local_u8_Pin);break;
			case 4 :PORTD=SetBit(PORTD,Local_u8_Pin);break;
			default:break;
		}
	}
	else{
		switch (Local_u8_Port) {
			case 1 :PORTA=ClearBit(PORTA,Local_u8_Pin);break;
			case 2 :PORTB=ClearBit(PORTB,Local_u8_Pin);break;
			case 3 :PORTC=ClearBit(PORTC,Local_u8_Pin);break;
			case 4 :PORTD=ClearBit(PORTD,Local_u8_Pin);break;
			default:break;
		}
	}
}

void M_Dio_PinTog(u8 Local_u8_Num){
	u8 Local_u8_Pin=Local_u8_Num%10;
	u8 Local_u8_Port=Local_u8_Num/10;
	switch (Local_u8_Port) {
		case 1 :PORTA=ToggleBit(PORTA,Local_u8_Pin);break;
		case 2 :PORTB=ToggleBit(PORTB,Local_u8_Pin);break;
		case 3 :PORTC=ToggleBit(PORTC,Local_u8_Pin);break;
		case 4 :PORTD=ToggleBit(PORTD,Local_u8_Pin);break;
		default:break;
	}
}

u8 M_Dio_PinRead(u8 Local_u8_Num)
{
	u8 Local_u8_Pin=Local_u8_Num%10;
	u8 Local_u8_Port=Local_u8_Num/10;
	u8 status=0;
	switch (Local_u8_Port) {
		case 1 :status=ReadBit(PINA,Local_u8_Pin);break;
		case 2 :status=ReadBit(PINB,Local_u8_Pin);break;
		case 3 :status=ReadBit(PINC,Local_u8_Pin);break;
		case 4 :status=ReadBit(PIND,Local_u8_Pin);break;
		default:break;
	}
	return status;
}

void M_Dio_PortMode(u8 Local_u8_Port,u8 Local_u8_Mode){
	if (Local_u8_Mode) {
		switch (Local_u8_Port) {
			case 1 : DDRA=0xff;break;
			case 2 : DDRB=0xff;break;
			case 3 : DDRC=0xff;break;
			case 4 : DDRD=0xff;break;
			default:break;
		}
	}
	else {
		switch (Local_u8_Port) {
			case 1 :DDRA=0x00;break;
			case 2 :DDRB=0x00;break;
			case 3 :DDRC=0x00;break;
			case 4 :DDRD=0x00;break;
			default:break;
		}
	}
}

void M_Dio_PortWrite(u8 Local_u8_Port,u8 Local_u8_Value){
	switch (Local_u8_Port) {
		case 1 : PORTA=Local_u8_Value;break;
		case 2 : PORTB=Local_u8_Value;break;
		case 3 : PORTC=Local_u8_Value;break;
		case 4 : PORTD=Local_u8_Value;break;
		default:break;
	}
}

void M_Dio_PinPullUpResistor(u8 Local_u8_Num,u8 Local_u8_Mode){
	u8 Local_u8_Pin=Local_u8_Num%10;
	u8 Local_u8_Port=Local_u8_Num/10;
	if (Local_u8_Mode){
		switch (Local_u8_Port) {
			case 1 : SetBit(PORTA,Local_u8_Pin);break;
			case 2 : SetBit(PORTB,Local_u8_Pin);break;
			case 3 : SetBit(PORTC,Local_u8_Pin);break;
			case 4 : SetBit(PORTD,Local_u8_Pin);break;
			default:break;
		}
	}
	else{
		switch (Local_u8_Port) {
			case 1 : ClearBit(PORTA,Local_u8_Pin);break;
			case 2 : ClearBit(PORTB,Local_u8_Pin);break;
			case 3 : ClearBit(PORTC,Local_u8_Pin);break;
			case 4 : ClearBit(PORTD,Local_u8_Pin);break;
			default:break;
		}
	}
}
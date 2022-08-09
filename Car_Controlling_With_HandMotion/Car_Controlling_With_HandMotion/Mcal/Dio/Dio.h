/*
 * Dio.h
 *
 * Created: 7/16/2022 2:59:46 AM
 *  Author: DELL G3
 */ 


#ifndef DIO_H_
#define DIO_H_

#include <avr/interrupt.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#define F_CPU 8000000
#include <util/delay.h>

#define Pa0 10
#define Pa1 11
#define Pa2 12
#define Pa3 13
#define Pa4 14
#define Pa5 15
#define Pa6 16
#define Pa7 17

#define Pb0 20
#define Pb1 21
#define Pb2 22
#define Pb3 23
#define Pb4 24
#define Pb5 25
#define Pb6 26
#define Pb7 27

#define Pc0 30
#define Pc1 31
#define Pc2 32
#define Pc3 33
#define Pc4 34
#define Pc5 35
#define Pc6 36
#define Pc7 37

#define Pd0 40
#define Pd1 41
#define Pd2 42
#define Pd3 43
#define Pd4 44
#define Pd5 45
#define Pd6 46
#define Pd7 47

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define ENABLE 1
#define DISABLE 0

// #define A 1
// #define B 2
// #define C 3
// #define D 4

void M_Dio_PinMode(u8,u8);
void M_Dio_PinWrite(u8,u8);
void M_Dio_PinTog(u8);
u8 M_Dio_PinRead(u8);
void M_Dio_PortMode(u8,u8);
void M_Dio_PortWrite(u8,u8);
void M_Dio_PinPullUpResistor(u8,u8);



#endif /* DIO_H_ */
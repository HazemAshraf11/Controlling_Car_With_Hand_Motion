/*
 * BitMath.h
 *
 * Created: 7/16/2022 2:48:25 AM
 *  Author: DELL G3
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Register,pin) Register|=1<<pin
#define ClearBit(Register,pin) Register&=~(1<<pin)
#define ToggleBit(Register,pin) Register^=1<<pin
#define ReadBit(Register,pin) 1&(Register>>pin)



#endif /* BITMATH_H_ */
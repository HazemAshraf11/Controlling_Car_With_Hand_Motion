/*
 * Reg.h
 *
 * Created: 7/16/2022 2:50:35 AM
 *  Author: DELL G3
 */ 


#ifndef REG_H_
#define REG_H_

/*********************************************************_DIO_REGISTERS_**********************************/
#define PINA           *(volatile u8*)0x39
#define DDRA           *(volatile u8*)0x3A
#define PORTA          *(volatile u8*)0x3B
#define PINB           *(volatile u8*)0x36
#define DDRB           *(volatile u8*)0x37
#define PORTB          *(volatile u8*)0x38
#define PINC           *(volatile u8*)0x33
#define DDRC           *(volatile u8*)0x34
#define PORTC          *(volatile u8*)0x35
#define PIND           *(volatile u8*)0x30
#define DDRD           *(volatile u8*)0x31
#define PORTD          *(volatile u8*)0x32
/*********************************************************_SREG_REGISTER_**********************************/

#define SREG           *(volatile u8*)0x5F                   // To enable Global Interrupt ( bit 7 )

/*******************************************************_EXT_INT_REGISTERS_**********************************/

#define MCUCR          *(volatile u8*)0x55                   // To select sense control for INT0 or INT1
#define MCUCSR         *(volatile u8*)0x54                   // To select sense control for INT2
#define GICR           *(volatile u8*)0x5B                   // choose interrupt pin (INT0 , INT1 , INT2)

/*********************************************************_ADC_REGISTERS_**********************************/
#define ADMUX          *(volatile u8*)0x27
#define ADCSRA         *(volatile u8*)0x26
#define ADCL           *(volatile u8*)0x24
#define ADCH           *(volatile u8*)0x25
#define ADC_VALUE      *(volatile u16*)0x24
/*******************************************************_TIMER0_REGISTERS_**********************************/
#define TCNT0          *(volatile u8*)0x52
#define TCCR0          *(volatile u8*)0x53
#define TIMSK          *(volatile u8*)0x59
#define OCR0           *(volatile u8*)0x5C
/*******************************************************_TIMER2_REGISTERS_**********************************/
#define TCNT2          *(volatile u8*)0x44
#define TCCR2          *(volatile u8*)0x45
#define OCR2           *(volatile u8*)0x43
/*******************************************************_TIMER1_REGISTERS_**********************************/
#define TCCR1A         *(volatile u8*)0x4F
#define TCCR1B         *(volatile u8*)0x4E

#define TCNT1H         *(volatile u8*)0x4D
#define TCNT1L         *(volatile u8*)0x4C
#define TCNT1          *(volatile u16*)0x4C

#define OCR1AH         *(volatile u8*)0x4B
#define OCR1AL         *(volatile u8*)0x4A
#define OCR1A          *(volatile u16*)0x4A

#define OCR1BH         *(volatile u8*)0x49
#define OCR1BL         *(volatile u8*)0x48
#define OCR1B          *(volatile u16*)0x48

#define ICR1H          *(volatile u8*)0x47
#define ICR1L          *(volatile u8*)0x46
#define ICR1           *(volatile u16*)0x46

/*******************************************************_WDT_REGISTERS_**********************************/
#define WDTCR          *(volatile u8*)0x41

/*******************************************************_UART_REGISTERS_**********************************/
#define UDR            *(volatile u8*)0x2C
#define UCSRA          *(volatile u8*)0x2B
#define UCSRB          *(volatile u8*)0x2A
#define UCSRC          *(volatile u8*)0x40
#define UBRRL          *(volatile u8*)0x29
#define UBRRH          *(volatile u8*)0x40



#endif /* REG_H_ */
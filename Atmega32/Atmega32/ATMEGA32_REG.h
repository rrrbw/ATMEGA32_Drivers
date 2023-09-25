/*
 * ATEMGA32_REG.h
 *
 * Created: 9/25/2023 4:58:59 AM
 *  Author: lraya
 */ 

#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

/* DIO REGISTERS*/

/* DATA DIRCTION REGISTERS */
#define DDRA           (*(volatile u8*)0x3A)
#define DDRB           (*(volatile u8*)0x37)
#define DDRC           (*(volatile u8*)0x34)
#define DDRD           (*(volatile u8*)0x31)

/* OUTPUT REGISTERS */
#define PORTA          (*(volatile u8*)0x3B)
#define PORTB          (*(volatile u8*)0x38)
#define PORTC          (*(volatile u8*)0x35)
#define PORTD          (*(volatile u8*)0x32)

/* INPUT REGISTERS */
#define PINA           (*(volatile u8*)0x39)
#define PINB           (*(volatile u8*)0x36)
#define PINC           (*(volatile u8*)0x33)
#define PIND           (*(volatile u8*)0x30)


/* EXTERNAL INTERRUPT REGISTERS */

// MCU Control Register
#define MCUCR           (*(volatile u8*)0x55)

// MCU Control and Status Register
#define MCUCSR          (*(volatile u8*)0x54)

// General Interrupt Control Register
#define GICR            (*(volatile u8*)0x5B)

// General Interrupt Flag Register
#define GIFR            (*(volatile u8*)0x5A)

/* GLOBAL INTERRUPT REGISTERS */
// Status Register
#define SREG            (*(volatile u8*)0x5F)


/* ADC REGISTERS*/

// ADC Multiplexer Selection Register
#define ADMUX            (*(volatile u8*)0x27)

// ADC Control and Status Register A
#define ADCSRA           (*(volatile u8*)0x26)

// The ADC Data Register
#define ADC_u16          (*(volatile u16*)0x24)

// Special FunctionIO Register
#define SFIOR            (*(volatile u8*)0x50)


/* TIMER0 REGISTERS*/

// Timer/Counter Control Register
#define TCCR0            (*(volatile u8*)0x53)

// Timer/Counter Register
#define TCNT0            (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0             (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK            (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR             (*(volatile u8*)0x58)


/* TIMER1 REGISTERS*/

// Timer/Counter1 Control Register A
#define TCCR1A             (*(volatile u8*)0x4F)

// Timer/Counter1 Control Register B
#define TCCR1B             (*(volatile u8*)0x4E)

// Timer/Counter1
#define TCNT1_u16          (*(volatile u16*)0x4C)

// Output Compare Register 1 A
#define OCR1A_u16          (*(volatile u16*)0x4A)

// Output Compare Register 1 B
#define OCR1B_u16          (*(volatile u16*)0x48)

// Input Capture Register 1
#define ICR1_u16           (*(volatile u16*)0x46)


/* WDT REGISTERS*/

// Watchdog Timer Control Register
#define WDTCR             (*(volatile u8*)0x41)

/* UART REGISTERS*/

// USART I/O Data Register
#define UDR             (*(volatile u8*)0x2C)

// USART Control and Status Register A
#define UCSRA           (*(volatile u8*)0x2B)

// USART Control and Status Register B
#define UCSRB           (*(volatile u8*)0x2A)

// USART Control and Status Register C
#define UCSRC           (*(volatile u8*)0x40)

// USART Baud Rate Registers
#define UBRRL           (*(volatile u8*)0x29)
#define UBRRH           (*(volatile u8*)0x40)


/* SPI REGISTERS*/

// SPI Control Register
#define SPCR            (*(volatile u8*)0x2D)

// SPI Status Register
#define SPSR            (*(volatile u8*)0x2E)

// SPI Data Register
#define SPDR            (*(volatile u8*)0x2F)


/* TWI REGISTERS */

// TWI Bit Rate Register
#define TWBR         (*(volatile u8*)0x20)

// TWI Control Register
#define TWCR         (*(volatile u8*)0x56)

// TWI Status Register
#define TWSR         (*(volatile u8*)0x21)

// TWI Data Register
#define TWDR         (*(volatile u8*)0x23)

// TWI (Slave) Address Register
#define TWAR         (*(volatile u8*)0x22)

#endif /* ATMEGA32_REG_H_ */
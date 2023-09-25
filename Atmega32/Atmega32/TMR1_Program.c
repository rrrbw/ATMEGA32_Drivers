/*
 * TMR1_Program.c
 *
 * Created: 9/25/2023 5:33:35 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR1_Interface.h"


void TMR1_init(void)
{
	// Select Mode = Fast PWM Mode(14)
	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	// Select Non Inverting Mode
	CLEAR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	
	//Set OC1A pin as O/P pin
	SET_BIT(DDRD,5);
	
	// ICR1 >> period time = 20ms >> freq. = 50HZ
	ICR1_u16 = 4999;
}


void TMR1_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,2);
}


void TMR1_setCompareMatchValueA(u16 value)
{
	// Init Timer With Compare Value
	OCR1A_u16 = value;
}
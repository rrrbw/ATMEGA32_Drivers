/*
 * TMR0_Program.c
 *
 * Created: 9/25/2023 5:36:27 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"

void TMR0_init(void)
{
	#if  TMR0_MODE == TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLEAR_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,3);
	
	// Init Timer With Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,0);
	
	#elif TMR0_MODE == TMR0_CTC_MODE
	// Select Mode = CTC Mode
	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);

	#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	// Select Mode = Fast PWM Mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Select Non Inverting Mode
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	
	SET_BIT(DDRB,3); //Set OC0 pin as O/P pin
	#endif
}


void TMR0_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
}

void TMR0_setCompareMatchValue(u8 value)
{
	// Init Timer With Compare Value
	OCR0 = value;
}
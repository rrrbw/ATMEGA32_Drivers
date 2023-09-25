/*
 * ADC_Program.c
 *
 * Created: 9/25/2023 5:20:35 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "ADC_Interface.h"


void ADC_init(void)
{
	// Select Vref = AVCC
	SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	
	// Select Right Adjustment
	CLEAR_BIT(ADMUX,5);
	
	// Single Conversation Mode
	CLEAR_BIT(ADCSRA,5);
	
	// Prescaler 128 For 16MHZ (125 KHZ)
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	// ADC Enable
	SET_BIT(ADCSRA,7);
}


void ADC_getDigitalValue(u8 channelNum,u16* digitalValue)
{
	if((channelNum<32) && (digitalValue != NULL))
	{
		//Clear ADMUX Channel Bits
		ADMUX &= 0b11100000;

		// Select Channel Number
		ADMUX |= channelNum;
		
		// Start Conversition
		SET_BIT(ADCSRA,6);
		
		// Wait For The Flag Of ADC
		while(0 == CHECK_BIT(ADCSRA,4));
		
		// Clear Flag
		SET_BIT(ADCSRA,4);
		
		// Read Digital Value
		*digitalValue = ADC_u16;
	}
}
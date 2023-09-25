/*
 * GI_Program.c
 *
 * Created: 9/25/2023 5:18:53 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_Interface.h"

void GI_enable(void)
{
	SET_BIT(SREG, 7);
}


void GI_disable(void)
{
	CLEAR_BIT(SREG, 7);
}

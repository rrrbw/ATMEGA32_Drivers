/*
 * CFile1.c
 *
 * Created: 9/25/2023 5:27:22 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "SPI_Interface.h"


void SPI_initMaster(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Master Mode
	SET_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// select CLK Rate = FCPU/16 (1 MHZ)
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
	
	// init Master Directions
	SET_BIT(DDRB,5);  // MOSI -> OUTPUT
	CLR_BIT(DDRB,6);  // MISO -> INPUT
	SET_BIT(DDRB,7);  // SCLK -> OUTPUT
	SET_BIT(DDRB,4);  // SS   -> OUTPUT
	CLEAR_BIT(PORTB,4); // SS  -> 0
	
	// enable SPI
	SET_BIT(SPCR,6);
}


void SPI_initSlave(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Slave Mode
	CLEAR_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// init Slave Directions
	CLEAR_BIT(DDRB,5); // MOSI -> INPUT
	SET_BIT(DDRB,6); // MISO -> OUTPUT
	CLEAR_BIT(DDRB,7); // SCLK -> INPUT
	CLEAR_BIT(DDRB,4); // SS   -> INPUT
	
	// enable SPI
	SET_BIT(SPCR,6);
}


void SPI_transieve(u8 TxData,u8* RxData)
{
	if(RxData != NULL)
	{
		SPDR = TxData;
		
		while(0 == CHECK_BIT(SPSR,7));
		*RxData = SPDR;
	}
}
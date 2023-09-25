/*
 * UART_Program.c
 *
 * Created: 9/25/2023 5:30:51 AM
 *  Author: lraya
 */ 
/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_Interface.h"


void UART_init(void)
{
	// writing the UCSRC , // selct UART MODE = Asynchronous , 	// configure no parity , // configure data bits = 8 , // configure stop bits = 1
	UCSRC = 0x86; //0b10000110
	CLEAR_BIT(UCSRB,2);
	
	// set buad rate = 9600
	UBRRL = 103;

	//Tx O/P
	SET_BIT(DDRD,1);
	
	//Rx I/P
	CLEAR_BIT(DDRD,0);
	
	//Enable Tx
	SET_BIT(UCSRB,3);
	
	//Enable Rx
	SET_BIT(UCSRB,4);
}


void UART_TxChar(u8 data)
{
	UDR = data;
	while(0 == CHECK_BIT(UCSRA,5));
}


void UART_RxChar(u8* returnedData)
{
	if(returnedData != NULL)
	{
		while(0 == CHECK_BIT(UCSRA,7));
		*returnedData = UDR;
	}
}


void UART_TxString(u8* String)
{
	if(String != NULL)
	{
		u8 counter = 0;
		while (String[counter] != '\0')
		{
			UART_TxChar(String[counter]);
			counter++;
		}
	}
}
/*
 * TWI_Program.c
 *
 * Created: 9/25/2023 5:23:59 AM
 *  Author: lraya
 */ 

/* Library */
#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "CLOCK.h"
#include "BIT_MATH.h"
/* MCAL */
#include "TWI_Interface.h"

void TWI_initMaster(void)
{
	// Set Prescaller = 1 >> Set Freq. = 400KHZ
	TWBR = 12;
	CLEAR_BIT(TWSR,0);
	CLEAR_BIT(TWSR,1);
	
	// Enable ACK
	SET_BIT(TWCR,6);

	// Enable TWI
	SET_BIT(TWCR,2);
}


void TWI_sendStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = SC ACK
	while((TWSR & 0xF8) != 0x08);
}


void TWI_sendRepStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = Repeated SC ACK
	while((TWSR & 0xF8) != 0x10);
}


void TWI_sendStopCondition(void)
{
	// Send Stop Condition
	SET_BIT(TWCR,4);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
}


void TWI_sendSlaveAddWithWrite(u8 slaveAdd)
{
	// Send slave address
	TWDR = slaveAdd<<1;
	
	// Select write operation
	CLEAR_BIT(TWDR,0);
	
	// Clear SC bit
	CLEAR_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = Master transmit ( slave address + Write request ) ACK
	while((TWSR & 0xF8) != 0x18);
}


void TWI_sendSlaveAddWithRead(u8 slaveAdd)
{
	// Send slave address
	TWDR = slaveAdd<<1;
	
	// Select Read operation
	SET_BIT(TWDR,0);
	
	// Clear SC bit
	CLEAR_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = Master transmit ( slave address + Read request ) ACK
	while((TWSR & 0xF8) != 0x40);
}


void TWI_sendMasterDataByte(u8 data)
{
	// Write Data into data register
	TWDR = data;
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = Master transmit data ACK
	while((TWSR & 0xF8) != 0x28);
}


u8 TWI_recieveMasterDataByte(void)
{
	u8 returnedData;
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == CHECK_BIT(TWCR,7));
	
	// Check ACK = Master received data with ACK
	while((TWSR & 0xF8) != 0x50);
	
	// Read Data from data register
	returnedData = TWDR;
	
	return returnedData;
}
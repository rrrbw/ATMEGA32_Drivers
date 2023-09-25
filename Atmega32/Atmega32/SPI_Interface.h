/*
 * SPI_Interface.h
 *
 * Created: 9/25/2023 5:27:12 AM
 *  Author: lraya
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_initMaster(void);
void SPI_initSlave (void);
void SPI_transieve (u8 TxData,u8* RxData);


#endif /* SPI_INTERFACE_H_ */
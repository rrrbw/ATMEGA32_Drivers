/*
 * TMR1.h
 *
 * Created: 9/25/2023 5:33:12 AM
 *  Author: lraya
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


void TMR1_init                 (void);
void TMR1_start                (void);
void TMR1_setCompareMatchValueA(u16 value);


#endif /* TMR1_INTERFACE_H_ */
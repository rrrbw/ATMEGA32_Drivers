/*
 * TMR0_Interface.h
 *
 * Created: 9/25/2023 5:35:11 AM
 *  Author: lraya
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

#define TMR0_NORMAL_MODE            1
#define TMR0_CTC_MODE               2
#define TMR0_FAST_PWM_MODE          3

void TMR0_init                (void);
void TMR0_start               (void);
void TMR0_setCompareMatchValue(u8 value);

#endif /* TMR_INTERFACE_H_ */
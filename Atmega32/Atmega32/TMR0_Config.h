/*
 * TMR0_Config.h
 *
 * Created: 9/25/2023 5:35:52 AM
 *  Author: lraya
 */ 


#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/* Options FOR TMR0 Mode:
1- TMR0_NORMAL_MODE
2- TMR0_CTC_MODE
3- TMR0_FAST_PWM_MODE
*/

#define TMR0_MODE                           TMR0_FAST_PWM_MODE

#define TMR0_PRELOAD_VALUE                  82
#define TMR0_OVER_FLOW_COUNTER              2930

#define TMR0_CTC_COUNTER                    1500

#endif /* TMR0_CONFIG_H_ */
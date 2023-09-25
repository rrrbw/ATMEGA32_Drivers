/*
 * ADC_Interface.h
 *
 * Created: 9/25/2023 5:20:11 AM
 *  Author: lraya
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_CHANNEL_0           0
#define ADC_CHANNEL_1           1
#define ADC_CHANNEL_2           2
#define ADC_CHANNEL_3           3
#define ADC_CHANNEL_4           4
#define ADC_CHANNEL_5           5
#define ADC_CHANNEL_6           6
#define ADC_CHANNEL_7           7

/*************** APIS PROTOTYPES ***************/

void ADC_init           (void);
void ADC_getDigitalValue(u8 channelNum,u16* digitalValue);

#endif /* ADC_INTERFACE_H_ */
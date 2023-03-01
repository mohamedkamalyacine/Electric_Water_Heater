#ifndef _MCAL_ADC_INTERFACE_H_
#define _MCAL_ADC_INTERFACE_H_


typedef enum
{
    ADC0_CHANNEL,
    ADC1_CHANNEL,
    ADC2_CHANNEL,
    ADC3_CHANNEL,
    ADC4_CHANNEL,
    ADC5_CHANNEL,
    ADC6_CHANNEL,
    ADC7_CHANNEL
}_enuADCChannels;


void ADC_vidInit(_enuADCChannels enuChannel);

u16 ADC_u16Read(void);
#endif
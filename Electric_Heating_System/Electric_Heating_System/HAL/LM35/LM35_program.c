

#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "../MCAL/ADC/ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_config.h"
#include "LM35_private.h"

void LM35_vidInit(_enuADCChannels enuADCChannel)
{
	ADC_vidInit(enuADCChannel);
}

u8 LM35_u8Read(void)
{
	//u16 u16Read, u16Analog;
	//u8 u8Temp;
	///* Return Digital value*/
	//u16Read = ADC_u16Read();
	///* Calculate Analog value */
	//u16Analog = (INT_VREF * u16Read) / 1024;
	///* Calculate Temperature value */
	//u8Temp = u16Analog / 10;
	//return u8Temp;
	float OutputVal;
	OutputVal = (0.48828125 * ADC_u16Read());
	return OutputVal;
}
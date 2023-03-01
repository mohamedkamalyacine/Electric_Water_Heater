#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "SevenSeg_private.h"
#include "SevenSeg_config.h"
#include "SevenSeg_interface.h"
#define F_CPU 8000000Ul
#include "util/delay.h"

void SevenSeg_vidInit(_enuGPIOX enuPortNum,_enuGPIOX enuENPortNum,_enuPINX enuPinNum)
{
	DIO_vidSetPortMode(enuPortNum, OUTPUT);
	DIO_vidSetPinMode(enuENPortNum,enuPinNum,OUTPUT);
	#if SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_vidWritePin(enuENPortNum,enuPinNum,HIGH);
	#endif
	
}
void SevenSeg_vidWrite(_enuGPIOX enuPortNum, u8 u8Data)
{
	u8 Changer = 0x00;
	u8 u8Copy_Data = u8Data%10;
	
	#if SEVEN_SEG_TYPE == COMMON_ANODE
		Changer = 0xFF;
	#endif
	
	#if NIBBLE == ON
		DIO_vidWriteLowNibble(enuPortNum,u8Copy_Data);
		DIO_vidWriteHighNibble(enuPortNum,(u8Data/10)<<4);
	#else
		u8 Num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D ,0x7D,0x07,0x7F,0x6F};
		DIO_vidWritePort(enuPortNum,Num[u8Data]^Changer);
	#endif	
	_delay_ms(100);
}
void SevenSeg_vidBlink(_enuGPIOX enuENPortNum,_enuPINX enuPinNum)
{
	u8 Read_Pin = DIO_enuReadPin(enuENPortNum,enuPinNum);
	if(Read_Pin == HIGH)
		{
			DIO_vidWritePin(enuENPortNum,enuPinNum,LOW);
		}
	else
		{
			DIO_vidWritePin(enuENPortNum,enuPinNum,HIGH);
	    }
		_delay_ms(1000);
}

void SevenSeg_vidEnable(_enuGPIOX enuENPortNum,_enuPINX enuPinNum,t_state status)
{
	if(status == NO)
	{
		_delay_ms(10);
		DIO_vidWritePin(enuENPortNum,enuPinNum,LOW);
	}
	else
	{
		_delay_ms(10);
		DIO_vidWritePin(enuENPortNum,enuPinNum,ON);
	}
}
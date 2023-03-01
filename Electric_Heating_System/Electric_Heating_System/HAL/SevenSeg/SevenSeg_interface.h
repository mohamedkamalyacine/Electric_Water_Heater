#ifndef HAL_SEVEN_SEG_INTERFACE_H_
#define HAL_SEVEN_SEG_INTERFACE_H_

#include "Types.h"
#include "BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
typedef enum
{
	YES,
	NO
	}t_state;
void SevenSeg_vidInit(_enuGPIOX enuPortNum,_enuGPIOX enuENPortNum,_enuPINX enuPinNum);
void SevenSeg_vidWrite(_enuGPIOX enuPortNum,u8 u8Data);
void SevenSeg_vidBlink(_enuGPIOX enuENPortNum,_enuPINX enuPinNum);
void SevenSeg_vidEnable(_enuGPIOX enuENPortNum,_enuPINX enuPinNum,t_state status);

#endif
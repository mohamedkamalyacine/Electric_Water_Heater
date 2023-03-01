#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "DCMotor_interface.h"
#include "DCMotor_private.h"
#include "DCMotor_config.h"

void DCMotor_vidInit(_enuGPIOX enuGPIOx,_enuPINX enuPinNum)
{
    DIO_vidSetPinMode(enuGPIOx, enuPinNum, OUTPUT);
}
void DCMotor_vidOn(_enuGPIOX enuGPIOx,_enuPINX enuPinNum)
{
    DIO_vidWritePin(enuGPIOx, enuPinNum, HIGH);
}
void DCMotor_vidOff(_enuGPIOX enuGPIOx,_enuPINX enuPinNum)
{
    DIO_vidWritePin(enuGPIOx, enuPinNum, LOW);
}
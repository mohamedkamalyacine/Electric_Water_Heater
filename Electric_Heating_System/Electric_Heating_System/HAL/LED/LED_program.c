#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_vidLEDInit(_enuGPIOX enuPortNum, _enuPINX enuPinNum)
{
    DIO_vidSetPinMode(enuPortNum, enuPinNum, OUTPUT);
}

void LED_vidLEDOn(_enuGPIOX enuPortNum, _enuPINX enuPinNum)
{
    DIO_vidWritePin(enuPortNum, enuPinNum, HIGH);
}

void LED_vidLEDOff(_enuGPIOX enuPortNum, _enuPINX enuPinNum)
{
    DIO_vidWritePin(enuPortNum, enuPinNum, LOW);
}

void LED_vidLEDToggle(_enuGPIOX enuPortNum, _enuPINX enuPinNum)
{
    _enuOUTPUT enuOUTPUT;
    enuOUTPUT = DIO_enuReadPin(enuPortNum, enuPinNum);
    if(enuOUTPUT == HIGH)
    {
        DIO_vidWritePin(enuPortNum, enuPinNum, LOW);
    }
    else 
    {
        DIO_vidWritePin(enuPortNum, enuPinNum, HIGH);
    }
}
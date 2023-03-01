#ifndef _MCAL_DIO_INTERFACE_H_
#define _MCAL_DIO_INTERFACE_H_

#include "Types.h"

typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD
}_enuGPIOX;

typedef enum
{
    PIN0 =0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}_enuPINX;

typedef enum
{
    INPUT =0,
    OUTPUT
}_enuMODE;

typedef enum
{
    LOW = 0,
    HIGH
}_enuOUTPUT;

typedef enum
{
    LOW_NIBBLE = 0,
    HIGH_NIBBLE
}_enuNIBBLE;

void DIO_vidSetPinMode(_enuGPIOX enuPortNum, _enuPINX enuPinNum, _enuMODE enuMODE);

void DIO_vidWritePin(_enuGPIOX enuPortNum, _enuPINX enuPinNum, _enuOUTPUT enuOUTPUT);

_enuOUTPUT DIO_enuReadPin(_enuGPIOX enuPortNum, _enuPINX enuPinNum);

void DIO_vidSetPortMode(_enuGPIOX enuPortNum, _enuMODE enuMODE);

void DIO_vidWritePort(_enuGPIOX enuPortNum, u8 u8OutputValue);

void DIO_vidSetLowNibbleMode(_enuGPIOX enuPortNum, _enuMODE enuMODE);

void DIO_vidSetHighNibbleMode(_enuGPIOX enuPortNum, _enuMODE enuMODE);

void DIO_vidWriteLowNibble(_enuGPIOX enuPortNum, u8 u8OutputValue);

void DIO_vidWriteHighNibble(_enuGPIOX enuPortNum, u8 u8OutputValue);

#endif
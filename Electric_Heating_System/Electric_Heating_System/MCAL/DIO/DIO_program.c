
#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_vidSetPinMode(_enuGPIOX enuPortNum, _enuPINX enuPinNum, _enuMODE enuMODE)
{
    switch(enuPortNum)
    {
        case GPIOA:
            if(enuMODE == OUTPUT)
            {
                SET_BIT(DDRA, enuPinNum);
            }
            else
            {
                CLR_BIT(DDRA, enuPinNum);
            }
            break;
        case GPIOB:
            if(enuMODE == OUTPUT)
            {
                SET_BIT(DDRB, enuPinNum);
            }
            else
            {
                CLR_BIT(DDRB, enuPinNum);
            }
            break;
        case GPIOC:
            if(enuMODE == OUTPUT)
            {
                SET_BIT(DDRC, enuPinNum);
            }
            else
            {
                CLR_BIT(DDRC, enuPinNum);
            }
            break;
        case GPIOD:
            if(enuMODE == OUTPUT)
            {
                SET_BIT(DDRD, enuPinNum);
            }
            else
            {
                CLR_BIT(DDRD, enuPinNum);
            }
            break;
        default:
            break;
    }
}

void DIO_vidWritePin(_enuGPIOX enuPortNum, _enuPINX enuPinNum, _enuOUTPUT enuOUTPUT)
{
    switch(enuPortNum)
    {
        case GPIOA:
            if(enuOUTPUT == HIGH)
            {
                SET_BIT(PORTA, enuPinNum);
            }
            else
            {
                CLR_BIT(PORTA, enuPinNum);
            }
            break;
        case GPIOB:
            if(enuOUTPUT == HIGH)
            {
                SET_BIT(PORTB, enuPinNum);
            }
            else
            {
                CLR_BIT(PORTB, enuPinNum);
            }
            break;
        case GPIOC:
            if(enuOUTPUT == HIGH)
            {
                SET_BIT(PORTC, enuPinNum);
            }
            else
            {
                CLR_BIT(PORTC, enuPinNum);
            }
            break;
        case GPIOD:
            if(enuOUTPUT == HIGH)
            {
                SET_BIT(PORTD, enuPinNum);
            }
            else
            {
                CLR_BIT(PORTD, enuPinNum);
            }
            break;
        default:
            break;
    }
}
_enuOUTPUT DIO_enuReadPin(_enuGPIOX enuPortNum, _enuPINX enuPinNum)
{
    _enuOUTPUT enuOUTPUT;
    switch(enuPortNum)
    {
        case GPIOA:
            enuOUTPUT = GET_BIT(PINA, enuPinNum);
            break;
        case GPIOB:
            enuOUTPUT = GET_BIT(PINB, enuPinNum);
            break;
        case GPIOC:
            enuOUTPUT = GET_BIT(PINC, enuPinNum);
            break;
        case GPIOD:
            enuOUTPUT = GET_BIT(PIND, enuPinNum);
            break;
        default:
            break;
    }
    return enuOUTPUT;
}

void DIO_vidSetPortMode(_enuGPIOX enuPortNum, _enuMODE enuMODE)
{
    switch(enuPortNum)
    {
        case GPIOA:
            if(enuMODE == OUTPUT)
            {
                DDRA = 0xff;
            }
            else
            {
                DDRA = 0x00;
            }
            break;
        case GPIOB:
            if(enuMODE == OUTPUT)
            {
                DDRB = 0xff;
            }
            else
            {
                DDRB = 0x00;
            }
            break;
        case GPIOC:
            if(enuMODE == OUTPUT)
            {
                DDRC = 0xff;
            }
            else
            {
                DDRC = 0x00;
            }
            break;
        case GPIOD:
            if(enuMODE == OUTPUT)
            {
                DDRD = 0xff;
            }
            else
            {
                DDRD = 0x00;
            }
            break;
        default:
            break;
    }
}

void DIO_vidWritePort(_enuGPIOX enuPortNum, u8 u8OutputValue)
{
    switch(enuPortNum)
    {
        case GPIOA:
            PORTA = u8OutputValue;
            break;
        case GPIOB:
            PORTB = u8OutputValue;
            break;
        case GPIOC:
            PORTC = u8OutputValue;
            break;
        case GPIOD:
            PORTD = u8OutputValue;
            break;
        default:
            break;
    }
}


void DIO_vidSetLowNibbleMode(_enuGPIOX enuPortNum, _enuMODE enuMODE)
{
    if(enuMODE == OUTPUT)
    {
        DIO_vidSetPinMode(enuPortNum, PIN0, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN1, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN2, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN3, OUTPUT);
    }
    else
    {
        DIO_vidSetPinMode(enuPortNum, PIN0, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN1, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN2, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN3, INPUT);
    }
}

void DIO_vidSetHighNibbleMode(_enuGPIOX enuPortNum, _enuMODE enuMODE)
{
    if(enuMODE == OUTPUT)
    {
        DIO_vidSetPinMode(enuPortNum, PIN4, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN5, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN6, OUTPUT);
        DIO_vidSetPinMode(enuPortNum, PIN7, OUTPUT);
    }
    else
    {
        DIO_vidSetPinMode(enuPortNum, PIN4, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN5, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN6, INPUT);
        DIO_vidSetPinMode(enuPortNum, PIN7, INPUT);
    }
}

void DIO_vidWriteLowNibble(_enuGPIOX enuPortNum, u8 u8OutputValue)
{
    u8OutputValue &= 0x0f;
    switch(enuPortNum)
    {
        case GPIOA:
            PORTA &= 0xf0;
            PORTA |= u8OutputValue;
            break;
        case GPIOB:
            PORTB &= 0xf0;
            PORTB |= u8OutputValue;
            break;
        case GPIOC:
            PORTC &= 0xf0;
            PORTC |= u8OutputValue;
            break;
        case GPIOD:
            PORTD &= 0xf0;
            PORTD |= u8OutputValue;
            break;
        default:
            break;
    }
}

void DIO_vidWriteHighNibble(_enuGPIOX enuPortNum, u8 u8OutputValue)
{
    u8OutputValue &= 0xf0;
    switch(enuPortNum)
    {
        case GPIOA:
            PORTA &= 0x0f;
            PORTA |= u8OutputValue;
            break;
        case GPIOB:
            PORTB &= 0x0f;
            PORTB |= u8OutputValue;
            break;
        case GPIOC:
            PORTC &= 0x0f;
            PORTC |= u8OutputValue;
            break;
        case GPIOD:
            PORTD &= 0x0f;
            PORTD |= u8OutputValue;
            break;
        default:
            break;
    }
}
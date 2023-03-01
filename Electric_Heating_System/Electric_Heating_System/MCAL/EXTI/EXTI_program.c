#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#include "avr/interrupt.h"

void (* Global_CBINT0)(void);
void (* Global_CBINT1)(void);
void (* Global_CBINT2)(void);


void EXTI_vidInit(_enuINT enuINTNum, _enuINTMODE enuINTMODE)
{
    SET_BIT(SREG, GI);
    switch(enuINTNum)
    { 
        case INT0_PIN:
            DIO_vidSetPinMode(GPIOD, PIN2, INPUT);
            if(enuINTMODE == LOW_LEVEL)
            {
                CLR_BIT(MCUCR, ISC00);
                CLR_BIT(MCUCR, ISC01);
            }
            else if(enuINTMODE == FALLING_EDGE)
            {
                CLR_BIT(MCUCR, ISC00);
                SET_BIT(MCUCR, ISC01);
            }
            else if(enuINTMODE == RISING_EDGE)
            {
                SET_BIT(MCUCR, ISC00);
                SET_BIT(MCUCR, ISC01);
            }
            else
            {
                SET_BIT(MCUCR, ISC00);
                CLR_BIT(MCUCR, ISC01);
            }
            SET_BIT(GICR, INT0);
            break;
        case INT1_PIN:
            DIO_vidSetPinMode(GPIOD, PIN3, INPUT);
            if(enuINTMODE == LOW_LEVEL)
            {
                CLR_BIT(MCUCR, ISC10);
                CLR_BIT(MCUCR, ISC11);
            }
            else if(enuINTMODE == FALLING_EDGE)
            {
                CLR_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);
            }
            else if(enuINTMODE == RISING_EDGE)
            {
                SET_BIT(MCUCR, ISC10);
                SET_BIT(MCUCR, ISC11);
            }
            else
            {
                SET_BIT(MCUCR, ISC10);
                CLR_BIT(MCUCR, ISC11);
            }
            SET_BIT(GICR, INT1);
            break;
        case INT2_PIN:
            DIO_vidSetPinMode(GPIOB, PIN2, INPUT);
            if(enuINTMODE == FALLING_EDGE)
            {
                CLR_BIT(MCUCSR, ISC2);
            }
            else if(enuINTMODE == RISING_EDGE)
            {
                SET_BIT(MCUCSR, ISC2);
            }
            else
            {

            }
            SET_BIT(GICR, INT2);
            break;
        default:
            break;
    }
}

void EXTI_vidSetCB(_enuINT enuINTNum, void (*INT_CB)(void))
{
    switch(enuINTNum)
    { 
        case INT0_PIN:
            Global_CBINT0 = INT_CB;
            break;
        case INT1_PIN:
            Global_CBINT1 = INT_CB;
            break;
        case INT2_PIN:
            Global_CBINT2 = INT_CB;
            break;
        default:
            break;
    }
}

ISR(INT0_vect)
{
	(*Global_CBINT0)();
}

ISR(INT1_vect)
{
	(*Global_CBINT1)();
}

ISR(INT2_vect)
{
	(*Global_CBINT2)();
}

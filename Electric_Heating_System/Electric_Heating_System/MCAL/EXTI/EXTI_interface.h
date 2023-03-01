#ifndef _MCAL_EXTI_INTERFACE_H_
#define _MCAL_EXTI_INTERFACE_H_

typedef enum
{
    INT0_PIN = 0,
    INT1_PIN,
    INT2_PIN
}_enuINT;

typedef enum
{
    LOW_LEVEL = 0,
    FALLING_EDGE,
    RISING_EDGE,
    LOGICAL_CHANGE
}_enuINTMODE;

void EXTI_vidInit(_enuINT enuINTNum, _enuINTMODE enuINTMODE);

void EXTI_vidSetCB(_enuINT enuINTNum, void (*INT_CB)(void));
#endif
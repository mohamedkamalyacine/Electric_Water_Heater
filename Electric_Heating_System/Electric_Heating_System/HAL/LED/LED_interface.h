#ifndef _HAL_LED_INTERFACE_H_
#define _HAL_LED_INTERFACE_H_

void LED_vidLEDInit(_enuGPIOX enuPortNum, _enuPINX enuPinNum);

void LED_vidLEDOn(_enuGPIOX enuPortNum, _enuPINX enuPinNum);

void LED_vidLEDOff(_enuGPIOX enuPortNum, _enuPINX enuPinNum);

void LED_vidLEDToggle(_enuGPIOX enuPortNum, _enuPINX enuPinNum);

#endif
#ifndef _HAL_DC_MOTOR_INTERFACE_H_
#define _HAL_DC_MOTOR_INTERFACE_H_

#include "Types.h"

#include "../MCAL/DIO/DIO_interface.h"

void DCMotor_vidInit(_enuGPIOX enuGPIOx, _enuPINX enuPinNum);
void DCMotor_vidOn(_enuGPIOX enuGPIOx, _enuPINX enuPinNum);
void DCMotor_vidOff(_enuGPIOX enuGPIOx, _enuPINX enuPinNum);

#endif
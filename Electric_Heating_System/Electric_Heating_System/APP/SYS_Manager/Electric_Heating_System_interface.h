#ifndef _ELECTRIC_HEATING_SYSTEM_INTERFACE_HAL_
#define _ELECTRIC_HEATING_SYSTEM_INTERFACE_HAL_
/*
 * Electric_Water_Heater.c
 *
 * Created: 28/10/2022 9:38:57 PM
 * Author : Amr Hesham
 */ 


#include "../LIBRARIES/Types.h"
#include "../LIBRARIES/BIT_MATH.h"

//Include libraries for building the program.\LIBRARIES\Types.h
//Including MCAL Lib
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
//Including HAL Lib
#include "../HAL/DC_Motor/DCMotor_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LM35/LM35_interface.h"
#include "../HAL/SevenSeg/SevenSeg_interface.h"



#define F_CPU 8000000UL
#include "util/delay.h"


typedef enum{ON,OFF}t_status;
void SYS_vidInit(void);
void SYS_vidStart(void);
void SYS_vidSetTemp(void);
u32 SYS_u32GetTempReading(void);
void SYS_vidHeatingControl(t_status state);
void SYS_vidCoolingControl(t_status state);
void Temp_vidInc(void);
void Temp_vidDec(void);
void SYS_vidSleep(void);

u8 Max_temp;
u8 Min_temp;
u8 Current_temp;
u8 Count;
u8 Clk1;
u8 SYS_state;
u8 SetTemp_flag;
u8 Temp_History[10];


#endif
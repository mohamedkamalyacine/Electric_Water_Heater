
#include "Electric_Heating_System_interface.h"
#include "Electric_Heating_System_private.h"
#include "Electric_Heating_System_config.h"

void SYS_vidInit(void){
	
	Max_temp = 60;
	Min_temp = 60;
	Current_temp = 60;
	Count = 0;
	Clk1 = 0;
	SYS_state = OFF;
	SetTemp_flag = OFF;
		
	//Initialize interrupts
	EXTI_vidInit(INT0_PIN,RISING_EDGE);
	EXTI_vidInit(INT1_PIN,RISING_EDGE);
	EXTI_vidInit(INT2_PIN,RISING_EDGE);
	EXTI_vidSetCB(INT0_PIN,Temp_vidInc);
	EXTI_vidSetCB(INT1_PIN,Temp_vidDec);
	EXTI_vidSetCB(INT2_PIN,SYS_vidSleep);
	
	//Initialize Temp sensor
	LM35_vidInit(ADC0_CHANNEL);
	
	//Initialize DC_Motor
	DCMotor_vidInit(GPIOB,PIN6);
	DCMotor_vidInit(GPIOB,PIN7);
	
	//Initialize 7 Segment Display
	SevenSeg_vidInit(GPIOC,GPIOD,PIN4);
	SevenSeg_vidEnable(GPIOD,PIN4,NO);
	
	//Initialize Indicators LEDs
	LED_vidLEDInit(GPIOB,PIN5);
	LED_vidLEDInit(GPIOA,PIN3);
	LED_vidLEDInit(GPIOA,PIN4);
	LED_vidLEDInit(GPIOA,PIN5);
	
	//EEPROM
	EEPROM_voidWrite(0x04,Max_temp);
	EEPROM_voidWrite(0x07,Min_temp);
		
}


void SYS_vidStart(void)
{
	SYS_vidSetTemp();
	
	if(Clk1 >= 5 && SYS_state == ON)
	{
		u32 average_temp = Current_temp;
		//100 ms between every temp reading
		
		LED_vidLEDOn(GPIOA,PIN3);	     //to indicate system is on
		average_temp = SYS_u32GetTempReading();
		SevenSeg_vidEnable(GPIOD,PIN4,ON);
		SevenSeg_vidWrite(GPIOC,Current_temp);
		
		
		//Determining the state of heating or cooling elements
		//based on the last 10 temp readings
		
		if(average_temp > Max_temp + 5)
		{
			SYS_vidCoolingControl(ON);
			SYS_vidHeatingControl(OFF);
			LED_vidLEDToggle(GPIOB,PIN5);
		}
		else if(average_temp < Min_temp - 5)
		{
			SYS_vidCoolingControl(OFF);
			SYS_vidHeatingControl(ON);
			LED_vidLEDOn(GPIOB,PIN5);
		}
		else
		{
			SYS_vidCoolingControl(OFF);
			SYS_vidHeatingControl(OFF);
			LED_vidLEDOff(GPIOB,PIN5);
		}
	}
	else if(SYS_state==ON)
		{
			SevenSeg_vidEnable(GPIOD,PIN4,YES);
		}	
	else
	{
		//shutting down leds and seven seg when system is off
		SevenSeg_vidEnable(GPIOD,PIN4,NO);
		LED_vidLEDOff(GPIOB,PIN5);
		LED_vidLEDOff(GPIOA,PIN3);
		LED_vidLEDOff(GPIOA,PIN4);
		LED_vidLEDOff(GPIOA,PIN5);
	}
}
void Temp_vidInc(void)
{
	//Maximum allowed temp is 75 degrees
	if(Max_temp < 75 && SYS_state == ON)
	{
		SetTemp_flag = ON;
		Max_temp += 5;
		SevenSeg_vidWrite(GPIOC,Max_temp);
		EEPROM_voidWrite(0x04,Max_temp); //storing new value in EEPROM
		LED_vidLEDToggle(GPIOA,4); //indicating that interrupt has been executed
		Clk1 = 0; //reseting set temp time
	}
	else
		SevenSeg_vidWrite(GPIOC,Max_temp);  //When reaching the maximum allowed temp
}
void Temp_vidDec(void)
{
	//Minimum allowed temp is 35 degrees
	if(Min_temp > 35 && SYS_state == ON)
	{
		SetTemp_flag = ON;
		Min_temp = Min_temp - 5;
		SevenSeg_vidWrite(GPIOC,Min_temp);
		EEPROM_voidWrite(0x07,Min_temp); //storing new value in EEPROM
		LED_vidLEDToggle(GPIOA,5); //indicating that interrupt has been executed
		Clk1 = 0;   //reseting set temp time
	}
	else
		SevenSeg_vidWrite(GPIOC,Min_temp);  //When reaching the minimum allowed temp
}
void SYS_vidSetTemp(void)
{
	//Get temp limits from user
	while(Clk1<=5 && SetTemp_flag == ON && SYS_state == ON)
	{
		SevenSeg_vidBlink(GPIOD,4); //there is an internal delay of 1 sec.
		Clk1++; // for delay 5 sec
		if(Clk1 == 5)
		{
			SetTemp_flag = OFF; // Getting out of set temp mode after 5 sec
		}
	}
	
}

u32 SYS_u32GetTempReading(void)
{
	//read data from temp sensors and disp it
	Current_temp = LM35_u8Read();
	SevenSeg_vidWrite(GPIOC,Current_temp);
	LED_vidLEDToggle(GPIOA,PIN4);
	_delay_ms(100);
	
	//Store it in an array
	//Checking if the array is full
	if(Count == 10)
		Count = 0;
		
	Temp_History[Count] = Current_temp;
	Count++;
	
	//Getting the average
	u32 average_temp = 0;
	for (int i = 0; i < Count; i++)
	{
		average_temp += Temp_History[i];
	}
	average_temp /= Count;
	return average_temp;
		
}
void SYS_vidSleep(void)
{
	//Hold system and close the seven segment
	SevenSeg_vidWrite(GPIOC,Current_temp);
	if(SYS_state == OFF)
		{
			LED_vidLEDToggle(GPIOA,5); //indicating the sys is on
			SevenSeg_vidWrite(GPIOD,Current_temp); //displaying current temp
			Max_temp = EEPROM_voidRead(0x04); //getting values from EEPROM
			Min_temp = EEPROM_voidRead(0x07);
			SYS_state = ON;
		}
	else
		{
			//Turning off leds and storing values in EEPROM
			LED_vidLEDOff(GPIOB,PIN5);
			EEPROM_voidWrite(0x04,Max_temp);
			EEPROM_voidWrite(0x07,Min_temp);
			Max_temp = 60; //To insure that data is retrived from EEPROM
			Min_temp = 60;
			SevenSeg_vidEnable(GPIOD,PIN4,NO);
			LED_vidLEDToggle(GPIOA,5);	
			SYS_vidHeatingControl(OFF);
			SYS_vidCoolingControl(OFF);
			SYS_state = OFF;
		}
}
void SYS_vidHeatingControl(t_status state)
{
	if(state == ON && SYS_state == ON)
		DCMotor_vidOn(GPIOB,PIN7);
	else if(state == OFF)
		DCMotor_vidOff(GPIOB,PIN7);
	else
	{
		
	}
		
}

void SYS_vidCoolingControl(t_status state)
{
	if(state == ON && SYS_state == ON)
		DCMotor_vidOn(GPIOB,PIN6);
	else if(state == OFF)
		DCMotor_vidOff(GPIOB,PIN6);
	else
	{
		
	}
	
}


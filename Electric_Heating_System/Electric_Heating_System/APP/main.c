/*
 * Electric_Heating_System.c
 *
 * Created: 9/11/2022 8:54:39 PM
 * Author : Amr Hesham
 */ 


#include "../APP/SYS_Manager/Electric_Heating_System_interface.h"

int main(void)
{
	SYS_vidInit(); // initializing system
	while(1)
	{
		SYS_vidStart(); //starting system
	}
	
}

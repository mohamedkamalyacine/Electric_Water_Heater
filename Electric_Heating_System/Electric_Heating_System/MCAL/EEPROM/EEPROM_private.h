


#ifndef  _MCAL_EEPROM_PRIVATE_H
#define  _MCAL_EEPROM_PRIVATE_H
	
	#define  EEARH     *((volatile u8*)0x3F)
	#define  EEARL	   *((volatile u8*)0x3E)
	#define  EEDR 	   *((volatile u8*)0x3D)
	#define  EECR	   *((volatile u8*)0x3C)
		#define  EERE   0
		#define  EEWE   1
		#define  EEMWE  2
		#define  EERIE  3

#endif
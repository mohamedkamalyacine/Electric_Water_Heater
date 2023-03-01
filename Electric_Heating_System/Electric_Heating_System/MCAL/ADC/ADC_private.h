#ifndef _MCAL_ADC_PRIVATE_H_
#define _MCAL_ADC_PRIVATE_H_

/* @Steps of Init ADC */ 
/* 
	    1- Make Channel selected I/p 
	    2- Select Conversion Speed of ADC
	    3- Select Voltage reference for ADC 
	    4- Select Type of Storing of the output
	    5- Turn on ADC
 */

/* @Steps of Reading from ADC */
/*		
		1- Activate Start of Conversion 
		2- Wait until conversion Ended
		3- Clear Interrupt Flag after Ended 
		4- Read ADCL then ADCH in order 
*/

#define ADMUX    *((volatile u8*)0x27)
	#define REFS1  7
	#define REFS0  6
	#define ADLAR  5
	#define MUX4   4
	#define MUX3   3
	#define MUX2   2
	#define MUX1   1
	#define MUX0   0
	
#define ADCSRA  *((volatile u8*)0x26)
	#define ADEN   7
	#define ADSC   6
	#define ADATE  5
	#define ADIF   4
	#define ADIE   3
	#define ADPS2  2
	#define ADPS1  1
	#define ADPS0  0

#define SFIOR    *((volatile u8*)0x50)
	#define ADTS2  7
	#define ADTS1  6
	#define ADTS0  5
	
#define ADCH     *((volatile u8*)0x25)
#define ADCL     *((volatile u8*)0x24)


#endif
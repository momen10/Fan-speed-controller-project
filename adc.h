/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR adc driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
/*some definitions, enums and structure related to adc
 * module
 */
#ifndef ADC_H_
#define ADC_H_
#define ADC_MAX_VALUE 1023
#define ADC_REF_VOLT  2.56

#include "std_types.h"

//writing values in enum according to the table
//in data sheet to insert it directly
typedef enum{
AREF, AVCC , INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum{
FCPU_2=1 ,FCPU_4,FCPU_8,FCPU_16 ,FCPU_32, FCPU_64, FCPU_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


void ADC_init (const ADC_ConfigType * adc_ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */

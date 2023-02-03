/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: source file for the AVR adc driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/

#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"
#include "std_types.h"

/*this function aim to initialize our adc
 * module according to the required settings
 * that put in our structure */

void ADC_init (const ADC_ConfigType * adc_ptr)
{
  ADMUX &= 0X3f;   //clearing REFS1 and REFS2 bits
  ADMUX |= (adc_ptr->ref_volt)<<6;

  SET_BIT(ADCSRA, ADEN);  //enabling the adc
  CLEAR_BIT(ADCSRA,ADIE); //disabling the interrupt

  ADCSRA &= 0xf8;  //clearing ADPS2, ADPS1, ADPS0
  ADCSRA |= adc_ptr->prescaler;

}

/*this function aim to read the digital value got from
 * the adc and put it in variable of type short */

uint16 ADC_readChannel(uint8 ch_num)
{
 ADMUX &= 0XE0;   //clearing first four bits
 ADMUX |= (ch_num&(0x07)); // 0000 0111 , channel number is from 0 to 7
 SET_BIT(ADCSRA ,ADSC);
 while (BIT_IS_CLEAR(ADCSRA, ADIF));  //waiting the conversion to complete (polling)
 SET_BIT(ADCSRA, ADIF);             //clearing adc flag
 return ADC;
}

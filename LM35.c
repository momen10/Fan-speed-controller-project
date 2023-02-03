/******************************************************************************
 *
 * Module: temperature sensor
 *
 * File Name: lm35.c
 *
 * Description: source file for the lm35 sensor driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
#include "LM35.h"
#include "adc.h"
#include "std_types.h"

/*the goal of this function is to get the temperature
 * read from the sensor, converting the output digital value
 * to a readable temperature in celsius */
uint8 LM35_getTemperature (void)
{
	uint8 temp_value =0;
	uint16 adc_value =0;

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
   temp_value=(uint8) ((uint32)adc_value * SENSOR_MAX_TEMP* \
		               ADC_REF_VOLT / (SENSOR_MAX_VOLT * ADC_MAX_VALUE));

   return temp_value;
}


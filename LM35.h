/******************************************************************************
 *
 * Module: temperature sensor
 *
 * File Name: lm35.h
 *
 * Description: Header file for the lm35 sensor driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"
#include "adc.h"

/*some definitions specific to
 * lm35 sensor
 */
#define SENSOR_MAX_TEMP 150
#define SENSOR_MAX_VOLT 1.5
#define SENSOR_CHANNEL_ID 2

uint8 LM35_getTemperature (void);

#endif /* LM35_H_ */

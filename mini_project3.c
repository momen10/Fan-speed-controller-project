/*
 * mini_project3.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Dell
 */
#include <util/delay.h>
#include "dc_motor.h"
#include "lcd.h"
#include "adc.h"
#include "LM35.h"

int main(void)
{
	ADC_ConfigType my_adc = {FCPU_8 ,INTERNAL};
	DCMotor_Init();
	LCD_init();
	ADC_init(&my_adc);

while(1)
{
	uint8 temp_value = LM35_getTemperature();

	if(temp_value<30)
	{
		LCD_displayStringRowColumn(0, 5, "Fan is off");
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
		LCD_moveCursor(0, 5);
		DcMotor_Rotate(CLOCKWISE, 0);
	}
	else if (temp_value<60)
	{
		LCD_displayStringRowColumn(0, 5, "Fan is on");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CLOCKWISE, 25);
		LCD_moveCursor(0, 5);
	}
	else if (temp_value <90)
	{
		LCD_displayStringRowColumn(0, 5, "Fan is on");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CLOCKWISE, 50);
		LCD_moveCursor(0, 5);
	}
	else if(temp_value<120)
	{
		LCD_displayStringRowColumn(0, 5, "Fan is on");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CLOCKWISE, 75);
		LCD_moveCursor(0, 5);
	}
	else
	{
		LCD_displayStringRowColumn(0, 5, "Fan is on");
		LCD_displayCharacter(' ');
		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp_value);
		LCD_displayCharacter('C');
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CLOCKWISE, 100);
		LCD_moveCursor(0, 5);
	}

}
}


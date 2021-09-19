/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Regs_map.h
 *
 * Description: registers map for atmega32
 *
 * Author: Mohamed AbdelAzeem
 *
 * Date : SEP,2021
 *
 *******************************************************************************/
#include "ECUAL/LCD/lcd.h"
#include "MCAL/DIO/DIO_Config.h"
#include "ECUAL/Delay/delay.h"
#include "stdlib.h"



int main(void)
{
	LCD_init();
	

	 DDRA = 0x00;
	 PORTA = 0xFF;
	 
	uint8_t BUFF[20]= {};

	// uint8_t randomNumber =rand() % 15 ;
	  uint8_t randomNumber = 4;
	 uint8_t KeyPressCounter = 0 ;
	 uint16_t TimeOutCounter = 0;
	 tostring(BUFF,randomNumber);

    while(1)
    {
	    LCD_displayStringRowColumn(0,0,"Guess Number...");
		 	
		if(BIT_IS_CLEAR(PINA,0))
		{
			KeyPressCounter++;
			if(KeyPressCounter == randomNumber)
			{
				LCD_clearScreen();
				LCD_displayStringRowColumn(0,0,"Winner...");
				LCD_displayStringRowColumn(1,0,BUFF);
			
				KeyPressCounter= 0;
				TimeOutCounter= 0;
			}
			delay_ms(700);
			LCD_clearScreen();
		}
		TimeOutCounter++;
		if(TimeOutCounter == 100 )
		{
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Loser...");
			delay_ms(3000);
			LCD_clearScreen();
			TimeOutCounter=0;
		}
    }
}
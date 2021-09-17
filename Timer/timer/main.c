/*
 * main.c
 *
 * Created: 9/4/2021 11:16:02 AM
 *  Author: Mohamed AbdelAzeem
 */ 

#include "timer.h"

/* default FCPU  = 1 Mhz */
uint32_t g_TIMER0_counter = 0 ;
void TIMER1_ISR(void)
{
		g_TIMER0_counter++;
		if(g_TIMER0_counter == 1500)
		{
			TOGGLE_BIT(PORTC, PC0);
			g_TIMER0_counter = 0;
		}	
}

int main(void)
{
	
	SET_BIT(DDRC, PC0); // Configure the led pin as output pin.
	CLEAR_BIT(PORTC, PC0); // LED is OFF at the beginning (Positive Logic).	
	
	
	
	//Interrupt
	Timer1_COMPA_ISR_setCallBack(TIMER1_ISR);
	St_Config_Timer_t timer0_config1 = {TIMER1, COMPARE_MODE_toggel , INTERNAL_CLK_PRESCALAR0_1 , DEFAULT_INITIAL_VALUE,200,CHANNEL_A};

	Timer_start(&timer0_config1);
    
	
	/*St_Config_Timer_t timer0_config1 = {TIMER1, COMPARE_MODE_toggel , INTERNAL_CLK_PRESCALAR0_1 , DEFAULT_INITIAL_VALUE,200,CHANNEL_A};

	Timer_start(&timer0_config1);*/

	

    while(1)
    {
		/*if(Timer1A_CTC_flag())
		{
			g_TIMER0_counter++;
			if(g_TIMER0_counter == 1500 )
			{
				TOGGLE_BIT(PORTC, PC0);
				g_TIMER0_counter=0;
			}
		
		}*/
		
    }
}
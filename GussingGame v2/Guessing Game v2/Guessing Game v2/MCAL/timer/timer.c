/******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.c
 *
 * Description: Source file for the Timer AVR driver
 *
 * Author: Mohamed AbdelAzeem
 *
 * Date : SEP,2021
 *
 *******************************************************************************/


#include "timer.h"
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtrTimer0OVF)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTimer0CTC)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTimer1OVF)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTimer1COMPA)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTimer1COMPB)(void) = NULL_PTR;
static volatile void (*g_callBackPtrTimer2CTC)(void) = NULL_PTR;
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/


void __vector_10(void) __attribute__((signal,used));	
void __vector_4(void) __attribute__((signal,used));
void __vector_7(void) __attribute__((signal,used));

/* timer 0 compare match ISR   */
void __vector_10(){
	
	g_callBackPtrTimer0CTC();
}
/* timer 2 compare match ISR */
void __vector_4(){
	
	g_callBackPtrTimer2CTC();
}

/* timer 1 compare match A ISR */
void __vector_7(){
	
	g_callBackPtrTimer1COMPA();
}








void Timer_start(St_Config_Timer_t* ConfigPtr)
{
	switch(ConfigPtr->timer_id)
	{
		case TIMER0:
			
			TCCR0 |= ConfigPtr->mode;
			TCCR0 |=  (ConfigPtr->prescaler & 0x07);
			TCNT0 =  ConfigPtr->initial_value;
			OCR0  = ConfigPtr->compare_value;
			
			#if INTERRUPT_MODE == STD_ON
				SET_BIT(SREG,I_BIT);
			#endif
				if(BIT_IS_SET(TCCR0, WGM01_BIT))
				{    /*Enable Interrupt for compare mode*/
					SET_BIT(TIMSK, OCIE0);
				}
				else
				{
					/*Enable Interrupt for Overflow mode*/
					SET_BIT(TIMSK, TOIE0);
				}
			
	
			break;
		case TIMER2:
			TCCR2 = ConfigPtr->mode;
			TCCR2 |=  (ConfigPtr->prescaler & 0x07);
			TCNT2 =  ConfigPtr->initial_value;
			OCR2 =  ConfigPtr->compare_value;	
			#if INTERRUPT_MODE == STD_ON
				SET_BIT(SREG,I_BIT);
			#endif
				if(BIT_IS_SET(TCCR2, WGM21_BIT))
				{    /*Enable Interrupt for compare mode*/
					SET_BIT(TIMSK, OCIE2_BIT);
				}
				else
				{
					/*Enable Interrupt for Overflow mode*/
					SET_BIT(TIMSK, TOIE2_BIT);
				}
		
			break;
		case TIMER1:
			TCNT1 = ConfigPtr->initial_value; //Set Timer initial value
			if( (ConfigPtr->mode) == NORMAL ) //Mode0
			{
				/* Configure the timer control register
				 * 1. Non PWM mode FOC1A=1 & FOC1B=1
				 * 2. Normal Mode WGM13=0 & WGM12=0 & WGM11=0 & WGM10=0
				 * 3. OC1A & OC1B disconnected COM1A1=0 & COM1A0=0 & COM1B1=0 & COM1B0=0
				 * 4. Clock Bits CS00 CS01 CS02
				 */
				#if INTERRUPT_MODE == STD_ON
					SET_BIT(SREG,I_BIT);
				#endif
					TIMSK |= (1<<TOIE1); // Enable Timer1 Overflow Interrupt
		
				TCCR1A = (1<<FOC1A) | (1<<FOC1B);
				TCCR1B |= (ConfigPtr->prescaler);
			}
			else if ((ConfigPtr->mode) == COMPARE_MODE_toggel)
			{
			    	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
			     //	SET_BIT(TCCR1B, WGM13);
			     	SET_BIT(TCCR1B, WGM12);
					if(ConfigPtr->channel == CHANNEL_A)
					{
						
						#if INTERRUPT_MODE == STD_ON
							SET_BIT(SREG,I_BIT);
						#endif
							SET_BIT(TIMSK, OCIE1A); // Enable Timer1 Compare Match Interrupt
						
						
						OCR1AL = ConfigPtr->compare_value & 0xFF;
						OCR1AH = (ConfigPtr->compare_value >> 8)  & 0xFF;
					}
					else if(ConfigPtr->channel == CHANNEL_B)
					{
						#if INTERRUPT_MODE == STD_ON
							SET_BIT(SREG,I_BIT);
						#endif
							SET_BIT(TIMSK, OCIE1B); // Enable Timer1 Compare Match Interrupt
					
						OCR1AL = ConfigPtr->compare_value & 0xFF;
						OCR1AH = (ConfigPtr->compare_value >> 8)  & 0xFF;
					}
					TCCR1B |= (ConfigPtr->prescaler);  //CLOCK SRC
			}
			break;
		}
}

/*
 * Description: Function to set the Call Back function address.
 */
void Timer0_Overflow_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer0OVF = a_ptr;
}


void Timer0_CTC_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer0CTC = a_ptr;
}

void Timer2_CTC_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer2CTC = a_ptr;
}

void Timer1_Overflow_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer1OVF = a_ptr;
}

void Timer1_COMPA_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer1COMPA = a_ptr;
}

void Timer1_COMPB_ISR_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtrTimer1COMPB = a_ptr;
}


/* Polling functions  */
uint8_t Timer0_CTC_flag()
{
	while(BIT_IS_CLEAR(TIFR,OCF0));
	SET_BIT(TIFR,OCF0);
	return 1;	
}

uint8_t Timer0_OV_flag()
{
	while(BIT_IS_CLEAR(TIFR,TOV0));
	SET_BIT(TIFR,TOV0);
	return 1;
}

uint8_t Timer2_CTC_flag()
{
	while(BIT_IS_CLEAR(TIFR,OCF2));
	SET_BIT(TIFR,OCF2);
	return 1;
}

uint8_t Timer2_OV_flag()
{
	while(BIT_IS_CLEAR(TIFR,TOV2));
	SET_BIT(TIFR,TOV2);
	return 1;
}


uint8_t Timer1A_CTC_flag()
{
	while(BIT_IS_CLEAR(TIFR,OCF1A));
	SET_BIT(TIFR,OCF1A);
	return 1;
}

uint8_t Timer1B_CTC_flag()
{
	while(BIT_IS_CLEAR(TIFR,OCF1B));
	SET_BIT(TIFR,OCF1B);
	return 1;
}
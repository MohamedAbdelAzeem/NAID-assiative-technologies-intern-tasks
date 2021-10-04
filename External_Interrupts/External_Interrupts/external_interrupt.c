/***********************************************************************
 *
 *  Module: ExternalInterrupt
 *
 *  File Name: external_interrupt.h
 *
 *  Description: Header file for AVR external interrupt module.
 *
 *  Author: Mohamed Khaled
 *
 ***********************************************************************/


/***********************************************************************
 *                      Include Module header file                      *
 ***********************************************************************/
#include "external_interrupt.h"



/***********************************************************************
 *              Include the other required header files                 *
 ***********************************************************************/
#include <avr/interrupt.h>
#include "common_macros.h" /* To use macros like SET_BIT */
#include "gpio.h"
#include <util/delay.h>


/***********************************************************************
 *                            Global Variables                          *
 ***********************************************************************/
static volatile void (*g_callBackPtrINT0)(void) = NULL_PTR;
static volatile void (*g_callBackPtrINT1)(void) = NULL_PTR;
static volatile void (*g_callBackPtrINT2)(void) = NULL_PTR;


/***********************************************************************
 *                      Local Functions Prototypes                      *
 ***********************************************************************/




/***********************************************************************
 *                          Functions Definitions                       *
 ***********************************************************************/
/*
 * Description:
 * Initializes interrupt 0 with rising edge or falling edge.
 */
void EX_INT_0_init( void )
{
	/* Define INT0 pin direction as output */
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);
	/* Enable inturrupt 0 interrupt */
	SET_BIT(GICR, EX_INT0_ENABLE_BIT);
	/* Select sense control according to configutations */
#if EX_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR, EX_INT0_SENSE_CONTROL_00);
	SET_BIT(MCUCR, EX_INT0_SENSE_CONTROL_01);
#elif EX_INT0_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCR, EX_INT0_SENSE_CONTROL_00);
	SET_BIT(MCUCR, EX_INT0_SENSE_CONTROL_01);
#endif
}


/*
 * Description:
 * Set call back function for interrupt 0
 */
void EX_INT0_setCallBackFunction(void (*callBack)(void))
{
	g_callBackPtrINT0 = callBack;
}

/*
 * Description:
 * Initializes interrupt 1 with rising edge or falling edge.
 */
void EX_INT_1_init( void )
{
	/* Define INT1 pin direction as output */
	GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_INPUT);
	/* Enable inturrupt 1 interrupt */
	SET_BIT(GICR, EX_INT1_ENABLE_BIT);
	/* Select sense control according to configutations */
#if EX_INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR, EX_INT1_SENSE_CONTROL_10);
	SET_BIT(MCUCR, EX_INT1_SENSE_CONTROL_11);
#elif EX_INT1_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCR, EX_INT1_SENSE_CONTROL_10);
	SET_BIT(MCUCR, EX_INT1_SENSE_CONTROL_11);
#endif
}


/*
 * Description:
 * Set call back function for interrupt 1
 */
void EX_INT1_setCallBackFunction(void (*callBack)(void))
{
	g_callBackPtrINT1 = callBack;
}

/*
 * Description:
 * Initializes interrupt 2 with rising edge or falling edge.
 */
void EX_INT_2_init( void )
{
	/* Define INT2 pin direction as output */
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_INPUT);
	/* Enable inturrupt 2 interrupt */
	SET_BIT(GICR, EX_INT2_ENABLE_BIT);
	/* Select sense control according to configutations */
#if EX_INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR, EX_INT2_SENSE_CONTROL);
#elif EX_INT2_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCSR, EX_INT2_SENSE_CONTROL);
#endif
}


/*
 * Description:
 * Set call back function for interrupt 2
 */
void EX_INT2_setCallBackFunction(void (*callBack)(void))
{
	g_callBackPtrINT2 = callBack;
}


/***********************************************************************
 *                              ISRs code                               *
 ***********************************************************************/
ISR(INT0_vect)
{
	if (g_callBackPtrINT0 != NULL_PTR)
	{
		(*g_callBackPtrINT0)();
	}
}

ISR(INT1_vect)
{
	if (g_callBackPtrINT1 != NULL_PTR)
	{
		(*g_callBackPtrINT1)();
	}
}

ISR(INT2_vect)
{
	if (g_callBackPtrINT2 != NULL_PTR)
	{
		(*g_callBackPtrINT2)();
	}
}



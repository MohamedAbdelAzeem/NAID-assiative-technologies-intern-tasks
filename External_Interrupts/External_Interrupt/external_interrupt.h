
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

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_


/***********************************************************************
*                       Include common modules                         *
***********************************************************************/
#include "std_types.h"
#include <avr/io.h>


/***********************************************************************
*                             Definitions                              *
***********************************************************************/
/* Define External interrupt registers */
//#define GICR   (*(volatile uint8* const) 0X5B)
//#define MCUCR  (*(volatile uint8* const) 0X55)
//#define MCUCSR (*(volatile uint8* const) 0X54)
//#define GIFR   (*(volatile uint8* const) 0X5A)

#define REG(n) (*((volatile uint8_t*)(n)))
#define  SREG				REG(0x5F)

#define EX_INT0_ENABLE_BIT   			   6
#define EX_INT0_SENSE_CONTROL_00  		   0
#define EX_INT0_SENSE_CONTROL_01  		   1

#define EX_INT0_SENSE  		  		   RISING_EDGE /* Or FALLING_EDGE*/
#define EX_INT1_SENSE       		   RISING_EDGE /* Or FALLING_EDGE*/
#define EX_INT2_SENSE   			   RISING_EDGE /* Or FALLING_EDGE*/


/***********************************************************************
*                           User defined Types                         *
***********************************************************************/




/***********************************************************************
*                global public variables and functions                 *
***********************************************************************/


/***********************************************************************
*                      Public Functions Prototypes                     *
***********************************************************************/
/*
 * Description:
 * Initializes interrupt 0 with rising edge or falling edge.
 */
void EX_INT_0_init( void );

void EX_INT_2_init( void );
void EX_INT_1_init( void );
/*
 * Description:
 * Set call back function for interrupt 0
 */
void EX_INT_setCallBackFunction(volatile void (*callBack)(void));
void EX_INT2_setCallBackFunction(void (*callBack)(void));
void EX_INT1_setCallBackFunction(void (*callBack)(void));


/***********************************************************************
*                                 Macros                               *
***********************************************************************/


#endif /* EXTERNAL_INTERRUPT_H_ */




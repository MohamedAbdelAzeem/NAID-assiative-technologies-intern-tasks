/*
 * timer.h
 *
 * Created: 9/16/2021 11:17:11 AM
 *  Author: Mohamed AbdelAzeem
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "Std_Types.h"
#include "Common_Macros.h"
#include "Regs_map.h"

#define INTERRUPT_MODE  (STD_ON)


#define DEFAULT_INITIAL_VALUE (0x00)
/* Timer ID's */
typedef enum{
	TIMER0 ,
	TIMER1, 
	TIMER2 
}en_timerId_t;

/* Timer 1 channels */
typedef enum{
	CHANNEL_A,
	CHANNEL_B
}en_TIMER_CHANNEL;

/*  Clock source   */
#define NO_CLK_SRC					    (0U)
#define INTERNAL_CLK_PRESCALAR0_1       (1U)
#define INTERNAL_CLK_PRESCALAR0_8       (2U)
#define INTERNAL_CLK_PRESCALAR0_64      (3U)
#define INTERNAL_CLK_PRESCALAR0_256     (4U)
#define INTERNAL_CLK_PRESCALAR0_1024    (5U)
#define EXTERNAL_CLK_FALLING_EDGE       (6U)
#define EXTERNAL_CLK_RISING_EDGE        (7U)

#define INTERNAL_CLK_PRESCALAR2_32       (3U)
#define INTERNAL_CLK_PRESCALAR2_64       (4U)
#define INTERNAL_CLK_PRESCALAR2_128      (5U)
#define INTERNAL_CLK_PRESCALAR2_256      (6U)
#define INTERNAL_CLK_PRESCALAR2_1024     (7U)

/* Timer modes  */
typedef enum{
		NORMAL = 0b10000000,
		COMPARE_MODE_toggel = 0b10001000,
		PHASE_CORRECT_PWM_INVERTING = 0b11110000 ,
		PHASE_CORRECT_PWM_NONINVERTING = 0b11100000,
		FAST_PWM_INVERTING = 0b11111000 ,
		FAST_PWM_NONINVERTING = 0b11101000
	}en_TIMER_MODE_t;


/* timer configuration structure  */
typedef struct{
	en_timerId_t			timer_id;
	en_TIMER_MODE_t			mode;
	uint8_t					prescaler;
	uint16_t				initial_value;
	uint16_t				compare_value;
	uint8_t					channel;
}St_Config_Timer_t;

/************************************************************************/
/*                      Function prototypes                             */
/************************************************************************/

/*******************************************************************/
/* Name       : Timer_Init
 * Description: function to start timer 
 * Input      : pointer to config structure
 * Output	  : void
 * In/Out     : void
 * Return     : Void
 *******************************************************************/
void Timer_start(St_Config_Timer_t* ConfigPtr);

/* Call  back functions */
void Timer0_Overflow_ISR_setCallBack(void(*a_ptr)(void));
void Timer0_CTC_ISR_setCallBack(void(*a_ptr)(void));
void Timer1_Overflow_ISR_setCallBack(void(*a_ptr)(void));
void Timer1_COMPA_ISR_setCallBack(void(*a_ptr)(void));
void Timer1_COMPB_ISR_setCallBack(void(*a_ptr)(void));
void Timer2_CTC_ISR_setCallBack(void(*a_ptr)(void));


uint8_t Timer0_CTC_flag();
uint8_t Timer0_OV_flag();
uint8_t Timer2_CTC_flag();
uint8_t Timer2_OV_flag();
uint8_t Timer1A_CTC_flag();
uint8_t Timer1B_CTC_flag();


#endif /* TIMER_H_ */
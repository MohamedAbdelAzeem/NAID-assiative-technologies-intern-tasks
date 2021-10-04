/*
 *
 * Module: ExternalInterrupt
 *
 * File Name: external_interrupt.c
 *
 * Description: Source file for external interrupt driver test.
 *
 * Author: Mohamed Khaled
 *
 */
#include "external_interrupt.h"
#include <avr/io.h>
#include <util/delay.h>

void test0 ( void )
{
	DDRA |= (1<<0);
	PORTA |= (1<<0);
	_delay_ms(1000);
	PORTA &= ~(1<<0);
}
void test1 ( void )
{
	DDRA |= (1<<1);
	PORTA |= (1<<1);
	_delay_ms(1000);
	PORTA &= ~(1<<1);
}

void test2 ( void )
{
	DDRA |= (1<<2);
	PORTA |= (1<<2);
	_delay_ms(1000);
	PORTA &= ~(1<<2);
}


int main ( void )
{
	SREG |= (1<<7);

	EX_INT_0_init();
	EX_INT_1_init();
	EX_INT_2_init();
	EX_INT0_setCallBackFunction(test0);
	EX_INT1_setCallBackFunction(test1);
	EX_INT2_setCallBackFunction(test2);

	while(1)
	{


	}

	return 0;
}




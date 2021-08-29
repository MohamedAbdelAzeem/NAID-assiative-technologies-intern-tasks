/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed AbdelAzeem
 */


#include "stack.h"
#include <stdio.h>
#define MAX_SIZE 10

extern uint8_t stack[MAX_SIZE]  ;
extern sint8_t stack_ptr_t  ;

void push(uint8_t u8_data)
{
	stack_ptr_t++;
	if(stack_ptr_t < MAX_SIZE )
	{
		stack[stack_ptr_t] = u8_data ;
	}
	else
	{
		stack_ptr_t = MAX_SIZE -1 ;
		printf("Stack is full, last insertion didnt complete!!\n");
	}
}
void printStack()
{
	if(stack_ptr_t == - 1)
	{
		printf("stack is empty!\n");
	}
	else
	{
		printf("stack content: \n");
		for(int i = stack_ptr_t ; i >= 0 ; i--)
		{

			printf("%d\n", stack[i] );
		}
	}
}


uint8_t pull()
{
	uint8_t temp ;
	if(stack_ptr_t >= 0 )
	{
		temp = stack[stack_ptr_t ];
		stack[stack_ptr_t] = 0 ;
		stack_ptr_t--;
	}
	return temp;
}

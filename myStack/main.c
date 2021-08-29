/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed AbdelAzeem
 */

#include <stdio.h>
#include "types.h"
#include "stack.h"


#define MAX_SIZE 10


uint8_t stack[MAX_SIZE] = {};
sint8_t stack_ptr_t = -1 ;

uint8_t* balancedParentheses(uint8_t* expression)
{
	uint8_t ans=  1;
	uint8_t* balanced = (uint8_t*)"Balanced";
	uint8_t* notbalanced = (uint8_t*)"Not Balanced";

	for (uint8_t i = 0; expression[i] != '\0'; i++)
	{
		uint8_t x = expression[i];
		if (x == '{' || x == '(' )
		{
			push(x);
		}
		else if(x == '}' || x == ')')
		{
			uint8_t top = pull();

			if ((top == '{' && x != '}') || (top== '(' && x != ')' ))
			{
				ans=  0;
				break;
			}
		}

	}

	if (!ans || stack_ptr_t != -1 )
	{
		return notbalanced;
	}
	else
	{
		return balanced;
	}
}




void application_1()
{
	uint8_t* expression1 = (uint8_t*)"(2*3+(5/2+(4*3)))";

		uint8_t* result_ptr = balancedParentheses(expression1);
		for(int i = 0 ; result_ptr[i] != '\0' ;i++)
		{
			printf("%c", result_ptr[i]);
		}
		printf("\n");

		uint8_t* expression2 =(uint8_t*) "{(2+10}}*11}";
		result_ptr = balancedParentheses(expression2);
		for(int i = 0 ; result_ptr[i] != '\0' ;i++)
		{
			printf("%c", result_ptr[i]);
		}

}

void application_2()
{
	push(1 );
	push(2);
	push(5 );

	printStack();

	push(20 );
	push(50 );
	push(60);

	printStack();

	push(15 );
	push(25 );
	push(35);
	push(45 );

	printStack();

	push(55 );

	pull();
	pull();

	printStack();

	pull();
	pull();


	printStack();


	pull();
	pull();
	printStack();


	pull();
	pull();
	pull();

	printStack();
	pull();
	printStack();
}

int main()
{

	application_2();

	//application_1();

	return 0;
}

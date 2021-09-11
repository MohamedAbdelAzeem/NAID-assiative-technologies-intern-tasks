/*
 * dio.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed AbdelAzeem
 */

#include "dio.h"
#include <stdio.h>



void main()
{
	DIO_SetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	printf("hello.");


}

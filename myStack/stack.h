/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed AbdelAzeem
 */

#ifndef STACK_H_
#define STACK_H_

#include "types.h"

#define STACK_SIZE (100)


//to use Functions bellow, you have to declare global array and stack_ptr in your application
void push(uint8_t u8_data);
uint8_t pull();
void printStack();

#endif /* STACK_H_ */

/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: ZAMALA
 */


#include <stdio.h>
#include "binarysearch.h"
#include <stdlib.h>

#define MAX_SIZE 100

uint8_t generateTestCase(uint8_t* arr)
{
	uint8_t randIndex =  rand()%100;
	printf("Test case: \n");
	for(int i=0 ; i<randIndex ; i++)
	{
		arr[i]=rand()%100;   //Generate number between 0 to 99
		printf("%d ", arr[i]);
	}
	printf("\n");
	return randIndex ;
}

int main()
{


	uint8_t arr[10] = {1,2,3,4 ,5,6 ,7,9,8,10};
	sint8_t result = myBinarySearch(arr,10 , 7);
	printf("element's Index in the sorted array is: \n");
	printf("%d\n", result);

	/*uint8_t arr[MAX_SIZE] = {};
	int numOfTests = 10 ;
	while(numOfTests--)
	{
		uint8_t size = generateTestCase(arr);
		sint8_t result = myBinarySearch(arr,size , 7);
		printf("element's Index in the sorted array is: \n");
		printf("%d\n", result);
	}*/


	return  0;
}

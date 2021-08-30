/*
 * binarysearch.c
 *
 *  Created on: Aug 30, 2021
 *      Author: ZAMALA
 */

#include "binarysearch.h"
#include <stdio.h>


sint8_t myBinarySearch(uint8_t* arr, uint8_t size, uint8_t value)
{
	if(isSorted(arr,size))
	{
		return binarySearch(arr, size, value);
	}
	else
	{
		//array is not sorted
		printf("Array is not sorted!\n");
		sortArray(arr, size);
		return binarySearch(arr, size, value);

	}
}


sint8_t binarySearch(uint8_t* arr, uint8_t size, uint8_t value)
{
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;
	uint8_t  found_Index = -1;
	while (left <= right)
	{
		if (arr[mid] == value)
		{
			//value is found
			found_Index = mid;
			return found_Index;
		}

		if (arr[mid] < value)
		{
			left = mid + 1 ;
			mid = (left + right) / 2;

		}
		else if (arr[mid] > value)
		{
			right = mid - 1;
			mid = (left + right) / 2;

		}
	}
	return found_Index;
}


uint8_t isSorted(uint8_t* arr, uint8_t size)
{
	uint8_t sorted = 1;
	for(int i = 0 ; i < size-1 ;i++)
	{
		if(arr[i] > arr[i+1])
		{
			sorted = 0;
		}
	}

	return sorted;
}

void sortArray(uint8_t* arr, uint8_t size)
{
   //Sort the array in ascending order
	uint8_t temp;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
		   if(arr[i] > arr[j]) {
			   temp = arr[i];
			   arr[i] = arr[j];
			   arr[j] = temp;
		   }
		}
	}

	printf("Sorted array is: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


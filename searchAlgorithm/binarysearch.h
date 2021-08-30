/*
 * binarysearch.h
 *
 *  Created on: Aug 30, 2021
 *      Author: ZAMALA
 */

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

typedef unsigned char uint8_t;
typedef unsigned int uint32_t ;
typedef signed char sint8_t;

sint8_t myBinarySearch(uint8_t* arr, uint8_t size, uint8_t value);
sint8_t binarySearch(uint8_t* arr, uint8_t size, uint8_t value);
uint8_t isSorted(uint8_t* arr, uint8_t size);
sint8_t binarySearch(uint8_t* arr, uint8_t size, uint8_t value);
void sortArray(uint8_t* arr, uint8_t size);

#endif /* BINARYSEARCH_H_ */

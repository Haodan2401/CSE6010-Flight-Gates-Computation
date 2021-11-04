//
//  addtional.h
//  gates
//
//  Created by Haodan Tan on 10/24/21.
//

#ifndef addtional_h
#define addtional_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *@brief    read the word txt file by relative path
 *@param path   relative path
 *@Param type   define open type
 *@Param flightSet store the flight information into the set
 */
void readFile(char* path, char* type, float* flightSet);


/**
 *@brief    judge if the element is negative
 *@param num    the value of the element
 */
int isNegative(float num);


/**
 *@brief    Set all the time of flights arrive to ATL into negative numbers, then I tranfer them into their abolute and add 0.5 before sorting all arrive time and departure time. In this condition, although the arrive time and the departure time has the same value, the arrive time would be always 0.5 large than the departure time after executing the transfer process.
 *@param num    the value of the element
 */
void transferFlight(float* flights);


/**
 *@brief    executing the insert sort
 *@param flights    the flight set
 */
void insertSort(float* flights);



/**
 *@brief    count the maximum sum and minimum sum in the flight set
 *@param flights    the flight set
 *@param max    the maximum sum of the flight set
 *@param min    the minimum sum of the flight set
 */
void countMaxAndMin(float* flights, int* max, int* min);



/**
 *@brief    swap twp numbers
 *@param a  the pointer of the first element
 *@param b  the pointer of the second element
 */
void swap(int *a, int *b);


/**
 *@brief    executing the heapify process
 *@param n  the number of element in the fight set
 */
void heapify(float* flights, int n, int i);




/**
 *@brief    executing the heap sort
 *@param flights    the flight set
 */
void heapSort(float* flights, int n);


/**
 *@brief    executing the quick sort
 *@param first    the flight set
 *@param last    the flight set
 * *@param flights    the flight set
 */
void quickSort(float* flights,int first,int last);

#endif /* addtional_h */

//
//  addtional.c
//  gates
//
//  Created by Haodan Tan on 10/24/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read the file
void readFile(char* path, char* type, float* flights){
    // read the csv file
    FILE* stream = fopen(path, type);
    int count = 0;
    char line[28];
    while (fgets(line, sizeof(line), stream))
    {
        
        char* token;
        int flag = 1;
        token = strtok(line, ",");
        
        int index = 0;
        while (token != NULL) {
            if (index == 2) {
                // if the flight departure from the ATL, flag = 1
                if (strcmp("ATL", token) == 0) {
                    flag = 1;
                }
                // if the flight arrive to the ATL, flag = 0
                else{
                    flag = 0;
                }
            }
            
            else{
                if (index == 4 && flag == 1) {
                    flights[count] = -1 * atoi(token);
                }
                // if the flight arrive at the ATL, we set the arrive time as negative flights
                if (index == 5 && flag == 0) {
                    flights[count] = atoi(token);
                    
                }// if the flight departure from the ATL, we set the depart time as positive flights
                
            }
            
            token = strtok(NULL, ",");
            index++;
        }
        count++;
    }
}


// insert sort
void insertSort(float* flights){
    int i, j;
    float key;
    for (i = 1; i < 2208; i++) {
        key = flights[i];
        j = i - 1;
        
        // insert the element into the position ahead the current postion
        while (j >= 0 && flights[j] > key) {
            flights[j + 1] = flights[j];
            j = j - 1;
        }
        flights[j + 1] = key;
    }
}


// to judge if the number is negative
int isNegative(float num){
    if (num - (int)num == 0.5){
        return 1;
    }
    else{
        return 0;
    }
}

// transfer the negative number to (negative number * -1) + 1
void transferFlight(float* flights){
    for (int i = 0; i < 2208; i++){
        if (flights[i] < 0){
            flights[i] = flights[i] * (-1) + 0.5;
        }
    }
}

// count the maximum and minimum of flights
void countMaxAndMin(float* flights, int* max, int* min){
    // record the maximum and minmum sum in the sorted flights array
    int tmp = 0;
    for (int i = 0; i < 2208; i++){
        // if the flight arrive at the ATL
        if(isNegative(flights[i]) == 0){
            tmp += 1;
            if (tmp >= *max)
                *max = tmp;
        }
        // if the flight departure from the ATL
        else{
            tmp -= 1;
            if (tmp <= *min)
                *min = tmp;
        }
    }
    *min = (*min) * (-1);
}

// swap two numbers
void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}


// execute the heapify
void heapify(float* flights, int n, int i) {
    int max = i; //Initialize max as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    
    //If left child is greater than root
    if (leftChild < n && flights[leftChild] > flights[max])
        max = leftChild;
    
    //If right child is greater than max
    if (rightChild < n && flights[rightChild] > flights[max])
        max = rightChild;
    
    //If max is not root
    if (max != i) {
        swap(&flights[i], &flights[max]);
        //heapify the affected sub-tree recursively
        heapify(flights, n, max);
    }
}


// heap sort
void heapSort(float* flights, int n) {
    //Build the heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(flights, n, i);
    
    //Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&flights[0], &flights[i]); // move the root to the end
        heapify(flights, i, 0); // execute the heapify again
    }
}


// quick sort
void quickSort(float* flights,int first,int last){
    int i, j, pivot;
    float temp;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(flights[i]<=flights[pivot]&&i<last)
                i++;
            while(flights[j]>flights[pivot])
                j--;
            if(i<j){
                temp=flights[i];
                flights[i]=flights[j];
                flights[j]=temp;
            }
        }
        
        temp=flights[pivot];
        flights[pivot]=flights[j];
        flights[j]=temp;
        quickSort(flights,first,j-1);
        quickSort(flights,j+1,last);
        
    }
}



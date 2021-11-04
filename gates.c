//
//  main.c
//  gates
//
//  Created by Haodan Tan on 10/24/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addtional.h"

/* Trick to handle the same value between arrive and departure time  */
/* I set all the time of flights arrive to ATL into negative numbers, then I transfer them into their abolute and add 0.5 before sorting all arrive time and departure time. In this condition, although the arrive time and the departure time has the same value, the arrive time would be always 0.5 large than the departure time after executing the transfer process. */


int main(int argc, char * argv[])
{
    char path[] = "flights_file.csv";
    char* type = "r";
    float flights[2208] = {0};
    int max = -1;
    int min = 10000;
    
    // read the file
    readFile(path, type, flights);
    
    // transfer all of numbers into positive, add 0.5 to the negative number
    transferFlight(flights);
    
    // read the arguments to choose the sorting method
    if (argc == 2){
        int sort_flag = atoi(argv[1]);
        
        // choose the sorting method
        // heap sort method
        if (sort_flag == 1){
            printf("If we use the heap sort method:\n");
            heapSort(flights, 2208);
        }
        // quick sort method
        else if (sort_flag == 2){
            printf("If we use the quick sort method:\n");
            quickSort(flights, 0, 2208 - 1);
        }
        // error argument control
        else{
            printf("This sort_flag is wrong! Please enter 1: insertSort/2: heapSort/3: quickSort for the sorting method.");
        }
    
    }
    // defualt insert sort method
    else{
        printf("If we use the insert sort method:\n");
        insertSort(flights);
    }
    


    // count the maximum and minimum of the flights
    countMaxAndMin(flights, &max, &min);
    printf("1) %d gates are needed to handle arrival and departure traffic at the ATL airport within the 24-hour period\n2) %d airplanes should be parked at ATL gates by midnight to ensure there are enough planes to accommodate the flight schedule for the following 24 hours.",max,min);
}



/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n){
    bool result = false;
    int first = 0;
    int middle = 0;
    int last = n;
    
    if (value >= values[first] && value <= values[last]){
        do {
            if (values[middle] == value){
                result = true;
                break;
            }
            if (value == values[first] || value == values[last]){
                result = true;
                break;
            }
            if (values[middle-1] < value && value < values[middle+1]){
                break;
            }
            
            middle = (first + last)/2;
            
            if (value < values[middle]){
                last = middle;
            } else {
                first = middle+1;
            }
        } while(true);
    }
    return result;
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n){
    unsigned int tmp = 0;
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n ; i++){
            if (values[i] > values[i+1]){
                tmp = values[i];
                values[i] = values[i+1];
                values[i+1] = tmp;
                swapped = true;
            }
        }
    }
    return;
}

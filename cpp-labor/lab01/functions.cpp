//
// Created by asus on 2023. 09. 25..
//
#include "functions.h"
#include <cmath>

int countBits(int number) {
    int count = 0;
    while (number > 0) {
        number = number & (number - 1);
    }
    return count;
}


double mean(int* array, int numElements){
    //implement the mean function
    double sum = 0; // initialize sum to 0
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    return sum / numElements;
}

double stddev(double *array, int numElements) {
    //implement the stddev function
}

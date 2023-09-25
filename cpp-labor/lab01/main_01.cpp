#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    //write a test code for the countBits function
    cout << "Test code for countbits function " << endl;

    int n = 7;
    cout << "The number of bits in " << n << " is " << countBits(n) << endl;

    n = 8;
    cout << "The number of bits in " << n << " is " << countBits(n) << endl;

    cout << "Test code for the mean function" << endl;
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/ sizeof(array[0]);
    cout << "The mean od the array is " << mean(array,size) << endl;
    //test the mean function of the array
    int emptyArray[] ={};
    size = sizeof(emptyArray)/sizeof(emptyArray[0]);
    cout << "The mean of the empty array is " << mean(emptyArray, size) << endl;

    return 0;
}

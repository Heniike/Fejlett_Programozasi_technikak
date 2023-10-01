//
// Created by asus on 2023. 09. 25..
//
#include "functions.h"
#include <sstream>
#include <cmath>
#include <utility>

int countBits(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
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
    //implement the standard deviation function
    if (numElements == 0) {
        return nan("");
    }
    double sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    double mean = sum / numElements;
    double variance = 0.0;
    for (int i = 0; i < numElements; i++) {
        variance += pow(array[i] - mean, 2);
    }
    double stdDev = sqrt(variance / numElements);
    return stdDev;
}

bool setBits(int &number, int order) {
    //implement the setBit function
    if (order < 0 || order > 31) {
        return false;
    }
    int mask = 1 << order;
    number |= mask;
    return true;

}

pair<double, double> max2(double *array, int numElements) {
    pair<double, double> result;
    if(numElements == 0){
        result.first = nan("");
        result.second = nan("");
    }
    else if(numElements == 1){
        result.first = array[0];
        result.second = array[0];
    } else{
        double m1 = array[0];
        double m2 = array[1];
        if(m1 > m2){
            result.first = m1;
            result.second = m2;
        } else{
            result.first = m2;
            result.second = m1;
        }
        for (int i = 2; i < numElements; ++i) {
            if(array[i] > m1){
                m2 = m1;
                m1 = array[i];
            }else if(array[i] > m2){
                m2 = array[i];
            }
        }
        result.first = m1;
        result.second = m2;
    }
    return result;
}

int countWords(string text) {
    istringstream iss(text);
    int countWords = 0;
    string word;
    while (iss >> word){
        countWords++;
    }
    return countWords;
}
string code(string text) {
    for (char& c : text) {
        if (isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            } else if (c == 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }
    return text;
}
string decode(string text) {
    for (char& c : text) {
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
//
    bool newWord = true;
    for (int i = 0; i < text.length(); ++i) {
        if (newWord && islower(text[i])) {
            text[i] = toupper(text[i]);
            newWord = false;
        } else if (!newWord && isupper(text[i])) {
            text[i] = tolower(text[i]);
        } else if (isspace(text[i])) {
            newWord = true;
        }
    }
    return text;
}

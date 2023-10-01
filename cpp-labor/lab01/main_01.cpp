#include <iostream>
#include "functions.h"
#include <sstream>

bool setBit(int n, int i);

using namespace std;

int main(int argc, char *argv[]) {
//    double sum = 0;
//    for (int i = 0; i < argc; ++i) {
//        istringstream iss(argv[i]);
//        double value = 0;
//        iss >> value;
//        if (!iss) {
//            cerr << "Error: " << argv[i] << " is not a number" << endl;
//        } else {
//            sum += value;
//        }
//
//    }
//    cout << "The sum of the command line arguments " << sum << endl;
//
//    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //write a test code for the countBits function
    cout << " 1.-Test code for the countBits function" << endl;
    int bit;
    for (int i = 0; i <= 127; ++i) {
        bit = countBits(i);
        cout << i << " ---> " << bit << endl;
    }
    cout << endl;

//    int n = 7;
//    cout << "the number of bits in " << n << " is " << countBits(n) << endl;
//    n = 8;
//    cout << "the number of bits in " << n << " is " << countBits(n) << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "2.The test code for the setBit function " << endl;
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBits(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "3.-test code for the mean function" << endl;
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "The mean of the array is " << mean(array, size) << endl;
    int emptyArray[] = {};
    size = sizeof(emptyArray) / sizeof(emptyArray[0]);
    cout << "the mean of the array is " << mean(emptyArray, size) << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "4.-test code for the stddev function" << endl;
    double array2[] = {1,2,3,4,5};
    size = sizeof(array2)/ sizeof(array2[0]);
    cout << "The standard deviation of the array is "<<  stddev(array2, size) << endl;
    double emptyArray2[] = {};
    size = sizeof(emptyArray2)/ sizeof(emptyArray2[0]);
    cout << "The standard deviation of the array is "<<  stddev(emptyArray2, size) << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "5.-test code for the max2 function" << endl;
    double array3[] = {1,2,3,4,5};
    size = sizeof(array3)/ sizeof(array3[0]);
    cout << "The max2 of the array is "<<  max2(array3, size).first << " and " << max2(array3, size).second << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout<< "Strings" << endl;
    cout << "1.numeric arguments" << endl;
//    double sum = 0;
//    for (int i = 0; i < argc; ++i) {
//        istringstream iss(argv[i]);
//        double value = 0;
//        iss >> value;
//        if(!iss){
//            cerr << "Error: "<< argv[i] << " is not a number" <<endl;
//        } else{
//            sum += value;
//        }
//    }
//    cout << "The sum of the command line arguments "<< sum << endl;
    istringstream inputstream("1 2 3 alma 4");
    string word;
    while(inputstream >> word){
        istringstream wordstream(word);
        double number;
        if( wordstream >> number ) {
            cout << word << ": NUMERICAL" << endl;
        } else {
            cout << word << ": TEXTUAL" << endl;
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "2.test code for the countWords function " << endl;
    string text = "I already finished my homework! ";
    cout << "The number of words in the text is " << countWords(text) << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "3.test code for the code function " << endl;
    string text2 = "Marvel studios";
    cout << "The code for " << text2 << " is " << code(text2) << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "3.test code for the decode function " << endl;
    string text3 = "Nbswfm tuvejpt";
    cout << "The code for " << text2 << " is " << decode(text3) << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "4.test code for the capitalizeWords function " << endl;
//    string text4 = "apple APPLE applE";
//    cout << "The capitalized text is " << capitalizeWords(text4) << endl;
//    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    string line;
    while (getline(cin, line)) {
        string result = capitalizeWords(line);
        cout << result << endl;
    }

}
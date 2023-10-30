#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {
    Matrix m1(2,3);
    m1.fillMatrix();
    m1.printMatrix();
    cout << "---------------------------------------" << endl;

    Matrix m3(4,4);
    m3.fillMatrix(1);
    m3.printMatrix();
    cout << "---------------------------------------" << endl;

    Matrix m2(m1); // = m1 => ugyanolyan copy konstruktor
    m2.fillMatrix();
    m2.printMatrix();
    cout << "---------------------------------------" << endl;

//    Matrix m4(move(Matrix(5,2)));
//    m4.printMatrix();
    Matrix m4(2,5);
    m4.randomMatrix(1,10);
    m4.printMatrix();
    if(m4.isSquare()){
        cout << "Negyzetes matrix" << endl;
    }else{
        cout << "Nem negyzetes matrix" << endl;
    }
    cout << m4.getRows() << " " << m4.getCols() << endl;
    cout << "---------------------------------------" << endl;

    Matrix m5(3,3);
    Matrix m6(3,3);
    m5.randomMatrix(1,10);
    m6.randomMatrix(1,10);
    m5.printMatrix();
    cout << "--------------" << endl;
    m6.printMatrix();
    cout << "--------------" << endl;

   try{
       cout << "Matrix m3 = m1 + m2: " << endl;
       Matrix m3 = (m1 + m2);
       cout << "m3: " << endl << m3 << endl;
   } catch (out_of_range& e){
       cout << e.what() << endl;
   }


    return 0;
}
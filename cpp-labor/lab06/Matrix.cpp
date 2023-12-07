//
// Created by asus on 10/30/2023.
//

#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

Matrix::~Matrix() {
    //legelso destruktor kiiratas az az ideigleneshez tartozik
    //cout << "Destruktor" << endl;
    for (int i = 0; i < mRows; ++i) {
        if(mElements[i] != nullptr){
            delete[]mElements[i];
        }
    }
    if(mElements != nullptr){
        delete[]mElements;
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
           mElements[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix &what) {
    //fizikai masolatot csinal
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }

    //masolas => memcpy val is lehet
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    //elveszi a tulajdonjogot
    //cout << "Move konstruktor" << endl;
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b-1); // return a number in the given range
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = dist(mt);
        }
    }
//    for (int i = 0; i < mRows; ++i) {
//        for (int j = 0; j < mCols; ++j) {
//            mElements[i][j] = rand() % (b - a + 1) + a;
//        }
//    }
//    for (int i = 0; i < mRows; ++i) {
//        for (int j = 0; j < mCols; ++j) {
//            random_device rd;
//            mt19937 gen(rd());
//            uniform_int_distribution<int> distribution(a, b-1);
//            int random =  distribution(gen);
//            mElements[i][j] = random;
//        }
//    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols){
        throw out_of_range("");;
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows && i < y.mRows; ++i) {
        for (int j = 0; j < x.mCols && j < y.mCols; ++j) {
            result.mElements[i][j] = (x.mElements[i][j] + y.mElements[i][j]);
        }
    }
    return result;

//    Matrix temp(x.getRows()+y.getRows(), x.getCols()+y.getCols());
//    return temp;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols){
        throw out_of_range("");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            for (int k = 0; k < x.mCols; ++k) {
                result.mElements[i][j] += x.mElements[i][k]*y.mElements[k][j];
            }
        }
    }
    return result;
}
ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &mat){
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

double *Matrix::operator[](int index) {
    if(index < 0 || index >= mRows){
        throw out_of_range("");
    }
    return mElements[index];
}
double *Matrix::operator[](int index)const {
    if(index < 0 || index >= mRows){
        throw out_of_range("");
    }
    return mElements[index];
}
Matrix &Matrix::operator=(Matrix &&mat) {
    if(this != &mat){
        this->mRows = mat.mRows;
        this->mCols = mat.mCols;
        this->mElements = mat.mElements;
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
    }
    return *this;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this != &mat){
        if(this->mRows != mat.mRows || this->mCols != mat.mCols){
            throw out_of_range("");
        }
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
    }
    return *this;
}
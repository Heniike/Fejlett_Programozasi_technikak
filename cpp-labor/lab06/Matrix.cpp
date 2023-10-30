//
// Created by asus on 10/30/2023.
//

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
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    Matrix temp;
    for (int i = 0; i < x.mRows && i < y.mRows; ++i) {
        for (int j = 0; j < x.mCols && j < y.mCols; ++j) {
            temp.mElements[i][j] = (x.mElements[i][j] + y.mElements[i][j]);
        }
    }
    return temp;

//    Matrix temp(x.getRows()+y.getRows(), x.getCols()+y.getCols());
//    return temp;
}

ostream &operator<<(ostream &os, const Matrix &mat) {

}


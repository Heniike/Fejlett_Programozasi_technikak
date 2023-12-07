//
// Created by asus on 12/7/2023.
//

//
// Created by asus on 11/9/2023.
//

#include "Polynomial.h"
#include <iostream>

using namespace std;

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->coefficients[i] = coefficients[i];
    }
}

///Copy konstruktor
Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }
}

///move konstruktor
Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;
    that.capacity;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

int Polynomial::degree() const {
    return capacity - 1;
}

double Polynomial::evaluate(double x) const {
    double result = coefficients[0];
    for (int i = 1; i < capacity; ++i) {
        result = result * x + coefficients[i];
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (capacity <= 1) {
        return Polynomial(0, new double[1]{0});
        //elso vagy annal kisebb fokszamu polinom derivaltja => 0
    }

    int derivativeDegree = capacity - 2;
    double *derivativeCoefficients = new double[derivativeDegree + 1];

    for (int i = 0; i <= derivativeDegree; ++i) {
        derivativeCoefficients[i] = coefficients[i] * (derivativeDegree - i + 1);
    }

    Polynomial derivativePolynomial(derivativeDegree, derivativeCoefficients);
    delete[] derivativeCoefficients;
    return derivativePolynomial;
}

double Polynomial::operator[](int index) const {
    if (index >= 0 && index < capacity) {
        return coefficients[index];
    } else {
        return 0.0; //alapertelmezett ertek hibas index eseten
    }
}

Polynomial operator-(const Polynomial &a) {
    int degree = a.degree();
    double *negatedCoefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        negatedCoefficients[i] = -a[i];
    }
    Polynomial negatedPolynomial(degree, negatedCoefficients);
    delete[] negatedCoefficients;
    return negatedPolynomial;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int degreeA = a.degree();
    int degreeB = b.degree();
    int maxDegree = max(degreeA, degreeB);
    double *sumCoefficients = new double[maxDegree + 1];
    for (int i = 0; i <= maxDegree; ++i) {
        sumCoefficients[i] = a[i] + b[i];
    }
    Polynomial sumPolynomial(maxDegree, sumCoefficients);
    delete[] sumCoefficients;
    return sumPolynomial;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    int degreeA = a.degree();
    int degreeB = b.degree();
    int maxDegree = max(degreeA, degreeB);
    double *differenceCoefficients = new double[maxDegree + 1];
    for (int i = 0; i <= maxDegree; ++i) {
        differenceCoefficients[i] = a[i] + b[i];
    }
    Polynomial sumPolynomial(maxDegree, differenceCoefficients);
    delete[] differenceCoefficients;
    return sumPolynomial;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int degreeA = a.degree();
    int degreeB = b.degree();
    int productDegree = degreeA + degreeB;
    double *productCoefficients = new double[productDegree + 1];
    for (int i = 0; i <= productDegree; ++i) {
        productCoefficients[i] = 0.0;
    }
    for (int i = 0; i < degreeA; ++i) {
        for (int j = 0; j < degreeB; ++j) {
            productCoefficients[i + j] += a[i] * b[j];
        }
    }

    Polynomial productPolynomial(productDegree, productCoefficients);
    delete[] productCoefficients;
    return productPolynomial;
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    int degree = what.degree();
    for (int i = degree; i >= 0; --i) {
        double coefficient = what[i];
        if (coefficient != 0) {
            if (i < degree) {
                if (coefficient > 0) {
                    out << " + ";
                } else {
                    out << " - ";
                }
            } else if (coefficient < 0) {
                out << "-";
            }
            out << abs(coefficient);
            if (i > 0) {
                out << "x";
                if (i > 1) {
                    out << "^" << i;
                }
            }
        }
    }
    return out;
}


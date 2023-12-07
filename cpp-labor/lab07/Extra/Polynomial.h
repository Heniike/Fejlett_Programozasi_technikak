//
// Created by asus on 12/7/2023.
//

#ifndef EXTRA_POLYNOMIAL_H
#define EXTRA_POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial {
// Polinom együtthatói
    double *coefficients;
// Polinom együtthatóinak a száma
    int capacity;
public:
    Polynomial(int degree, const double coefficients[]);

    Polynomial(const Polynomial &that);

    Polynomial(Polynomial &&that);

    ~Polynomial();

// Polinom fokszáma
    int degree() const;

// Polinom értéke a megadott pontban
    double evaluate(double x) const;

// Polinom deriváltja
    Polynomial derivative() const;

    double operator[](int index) const;

    friend Polynomial operator-(const Polynomial &a);

    friend Polynomial operator+(const Polynomial &a, const Polynomial &b);

    friend Polynomial operator-(const Polynomial &a, const Polynomial &b);

    friend Polynomial operator*(const Polynomial &a, const Polynomial &b);

    friend ostream &operator<<(ostream &out, const Polynomial &what);

/* copy assignment - mély másolat letiltása értékadásra nézve */
    Polynomial &operator=(const Polynomial &) = delete;

/* move assignment - sekély másolat letiltása értékadásra nézve */
    Polynomial &operator=(Polynomial &&) = delete;
};

#endif //EXTRA_POLYNOMIAL_H

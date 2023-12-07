#include "Polynomial.h"
#include <iostream>

using namespace std;

int main() {
    // Példa polinom létrehozása: 2x^3 - 3x^2 + x - 5
    double coefficients[] = {2, -3, 1, -5};
    Polynomial poly(3, coefficients);

    cout << "Polynomial: " << poly << endl;
    cout << "Degree: " << poly.degree() << endl;

    double x = 2.5;
    cout << "Polynomial evaluated at x = " << x << ": " << poly.evaluate(x) << endl;

    Polynomial derivativePoly = poly.derivative();
    cout << "Derivative: " << derivativePoly << endl;

    Polynomial negatedPoly = -poly;
    cout << "Negated Polynomial: " << negatedPoly << endl;

    double coefficients2[] = {1, 0, -2};
    Polynomial poly2(2, coefficients2);
    cout << "Second Polynomial: " << poly2 << endl;

    Polynomial sumPoly = poly + poly2;
    cout << "Sum: " << sumPoly << endl;

    Polynomial differencePoly = poly - poly2;
    cout << "Difference: " << differencePoly << endl;

    Polynomial productPoly = poly * poly2;
    cout << "Product: " << productPoly << endl;

    return 0;
}
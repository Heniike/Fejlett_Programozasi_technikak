#include <iostream>
#include "Point.h"
#include "util.h"


using namespace std;

int main() {
//    Point p1(2,3);
//    p1.print();
//    cout << endl;
//    Point p2(100, 200);
//    p2.print();
//    cout << endl;
//
//    Point * pp1 = new Point(300, 400);
//    Point * pp2 = new Point(500, 1000);
//    pp1->print();
//    cout<< endl;
//    pp2->print();
//    cout << endl;
//
//    delete pp1;
//    delete pp2;

    testIsSquare("points.txt");

    int numPoints = 10;
    Point *points = createArray(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % 50, rand() % 50);
    }
    printArray(points, numPoints);
    sortPoints(points, numPoints);
    printArray(points, numPoints);

    return 0;

}

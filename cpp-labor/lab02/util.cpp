//
// Created by asus on 2023. 10. 02..
//
#include "util.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

double distance(const Point &a, const Point &b) {
    //implement this distance function
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    //implement this isSquare function
    return distance(a, b) == distance(c, d);
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file) {
        //sikertelen megnyitas
        cerr << "File not found" << endl;
        return;
    }
    while (true) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (!file) {
            break;
        }
        Point p1(x1, y1);
        Point p2(x2, y2);
        Point p3(x3, y3);
        Point p4(x4, y4);
        p1.print();
        cout << " ";
        p2.print();
        cout << " ";
        p3.print();
        cout << " ";
        p4.print();
        cout << ": ";

        if (isSquare(p1, p2, p3, p4)) {
            cout << "square" << endl;
        } else {
            cout << "not square" << endl;
        }
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    return points;
}

void deletePoints(Point *points) {
    if(points != nullptr){
        delete[] points;
    }
}

bool compareX(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}


void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, compareX);

}

void printArray(Point *points, int numPoints) {
    for(int i = 0; i < numPoints; i++){
        points[i].print();
        cout << " ";
    }
    cout << endl;
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {

    for (int i = 0; i < numPoints; i++) {

    }
    cout<< " ";

}


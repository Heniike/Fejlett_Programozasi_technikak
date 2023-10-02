//
// Created by asus on 2023. 10. 02..
//

#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H

#include "Point.h"
#include <utility>

using namespace std;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void deletePoints(Point* points);
void sortPoints(Point* points, int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);



#endif //LAB2_UTIL_H

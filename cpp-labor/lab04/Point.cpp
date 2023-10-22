//
// Created by asus on 10/16/2023.
//

#include "Point.h"
#include <math.h>

Point::Point(int x, int y) {
    if(x >= 0 && x <= M && y >= 0 && y <= M){
        this->x = x;
        this->y = y;
    }else{
        this->x = 0;
        this->y = 0;
    }
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
}

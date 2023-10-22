//
// Created by asus on 10/16/2023.
//

#include "PointSet.h"
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;
bool exists[M+1][M+1] {false};

PointSet::PointSet(int n) {
    this->n = n;
    this->points.reserve(n);
    this->distances.reserve(n*(n-1)/2);

    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range, dist-objektum

    while(points.size() < n){
        int x = dist(mt);
        int y = dist(mt);
        //CSak kulonbozo pontok
        if(exists[x][y]) {
            continue;
        }

        //bool exists[M+1][M+1] {false}; => exists[x][y] = true
        this->points.push_back(Point (x, y)); //ideiglenes objektum x,y, majd masolatot keszit, meghivodott a destruktor, eltuntek az ideiglenes obj
    }

    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b){
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b){
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    sortDistances();
    return unique(distances.begin(), distances.end()) - distances.begin();
}

//
// Created by asus on 12/8/2023.
//

#ifndef LAB11_STUDENTSERVICE_H
#define LAB11_STUDENTSERVICE_H
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const string& subject) const = 0;
    virtual vector<string> getSubjects(int id) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;
};


#endif //LAB11_STUDENTSERVICE_H

//
// Created by asus on 12/8/2023.
//

#include <stdexcept>
#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    return dao->numEnrolled() > 0 && dao->findById(id).getId() == id;
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    try{
        auto grades = dao->findById(id).getGrades();
        vector<string> subjects;
        for(const auto &grade : grades){
            subjects.push_back(grade.first);
        }
        return subjects;
    }catch(out_of_range &e){
        return {};
    }
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return dao->findById(id).getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    return dao->findById(id).getAverage() >= 6;

}



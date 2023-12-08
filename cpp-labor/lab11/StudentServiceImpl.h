//
// Created by asus on 12/8/2023.
//

#ifndef LAB11_STUDENTSERVICEIMPL_H
#define LAB11_STUDENTSERVICEIMPL_H

#include "GraduationDao.h"
#include "StudentService.h"


class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {}
    virtual bool isEnrolled(int id) const override;
    vector<string> getSubjects(int id) const override;
    double getResultBySubject(int id, const string& subject) const override;
    double getAverage(int id) const override;
    bool isPassed(int id) const override;
};



#endif //LAB11_STUDENTSERVICEIMPL_H

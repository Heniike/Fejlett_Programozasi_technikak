//
// Created by asus on 12/4/2023.
//

#include <fstream>
#include "GraduationDao.h"
#include <iostream>
#include <map>

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if(!file){
        cout << "File not found" << endl;
        exit(1);
    }
    int id;
    int firstName, lastName;
    while(file >> id >> firstName >> lastName){
        Student student(id, to_string(firstName), to_string(lastName));
        students.insert(pair<int, Student>(id, student));
    }
    file.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
//    ofstream file(filename);
//    if(!file){
//        cout << "File not found" << endl;
//        exit(1);
//    }
//    for(auto it = students.begin(); it != students.end(); it++){
//        file << it->second.getGrade(subject) << endl;
//    }
//    file.close();
    ifstream file(filename);
    if(!file){
        cout << "File not found" << endl;
        exit(1);
    }
    double grade;
    int id;
    while(file >> id >> grade){
        students.at(id).addGrade(subject, grade);
    }
    file.close();
}

void GraduationDao::computeAverage() {
    for(auto it = students.begin(); it != students.end(); it++){
        it->second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for(auto it = students.begin(); it != students.end(); it++){
        if(it->second.getAverage() >= 6){
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    if(!students.count(id)){
        throw out_of_range("Student not found");
    }
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
   for(auto it = students.begin(); it != students.end(); it++){
       sum += it->second.getAverage();
       //sum += it->second.getGrade(subject);
       if(it->second.getAverage() < 6){
           return 0;
       }
   }
    return sum / students.size();
}

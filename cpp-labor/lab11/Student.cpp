//
// Created by asus on 12/4/2023.
//

#include <stdexcept>
#include <iostream>
#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) :
        id(id), firstName(firstName), lastName(lastName) {}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    //grades[subject] = grade;
    grades.emplace(subject, grade);
}

double Student::getGrade(const string &subject) {
    if (grades.find(subject) == grades.end()) {
        throw out_of_range("Subject not found");
    }
    return grades.at(subject);
    //return grades[subject];
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    double sum = 0;
    for (auto it = grades.begin(); it != grades.end(); it++) {
        if (it->second < 5) {
            return;
        }
        sum += it->second;
    }
    average = sum / (double) grades.size();
    if (average < 6) {
        return;
    }
    this->average = average;
}

double Student::getAverage() const {
    return average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.id << ": " << student.firstName << " " << student.lastName << " " <<
       "\ngrades:\n";
    for (auto it = student.grades.begin(); it != student.grades.end(); it++) {
        os << "\t" << it->first << " - " << it->second << "\n";
    }
    os << "average: " << student.average << endl;
    return os;
}



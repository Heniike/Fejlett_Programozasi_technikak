//
// Created by asus on 11/13/2023.
//

#ifndef INFOB_PROJECT_H
#define INFOB_PROJECT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Developer.h"
using namespace std;

class Project {
public:
    Project(std::string name, int startYear, int endYear);

    ~Project();

    friend std::ostream& operator<<(std::ostream& os, const Project& project);

    void addDeveloper(Developer* developer);

    // Getter függvények
    int getId() const;
    std::string getName() const;
    int getStartYear() const;
    int getEndYear() const;
    const std::vector<Developer*>& getDevelopers() const;

private:
    static int nextId;
    int id;
    string name;
    int startYear;
    int endYear;
    vector<Developer*> *developers;
};





#endif //INFOB_PROJECT_H

//
// Created by asus on 11/13/2023.
//

#ifndef INFOB_COMPANY_H
#define INFOB_COMPANY_H

#include "developer.h"
#include "project.h"

class Company {
public:
    void addProject(const Project& project);
    void addDeveloper(const Developer& developer);
    void readProjectsFromFile(const std::string& filename);
    void readDevelopersFromFile(const std::string& filename);
    void readProjectsDevelopersFromFile(const std::string& filename);

    void printDevelopers() const;
    void printProjects() const;
    void printActiveProjects() const;
    void printDevelopersOrderedBySalary();
    void printDevelopersOrderedByName();
    void printProjectsOrderedByStartYearAndName();
    Developer* getDeveloperWithMaxProjects() const;

private:
    std::vector<Project> projects;
    std::vector<Developer> developers;
};


#endif //INFOB_COMPANY_H

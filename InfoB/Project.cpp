//
// Created by asus on 11/13/2023.
//

#include "Project.h"
int Project:: nextId = 0;

Project::Project(string name, int startYear, int endYear) : id(++nextId), name(name), startYear(startYear), endYear(endYear) {
    developers = new vector<Developer*>();
}

Project::~Project() {
    delete developers;
}

ostream& operator<<(ostream& os, const Project& project) {
    os << "ID: " << project.id << ", Name: " << project.name << ", Start Year: " << project.startYear << ", End Year: " << project.endYear << "\nDevelopers: ";
    for (const auto& developer : *(project.developers)) {
        os << developer->getName() << " ";
    }
    return os;
}

void Project::addDeveloper(Developer* developer) {
    developers->push_back(developer);
}

int Project::getId() const {
    return id;
}

std::string Project::getName() const {
    return name;
}

int Project::getStartYear() const {
    return startYear;
}

int Project::getEndYear() const {
    return endYear;
}

const std::vector<Developer*>& Project::getDevelopers() const {
    return *developers;
}
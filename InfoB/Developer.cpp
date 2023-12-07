//
// Created by asus on 11/13/2023.
//

#include "Developer.h"
int Developer:: nextID = 0;

Developer::Developer(string name, int salary, Level level) :
    id(++nextID), name(name), salary(salary),level(level){}

ostream &operator<<(ostream &os, const Developer &developer) {
    os << "ID: " << developer.id << ", Name: " << developer.name << ", Salary: " << developer.salary << ", Level: "<< developer.level;
    return os;
}
int Developer::getId() const {
    return id;
}

std::string Developer::getName() const {
    return name;
}

int Developer::getSalary() const {
    return salary;
}

Level Developer::getLevel() const {
    return level;
}
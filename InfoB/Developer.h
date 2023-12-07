//
// Created by asus on 11/13/2023.
//

#ifndef INFOB_DEVELOPER_H
#define INFOB_DEVELOPER_H
#include <string>
#include <iostream>

using namespace std;

enum Level{JUNIOR, MID, SENIOR};

class Developer {
public:
    Developer(string name, int salary, Level level);
    friend ostream& operator<<(ostream &os, const Developer& developer);
    int getId() const;
    string getName() const;
    int getSalary() const;
    Level getLevel() const;

private:
    static int nextID;
    int id;
    string name;
    int salary;
    Level level;
};






#endif //INFOB_DEVELOPER_H

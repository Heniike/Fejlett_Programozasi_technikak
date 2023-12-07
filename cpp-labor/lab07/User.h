//
// Created by asus on 12/7/2023.
//

#ifndef EXTRA_USER_H
#define EXTRA_USER_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class User {
private:

    int id;
    string name;
    map<string, double> scores;
    static int counter;

public:
    User(const string &name);

    int getId() const;

    const string &getName() const;

    void addScore(const string &quizName, double score);

    double getScore(const string &quizName) const;

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const User &user);
};



#endif //EXTRA_USER_H

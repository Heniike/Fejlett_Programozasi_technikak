//
// Created by asus on 12/7/2023.
//
#include <iostream>
#include "User.h"

using namespace std;

int User::counter = 0;

User::User(const string &name) {
    this->id = counter++;
    this->name = name;
}

int User::getId() const {
    return id;
}

const string &User::getName() const {
    return name;
}

void User::addScore(const string &quizName, double score) {
    scores.insert(pair<string, double>(quizName, score));
}

double User::getScore(const string &quizName) const {
    return scores.at(quizName);
}

void User::print(ostream &os) const {
    os << "User: " << name << endl;
    os << "Scores: " << endl;
    for (auto &score : scores) {
        os << score.first << ": " << score.second << endl;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    os << "User: " << user.name << endl;
    os << "Scores: " << endl;
    for (auto &score : user.scores) {
        os << score.first << ": " << score.second << endl;
    }
    return os;
}


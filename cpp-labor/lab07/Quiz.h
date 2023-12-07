//
// Created by asus on 12/7/2023.
//

#ifndef EXTRA_QUIZ_H
#define EXTRA_QUIZ_H

#include <stdio.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "Question.h"

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;

    void readQuestions(const string &filename);

public:
    Quiz(const string &name) {
        this->name = name;
        readQuestions(name + ".txt");
    };

    string getName() const { return name; }

//    vector<Question> getQuestions() const { return questions; }

    int getNumberOfQuestions() const { return questions.size(); }

    const Question &getQuestion(int index) const {
        if(index < 0 || index >= questions.size())
            throw out_of_range("Index out of range");
        return questions[index];
    }
};



#endif //EXTRA_QUIZ_H

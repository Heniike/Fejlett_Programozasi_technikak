//
// Created by asus on 10/23/2023.
//

#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

#include <string>
#include "Answer.h"
#include <vector>

using namespace std;

class Question {
private:
    string text;
    vector<Answer> answers;
public:
    Question() = default;
    void setText(const string &text) { this->text = text; }
    void setAnswers(const vector<Answer> &answers) { this->answers = answers; }
    string getText() const { return text; }
    vector<Answer> getAnswers() const { return answers; }

//    Question() = default; //default konstruktor
//    void setText(const string &text) {
//        this->text = text;
//    }
//
//    string getText() const { // a getterek konstans tagfuggvenyek
//        return text;
//    }
//
//    void setAnswers(const vector<Answer> &answers) {
//        this->answers = answers;
//    }
//
//    vector<Answer> getAnswers() const {
//        return answers;
//    }

};


#endif //LAB5_QUESTION_H

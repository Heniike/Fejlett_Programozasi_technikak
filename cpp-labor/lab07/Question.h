//
// Created by asus on 12/7/2023.
//

#ifndef EXTRA_QUESTION_H
#define EXTRA_QUESTION_H

#include <string>
#include <vector>
#include "Answer.h"


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
    Answer getAnswer(const int index) const { return answers[index]; }

};


#endif //EXTRA_QUESTION_H

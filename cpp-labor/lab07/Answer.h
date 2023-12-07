//
// Created by asus on 12/7/2023.
//

#ifndef LAB7_ANSWER_H
#define LAB7_ANSWER_H

#include <string>

using namespace std;

class Answer {
private:
    string text;
    bool isCorrect;
public:
    Answer(string text = "", bool isCorrect = false) : text(text), isCorrect(isCorrect) {}
    string getText() const { return text; }
    void setText(const string &text) { this->text = text; }
    bool getIsCorrect() const { return isCorrect; }
    void setIsCorrect(const bool &isCorrect) { this->isCorrect = isCorrect; }
};


#endif //LAB7_ANSWER_H

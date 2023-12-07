//
// Created by asus on 10/23/2023.
//

#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H

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
//    //implicit kezdoertekkel egyparameter lesz
//    Answer(string answer = "", bool correct = false) :
//            text(answer), correct(correct) {}
//
//    void setText(const string text) {
//        this->text = text;
//    }
//
//    void setCorrect(bool correct) { //primitiv  tipus
//        this->correct = correct;
//    }
//
//    string getText() {
//        return text;
//    }
//
//    bool getCorrect() {
//        return correct;
//    }
};

#endif //LAB5_ANSWER_H

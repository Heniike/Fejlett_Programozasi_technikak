//
// Created by asus on 10/23/2023.
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include <vector>
#include <string>
#include <stdexcept>
#include "Question.h"

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;

    void readQuestions(const string& fileName);

public:
    Quiz(const string& name, const string& fileName){
        this->name = name;
        readQuestions(fileName);
    }
    string getName() const{
        return name;
    }
//    vector<Question> getQuestions() const{
//        return questions;
//    }
    int getNumberOfQuestions() const{
        return questions.size();
    }
    const Question &getQuestion(int index) const{ //const az elejen es referencia, mert garantalja, hogy nem keszit masolatot
        if(index < 0 || index >= questions.size()){
            throw out_of_range("Index out of range");
        }
        return questions[index];
    }
};


#endif //LAB5_QUIZ_H

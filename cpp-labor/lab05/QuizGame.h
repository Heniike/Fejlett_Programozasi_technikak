//
// Created by asus on 10/23/2023.
//

#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include <string>
#include "Answer.h"
#include <vector>
#include <stdexcept>
#include "Question.h"
#include "Quiz.h"

using namespace std;

class QuizGame {
private:
    vector<string> playersName;
    int score;



public:

    QuizGame(const vector<string> &name, int score = 0) {
        this->playersName = name;
        this->score = score;

    }

    string getName() const {
        return playersName[0];
    }

    int getScore() const {
        return score;
    }

//    const vector<string> &getPlayersName(int index) const {
//        if(index < 0 || index >= playersName.size()){
//            throw out_of_range("Index out of range");
//        }
//        return playersName[index];
//    }

    void playQuiz(Quiz &quiz, vector<string>& playersName);
};


#endif //LAB5_QUIZGAME_H

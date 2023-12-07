//
// Created by asus on 10/23/2023.
//

#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include <string>
#include "Quiz.h"

using namespace std;

class QuizGame {
private:
    const Quiz& quiz;
    int score;

    //vector<string> QuizName;

public:
        QuizGame(const Quiz &quiz, int score = 0) : quiz(quiz), score(score){};
        void playQuiz();
        int getScore() const { return score; }


//    QuizGame(const vector<string> &name, int score = 0) {
//        this->QuizName = name;
//        this->score = score;
//        this->playersName.resize(name.size());
//    }

//    string getName() const {
//        return QuizName[0];
//    }
//
//    const vector<string> &getPlayersName(int index) const {
//        if(index < 0 || index >= playersName.size()){
//            throw out_of_range("Index out of range");
//        }
//        return playersName[index];
//    }

};


#endif //LAB5_QUIZGAME_H

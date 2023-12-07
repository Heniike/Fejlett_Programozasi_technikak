//
// Created by asus on 12/7/2023.
//

#ifndef EXTRA_QUIZGAME_H
#define EXTRA_QUIZGAME_H


#include "Quiz.h"
#include "User.h"

class QuizGame {
private:
    User &user;
    const Quiz &quiz;
    double score = 0;
public:
    QuizGame(User &user, const Quiz &quiz) : user(user), quiz(quiz) {};

    void play();

    double getScore() const { return score; }

    User getUser() const { return user; }

    Quiz getQuiz() const { return quiz; }
};


#endif //EXTRA_QUIZGAME_H

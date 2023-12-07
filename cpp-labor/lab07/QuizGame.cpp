//
// Created by asus on 12/7/2023.
//

#include <iostream>
#include <sstream>
#include "QuizGame.h"

using namespace std;

void QuizGame::play() {
    cout << user.getName() << "! You are playing " << quiz.getName() << "!" << endl;
    for (int i = 0; i < quiz.getNumberOfQuestions(); ++i) {
        cout << "\nQuestion " << i + 1 << ": " << quiz.getQuestion(i).getText() << endl;
        int numberOfAnswer = 0;
        for (Answer &a: quiz.getQuestion(i).getAnswers()) {
            cout << numberOfAnswer + 1 << ".) " << a.getText() << endl;
            numberOfAnswer++;
        }
        cout << "Enter the correct answer(s), than press ENTER" << endl;
        string userInputAnswers;
        getline(cin, userInputAnswers);
        istringstream iss(userInputAnswers);
        int answer;
        bool ok = false;
        while (iss >> answer) {
            if (answer < 1 or answer > numberOfAnswer) {
                continue;
            }
            if (quiz.getQuestion(i).getAnswer(answer - 1).getIsCorrect()) {
                score += 1.00 / quiz.getNumberOfQuestions();
                ok = true;
            }
        }
        if (ok) {
            cout << "Congrats! Your answer was correct!" << endl;
        } else {
            cout << "Sorry! Your answer was incorrect!" << endl;
        }
    }
    user.addScore(quiz.getName(), score);
}

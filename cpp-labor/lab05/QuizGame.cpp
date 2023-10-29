//
// Created by asus on 10/23/2023.
//

#include "QuizGame.h"
#include <iostream>
#include "Quiz.h"

void QuizGame::playQuiz(Quiz &quiz, vector<string> &playersName) {
    cout << "--------------------------------------\n";
    cout << "\n\n\tWelcome to the quiz game!" << endl;
    for (int i = 0; i < playersName.size(); ++i) {
        cout << "\n\n\tTHE PLAYER'S NAME IS: " << playersName[i] << endl;
        for (int i = 0; i < quiz.getNumberOfQuestions(); ++i) {
            cout << "\nQUESTION:\n " << i+1 << ": " << quiz.getQuestion(i).getText() << endl;
            cout << "\tANSWERS:\n ";
            for (int j = 0; j < quiz.getQuestion(j).getAnswers().size(); ++j) {
                cout << "\t\t" <<(j+1) << ". " << quiz.getQuestion(i).getAnswers()[j].getText() << endl;
            }
            int userAnswer;
            cout << "Enter your answer(1-  " << quiz.getQuestion(i).getAnswers().size() << "): ";
            cin >> userAnswer;
            userAnswer--;
            cout << "\n--------------------------------------\n";

            if(userAnswer >= 0 && userAnswer < quiz.getQuestion(i).getAnswers().size()){
                if (quiz.getQuestion(i).getAnswers()[userAnswer].getCorrect()){
                    cout << "Correct!" << endl;
                    score++;
                }else{
                    cout << "Incorrect!" << endl;
                }
            }
            cout << "\n--------------------------------------\n";



        }
        cout << playersName[i] << "'s score: " << score << endl;
    }

}

//
// Created by asus on 10/23/2023.
//

#include "QuizGame.h"
#include <iostream>

void QuizGame::playQuiz() {
    int numQuestions = quiz.getNumberOfQuestions();
    for (int i = 0; i < numQuestions; i++) {
        auto &question = quiz.getQuestion(i);
        cout << "\nQuestion " << (i + 1) << ": " << question.getText() << endl;
        for (int j = 0; j < question.getAnswers().size(); j++) {
            cout << "\tAnswer " << (j + 1) << ": " << question.getAnswers()[j].getText() << endl;
        }
        cout << "Choose the correct answers(s)!" << endl;
        cout << "Enter your answer, than press enter. Enter 0 to finish adding answers." << endl;
        int userInput, userNumberfCorrectAnswers = 0;
        int numCorrectAnswers = 0;
        cin >> userInput;
        while (userInput != 0) {
            if (question.getAnswers()[userInput - 1].getIsCorrect()) {
                userNumberfCorrectAnswers++;
            }
            cin >> userInput;
        }
        cout << "You have finished the " << i + 1 << "th " << "question!" << endl;
        for (int j = 0; j < question.getAnswers().size(); ++j) { //get how many answers to this question are correct
            if (question.getAnswers()[j].getIsCorrect()) {
                numCorrectAnswers++;
            }
        }
        if (userNumberfCorrectAnswers == numCorrectAnswers) {
            cout << "You have answered correctly!" << endl;
            score++;
        } else {
            cout << "You have answered incorrectly!" << endl;
        }
    }
}
//void QuizGame::playQuiz(Quiz &quiz, vector<string> &playersName) {
//    cout << "--------------------------------------\n";
//    cout << "\n\n\tWelcome to the quiz game!" << endl;
//    for (int i = 0; i < playersName.size(); ++i) {
//        cout << "\n\n\tTHE PLAYER'S NAME IS: " << playersName[i] << endl;
//        for (int i = 0; i < quiz.getNumberOfQuestions(); ++i) {
//            cout << "\nQUESTION:\n " << i+1 << ": " << quiz.getQuestion(i).getText() << endl;
//            cout << "\tANSWERS:\n ";
//            for (int j = 0; j < quiz.getQuestion(j).getAnswers().size(); ++j) {
//                cout << "\t\t" <<(j+1) << ". " << quiz.getQuestion(i).getAnswers()[j].getText() << endl;
//            }
//            int userAnswer;
//            cout << "Enter your answer(1-  " << quiz.getQuestion(i).getAnswers().size() << "): ";
//            cin >> userAnswer;
//            userAnswer--;
//            cout << "\n--------------------------------------\n";
//
//            if(userAnswer >= 0 && userAnswer < quiz.getQuestion(i).getAnswers().size()){
//                if (quiz.getQuestion(i).getAnswers()[userAnswer].getCorrect()){
//                    cout << "Correct!" << endl;
//                    score++;
//                }else{
//                    cout << "Incorrect!" << endl;
//                }
//            }
//            cout << "\n--------------------------------------\n";
//
//
//
//        }
//        cout << playersName[i] << "'s score: " << score << endl;
//    }
//
//}

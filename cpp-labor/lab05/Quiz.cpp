//
// Created by asus on 10/23/2023.
//

#include "Quiz.h"
#include <fstream>
#include <iostream>
#include <iosfwd>
#include <sstream>

using namespace std;

void Quiz::readQuestions(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        exit(1);
    }

    string line;
    Question question;
    vector<Answer> answers;

    while (getline(file, line)) {
        switch (line[0]) {
            case 'Q': {
                question.setText(line.substr(2));
                answers.clear(); //reseteljuk a tombot
                break;
            }
            case 'A': {
                answers.push_back(Answer(line.substr(2)));
                break;
            }
            default: {
                istringstream iss(line);
                int val;
                while (iss >> val) {
                    answers[val - 1].setCorrect(true);
                }
                question.setAnswers(answers);
                questions.push_back(question);
                break;
            }
        }
    }
}

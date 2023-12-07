//
// Created by asus on 12/7/2023.
//

#include "Quiz.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void Quiz::readQuestions(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }
    string line;
    Question question;
    vector<Answer> answers;
    while (getline(file, line)) {
        switch (line[0]) {
            case 'Q': {
                question.setText(line.substr(2));
                answers.clear();
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
                    answers[val - 1].setIsCorrect(true);
                }
                question.setAnswers(answers);
                questions.push_back(question);
                break;
            }
        }
    }

}



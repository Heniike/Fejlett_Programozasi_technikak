#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

int main() {
    Quiz quiz("Quiz", "quiz.txt");
    cout << quiz.getName() << endl;
    cout << quiz.getNumberOfQuestions() << endl;

    int num_questions = quiz.getNumberOfQuestions();
    for (int i = 0; i < num_questions; ++i) {
        auto &question = quiz.getQuestion(i);
        cout << (i+1) << ". " << question.getText() << endl;

        for (int j = 0; j < question.getAnswers().size(); ++j) {
            cout << "\t" << (j+1) << ". " << question.getAnswers()[j].getText() << endl;
        }
        cout << "Pick the correct answers! " << endl;
    }

    cout << "\n--------------------------------------\n";

    vector<string> playersName = {"Henike", "Kinga", "Alpar"};
    QuizGame quizGame(playersName, 0);


    cout << "\n--------------------------------------\n";

    quizGame.playQuiz(quiz, playersName);

    return 0;
}
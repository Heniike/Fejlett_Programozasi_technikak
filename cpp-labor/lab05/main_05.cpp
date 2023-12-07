#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

int main() {
    Quiz quiz("quiz.txt", "quiz2.txt");
    QuizGame quizGame(quiz);
    cout << "Quiz name: " << quiz.getName() << endl;
    cout << "Number of questions: " << quiz.getNumberOfQuestions() << endl;
    cout << "Do you want to start the quiz? y/n " << endl;
    char startCom;
    cin >> startCom;
    if(startCom == 'n'){
        cout << "You have exited the quiz!" << endl;
        return 0;
    }
    cout << "Starting quiz..." << endl;
    quizGame.playQuiz();
    cout << "\nCongrats! You have finished the quiz with " << quizGame.getScore() << " points!" << endl;

//    Quiz quiz("Quiz", "quiz.txt");
//    cout << quiz.getName() << endl;
//    cout << quiz.getNumberOfQuestions() << endl;
//
//    int num_questions = quiz.getNumberOfQuestions();
//    for (int i = 0; i < num_questions; ++i) {
//        auto &question = quiz.getQuestion(i);
//        cout << (i+1) << ". " << question.getText() << endl;
//
//        for (int j = 0; j < question.getAnswers().size(); ++j) {
//            cout << "\t" << (j+1) << ". " << question.getAnswers()[j].getText() << endl;
//        }
//        cout << "Pick the correct answers! " << endl;
//    }
//
//    cout << "\n--------------------------------------\n";
//
//    vector<string> playersName = {"Henike", "Kinga", "Alpar"};
//    QuizGame quizGame(playersName, 0);
//
//
//    cout << "\n--------------------------------------\n";
//
//    quizGame.playQuiz(quiz, playersName);

    return 0;
}
#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

using namespace std;

int main() {
    User users[] = {User("Henike"), User("Kinga")};
    Quiz quizzes[] = {Quiz("quiz"), Quiz("quiz2")};
    int num_users = sizeof(users) / sizeof(users[0]);
    int num_quizzes = sizeof(quizzes) / sizeof(quizzes[0]);
    for (int i = 0; i < num_users; ++i) {
        for (int j = 0; j < num_quizzes; ++j) {
            QuizGame game(users[i], quizzes[j]);
            game.play();
            cout << "Quiz: " << game.getQuiz().getName() << endl;
            cout << "Name: " << game.getUser().getName() << ", score: " << game.getScore() << endl << endl;
        }
    }
    cout << endl << "****************" << endl;
    cout << "Users' results:" << endl << endl;
    for (int i = 0; i < num_users; ++i) {
        cout << users[i] << endl;
    }
    cout << "****************" << endl;
    return 0;
}
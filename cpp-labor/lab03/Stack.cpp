//
// Created by asus on 10/22/2023.
//
#include "Stack.h"
#include <stdexcept>

using namespace std;

Stack::Stack() {
    // Konstruktor
    cout << "Stack constructor called." << endl;
}

Stack::~Stack() {
    // Destruktor
    cout << "Stack destructor called." << endl;
}

void Stack::push(int e) {
    list.insertFirst(e);
}

int Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty, cannot pop.");
    }
    return list.removeFirst();
}

bool Stack::isEmpty() const {
    return list.empty();
}

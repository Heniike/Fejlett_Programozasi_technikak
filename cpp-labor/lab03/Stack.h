//
// Created by asus on 10/22/2023.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>
#include "List.h"

class Stack {
public:
    Stack(); // Konstruktor
    ~Stack(); // Destruktor

    void push(int e);
    int pop();
    bool isEmpty() const;

private:
    List list; // List osztály használata a verem implementálásához
};
#endif //LAB3_STACK_H

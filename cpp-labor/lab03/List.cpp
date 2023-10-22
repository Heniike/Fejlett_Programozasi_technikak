//
// Created by asus on 10/22/2023.
//
#include "List.h"
#include <iostream>
#include <stdexcept>

using namespace std;

List::List() : nodeCounter(0), first(nullptr) {}

List::~List() {
    while (!empty()) {
        removeFirst();
    }
}

bool List::exists(int d) const {
    Node* current = first;
    while (current != nullptr) {
        if (current->value == d) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    first = new Node(d, first);
    nodeCounter++;
}

int List::removeFirst() {
    if (empty()) {
        throw runtime_error("List is empty, cannot remove.");
    }

    int value = first->value;
    Node* temp = first;
    first = first->next;
    delete temp;
    nodeCounter--;
    return value;
}

void List::remove(int d, DeleteFlag df) {
    Node* current = first;
    Node* prev = nullptr;

    while (current != nullptr) {
        if ((df == DeleteFlag::LESS && current->value < d) ||
            (df == DeleteFlag::EQUAL && current->value == d) ||
            (df == DeleteFlag::GREATER && current->value > d)) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                first = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
            nodeCounter--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void List::print() const {
    Node* current = first;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

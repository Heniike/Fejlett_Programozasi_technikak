#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;

int main() {
    ///Exercise 1
    List list;

    list.insertFirst(10);
    list.insertFirst(20);
    list.insertFirst(30);
    list.insertFirst(40);

    cout << "List size: " << list.size() << endl;
    list.print();

    list.remove(20, List::DeleteFlag::EQUAL);
    cout << "After removing 20: ";
    list.print();

    list.remove(35, List::DeleteFlag::LESS);
    cout << "After removing less than 35: ";
    list.print();

    list.remove(40, List::DeleteFlag::GREATER);
    cout << "After removing greater than 40: ";
    list.print();

    if (list.exists(10)) {
        cout << "10 exists in the list." << endl;
    } else {
        cout << "10 does not exist in the list." << endl;
    }

    try {
        list.removeFirst();
        list.removeFirst();
        list.removeFirst();
        list.removeFirst();
        list.removeFirst(); // Should throw an exception
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    ///Exercise 2
    Stack stack;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    cout << "Popped value: " << stack.pop() << endl;
    cout << "Popped value: " << stack.pop() << endl;
    cout << "Popped value: " << stack.pop() << endl;

    try {
        cout << "Popped value: " << stack.pop() << endl; // Should throw an exception
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

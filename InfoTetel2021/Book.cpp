//
// Created by asus on 11/10/2023.
//

#include <iostream>
#include "Book.h"

ostream &operator<<(ostream &os, const Book &book) {
    book.printBook(os);
    return os;
}

void Book::printBook(ostream &os) const {
    os << "The book: " << title << " by " << author << ", " << year << ", " << pages << " pages";
}

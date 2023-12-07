//
// Created by asus on 11/13/2023.
//

#include "Book.h"

const int &Book::getID() {
    return id;
}

const string &Book::getTitle() const {
    return title;
}
const int &Book::getYear() const {
    return year;
}
const vector<string> Book::getAuthors() const {
    return authors;
}

ostream &operator<<(ostream &os, const Book &book) {
    book.printBook(os);
    return os;
}
void Book ::printBook(ostream &os) const {
    os << "Title: " << title << ", Year: " << year << endl;
}
Book operator==(Book &book1,  Book &book2) {
    Book result(book1.getTitle(), book1.getYear());
    if(book1.getTitle() != book2.getTitle() &&
    book1.getYear() != book2.getYear() &&
    book1.getAuthors() != book2.getAuthors()){
        return result;
    }
}

void Book::setTitle(const string &title) {
    this->title = title;
}

void Book::setYear(const int &year) {
    this->year = year;
}

void Book::setAuthor(const vector<string> &authors) {
    this->authors = authors;
}

//
// Created by asus on 11/13/2023.
//

#ifndef PARICIALISA_LIBRARY_H
#define PARICIALISA_LIBRARY_H

#include "Book.h"

class Library {
public:
    Library(string name) : name(name){};
    const string getLibraryName() const;
    const vector<Book> getBooks() const;

    void addBook(Book &book);
    void printBooks() ;
    friend ostream &operator<<(ostream &os, vector<Book> &books);
    void sortBooks();
    void sortBooksByTitleAndAuthors();
    void readLibrary(const string& filename);
private:
    string name;
    vector<Book> books;
};


#endif //PARICIALISA_LIBRARY_H

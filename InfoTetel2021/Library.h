//
// Created by asus on 11/12/2023.
//

#ifndef INFOTETEL2021_LIBRARY_H
#define INFOTETEL2021_LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    vector<Book> books;
public:
   // Library(const vector<Book> &books) : books(books) {};

    void addBook(const Book &book);
    void listBooks() const;
    const Book& findBook(const string& searchTerm);
    int countBooksByAuthor(const string& authorName) const;
    void sortBooks();
    void removeBook(const string& title);

};


#endif //INFOTETEL2021_LIBRARY_H

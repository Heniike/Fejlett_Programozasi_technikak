//
// Created by asus on 11/12/2023.
//

#include <iostream>
#include <algorithm>
#include "Library.h"


void Library::addBook(const Book &book) {
    books.push_back(book);
}

void Library::listBooks() const {
    for (const auto& book : books){
        cout << book << endl;
    }
}

const Book &Library::findBook(const string &searchTerm) {
    auto it = find_if(books.begin(), books.end(), [searchTerm](const Book& book){
        return (book.getAuthor().find(searchTerm) != string::npos) ||
                (book.getTitle().find(searchTerm) != string::npos);
    });

    if(it != books.end()){
        return *it;
    }else{
        throw runtime_error("The book is not found");
    };

}

int Library::countBooksByAuthor(const string &authorName) const {
    int counter = 0;
    for (const auto& book : books){
        if(book.getAuthor() == authorName){
            counter++;
        }
    }
    return counter;
}

void Library::sortBooks() {
    sort(books.begin(), books.end(),[](const Book& a, const Book& b){
        if(a.getAuthor() == b.getAuthor()){
            return a.getYear() > b.getYear();
        }
    });
}

void Library::removeBook(const string &title) {
    auto it = remove_if(books.begin(), books.end(), [title](const Book& book){
        return book.getTitle() == title;
    });

    if(it != books.end()){
        books.erase(it, books.end());
    }else{
        throw runtime_error("The book is not found");
    }
}

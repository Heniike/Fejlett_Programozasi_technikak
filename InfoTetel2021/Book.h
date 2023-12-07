//
// Created by asus on 11/10/2023.
//

#ifndef INFOTETEL2021_BOOK_H
#define INFOTETEL2021_BOOK_H


#include <string>

using namespace std;

class Book {

public:
    Book(const string &author, const string &title, int year, int pages)
     : author(author), title(title), year(year), pages(pages){}

    string getAuthor() const{ return  author;}
    string getTitle() const{ return title; }
    int getYear() const{ return year; }
    int getPages() const{ return pages; }

    void printBook(ostream &os) const;
    friend ostream& operator<<(ostream& os, const Book& book);

private:
    string author;
    string title;
    int year;
    int pages;
};


#endif //INFOTETEL2021_BOOK_H

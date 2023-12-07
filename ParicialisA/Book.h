//
// Created by asus on 11/13/2023.
//

#ifndef PARICIALISA_BOOK_H
#define PARICIALISA_BOOK_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Book {
public:
    //Book(string &title, int year) : title(title), year(year), id(++nextID) {}
    Book (const string& title, int year){
        this->title = title;
        this->year = year;
        this->id = nextID++;
    }
    const int &getID();
    const string &getTitle() const;
    const int &getYear() const;
    const vector<string> getAuthors() const;
    static int getNextId();
    void setID(const string id);
    void setTitle(const string &title);
    void setAuthor(const vector<string> &authors);
    void setYear(const int &year);
    void addBook(Book book);
    friend ostream& operator<<(ostream &os, const Book &book);
    void printBook(ostream &os)const ;
    friend Book operator==( Book &book1,  Book &book2);

private:
    //static
    int nextID = 0;
    int id;
    string title;
    int year;
    vector<string> authors;
};



#endif //PARICIALISA_BOOK_H

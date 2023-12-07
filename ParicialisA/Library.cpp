//
// Created by asus on 11/13/2023.
//

#include <algorithm>
#include "Library.h"
#include <fstream>

const string Library::getLibraryName() const {
    return name;
}

const vector<Book> Library::getBooks() const {
    return books;
}

void Library::addBook(Book &book) {
//    int id = book.getID();
//    for (int i = 0; i < books.capacity(); ++i) {
//        if (id == books[i].getID()) {
            books.push_back(book);
//        }
//    }
}

ostream &operator<<(ostream &os, vector<Book> books) {
//    for (const auto &book: books) {
//        book.printBook(os);
//    }
    for (const auto &book : books) {
        os << "Title: " << book.getYear() << ", Year: " << book.getYear() << endl;
        return os;
    }

}

void Library::sortBooks() {
    sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        return a.getTitle() > b.getTitle();
    });
    printBooks();
}

void Library::sortBooksByTitleAndAuthors() {
    sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
        if (a.getAuthors() == b.getAuthors()) {
            return a.getTitle() > b.getTitle();
        }
        return a.getAuthors() > b.getAuthors();
    });
    printBooks();
}


void Library::printBooks() {
    cout << this->getLibraryName() << endl;
    for (Book book: books) {
        cout << "\t" <<book;
    }
}

void Library::readLibrary(const string &filename) {
    ifstream file(filename);
    if(file.is_open()){
        cerr << "Error when oprning file " << endl;
    }
    string line;
    Library *library;
    vector<Book> books;

    while(getline(file, line)){
        for (Book book : books) {
                switch(line[0]){
                case'T':{
                        book.setTitle(line.substr(2));
                        books.clear();

                    case 'A':{
                            //book.getAuthors(line.substr(2));
                            books.clear();

                    }
                    case 'Y':{
                          //  book.setYear(line.substr(2));
                            books.clear();
                    }default: break;
            }
            library->addBook(book);
        }

        }

    }



}


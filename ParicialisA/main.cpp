#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {
    Book book("Aranyember", 1956);
    cout << book;
    Book book1("Aranyember", 1956);
    Book book2("Koszivu ember fiai", 1888);

    try{
        book2 == book1;
    }catch(const exception &e){
        cout << e.what() << "Nem egyformak a konyvek";
    }

    Library library("Kele");
    library.addBook(book1);
    library.addBook(book2);
    library.printBooks();

    library.sortBooks();
    cout << "------------------------------" << endl;
    library.sortBooksByTitleAndAuthors();



    return 0;
}

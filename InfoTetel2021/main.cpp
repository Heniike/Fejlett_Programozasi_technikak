#include <iostream>
#include "Book.h"
#include "Library.h"


int main() {
    Book book1("Jokai Mor", "Egri csillagok", 1980, 300);
    cout << book1;
    cout << "--------------------------------------------------";

    Book book2("Jokai Mor", "A koszivu ember fiai", 1967, 400);
    Book book3("Murakami Haruki", "Sotetedes utan", 2004, 250);
    Book book4("Murakami Haruki", "A norveg erdo", 1987, 420);
    Book book5("Murakami Haruki", "1Q84", 1987, 800);
    Book book6("Knausgard Karl Ove", "Harcom", 2009, 1000);

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    library.addBook(book6);


    cout << "All the books in the library:\n" << endl;
    library.listBooks();
    cout << "--------------------------------------------------";


    cout << "\nMurakami Haruki's books number: " << library.countBooksByAuthor("Murakami Haruki") << endl;
    cout << "--------------------------------------------------";

    try {
        cout << "\nThe searched book: " << library.findBook("A norveg erdo") << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << "--------------------------------------------------";

    cout << "\nThe books sorted by authors, in reverse chronological order:" << endl;
    library.sortBooks();
    library.listBooks();
    cout << "--------------------------------------------------";

    try {
        cout << "\nBook to be removed: 'Egri csillagok'" << endl;
        library.removeBook("Egri csillagok");
        cout << "\nThe book is removed!" << endl;

        cout << "\nList of books after deletion:" << endl;
        library.listBooks();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    cout << "--------------------------------------------------";

}

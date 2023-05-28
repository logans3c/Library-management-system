#include "Book.h"
#include <iostream>
#include <string>

// Implementations of member functions for the Book class

int Book::getId() {
    return id;
}

std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthor() {
    return author;
}

std::string Book::getCategory() {
    return category;
}

void Book::markAsBorrowed() {
    borrowed = true;
}

void Book::markAsReturned() {
    borrowed = false;
}
bool Book::isBorrowed() const {
    return borrowed;
    /** Book book("QUEEN'S GAMBIT", "F. Scott Fitzgerald", "Fiction");
    book.printInfo();  // Borrowed: No
    book.markAsBorrowed();
    book.printInfo();  // Borrowed: Yes
    book.markAsReturned();
    book.printInfo();  // Borrowed: No
    **/
}

// Initialize the static member variable
int Book::nextId = 1;
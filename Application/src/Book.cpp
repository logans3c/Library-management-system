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

bool Book::isBorrowed() const {
    return borrowed;
}

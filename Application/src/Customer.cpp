//
// Created by MAHMOUD on 5/18/2023.
//

#include "Customer.h"

#include <utility>



/** Constructors **/

Customer::Customer(std::string name) : User(std::move(name)) {
}

/** Const Methods **/

std::vector<Book*> Customer::getBorrowedBooks() const {
    return borrowedBooks;
}

int Customer::getBorrowedBooksCount() const {
    return (int) borrowedBooks.size();
}

/** Non-Const Methods **/

void Customer::borrowBook(Book *book) {
    if (borrowedBooks.size() >= Customer::maxBorrowedBooks){
        throw "Maximum number of borrowed books reached!";
    }
    book->markAsBorrowed();
    borrowedBooks.push_back(book);
}

void Customer::returnBook(Book *returnedBook) {
    auto it = borrowedBooks.begin();

    for (it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == returnedBook) {
            (*it)->markAsReturned();
            borrowedBooks.erase(it);
        }
    }
}

/** Static Members **/
int Customer::maxBorrowedBooks = 5;
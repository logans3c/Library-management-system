//
// Created by MAHMOUD on 5/18/2023.
//

#include "Customer.h"

#include <utility>



/** Constructors **/

Customer::Customer(std::string name) : User(std::move(name)) {
}

/** Const Methods **/

DynamicArray<Book*> Customer::getBorrowedBooks() const {
    return borrowedBooks;
}

int Customer::getBorrowedBooksCount() const {
    return (int) borrowedBooks.getSize();
}

/** Non-Const Methods **/

void Customer::borrowBook(Book *book) {
    if (borrowedBooks.getSize() >= Customer::maxBorrowedBooks){
        throw "Maximum number of borrowed books reached!";
    }
    book->markAsBorrowed();
    borrowedBooks.insert(book);
}

void Customer::returnBook(Book *returnedBook) {
    int size = borrowedBooks.getSize();
    for (int i = 0; i < size; ++i) {
        if (borrowedBooks[i] == returnedBook) {
            (borrowedBooks[i])->markAsReturned();
            borrowedBooks.removeAt(i);
            break;
        }
    }
}

/** Static Members **/
int Customer::maxBorrowedBooks = 5;
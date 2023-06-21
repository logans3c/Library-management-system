//
// Created by MAHMOUD on 5/18/2023.
//

#include "Customer.h"

#include <utility>



/** Constructors **/

Customer::Customer(std::string name) : User(std::move(name)) {
}
Customer::Customer(std::string name,int id) : User(std::move(name),id) {
}
Customer::Customer(std::string name,int id,DynamicArray<int>* booksIds) : User(std::move(name),id) {
    borrowedBooksId = *booksIds;
}
/** Const Methods **/

DynamicArray<int> Customer::getBorrowedBooksIds() const {
    return borrowedBooksId;
}

int Customer::getBorrowedBooksCount() const {
    return (int) borrowedBooksId.getSize();
}

/** Non-Const Methods **/

void Customer::borrowBook(int &BookId) {
    if (borrowedBooksId.getSize() >= Customer::maxBorrowedBooks){
        throw "Maximum number of borrowed books reached!";
    }
    borrowedBooksId.insert(BookId);
}

void Customer::returnBook(int &returnedBookId) {
    int size = borrowedBooksId.getSize();
    for (int i = 0; i < size ; ++i) {
        if( borrowedBooksId[i] == returnedBookId ){
            borrowedBooksId.removeAt(i);
            break;
        }
    }
}

/** Static Members **/
int Customer::maxBorrowedBooks = 5;
#ifndef INC_23_05_CUSTOMER_H
#define INC_23_05_CUSTOMER_H

#include <iostream>

#include "User.h"
#include "Book.h"
#include "DynamicArray.h"

class Customer : public User {
public:
    /** Constructors **/
    explicit Customer(std::string name);
    Customer()= default;

    /** Const Methods **/
    DynamicArray<Book*> getBorrowedBooks() const;
    int getBorrowedBooksCount() const;

    /** Non-Const Methods **/
    void borrowBook(Book* book);
    void returnBook(Book* book);

private:

    /** Static Members **/
    static int maxBorrowedBooks;

    /** Non-Static Members **/
    DynamicArray<Book*> borrowedBooks;
};


#endif //INC_23_05_CUSTOMER_H

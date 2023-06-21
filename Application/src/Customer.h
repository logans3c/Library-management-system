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
    Customer(std::string name,int id) ;
    Customer(std::string name,int id,DynamicArray<int>* booksIds);
    Customer() = default;

    /** Const Methods **/
    DynamicArray<int> getBorrowedBooksIds() const;
    int getBorrowedBooksCount() const;

    /** Non-Const Methods **/
    void borrowBook(int& borrowedBookId);
    void returnBook(int& returnedBookId);

private:

    /** Static Members **/
    static int maxBorrowedBooks;

    /** Non-Static Members **/
    DynamicArray<int> borrowedBooksId;
};


#endif //INC_23_05_CUSTOMER_H
//
// Created by MAHMOUD on 5/19/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARYAPI_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARYAPI_H

#include "Library.h"
#include "Admin.h"
#include "Book.h"
#include "Customer.h"
#include "DynamicArray.h"

class LibraryAPI {
public:
    /** Constructors **/
    LibraryAPI();

    /** Const Methods **/
    bool adminLogin(string& username, string& password);

    /*saving data in files*/
    void saveData() ;


    /*reading data from files*/
    void readBooksData();
    void readCustomersData();
    void readAdminsData();


    /*Search*/
    DynamicArray<Book *> * bookSearchByAuthor(string &query );
    DynamicArray<Book *> * bookSearchByCategory(string &bookCategory );
    DynamicArray<Book *> * bookSearchByTitle(string& query );
    Book* bookSearchById( int id);

    /*Get Data*/
    DynamicArray<Book *> * getAllLibraryBooks();
    DynamicArray<Book *> * getBorrowedBooks();
    DynamicArray<Book *> * getNonBorrowedBooks();
    DynamicArray<Book*> getCustomerBorrowedBooks( int customerId) const;
    int getCustomerBorrowedBooksCount( int customerId) const;
    Customer * getCustomer(int id) const;
    Admin* getAdmin( int id);
    DynamicArray<Admin*>* getAdminsData();
    DynamicArray<Customer *> * getCustomersData();


    /** Non-Const Methods **/


    /*Adding Books to the library or Removing Books from the library*/
    void AddBook(string&title,string&author,string&category);
    void removeBook( int bookId );


    /*Adding Customer to the library or Removing Customer from the library*/
    void createCustomer( string &name );
    void removeCustomerById( int id);


    /*Adding Admin to the library or Removing Admin from the library*/
    void createAdmin( string& name , string& username , string& password);
    void removeAdminById( int id);


    /*Borrow or return a book*/
    void borrowBook(int bookId , int customerId );
    void returnBook(int bookId , int customerId );


private:
    Library* lib;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARYAPI_H
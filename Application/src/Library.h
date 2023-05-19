//
// Created by Abdelrahman on 5/18/2023.
//
#include "DynamicArray.h"
#include "Book.h"
#include "Admin.h"
#include "Customer.h"

#include <iostream>
using namespace std;


#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H


class Library {
public:

    DynamicArray<Book> findBooksByAuthor(string bookAuthorName );
    DynamicArray<Book> findBooksByCategory(string bookCategory );
    DynamicArray<Book> findBookByTitle(string& bookTitle );

    DynamicArray<Book> getAllLibraryBooks();
    DynamicArray<Book> getBorrowedBooks();
    DynamicArray<Book> getNonBorrowedBooks();

    void addBook( Book newBook );
    void removeBook( int bookId );

    void createCustomer( string name );
    void removeCustomerById( int id);
    Customer* getCustomer( int id);
    DynamicArray<Customer> getAllCustomer();

    void createAdmin( string name , string username , string password);
    void removeAdminById( int id);
    Admin* getAdmin( int id);
    DynamicArray<Admin> getAllAdmins();

private:

    DynamicArray<Admin> libraryAdmins ;
    DynamicArray<Customer> libraryCustomers ;
    DynamicArray<Book> libraryBooks ;

};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H

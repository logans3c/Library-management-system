//
// Created by Abdelrahman on 5/18/2023.
//
#include "DynamicArray.h"
#include "Book.h"
#include "Customer.h"
#include "Admin.h"
#include <iostream>
using namespace std;


#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H


class Library {
public:
    static bool isPasswordValid( string& password);
    bool isUsernameUnique( string& username);
    bool isValidAdminCredentials( string& username , string& password);

    void addBook(Book* newBook );
    void removeBook( int bookId );


    DynamicArray<Book *> * findBooksByAuthor(string &query );
    DynamicArray<Book *> * findBooksByCategory(string &bookCategory );
    DynamicArray<Book *> * findBooksByTitle(string& query );

    DynamicArray<Book *> * getAllLibraryBooks();
    DynamicArray<Book *> * getBorrowedBooks();
    DynamicArray<Book *> * getNonBorrowedBooks();


    void createCustomer( string &name );
    void removeCustomerById( int id);
    Customer* getCustomer( int id);
    DynamicArray<Customer *> * getAllCustomer();

    void createAdmin( string& name , string& username , string& password);
    void removeAdminById( int id);
    Admin* getAdmin( int id);
    DynamicArray<Admin *> * getAllAdmins();


private:

    DynamicArray<Admin *> libraryAdmins ;
    DynamicArray<Customer *> libraryCustomers ;
    DynamicArray<Book *> libraryBooks;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H

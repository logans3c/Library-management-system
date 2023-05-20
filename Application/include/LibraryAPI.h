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
    int getCustomerBorrowedBooksCount( int customerId) const;
    DynamicArray<Admin*>* getAdminsData();
    DynamicArray<Customer *> * getCustomersData();
    DynamicArray<Book *> * bookSearchByAuthor(string &query );
    DynamicArray<Book *> * bookSearchByCategory(string &bookCategory );
    DynamicArray<Book *> * bookSearchByTitle(string& query );
    DynamicArray<Book *> * getAllLibraryBooks();
    DynamicArray<Book *> * getBorrowedBooks();
    DynamicArray<Book *> * getNonBorrowedBooks();
    DynamicArray<Book*> getCustomerBorrowedBooks( int customerId) const;
    Book* bookSearchById( int id);
    Customer* getCustomer( int id);
    Admin* getAdmin( int id);


    /** Non-Const Methods **/
    void AddBook(string&title,string&author,string&category);
    void removeBook( int bookId );
    void createCustomer( string &name );
    void removeCustomerById( int id);
    void createAdmin( string& name , string& username , string& password);
    void removeAdminById( int id);
    void borrowBook(int bookId , int customerId );
    void returnBook(int bookId , int customerId );


private:
    Library* lib;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARYAPI_H
//
// Created by Abdelrahman on 5/18/2023.
//
#include "DynamicArray.h"
#include "Book.h"

#include <iostream>
using namespace std;


#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H


class Library {
public:
    DynamicArray<Book> findBooksByAuthor(string bookAuthorName );
    DynamicArray<Book> findBooksByCategory(string bookCategory );
    DynamicArray<Book> findBookByTitle( string bookTitle );
    void addBook( Book newBook );
    void removeBook( int bookId);
private:
    DynamicArray<Book> libraryBooks ;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H

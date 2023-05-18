//
// Created by Abdelrahman on 5/18/2023.
//

#include "Library.h"

void Library::removeBook(int bookId) {
    for (int i = 0; i < libraryBooks.getSize() ; ++i) {
        if ( libraryBooks[i].getId() == bookId ){
            libraryBooks.removeAt(i) ;
            break;
        }
    }
}

void Library::addBook(Book newBook) {
    libraryBooks.insert(newBook);
}

DynamicArray<Book> Library::findBooksByCategory(string bookCategory) {
    DynamicArray<Book> searchResult;
    for (int i = 0; i < libraryBooks.getSize() ; ++i) {
        if ( libraryBooks[i].getCategory() == bookCategory){
            searchResult.insert(libraryBooks[i]);
        }
    }
    return searchResult ;
}

DynamicArray<Book> Library::findBookByTitle(string bookTitle) {
    DynamicArray<Book> searchResult ;

    return searchResult ;
}

DynamicArray<Book> Library::findBooksByAuthor(string bookAuthorName) {
    DynamicArray<Book> searchResult ;

    return searchResult;
}



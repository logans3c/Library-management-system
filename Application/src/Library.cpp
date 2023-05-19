//
// Created by Abdelrahman on 5/18/2023.
//

#include <map>
#include "Library.h"
#include "Search.cpp"

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
            searchResult.insert( libraryBooks[i] );
        }
    }
    return searchResult ;
}

DynamicArray<Book> Library::findBookByTitle(string& query) {
    DynamicArray<Book> searchResult ;

    // the map is only used for ranking the search results
    map<double,DynamicArray<Book> > mp;

    int sz = libraryBooks.getSize();
    for (int i = 0; i < sz; ++i) {

        auto book = libraryBooks[i];
        auto bookTitle = book.getTitle();

        int maxCommonLength = calculateCommonSubstringLength( bookTitle, query);

        double score = calculateRelevanceScore(query.size(),maxCommonLength);
        if (score > 50)
            mp[score * -1].insert(book);
    }

    // loop over the map to add the books to the dynamic array
    for (const auto& pair : mp) {

        auto books = pair.second;
        for (int i = 0; i < books.getSize(); ++i) {
            searchResult.insert(books[i]);
        }
    }


    return searchResult ;
}

DynamicArray<Book> Library::findBooksByAuthor(string query) {
    DynamicArray<Book> searchResult ;

    // the map is only used for ranking the search results
    map<double,DynamicArray<Book> > mp;

    int sz = libraryBooks.getSize();
    for (int i = 0; i < sz; ++i) {

        auto book = libraryBooks[i];
        auto bookAuthor = book.getAuthor();

        int maxCommonLength = calculateCommonSubstringLength( bookAuthor, query);

        double score = calculateRelevanceScore(query.size(),maxCommonLength);
        if (score > 50)
            mp[score * -1].insert(book);
    }

    // loop over the map to add the books to the dynamic array
    for (const auto& pair : mp) {

        auto books = pair.second;
        for (int i = 0; i < books.getSize(); ++i) {
            searchResult.insert(books[i]);
        }
    }


    return searchResult;
}


void Library::createCustomer( string name ) {
    Customer theCustomer( name ) ;
    libraryCustomers.insert( theCustomer );
}

void Library::createAdmin(string name, string username, string password) {
    Admin theAdmin( name , username , password) ;
    libraryAdmins.insert(theAdmin);
}

DynamicArray<Book> Library::getAllLibraryBooks() {
    return libraryBooks;
}

DynamicArray<Book> Library::getBorrowedBooks() {
    DynamicArray<Book> borrowedBooks ;
    for (int i = 0; i < libraryBooks.getSize(); ++i) {
        if(libraryBooks[i].isBorrowed()){
            borrowedBooks.insert(libraryBooks[i]);
        }
    }
    return borrowedBooks ;
}

DynamicArray<Book> Library::getNonBorrowedBooks() {
    DynamicArray<Book> nonBorrowedBooks ;
    for (int i = 0; i < libraryBooks.getSize(); ++i) {
        if(!libraryBooks[i].isBorrowed()){
            nonBorrowedBooks.insert(libraryBooks[i]);
        }
    }
    return nonBorrowedBooks ;
}

DynamicArray<Customer> Library::getAllCustomer() {
    return libraryCustomers;
}

DynamicArray<Admin> Library::getAllAdmins() {
    return libraryAdmins;
}

Customer* Library::getCustomer( int id) {
    Customer* theCutomer;
    for (int i = 0; i < libraryCustomers.getSize(); ++i) {
        if ( libraryCustomers[i].getId() == id ){
            *theCutomer = libraryCustomers[i] ;
            break;
        }
    }
    return theCutomer ;
}

Admin *Library::getAdmin(int id) {
    Admin* theAdmin;
    for (int i = 0; i < libraryAdmins.getSize(); ++i) {
        if ( libraryAdmins[i].getId() == id ){
            *theAdmin = libraryAdmins[i] ;
            break;
        }
    }
    return theAdmin ;
}


void Library::removeCustomerById(int id) {
    for (int i = 0; i < libraryCustomers.getSize(); ++i) {
        if( libraryCustomers[i].getId() == id ){
            libraryCustomers.removeAt(i) ;
            break;
        }
    }
}

void Library::removeAdminById(int id) {
    for (int i = 0; i < libraryAdmins.getSize(); ++i) {
        if( libraryAdmins[i].getId() == id ){
            libraryAdmins.removeAt(i) ;
            break;
        }
    }
}
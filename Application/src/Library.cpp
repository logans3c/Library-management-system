//
// Created by Abdelrahman on 5/18/2023.
//

#include <map>
#include "Library.h"
#include "Search.cpp"


void Library::removeBook(int bookId) {
    int size = libraryBooks.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if ( libraryBooks[i]->getId() == bookId ){
            libraryBooks.removeAt(i) ;
            break;
        }
    }
}

void Library::addBook(Book *newBook) {
    libraryBooks.insert(newBook);
}




DynamicArray<Book *> * Library::findBooksByCategory(string &bookCategory) {
    auto searchResult = new DynamicArray<Book* > ;
    int size = libraryBooks.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if ( libraryBooks[i] -> getCategory() == bookCategory){
            searchResult -> insert(libraryBooks[i]);
        }
    }
    return searchResult ;
}

DynamicArray<Book *> * Library::findBooksByTitle(string& query) {
    auto searchResult = new DynamicArray<Book* >  ;

    // the map is only used for ranking the search results
    map<double,DynamicArray<Book*> > mp;

    int sz = libraryBooks.getSize();
    for (int i = 0; i < sz; ++i) {

        auto book = libraryBooks[i];
        auto bookTitle = book->getTitle();

        int maxCommonLength = calculateCommonSubstringLength( bookTitle, query);

        double score = calculateRelevanceScore(query.size(),maxCommonLength);
        if (score > 35)
            mp[score * -1].insert(book);
    }

    // loop over the map to add the books to the dynamic array
    for (const auto& pair : mp) {

        for (int i = 0; i < pair.second.getSize(); ++i) {
            searchResult->insert(pair.second[i]);
        }
    }


    return searchResult ;
}

DynamicArray<Book *> * Library::findBooksByAuthor(string &query) {
    auto searchResult = new DynamicArray<Book*>  ;

    // the map is only used for ranking the search results
    map<double,DynamicArray<Book*> > mp;

    int sz = libraryBooks.getSize();
    for (int i = 0; i < sz; ++i) {

        auto book = libraryBooks[i];
        auto bookAuthor = book->getAuthor();

        int maxCommonLength = calculateCommonSubstringLength( bookAuthor, query);

        double score = calculateRelevanceScore(query.size(),maxCommonLength);
        if (score > 35)
            mp[score * -1].insert(book);
    }

    // loop over the map to add the books to the dynamic array
    for (const auto& pair : mp) {

        for (int i = 0; i < pair.second.getSize(); ++i) {
            searchResult->insert(pair.second[i]);
        }
    }


    return searchResult;
}





DynamicArray<Book *> * Library::getAllLibraryBooks() {
    return &libraryBooks;
}

DynamicArray<Book *> * Library::getBorrowedBooks() {
    auto borrowedBooks = new DynamicArray<Book *>  ;
    int size = libraryBooks.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if(libraryBooks[i]->isBorrowed()){
            borrowedBooks->insert(libraryBooks[i]);
        }
    }
    return borrowedBooks ;
}

DynamicArray<Book *> * Library::getNonBorrowedBooks() {
    int size = libraryBooks.getSize() ;
    auto nonBorrowedBooks = new DynamicArray<Book *>;
    for (int i = 0; i < size ; ++i) {
        if(!libraryBooks[i]->isBorrowed()){
            nonBorrowedBooks->insert(libraryBooks[i]);
        }
    }
    return nonBorrowedBooks ;
}





void Library::createCustomer( string &name ) {
    libraryCustomers.insert( new Customer {name});
}

void Library::removeCustomerById(int id) {
    int size = libraryCustomers.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if( libraryCustomers[i]->getId() == id ){
            libraryCustomers.removeAt(i) ;
            break;
        }
    }

}

Customer* Library::getCustomer( int id) {
    int size = libraryCustomers.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if ( libraryCustomers[i]->getId() == id ){
            return libraryCustomers[i] ;
        }
    }
    throw std::invalid_argument("id");
}

DynamicArray<Customer *> * Library::getAllCustomers() {
    return &libraryCustomers;
}




void Library::createAdmin(string& name, string& username, string& password) {
    if(!isPasswordValid(password)){
        throw std::invalid_argument( password);
    }
    else if(!isUsernameUnique(username)){
        throw std::invalid_argument( username);
    }
    libraryAdmins.insert(new Admin{name, username, password});
}


void Library::removeAdminById(int id) {
    int size = libraryAdmins.getSize() ;
    for (int i = 0; i < size; ++i) {
        if( libraryAdmins[i]->getId() == id ){
            libraryAdmins.removeAt(i) ;
            break;
        }
    }
}

Admin *Library::getAdmin(int id) {
    int size = libraryAdmins.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if ( libraryAdmins[i]->getId() == id ){
            return libraryAdmins[i] ;
        }
    }
    throw std::invalid_argument("id");
}

DynamicArray<Admin *> * Library::getAllAdmins() {
    return &libraryAdmins;
}

bool Library::isValidAdminCredentials(string &username, string &password) {
    int size = libraryAdmins.getSize() ;
    for (int i = 0; i < size ; ++i) {
        if( libraryAdmins[i]->getUsername() == username && libraryAdmins[i]->getPassword() == password ){
            return true ;
        }
    }
    return false;
}

bool Library::isUsernameUnique(string &username) {
    int size = libraryAdmins.getSize() ;
    for (int i = 0; i < size; ++i) {
        if(libraryAdmins[i]->getUsername() == username ){
            return false ;
        }
    }
    return true;
}

bool Library::isPasswordValid(string &password) {
    if( password.size() < 8 ){
        return false;
    }
    return true;
}

Book *Library::findBookById(int id) {
    int size = libraryBooks.getSize() ;
    for (int i = 0; i < size; ++i) {
        if( libraryBooks[i]->getId() == id ){
            return libraryBooks[i] ;
        }
    }
    throw std::invalid_argument("id");
}

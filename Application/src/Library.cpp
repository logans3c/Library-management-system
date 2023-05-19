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
            searchResult.insert(libraryBooks[i]);
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


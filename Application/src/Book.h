#include <iostream>
#include <string>
#include <utility>
#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H


class Book {

    public:
        Book(std::string bookTitle, std::string bookAuthor, std::string bookCategory)
                : id(nextId++), title(std::move(bookTitle)), author(std::move(bookAuthor)), category(std::move(bookCategory)), borrowed(false) {}


        std::string getTitle();
        int getId();
        std::string getAuthor();
        std::string getCategory();
        bool isBorrowed() const;
        void markAsBorrowed();
        void markAsReturned();

private:
        static int nextId;
        int id;
        std::string title;
        std::string author;
        std::string category;
        bool borrowed;


};
// Initialize the static member variable
int Book::nextId = 1;
Book() = default;   // define default constructor
#endif //LIBRARY_BOOK_H

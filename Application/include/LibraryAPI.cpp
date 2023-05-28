//
// Created by MAHMOUD on 5/19/2023.
//
#include "LibraryAPI.h"

/** Constructors **/

LibraryAPI::LibraryAPI() {
    lib = new Library;
}

/** Const Methods **/
bool LibraryAPI::adminLogin(string &username, string &password) {
    return lib->isValidAdminCredentials(username,password);
}

DynamicArray<Admin *> *LibraryAPI::getAdminsData() {
    return lib->getAllAdmins();
}

DynamicArray<Customer *> * LibraryAPI::getCustomersData() {
    return lib->getAllCustomers();
}

DynamicArray<Book *> *LibraryAPI::bookSearchByAuthor(string &query) {
    return lib->findBooksByAuthor(query);
}

DynamicArray<Book *> *LibraryAPI::bookSearchByCategory(string &bookCategory) {
    return lib->findBooksByCategory(bookCategory);
}

DynamicArray<Book *> *LibraryAPI::bookSearchByTitle(string &query) {
    return lib->findBooksByTitle(query);
}

Book *LibraryAPI::bookSearchById(int id) {
    return lib->findBookById( id);
}

DynamicArray<Book *> *LibraryAPI::getNonBorrowedBooks() {
    return lib->getNonBorrowedBooks();
}

DynamicArray<Book *> *LibraryAPI::getBorrowedBooks() {
    return lib->getBorrowedBooks();
}

DynamicArray<Book *> *LibraryAPI::getAllLibraryBooks() {
    return lib->getAllLibraryBooks();
}

Admin *LibraryAPI::getAdmin(int id) {
    return lib->getAdmin(id);
}

Customer * LibraryAPI::getCustomer(int id) const {
    return lib->getCustomer(id);
}

/** Non-Const Methods **/

void LibraryAPI::AddBook(string&title,string&author,string&category) {
    lib->addBook(new Book {title,author,category});
}

void LibraryAPI::createCustomer(string &name) {
    lib->createCustomer(name);
}

void LibraryAPI::removeCustomerById(int id) {
    lib->removeCustomerById(id);
}

void LibraryAPI::createAdmin(string &name, string &username, string &password) {
    lib->createAdmin(name,username,password);
}

void LibraryAPI::removeAdminById(int id) {
    lib->removeAdminById(id);
}

void LibraryAPI::removeBook(int bookId) {
    lib->removeBook(bookId);
}

void LibraryAPI::borrowBook(int bookId, int customerId) {
    lib->lendBook( bookId , customerId);
}

void LibraryAPI::returnBook(int bookId, int customerId) {
    lib->returnBook( bookId, customerId);
}

DynamicArray<Book *> LibraryAPI::getCustomerBorrowedBooks(int customerId) const {
    Customer* theCustomer = getCustomer(customerId) ;
    DynamicArray<int> customerBorrowedBooksIds = theCustomer->getBorrowedBooksIds();
    return lib->getBooksByIds(customerBorrowedBooksIds);
}

int LibraryAPI::getCustomerBorrowedBooksCount(int customerId) const {
    Customer* theCustomer ;
    int borrowedBooksNum ;
    theCustomer = lib->getCustomer(customerId);
    borrowedBooksNum = theCustomer->getBorrowedBooksCount();
    return borrowedBooksNum ;
}

void LibraryAPI::readBooksData() {
    lib->readBooks() ;
}

void LibraryAPI::readAdminsData() {
    lib->readAdmins() ;
}

void LibraryAPI::readCustomersData() {
    lib->readCustomers() ;
}

void LibraryAPI::saveData() {
    lib->saveData() ;
}

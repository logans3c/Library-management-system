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

/** Non-Const Methods **/

void LibraryAPI::AddBook(string&title,string&author,string&category) {
    lib->addBook(new Book {title,author,category});
}


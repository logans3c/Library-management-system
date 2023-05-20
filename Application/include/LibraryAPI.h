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

    DynamicArray<Admin*>* getAdminsData();
    DynamicArray<Customer *> * getCustomersData();

    /** Non-Const Methods **/
    void AddBook(string&title,string&author,string&category);

private:
    Library* lib;
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARYAPI_H

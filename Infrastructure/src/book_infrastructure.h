//
// Created by moham on 5/28/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_INFRASTRUCTURE_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_INFRASTRUCTURE_H
#include "../../Utility/DynamicArray.h"
#include "../Application/src/Book.h"

void saveBooks(DynamicArray<Book*>& books, const std::string& filename);
DynamicArray<Book *> * readBooks(const std::string& filename);
#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOK_INFRASTRUCTURE_H
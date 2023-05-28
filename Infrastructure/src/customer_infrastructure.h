//
// Created by moham on 5/28/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_SAVECUSTOMER_H
#define LIBRARY_MANAGEMENT_SYSTEM_SAVECUSTOMER_H


#include "../Utility/DynamicArray.h"
#include "../Application/src/Customer.h"

void saveCustomer(const DynamicArray<Customer*>& libraryCustomers, const std::string& filename);
DynamicArray<Customer*> readCustomers(const std::string& filename);

#endif // LIBRARY_MANAGEMENT_SYSTEM_SAVECUSTOMER_H

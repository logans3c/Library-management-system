//
// Created by Mohammed Ashraf(LOGAN0X) on 5/22/2023.
//
#include <fstream>
#include <sstream>
#include "../Application/src/Customer.h"
#include "../Utility/DynamicArray.h"
#include "../Application/src/Library.h"
#include "customer_infrastructure.h"

void saveCustomer(const DynamicArray<Customer*>& libraryCustomers, const std::string& filename) {
    std::ofstream writeFile("customersData.csv", std::ios::trunc);
    if (!writeFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    writeFile << "ID,Name,BorrowedBooks\n";

    for (int i = 0; i < libraryCustomers.getSize(); ++i) {
        const Customer* customer = libraryCustomers[i];
        writeFile << customer->getId() << ","
                  << customer->getName() << ",";

        DynamicArray<int> borrowedBooks = customer->getBorrowedBooksIds();
        for (int j = 0; j < borrowedBooks.getSize(); ++j) {
            Book *book = reinterpret_cast<Book *>(borrowedBooks[j]);
            writeFile << book->getId() << ",";
        }

        writeFile << "\n";
    }

    writeFile.close();
}


DynamicArray<Customer*> readCustomers(const std::string& filename) {
    DynamicArray<Customer*> customers;

    std::ifstream readFile(filename);
    if (!readFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return customers;
    }

    std::string line;
    // Skip the header line
    std::getline(readFile, line);

    while (std::getline(readFile, line)) {
        std::istringstream iss(line);
        std::string field;

        std::getline(iss, field, ',');
        int id = std::stoi(field);

        std::getline(iss, field);
        std::string name = field;

        Customer* customer = new Customer(name);
        customers.insert(customer);
    }

    readFile.close();

    return customers;
}


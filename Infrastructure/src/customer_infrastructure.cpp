//
// Created by Mohammed Ashraf(LOGAN0X) on 5/22/2023.
//
#include <fstream>
#include "Application/src/Customer.h"

void saveCustomer(const DynamicArray<Customer*>& libraryCustomers, const std::string& filename) {
    std::ofstream writeFile(filename, std::ios::trunc);
    if (!writeFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    writeFile << "ID,Name,BorrowedBooks\n";

    for (const Customer* customer : libraryCustomers) {
        writeFile << customer->getId() << ","
                  << customer->getName() << ",";

        const DynamicArray<Book*>& borrowedBooks = customer->getBorrowedBooks();
        for (const Book* book : borrowedBooks) {
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

        Customer* customer = new Customer(id, name);
        customers.push_back(customer);
    }

    readFile.close();

    return customers;
}
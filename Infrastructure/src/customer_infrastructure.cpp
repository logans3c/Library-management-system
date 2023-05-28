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
    std::ofstream writeFile(filename, std::ios::trunc);
    if (!writeFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    writeFile << "ID,Name,BorrowedBooks\n";

    for (int i = 0; i < libraryCustomers.getSize(); ++i) {
        const Customer* customer = libraryCustomers[i];
        writeFile << customer->getId() << ","
                  << customer->getName() << ",";

        DynamicArray<int> borrowedBooksIds = customer->getBorrowedBooksIds();

        // Write all borrowed book IDs separated by a comma
        for (int j = 0; j < borrowedBooksIds.getSize(); ++j) {
            if (j > 0) {
                writeFile << ",";  // Add a comma separator
            }
            writeFile << borrowedBooksIds[j];  // Write borrowed book ID
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

        std::getline(iss, field, ',');
        std::string name = field;

        std::getline(iss, field);
        std::istringstream issBooks(field);
        std::string bookId;
        DynamicArray<int> borrowedBooksIds;

        while (std::getline(issBooks, bookId, ',')) {
            borrowedBooksIds.insert(std::stoi(bookId));
        }

        // Create a Customer object using the constructor
        Customer* customer = new Customer(name, id);
        customer->getBorrowedBooksIds() = borrowedBooksIds;
        customers.insert(customer);

        // Print customer information
        std::cout << "Customer ID: " << customer->getId() << std::endl;
        std::cout << "Name: " << customer->getName() << std::endl;
        std::cout << "Borrowed Books IDs: ";
        for (int i = 0; i < borrowedBooksIds.getSize(); ++i) {
            std::cout << borrowedBooksIds[i];
            if (i < borrowedBooksIds.getSize() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    readFile.close();

    return customers;
}


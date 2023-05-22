//
// Created by Mohammed Ashraf(LOGAN0X) on 5/22/2023.
//
#include <fstream>
#include "Application/src/Book.h"

void saveBooks(const std::string& filename, DynamicArray<Book*>& books) {
    std::ofstream file(filename);

    if (file) {
        // Delete the content of the CSV file
        file.close();
        std::ofstream clearFile(filename);

        if (!clearFile) {
            std::cout << "Error: Unable to clear the file." << std::endl;
            return;
        }

        clearFile.close();

        // Write the information from the dynamic array to the CSV file
        std::ofstream writeFile(filename, std::ios::app);

        if (writeFile) {
            for (int i = 0; i < books.getSize(); ++i) {
                Book* book = books[i];
                writeFile << book->getId() << ","
                          << book->getTitle() << ","
                          << book->getAuthor() << ","
                          << book->getCategory() << ","
                          << book->isBorrowed() << std::endl;
            }

            writeFile.close();
            std::cout << "Library books saved to " << filename << " successfully." << std::endl;
        } else {
            std::cout << "Error: Unable to open the file for writing." << std::endl;
        }
    } else {
        std::cout << "Error: Unable to open the file." << std::endl;
    }
}
DynamicArray<Book*> readBooks(const std::string& filename) {
    DynamicArray<Book*> books;

    std::ifstream readFile(filename);
    if (!readFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return books;
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
        std::string title = field;

        std::getline(iss, field, ',');
        std::string author = field;

        std::getline(iss, field, ',');
        std::string category = field;

        std::getline(iss, field);
        bool borrowed = (field == "1");

        Book* book = new Book(id, title, author, category, borrowed);
        books.insert(book);
    }

    readFile.close();

    return books;
}
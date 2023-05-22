//
// Created by Mohammed Ashraf(LOGAN0X) on 5/22/2023.
//
#include <fstream>
#include "Application/src/Admin.h"

void saveAdminsToCSV(const DynamicArray<Admin*>& admins, const std::string& filename) {
    std::ofstream writeFile(filename, std::ios::trunc);
    if (!writeFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    writeFile << "ID,Name,Username,Password\n";

    for (const Admin* admin : admins) {
        writeFile << admin->getId() << ","
                  << admin->getName() << ","
                  << admin->getUsername() << ","
                  << admin->getPassword() << "\n";
    }

    writeFile.close();
}

DynamicArray<Admin*> readAdmins(const std::string& filename) {
    DynamicArray<Admin*> admins;

    std::ifstream readFile(filename);
    if (!readFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return admins;
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

        std::getline(iss, field, ',');
        std::string username = field;

        std::getline(iss, field);
        std::string password = field;

        Admin* admin = new Admin(id, name, username, password);
        admins.push_back(admin);
    }

    readFile.close();

    return admins;
}
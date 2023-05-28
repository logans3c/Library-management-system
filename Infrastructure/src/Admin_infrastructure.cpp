//
// Created by Mohammed Ashraf(LOGAN0X) on 5/22/2023.
//
#include <fstream>
#include <sstream>
#include "../Application/src/Admin.h"
#include "../Utility/DynamicArray.h"
#include "../Application/src/Library.h"
#include "../Application/src/Customer.h"


void saveAdminsToCSV(const DynamicArray<Admin*>& admins, const std::string& filename) {
    std::ofstream file(filename);

    if (file) {
        // Write the header line
        file << "ID,Name,Username,Password" << std::endl;

        for (int i = 0; i < admins.getSize(); ++i) {
            Admin* admin = admins[i];
            file << admin->getId() << ","
                 << admin->getName() << ","
                 << admin->getUsername() << ","
                 << admin->getPassword() << std::endl;

            if (!file) {
                std::cout << "Error: Failed to write data for an admin." << std::endl;
                return;
            }
        }

        file.close();
        std::cout << "Admins data saved to " << filename << " successfully." << std::endl;
    } else {
        std::cout << "Error: Unable to open the file for writing." << std::endl;
    }
}



DynamicArray<Admin*>* readAdmins(const std::string& filename) {
    auto admins = new DynamicArray<Admin*>();

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
        int id = stoi( field);

        std::getline(iss, field, ',');
        std::string name = field;

        std::getline(iss, field, ',');
        std::string username = field;

        std::getline(iss, field);
        std::string password = field;

        Admin* admin = new Admin(name, username, password,id);
        admins->insert(admin);
    }

    readFile.close();

    return admins;
}


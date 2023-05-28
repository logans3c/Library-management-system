//
// Created by moham on 5/28/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_ADMIN_INFRASTRUCTURE_H
#define LIBRARY_MANAGEMENT_SYSTEM_ADMIN_INFRASTRUCTURE_H
#include "../Utility/DynamicArray.h"
#include "../Application/src/Admin.h"

void saveAdminsToCSV(const DynamicArray<Admin*>& admins, const std::string& filename);
DynamicArray<Admin*>* readAdmins(const std::string& filename);
#endif //LIBRARY_MANAGEMENT_SYSTEM_ADMIN_INFRASTRUCTURE_H

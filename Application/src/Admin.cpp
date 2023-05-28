//
// Created by MAHMOUD on 5/18/2023.
//

#include "Admin.h"

#include <utility>
#include "User.h"

/** Constructors **/
Admin::Admin(std::string name, std::string username, std::string password)
:   User(std::move(name)),
    username{std::move(username)},
    password{std::move(password)}
{}
Admin::Admin(std::string name, std::string username, std::string password,int id)
        :   User(std::move(name),id),
            username{std::move(username)},
            password{std::move(password)}
{}

std::string Admin::getPassword() {
    return password;
}

Admin::Admin() = default;
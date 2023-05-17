//
// Created by MAHMOUD on 5/18/2023.
//

#include "User.h"

#include <utility>


/** Constructors **/

User::User(std::string name) {
    this -> name = std::move(name);
    this -> id = User::getNewId();
}


/** Constant Methods **/

const std::string& User::getName() const { return name;}

int User::getId() const { return id; }

/** Non-Const Methods **/

/** Static Members **/

int User::lastId = 100001;

int User::getNewId() {
    return ++lastId;
}

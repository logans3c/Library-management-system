//
// Created by MAHMOUD on 5/18/2023.
//

#ifndef INC_23_05_ADMIN_H
#define INC_23_05_ADMIN_H

#include "User.h"
#include <string>

class Admin : public User {
public:
    /** Constructors **/
    Admin(std::string name,std::string username,std::string password);
    Admin(std::string name, std::string username, std::string password,int id);

    Admin() ;

    /** Const Methods **/
    std::string getUsername(){return username;};

    std::string getPassword();
private:
    /**  **/
    std::string username;
    std::string password;
};


#endif //INC_23_05_ADMIN_H

//
// Created by MAHMOUD on 5/18/2023.
//

#ifndef INC_23_05_USER_H
#define INC_23_05_USER_H

#include <string>

class User {
public:
    /** Constructors **/
    explicit User(std::string name);
    User(std::string name, int id);

    User(){};

    /** Const Methods **/
    int getId() const;
    const std::string &getName() const;

private:
    /** Static Members **/
    static int lastId;
    static int getNewId();

    /** Non-Static Members **/
    int id;
    std::string name;


};


#endif //INC_23_05_USER_H

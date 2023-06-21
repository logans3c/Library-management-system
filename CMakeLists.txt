cmake_minimum_required(VERSION 3.25)
project(Library_Management_System)

add_subdirectory(Application/src)
add_subdirectory(Application/include)

include_directories(Infrastructure/src)
include_directories(Utility)
include_directories(Application/include)
include_directories(Application/src)

add_executable(Console Console_Presentation/main.cpp
        Application/src/Library.h Application/src/Library.cpp
        Application/include/LibraryAPI.h Application/include/LibraryAPI.cpp
        Application/src/User.h Application/src/User.cpp
        Application/src/Book.h Application/src/Book.cpp
        Application/src/Admin.h Application/src/Admin.cpp
        Utility/DynamicArray.h
        Application/src/Customer.h Application/src/Customer.cpp
        Infrastructure/src/Admin_infrastructure.h Infrastructure/src/Admin_infrastructure.cpp
        Infrastructure/src/book_infrastructure.h Infrastructure/src/book_infrastructure.cpp
        Infrastructure/src/customer_infrastructure.h Infrastructure/src/customer_infrastructure.cpp
        )
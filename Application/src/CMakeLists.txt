cmake_minimum_required(VERSION 3.24)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../../Utility)
include_directories(../../Infrastructure/src)
add_executable(Application  User.h User.cpp Customer.cpp Customer.h Book.cpp Admin.cpp Admin.h Library.cpp Library.h main.cpp ../../Infrastructure/src/customer_infrastructure.h ../../Infrastructure/src/book_infrastructure.h ../../Infrastructure/src/Admin_infrastructure.h ../../Infrastructure/src/book_infrastructure.cpp ../../Infrastructure/src/Admin_infrastructure.cpp ../../Infrastructure/src/customer_infrastructure.cpp ../include/LibraryAPI.h ../include/LibraryAPI.cpp)
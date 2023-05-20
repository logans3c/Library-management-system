cmake_minimum_required(VERSION 3.25)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../../Utility)
add_executable(Application  User.h User.cpp Customer.cpp Customer.h Book.cpp Admin.cpp Admin.h Library.cpp Library.h )
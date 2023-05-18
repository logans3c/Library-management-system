cmake_minimum_required(VERSION 3.25)
project(23_05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(Application  User.h User.cpp Customer.cpp Customer.h Book.cpp Admin.cpp Admin.h)
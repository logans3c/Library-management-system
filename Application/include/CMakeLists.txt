cmake_minimum_required(VERSION 3.25)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_library(App STATIC LibraryAPI.h LibraryAPI.cpp)
include_directories(../src ../../Utility)
cmake_minimum_required(VERSION 3.31)
project(File_Organizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(File_Organizer main.cpp
        CategoryManager.h
        CategoryManager.cpp
        FileOrganizer.h
        FileOrganizer.cpp)

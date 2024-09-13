cmake_minimum_required(VERSION 3.29)
project(Online_Reader_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Online_Reader_Project main.cpp
        header/FileManager.h
        header/Headers.h
        header/Menu.h
        header/Online_Reader.h
        header/Site.h
        header/Backend.h
        FileManager.cpp
        Online_Reader.cpp
        Menu.cpp
        Site.cpp
        Backend.cpp)

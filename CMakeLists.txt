cmake_minimum_required(VERSION 3.26)
project(SIAOD_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(SIAOD_3 main.cpp
        entry.cpp
        entry.h
        hash_table.cpp
        hash_table.h
        Node.cpp
        Node.h)

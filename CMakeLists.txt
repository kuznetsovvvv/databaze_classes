cmake_minimum_required(VERSION 3.10) 

project(dz2_2sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(dz2_2sem
    dz2_2sem.cpp
    employees.cpp
    structual_divisions.cpp
    employees.h 
    structual_divisions.h
)

target_include_directories(dz2_2sem PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} 
)

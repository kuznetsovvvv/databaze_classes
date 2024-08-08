cmake_minimum_required(VERSION 3.10)
project(includes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(includes ${CMAKE_CURRENT_SOURCE_DIR}/employees.cpp 
                     ${CMAKE_CURRENT_SOURCE_DIR}/structual_divisions.cpp) 

add_executable(first_executable ${CMAKE_CURRENT_SOURCE_DIR}/employees.cpp)

add_executable(second_executable ${CMAKE_CURRENT_SOURCE_DIR}/structual_divisions.cpp)


target_link_libraries(first_executable includes)
target_link_libraries(second_executable includes)

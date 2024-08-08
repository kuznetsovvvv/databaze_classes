cmake_minimum_required(VERSION 3.10)
project(dz2_2sem)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../includes includes_dir)
add_executable(dz2_2sem ${CMAKE_CURRENT_SOURCE_DIR}/dz2_2sem.cpp)
target_include_directories(includes PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/../includes
)
target_link_libraries(dz2_2sem includes)

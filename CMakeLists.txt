cmake_minimum_required(VERSION 3.10)

project(mutual_exclusion_problem)

add_executable(dekker ./src/dekker.cpp)
add_executable(peterson ./src/peterson.cpp)
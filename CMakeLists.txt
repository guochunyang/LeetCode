cmake_minimum_required(VERSION 3.2)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpp/main.cpp)
add_executable(leetcode cpp/main.cpp)
add_executable(1_two_sum cpp/1_two_sum.cpp)
add_executable(2_add_two_number cpp/2_add_two_numbers.cpp)
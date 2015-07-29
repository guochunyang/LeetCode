cmake_minimum_required(VERSION 3.2)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpp/main.cpp)
add_executable(leetcode cpp/main.cpp)
add_executable(1_two_sum cpp/1_two_sum.cpp)
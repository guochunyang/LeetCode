cmake_minimum_required(VERSION 3.2)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(1_two_sum cpp/1_two_sum.cpp)
add_executable(2_add_two_number cpp/2_add_two_numbers.cpp)
add_executable(3_l_s_w_r_c cpp/3_longest_substring_without_repeating_characters.cpp)
add_executable(main cpp/main.cpp)

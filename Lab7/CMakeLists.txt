cmake_minimum_required(VERSION 3.17)
project(Lab7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Animal Animal.cpp)
add_executable(problem_1 problem_1.cpp Animal.cpp)
add_executable(problem_2 problem_2.cpp Animal.cpp)
add_executable(problem_3 problem_3.cpp Animal.cpp)
add_executable(problem_4 problem_4.cpp Animal.cpp)
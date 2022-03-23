cmake_minimum_required(VERSION 3.19)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)


add_executable(problem_1 problem_1.cpp Animal.cpp)
add_executable(problem_2 problem_2.cpp Animal.cpp Mammal.cpp Bird.cpp Fish.cpp Reptile.cpp Amphibian.cpp)
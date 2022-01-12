cmake_minimum_required(VERSION 3.0)
project(yahtzee)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -fsanitize=address -g")

add_executable(Yahtzee main.cpp assets.h die.cpp yahtzee.cpp)

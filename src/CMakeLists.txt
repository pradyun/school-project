cmake_minimum_required(VERSION 2.8)

project(sudoku_solver CXX)

# Needed for gcc
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

ADD_EXECUTABLE(solver main.cpp board.cpp solver.cpp)

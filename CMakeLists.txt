cmake_minimum_required(VERSION 2.8)
project("School Project" CXX)

option(TEST "Build the tests" ON)
# Needed for using C++11
add_definitions(-std=gnu++0x)

if (CMAKE_COMPILER_IS_GNUCC)
   set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
   set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
endif()

add_subdirectory(src)

if(TEST)
    add_subdirectory(lib/gmock-1.7.0)
    add_subdirectory(test)
endif()

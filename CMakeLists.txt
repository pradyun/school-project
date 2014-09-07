cmake_minimum_required(VERSION 2.8)
project("School Project" CXX)

# Needed for using C++11
add_definitions(-std=gnu++0x)

# Add the testing libraries
add_subdirectory(lib/gmock-1.7.0)

add_subdirectory(src)
add_subdirectory(test)

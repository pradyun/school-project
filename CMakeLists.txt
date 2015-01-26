# <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.

#
# Project Properties
#
CMAKE_MINIMUM_REQUIRED (VERSION 2.6.2)
PROJECT (SudokuSolver)
SET (APPLICATION_NAME "Sudoku Solver")
SET (APPLICATION_CODENAME "${PROJECT_NAME}")

# Compiler options
ADD_DEFINITIONS(-std=c++11)
IF(CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
    SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
ENDIF()

# Project details
SET (SOURCE_FOLDER ${PROJECT_SOURCE_DIR})

# Project Libraries
INCLUDE_DIRECTORIES(${SOURCE_FOLDER}/lib)
SET(PROJECT_LIBRARIES board solver)
ADD_SUBDIRECTORY(lib)

# Final executable
ADD_SUBDIRECTORY(src)

# Tests
ADD_SUBDIRECTORY(thirdparty/gmock-1.7.0)
ADD_SUBDIRECTORY(test)


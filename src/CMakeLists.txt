add_library(solver solver.cpp solver.h board.cpp board.h)

ADD_EXECUTABLE(sudoku_solver main.cpp)
target_link_libraries (sudoku_solver solver)

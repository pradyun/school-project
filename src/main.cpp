/**

 @author  Pradyun Gedam <pradyunsg@gmail.com>
 @version 1.0

 @section DESCRIPTION
 A simple backtracking based Sudoku solver written in C++.

*/
#include <math.h>
#include <array>
#include <iostream>
#include <exception>

#include "constants.h"
#include "errors.h"
#include "board.h"
#include "solver.h"


////////////////////////
// Grid related stuff //
////////////////////////
std::string getGridString() {
    std::string text ("");

    // Get a string that is 81 chars long from the user.
    while (1) {
        std::cout << "Enter the grid: ";
        std::getline(std::cin, text);
        if (text.size() == SIZE*SIZE) {
            break;
        }
        std::cout << "Need " << SIZE*SIZE << " chars, got " << text.size() << "." << std::endl;
    }
    return text;
}


#ifdef DEBUG

void clearGrid() {
    // CSI n F
    std::cout << "\e[" << SIZE + (int) sqrt(SIZE)  << "F";
}

template <size_t N>
void printArray(std::array<int, N> array) {
    std::cout << "[";
    for (int i = 0; i < N - 1; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[N-1];
    std::cout << "]" << std::endl;
}
#endif


int main() {
    int retval;
    std::string grid;

    Board board;
    Solver solver;

    // Get the grid string from the user.
    grid = getGridString();

    // Try to convert the string to a the board.
    try {
        board = Board(grid);
    } catch (std::exception &err) {
        return 1;
    }
    std::cout << "Initial Board\n" << std::endl;
    // Display the board (aesthetic purpose)
    board.display(std::cout);

    // Solve the board (in place)
    retval = solver.solve(board);

    // Give the output
    if (retval == SOLVED) {
        // Display the solved board
        std::cout << "\nSolved Board\n" << std::endl;
        board.display(std::cout);
    } else if (retval == MULTIPLE_SOLUTIONS) {
        // Board has multiple solutions, fail
        std::cerr << "Given grid has multiple solutions." << std::endl;
    } else if (retval == NO_SOLUTIONS) {
        // Board has no solutions
        std::cerr << "Given grid has no solutions." << std::endl;
    }
    return retval;
}

#undef ERROR
/*
    Board class
*/

/*
    Solver class
*/


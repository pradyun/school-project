#include <algorithm>
#include "solver.h"

void Solver::calculatePeersAndUnits(int row, int col) {
    // Same row
    for (int col_i = 0; col_i < SIZE; col_i++) {
        if (col_i != col) {
            square tmp_sqr;
            tmp_sqr.row = row;
            tmp_sqr.col = col_i;
            peers[row][col].push_back(tmp_sqr);
        }
    }
    // Same column
    for (int row_i = 0; row_i < SIZE; row_i++) {
        if (row_i != row) {
            square tmp_sqr;
            tmp_sqr.row = row_i;
            tmp_sqr.col = col;
            peers[row][col].push_back(tmp_sqr);
        }
    }

    // Same Unit
    int n = sqrt(SIZE);  // Longer names made the loops super unreadable
    for (int row_b = (row / n) * n; row_b < (row / n) * n + n; row_b++) {
        for (int col_b = (col / n) * n; col_b < (col / n) * n + n; col_b++) {
            if (row_b != row and col_b != col) {
                square tmp_sqr;
                tmp_sqr.row = row_b;
                tmp_sqr.col = col_b;
                peers[row][col].push_back(tmp_sqr);
            }
        }
    }
}

Solver::Solver() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            calculatePeersAndUnits(row, col);
        }
    }
}

Solver::~Solver() {
}

// Backtracking algorithm
bool Solver::solve(Board& board) {
    bool retval = backtrack_solve(board);
    std::cout << "Solved:" << std::endl;
    return retval;
}


bool Solver::backtrack_solve(Board& board) {
    int row, col;
    std::cout << "Solving " << board.as_string() << "\r";

    if (not findUnassigned(board, row, col)) {
        return true;
    }
    for (int i = 0; i < SIZE; i++) {
        int val = i + 1;
        if (isSafe(board, row, col, val)) {
            board.set(row, col, val);
            if (backtrack_solve(board)) {
                return true;
            }
            board.set(row, col, EMPTY);
        }
    }
    return false;
}
bool Solver::isSafe(Board board, int row, int col, int val) {
    for (std::vector<square>::iterator i = peers[row][col].begin(); i != peers[row][col].end(); ++i) {
        square sqr = *i;
        if (board.get(sqr.row, sqr.col) == val) {
            return false;
        }
    }
    return true;
}

bool Solver::findUnassigned(Board board, int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board.get(row, col) == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

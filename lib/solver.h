#ifndef SUDUKU_SOLVER_H
#define SUDUKU_SOLVER_H

#include <vector>
#include "math.h"
#include "board.h"

// Used in definition of peers.
struct square {
    int row;
    int col;
};


class Solver {

private:

    bool backtrack_solve(Board& board);
    void calculatePeersAndUnits(int row, int col);

public:
    Solver();
    ~Solver();

    std::array<std::array<std::vector<square>, SIZE>, SIZE> peers;

    bool isSafe(Board board, int row, int col, int val);
    bool findUnassigned(Board board, int& row, int& col);

    bool solve(Board& board);

};

#endif

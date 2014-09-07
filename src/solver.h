#ifndef _SUDOKU_SOLVER_H_
#define _SUDOKU_SOLVER_H_ 1

#include <array>
#include <algorithm>

#include "board.h"
#include "errors.h"
#include "constants.h"

// This is a completely declared class.
class Possible {

    private:
       std::array<bool, 9> vals;

    public:
        Possible() {
            // 9 true's
            vals = {true, true, true, true, true, true, true, true, true};
        }

        bool is_on(int i) const {
            return vals[i-1];
        }

        int count() const {
            return std::count(vals.begin(), vals.end(), true);
        }

        void eliminate(int i) {
            vals[i-1] = false;
        }

        int val() const {
            auto it = std::find(vals.begin(), vals.end(), true);
            return (it != vals.end() ? 1 + (it - vals.begin()) : -1);
        }
};

class Solver {

    private:
        std::array<Possible, SIZE*SIZE> values;

    public:
        Solver();
        ~Solver();

        int solve(Board& grid);
};

#endif

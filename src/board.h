#ifndef _SUDOKU_BOARD_H_
#define _SUDOKU_BOARD_H_ 1

#include <array>
#include <string>
#include <iostream>
#include <math.h>

#include "errors.h"
#include "constants.h"

class Board {

    private:
        std::array<int, SIZE*SIZE> grid;
        std::array<int, SIZE*SIZE> parse_string(std::string input);

    public:
        Board();
        Board(std::string input);
        ~Board();

        bool is_solved();
        void display(std::ostream& stream);

        bool is_valid(int index);
        bool assign(int k, int val);

        std::array<int, SIZE> row(int index);
        std::array<int, SIZE> col(int index);
};

#endif

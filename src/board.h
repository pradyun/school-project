#ifndef _SUDOKU_BOARD_H_
#define _SUDOKU_BOARD_H_ 1

#include <array>
#include <string>
#include <iostream>
#include <stdexcept>
#include <math.h>

#include "errors.h"
#include "constants.h"

class Board {

    private:
        std::array<int, SIZE*SIZE> grid;
        std::array<int, SIZE*SIZE> parse_string(std::string input);
        void displayNumbers(int y, std::ostream& stream);
        void displayLineIfNeeded(int y, std::ostream& stream);

    public:
        Board();
        Board(std::string input);
        ~Board();

        void display(std::ostream& stream);

        int get(int index);
        bool assign(int index, int val);

        std::array<int, SIZE> row(int index);
        std::array<int, SIZE> col(int index);
};

#endif

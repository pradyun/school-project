#ifndef SUDUKU_BOARD_H
#define SUDUKU_BOARD_H

#include <array>
#include <string>
#include <iostream>
#include "constants.h"

#if DEBUG > 1
static int id = 0;
#endif


class Board {

private:
    std::array<std::array<int, SIZE>, SIZE> board_grid;

    void displayNumbers(int row, std::ostream& stream);
    void displayLineIfNeeded(int row, std::ostream& stream);

public:
    Board();
    ~Board();

    // Virtuals for Google Mock!
    virtual int get(int row, int column);
    virtual bool set(int row, int column, int value);

    void display(std::ostream& stream);
    std::string as_string();

};

// Function for gettting a board from a user string.
bool initializeBoardFromString(Board& board, std::string str);

#endif

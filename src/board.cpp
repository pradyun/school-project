#include "board.h"

Board::Board(std::string input) {
    grid = parse_string(input);
}
Board::~Board() {}
Board::Board() {}

std::array<int, SIZE*SIZE> Board::parse_string(std::string input) {
    char ch;
    std::array<int, SIZE*SIZE> retval;
    // Copy that string into the grid, in the form of integers
    for (unsigned int i = 0; i < input.size(); i++) {
        ch = input[i];
        if (ch >= '1' && ch <= '9') {
            retval[i] = ch - '0'; // integer value of the character.
        } else if (ch == '0' || ch == '.') {
            retval[i] = EMPTY;
        } else {
            char error_string[50];
            sprintf(error_string, "Invalid character '%c' in input (index %d)\n" , ch, i);
            throw InvalidGridError((std::string) error_string);
            // InvalidInputError error;
            // throw error;
        }
    }
    return retval;
}

void Board::display(std::ostream& stream) {
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            stream << grid[i + k*SIZE];
            if (!((k + 1) % (int) sqrt(SIZE)) && ((k + 1) < SIZE)) {
                stream << "|";
            }
        }
        stream << std::endl;
        if (!((i + 1) % (int) sqrt(SIZE)) && ((i + 1) < SIZE)) {
            stream << std::string(SIZE + (int) sqrt(SIZE), '-') << std::endl;
        }
    }
}

std::array<int, SIZE> Board::col(int index) {
    int col_no = index / SIZE;
    std::array<int, SIZE> row;

    for (int i = 0; i < SIZE; i++) {
        row[i] = grid[col_no + i*SIZE];
    }

    return row;
}

std::array<int, SIZE> Board::row(int index) {
    int row_no = index % SIZE;
    std::array<int, SIZE> row;

    for (int i = 0; i < SIZE; i++) {
        row[i] = grid[row_no*SIZE + i];
    }

    return row;
}

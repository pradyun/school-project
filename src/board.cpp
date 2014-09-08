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
        } else if (ch == '0' || ch == '.' || ch == ' ') {
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
void Board::displayNumbers(int y, std::ostream& stream) {
    if (!(y < SIZE)) {
        return;
    }
    int index, sqr_size = sqrt(SIZE);
    stream << "| ";
    for (int x = 0; x < SIZE; x++) {
        index = x + y*SIZE;
        if (grid[index] == EMPTY) {
            stream << "  ";
        } else {
            stream << grid[index] << " ";
        }
        if ((x +1) % sqr_size == 0 && x != SIZE-1) {
            stream << "| ";
        }
    }
    stream << "|" << std::endl;
}

void Board::displayLineIfNeeded(int y, std::ostream& stream) {
    if (y % 3 == 0) {
        int sqr_size = sqrt(SIZE);
        stream << "+-";
        for (int x = 0; x < SIZE; x++) {
            stream << "--";
            if ((x +1) % sqr_size == 0 && x != SIZE-1) {
                stream << "+-";
            }
        }
        stream << "+" << std::endl;
    }
}

void Board::display(std::ostream& stream) {
    int y;
    for (y = 0; y <= SIZE; y++) {
        displayLineIfNeeded(y, stream);
        displayNumbers(y, stream);
    }
}

int Board::get(int index) {
    if (index >= grid.size()) {
        char buffer[50];
        sprintf(buffer, "'index' should be less than %d.", (int) grid.size());
        throw std::out_of_range(buffer);
    }
    return grid[index];
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

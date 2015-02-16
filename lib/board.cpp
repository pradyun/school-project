#include <cmath>

#include "board.h"


bool initializeBoardFromString(Board& board, std::string str) {
#if DEBUG > 1
    LOG("initializeBoardFromString(board " << ", " << "std::string('" << str << "')" << ")");
#endif
    if (str.size() != SIZE*SIZE) {
        return false;
    }
    int grid[SIZE][SIZE];
    // Validate input
    for (unsigned int row = 0; row < SIZE; row++) {
        for (unsigned int col = 0; col < SIZE; col++) {
            unsigned int index = row*SIZE + col;

            char ch = str[index];
            if (ch >= '0' && ch <= '9') {
                grid[row][col] = ch - '0';
            } else if (ch == '.' || ch == ' ') {
                grid[row][col] = EMPTY;
            } else {
                return false;
            }
        }
    }
    // Assign input
    for (unsigned int row = 0; row < SIZE; row++) {
        for (unsigned int col = 0; col < SIZE; col++) {
            board.set(row, col, grid[row][col]);
        }
    }
    return true;
}

Board::Board() {
#if DEBUG > 1
    LOG("Board::Board(" << ++id << ")");
#endif
    // Initialize grid as empty!
    for (unsigned int row = 0; row < SIZE; row++) {
        for (unsigned int col = 0; col < SIZE; col++) {
            set(row, col, EMPTY);
        }
    }
}

Board::~Board() {
}

std::string Board::as_string() {
    std::string retval;

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            int val = get(row, col);
            if (val == EMPTY) {
                retval.append(".");
            } else {
                retval.append(std::to_string(static_cast<long long>(val)));
            }
        }
    }
    return retval;
}

void Board::display(std::ostream& stream) {
#if DEBUG > 1
    LOG("Board::display(stream)");
#endif
    int row;
    for (row = 0; row <= SIZE; row++) {
        displayLineIfNeeded(row, stream);
        displayNumbers(row, stream);
    }
}

void Board::displayNumbers(int row, std::ostream& stream) {
    if (row >= SIZE) {
        return;
    }

    int sqr_size = sqrt(float(SIZE));

    stream << "| ";
    for (int column = 0; column < SIZE; column++) {
        int val = get(row, column);
        if (val == EMPTY) {
            stream << "  ";
        } else {
            stream << val << " ";
        }
        if ((column + 1) % sqr_size == 0 && (column + 1) != SIZE) {
            stream << "| ";
        }
    }
    stream << "|" << std::endl;
}

void Board::displayLineIfNeeded(int row, std::ostream& stream) {
    int sqr_size = sqrt(float(SIZE));
    if (row % sqr_size != 0) {
        return;
    }
    stream << "+-";
    for (int column = 0; column < SIZE; column++) {
        stream << "--";
        if ((column + 1) % sqr_size == 0 && (column + 1) != SIZE) {
            stream << "+-";
        }
    }
    stream << "+" << std::endl;
}

int Board::get(int row, int col) {
#if DEBUG > 2
    LOG("Board::get(" << row << ", " << col << ")");
#endif
    if (row >= SIZE || col >= SIZE) {
        return INVALID;
    }
    return board_grid[row][col];
}

bool Board::set(int row, int col, int value) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
#if DEBUG > 2
    LOG("Board::set(" << row << ", " << col << ", " << value << ")");
#endif
    board_grid[row][col] = value;
    return true;
}

#include <string>
#include <iostream>

#include "../lib/solver.h"

// This function is manually checked (Has no automated tests).
// States to test:
//   - != 81 valid chars given             (Re-asks)
//   - == 81 valid chars given, 1+ invalid (Re-asks)
//   - == 81 valid chars given, all valid  (Returns)
std::string getGridString() {
    char ch;
    bool has_invalid_char;
    std::string text ("");

    // Get a string that is 81 chars long from the user.
    while (1) {
        std::cout << "Input : ";
        std::getline(std::cin, text);
        if (text.size() == SIZE*SIZE) {
            has_invalid_char = false;
            for (unsigned int i = 0; i < text.size(); i++) {
                ch = text[i];
                if (ch >= '1' && ch <= '9') {
                    continue;
                } else if (ch == '.' || ch == '0') {
                    continue;
                } else {
                    std::cout << "Invalid character '" << ch
                              << "' at index " << i << "." << std::endl;
                    has_invalid_char = true;
                    break;
                }
            }
            if (has_invalid_char) {
                continue;
            } else {
                break;
            }
        }
        std::cout << "Need " << SIZE*SIZE << " chars, got "
                  << text.size() << "." << std::endl;
    }
    return text;
}

int main(int argc, char const *argv[]) {
    // Welcome message
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Welcome to this awesome Sudoku solver!" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    // Inform of the format
    std::cout << "The grid input format is as follows: " << std::endl
              << " - '.' or '0' for empty spaces and " << std::endl
              << " - '1' to '9' for the filled places." << std::endl;
    std::cout << std::endl;

    // Take the input
    std::string input = getGridString();

    // Make the board
    Board board;
    initializeBoardFromString(board, input);

    Solver solver;
    if (!solver.solve(board)) {
        std::cout << "Could not solve! :(" << std::endl;
    } else {
        std::cout << std::endl << "Let's see how that looks:" << std::endl;
        board.display(std::cout);
    }

    return 0;
}

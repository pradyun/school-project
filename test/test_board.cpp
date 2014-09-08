#include <string>
#include <sstream>

#include "../src/board.h"
#include "../src/constants.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(Board, TakesValidStringWithoutError) {
    ASSERT_NO_THROW(Board board(
        // '0', ' ' and '.' represent empty blocks
        "0. 456789456789123789123456234567891567891234891234567345678912678912345912345678"
    ));
    /*
    +-----------------------+
    |       | 4 5 6 | 7 8 9 |
    | 4 5 6 | 7 8 9 | 1 2 3 |
    | 7 8 9 | 1 2 3 | 4 5 6 |
    |-------+-------+-------|
    | 2 3 4 | 5 6 7 | 8 9 1 |
    | 5 6 7 | 8 9 1 | 2 3 4 |
    | 8 9 1 | 2 3 4 | 5 6 7 |
    |-------+-------+-------|
    | 3 4 5 | 6 7 8 | 9 1 2 |
    | 6 7 8 | 9 1 2 | 3 4 5 |
    | 9 1 2 | 3 4 5 | 6 7 8 |
    +-----------------------+
    */
}
// Even though this situation shall not occur again.
TEST(Board, RaisesErrorOnInvalidString) {
    ASSERT_THROW(
        Board board(
            "a23456789456789123789123456234567891567891234891234567345678912678912345912345678"
        ),
        InvalidGridError
    );
    /*
    +-----------------------+
    | a 2 3 | 4 5 6 | 7 8 9 |
    | 4 5 6 | 7 8 9 | 1 2 3 |
    | 7 8 9 | 1 2 3 | 4 5 6 |
    |-------+-------+-------|
    | 2 3 4 | 5 6 7 | 8 9 1 |
    | 5 6 7 | 8 9 1 | 2 3 4 |
    | 8 9 1 | 2 3 4 | 5 6 7 |
    |-------+-------+-------|
    | 3 4 5 | 6 7 8 | 9 1 2 |
    | 6 7 8 | 9 1 2 | 3 4 5 |
    | 9 1 2 | 3 4 5 | 6 7 8 |
    +-----------------------+
    */
}

TEST(Board, DisplayFilled) {
    std::ostringstream stream;
    std::string expected;
    Board board(
        "123456789456789123789123456234567891567891234891234567345678912678912345912345678"
    );
    // Expected board
    expected.append("+-------+-------+-------+\n");
    expected.append("| 1 2 3 | 4 5 6 | 7 8 9 |\n");
    expected.append("| 4 5 6 | 7 8 9 | 1 2 3 |\n");
    expected.append("| 7 8 9 | 1 2 3 | 4 5 6 |\n");
    expected.append("+-------+-------+-------+\n");
    expected.append("| 2 3 4 | 5 6 7 | 8 9 1 |\n");
    expected.append("| 5 6 7 | 8 9 1 | 2 3 4 |\n");
    expected.append("| 8 9 1 | 2 3 4 | 5 6 7 |\n");
    expected.append("+-------+-------+-------+\n");
    expected.append("| 3 4 5 | 6 7 8 | 9 1 2 |\n");
    expected.append("| 6 7 8 | 9 1 2 | 3 4 5 |\n");
    expected.append("| 9 1 2 | 3 4 5 | 6 7 8 |\n");
    expected.append("+-------+-------+-------+\n");

    board.display(stream);

    ASSERT_EQ(stream.str(), expected);
}

TEST(Board, DisplayNonFilled) {
    std::ostringstream stream;
    std::string expected;
    Board board(
        " . 0 . 0 456789123789123456234567891567891234891234567345678912678912345912345678"
    );
    // Expected board
    expected.append("+-------+-------+-------+\n");
    expected.append("|       |       |       |\n");
    expected.append("| 4 5 6 | 7 8 9 | 1 2 3 |\n");
    expected.append("| 7 8 9 | 1 2 3 | 4 5 6 |\n");
    expected.append("+-------+-------+-------+\n");
    expected.append("| 2 3 4 | 5 6 7 | 8 9 1 |\n");
    expected.append("| 5 6 7 | 8 9 1 | 2 3 4 |\n");
    expected.append("| 8 9 1 | 2 3 4 | 5 6 7 |\n");
    expected.append("+-------+-------+-------+\n");
    expected.append("| 3 4 5 | 6 7 8 | 9 1 2 |\n");
    expected.append("| 6 7 8 | 9 1 2 | 3 4 5 |\n");
    expected.append("| 9 1 2 | 3 4 5 | 6 7 8 |\n");
    expected.append("+-------+-------+-------+\n");

    board.display(stream);

    ASSERT_EQ(stream.str(), expected);
}

TEST(Board, ArrangedValuesCorrectly) {
    Board board(
        " . 0 . 0 456789123789123456234567891567891234891234567345678912678912345912345678"
    );
    ASSERT_EQ(board.get(80), 8);
    ASSERT_EQ(board.get(40), 9);
    ASSERT_EQ(board.get(10), 5);
    ASSERT_EQ(board.get( 9), 4);
    ASSERT_EQ(board.get( 8), EMPTY);
    ASSERT_EQ(board.get( 5), EMPTY);
    ASSERT_EQ(board.get( 0), EMPTY);
}

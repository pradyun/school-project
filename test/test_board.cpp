#include <string>
#include <sstream>

#include "gmock/gmock.h"
#include "../lib/board.h"

TEST(Board, ConstructorCheck) {
    ASSERT_NO_THROW(Board board);
}

TEST(Board, InitializesWithValidString) {
    Board board;
    ASSERT_EQ(
        initializeBoardFromString(
            board,
            "0. 456789"
            "456789123"
            "789123456"
            "234567891"
            "567891234"
            "891234567"
            "345678912"
            "678912345"
            "912345678"
        ), true
    );
}

TEST(Board, RefusesOnInitializationWithStringWithInvalidCharacter) {
    Board board;
    ASSERT_EQ(
        initializeBoardFromString(
            board,
            "a23456789"
            "456789123"
            "789123456"
            "234567891"
            "567891234"
            "891234567"
            "345678912"
            "678912345"
            "912345678"
        ), false
    );
}

TEST(Board, RefusesOnInitializationWithStringWithInvalidSize) {
    Board board;
    ASSERT_EQ(
        initializeBoardFromString(
            board,
            "2"  // Not 81 chars
        ), false
    );
}

TEST(Board, DisplaysFilledBoardCorrectly) {
    std::string expected;
    std::ostringstream stream;

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

    Board board;
    initializeBoardFromString(
        board,
        "123456789"
        "456789123"
        "789123456"
        "234567891"
        "567891234"
        "891234567"
        "345678912"
        "678912345"
        "912345678"
    );
    board.display(stream);

    ASSERT_EQ(expected, stream.str());
}

TEST(Board, DisplaysUnFilledBoardCorrectly) {
    std::string expected;
    std::ostringstream stream;

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


    Board board;
    initializeBoardFromString(
        board,
        " . 0 . 0 "
        "456789123"
        "789123456"
        "234567891"
        "567891234"
        "891234567"
        "345678912"
        "678912345"
        "912345678"
    );
    board.display(stream);

    ASSERT_EQ(expected, stream.str());
}

TEST(Board, AccessingValues) {
    Board board;
    ASSERT_EQ(EMPTY, board.get(0, 0));
    ASSERT_EQ(EMPTY, board.get(1, 1));
    ASSERT_EQ(EMPTY, board.get(4, 4));
    ASSERT_EQ(EMPTY, board.get(4, 5));
    ASSERT_EQ(EMPTY, board.get(8, 8));

    initializeBoardFromString(
        board,
        " . 0 . 0 "
        "456789123"
        "789123456"
        "234567891"
        "567891234"
        "891234567"
        "345678912"
        "678912345"
        "912345678"
    );

    ASSERT_EQ(EMPTY, board.get(0, 0));

    ASSERT_EQ(5, board.get(1, 1));
    ASSERT_EQ(9, board.get(4, 4));
    ASSERT_EQ(1, board.get(4, 5));
    ASSERT_EQ(8, board.get(8, 8));
}

TEST(Board, SettingValues) {
    Board board;
    initializeBoardFromString(
        board,
        " . 0 . 0 "
        "456789123"
        "789123456"
        "234567891"
        "567891234"
        "891234567"
        "345678912"
        "678912345"
        "912345678"
    );

    ASSERT_EQ(EMPTY, board.get(0, 0));
    ASSERT_EQ(true,  board.set(0, 0, 1));
    ASSERT_EQ(1,     board.get(0, 0));

    ASSERT_EQ(EMPTY, board.get(0, 4));
    ASSERT_EQ(true,  board.set(0, 4, 2));
    ASSERT_EQ(2,     board.get(0, 4));

    ASSERT_EQ(EMPTY, board.get(0, 8));
    ASSERT_EQ(true,  board.set(0, 8, 8));
    ASSERT_EQ(8,     board.get(0, 8));

    ASSERT_EQ(4,     board.get(1, 0));
    ASSERT_EQ(true,  board.set(1, 0, EMPTY));
    ASSERT_EQ(EMPTY, board.get(1, 0));
}

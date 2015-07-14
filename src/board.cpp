#include "board.hpp"
#include "exceptions.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace checkers {
    Board::Board() {
        for (int row = 0; row != BOARD_SIZE; ++row) {
            for (int col = 0; col != BOARD_SIZE; ++col) {
                board[row][col] = EMPTY;
            }
        }
    }

    void Board::placePiece(char player, int x, int y) {
        if (board[x][y] != EMPTY) {
            throw InvalidMoveException("There is already a piece there!");
        } else {
            board[x][y] = player;
        }
    }

    void Board::removePiece(int x, int y) {

    }

    void Board::displayBoard() {
        for (int row = 0; row != BOARD_SIZE; ++row) {
            cout << row << " | ";
            for (int col = 0; col != BOARD_SIZE; ++col) {
                cout << board[row][col];
            }
            cout << endl;
        }

    }
}

#include "board.hpp"
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
        board[x][y] = player;
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

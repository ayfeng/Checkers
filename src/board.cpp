#include "board.hpp"
#include "exceptions.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace checkers {
    Board::Board() {
        for (int row = 0; row != BOARD_SIZE; ++row) {
            for (int col = 0; col != BOARD_SIZE; ++col) {
                if (!(row==BOARD_SIZE/2 - 1 || row==BOARD_SIZE/2)) { //keep center rows free
                    if (row%2==0 && col%2==1) {
                        board[row][col] = (row>=BOARD_SIZE/2) ? BLACK : WHITE;
                    } else if (row%2==1 && col%2==0) {
                        board[row][col] = (row<BOARD_SIZE/2) ? WHITE : BLACK;
                    } else {
                        board[row][col] = EMPTY;
                    }
                } else {
                    board[row][col] = EMPTY; //TODO? repetition? better way to do this?
                }
            }
        }
    }

    void Board::placePiece(char player, int x, int y) {
        if (spotOccupied(x, y)) {
            throw InvalidMoveException("There is already a piece there!");
        } else {
            board[x][y] = player;
        }
    }

    bool Board::spotOccupied(int x, int y) {
        return board[x][y] != EMPTY;
    }

    void Board::removePiece(int x, int y) {
        board[x][y] = EMPTY;
    }

    void Board::displayBoard() {
        cout << "X | ";
        for (int col = 0; col != BOARD_SIZE; ++col) {
            cout << col << " ";
        }
        cout << endl;

        for (int row = 0; row != BOARD_SIZE; ++row) {
            cout << row << " | ";
            for (int col = 0; col != BOARD_SIZE; ++col) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
    }
}

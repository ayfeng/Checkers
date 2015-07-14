#include "logic.hpp"
#include "player.hpp"
#include "board.hpp"
#include "move.hpp"
#include "pair.hpp"
#include "exceptions.hpp"

#include <iostream>

namespace checkers {
    Logic::Logic(Player* p1, Player* p2, Board* board): playerOne(p1), playerTwo(p2), gameboard(board) { 
        currentPlayer = playerOne; //TODO: implement randomness or choose
    }

    bool Logic::gameOver() {
        return playerOne->getPoints() == (BOARD_SIZE*BOARD_SIZE)/2 || playerTwo->getPoints() == (BOARD_SIZE*BOARD_SIZE)/2;
    }
    
    void Logic::makeMove(Pair<Move, Move> origin_destination_pair) {
        try {
            std::cout << "MAKING MOVE FROM " << origin_destination_pair.first.row << "," << origin_destination_pair.first.col << " TO "<< origin_destination_pair.second.row << "," << origin_destination_pair.second.col << std::endl;
            gameboard->placePiece(currentPlayer->getColor(), origin_destination_pair.second.row, origin_destination_pair.second.col);
            gameboard->removePiece(origin_destination_pair.first.row, origin_destination_pair.first.col);
        } catch(const InvalidMoveException& e) {
            std::cout << e.what() << std::endl;
        }

        switchTurns();
    }

    bool Logic::moveInBounds(const Move& move) const {
        return (0 <= move.row && move.row < BOARD_SIZE) && (0 <= move.col && move.col < BOARD_SIZE);
    }

    bool Logic::moveReachable(const Move& origin, const Move& destination) const {
        //TODO: Can reach farther if eating pieces
        return (destination.row == origin.row+1 || destination.row == origin.row-1) && (destination.col == origin.row+1 || destination.row == origin.row-1);
    }

    bool Logic::moveIsLegal(const Move& origin, const Move& destination) const {
        return moveInBounds(destination) && moveReachable(origin, destination) && !gameboard->spotOccupied(destination.row, destination.col);
    }

    char Logic::getCurrentPlayerColor() const {
        return currentPlayer->getColor();
    }

    void Logic::switchTurns() {
        currentPlayer = (currentPlayer == playerOne ? playerTwo : playerOne);
    }
}

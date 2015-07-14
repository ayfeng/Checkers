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
        //TODO EATING PIECES
        const Move& origin = origin_destination_pair.first;
        const Move& dest = origin_destination_pair.second;
        unsigned char moveGoesRight = (origin.col<dest.col) ? 1 : -1; //-1 if goes left, 1 if right
        
        try {
            if (!moveIsLegal(origin, dest))
                throw InvalidMoveException("Error occurred making the move. Please try again.");

            std::cout << "MAKING MOVE FROM " << origin.row << "," << origin.col << " TO "<< dest.row << "," << dest.col << std::endl;
            if (gameboard->spotOccupied(dest.row, dest.col)) {
                currentPlayer->incrementPointCounter();
                gameboard->removePiece(dest.row, dest.col);
                if (currentPlayer->getColor() == BLACK)
                    gameboard->placePiece(currentPlayer->getColor(), dest.row-1, dest.col+moveGoesRight);
                else if (currentPlayer->getColor() == WHITE)
                    gameboard->placePiece(currentPlayer->getColor(), dest.row+1, dest.col+moveGoesRight);
            }
            gameboard->placePiece(currentPlayer->getColor(), dest.row, dest.col);
            gameboard->removePiece(origin.row, origin.col);
            switchTurns();
        } catch(const InvalidMoveException& e) {
            std::cout << e.what() << std::endl;
        }

    }

    bool Logic::moveInBounds(const Move& move) const {
        return (0 <= move.row && move.row < BOARD_SIZE) && (0 <= move.col && move.col < BOARD_SIZE);
    }

    bool Logic::moveReachable(const Move& origin, const Move& destination) const {
        //TODO: Can reach farther if eating pieces
        return (destination.row == origin.row+1 || destination.row == origin.row-1) && (destination.col == origin.row+1 || destination.row == origin.row-1);
    }

    bool Logic::moveIsLegal(const Move& origin, const Move& destination) const {
        //TODO fix logic
        return gameboard->spotOccupied(origin.row, origin.col) && moveInBounds(destination) && moveReachable(origin, destination) && !gameboard->spotOccupied(destination.row, destination.col);
    }

    char Logic::getCurrentPlayerColor() const {
        return currentPlayer->getColor();
    }

    void Logic::switchTurns() {
        currentPlayer = (currentPlayer == playerOne ? playerTwo : playerOne);
    }
}

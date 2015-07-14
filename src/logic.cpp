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
            validateMove(origin, dest);

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

    void Logic::validateMove(const Move& origin, const Move& destination) const {
        //TODO fix logic
        if (!gameboard->getPieceAt(origin.row, origin.col)==getCurrentPlayerColor())
            throw InvalidMoveException("You must have a piece in the selected origin location to move from there");
        if (!moveInBounds(destination))
            throw InvalidMoveException("Move goes out of bounds");
        if (!moveReachable(origin, destination))
            throw InvalidMoveException("Selected destination is not reachable from your selected origin. Pieces can only move one space diagonally forward or eat an enemy piece.");
    }

    char Logic::getCurrentPlayerColor() const {
        return currentPlayer->getColor();
    }

    void Logic::switchTurns() {
        currentPlayer = (currentPlayer == playerOne ? playerTwo : playerOne);
    }
}

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "player.hpp"
#include "board.hpp"
#include "move.hpp"
#include "pair.hpp"

namespace checkers {
    class Logic {
        public: 
            Logic(Player* p1, Player* p2, Board* board);
            bool gameOver();
            void makeMove(Pair<Move, Move> origin_destination_pair);
            char getCurrentPlayerColor() const;
        private:
            void switchTurns();
            bool moveInBounds(const Move& move) const;
            Player* playerOne;
            Player* playerTwo;
            Player* currentPlayer;
            Board* gameboard;
    };
}

#endif

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
            static bool moveInBounds(const Move& move);
            static bool moveReachable(const Move& origin, const Move& destination);
        private:
            void switchTurns();
            void validateMove(const Move& origin, const Move& destination) const;
            Player* playerOne;
            Player* playerTwo;
            Player* currentPlayer;
            Board* gameboard;
    };
}

#endif

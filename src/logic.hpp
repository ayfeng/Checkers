#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "player.hpp"
#include "board.hpp"
#include "move.hpp"

namespace checkers {
    class Logic {
        public: 
            Logic(Player* p1, Player* p2, Board* board);
            bool gameOver();
            void makeMove(Move move);
        private:
            Player* playerOne;
            Player* playerTwo;
            Player** currentPlayer;
            Board* gameboard;
    };
}

#endif

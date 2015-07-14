#ifndef BOARD_HPP
#define BOARD_HPP

#define BOARD_SIZE 6
#define EMPTY '.'
#define BLACK 'B'
#define WHITE 'W'

namespace checkers {

    class Board {
        public:
            Board(); //initialize board of size x size dimensions
            void placePiece(char player, int x, int y); //throws InvalidMoveException if piece exists
            void removePiece(int x, int y); //throws InvalidMoveException if no piece 
            void displayBoard(); //print board
        private:
            char board[BOARD_SIZE][BOARD_SIZE];
    };
}
#endif

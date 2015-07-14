#include <iostream>
#include <string>
#include <cmath>

#include "player.hpp"
#include "ai.hpp"
#include "board.hpp"
#include "piece.hpp"
#include "logic.hpp"
#include "move.hpp"
#include "pair.hpp"

using namespace checkers;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::max;
using std::min;

class Interface {
    public:
        Pair<Move, Move> getMove(char color) {
            int row, col, dest;
            cout << "SELECTING PIECE..." << endl;
            cout << "ENTER ROW: ";
            cin >> row;

            cout << "ENTER COL: ";
            cin >> col;

            
            cout << "SELECT DESTINATION..." << endl;
            cout << "ENTER COLUMN TO MOVE THE PIECE TO: ";
            cin >> dest;

            Move origin = Move();
            origin.row = row;
            origin.col = col;

            Move destination = Move();
            destination.row = (color==WHITE ? min(row+1, BOARD_SIZE) : max(row-1, 0)); //TODO better boundary checking
            destination.col = dest;
            return Pair<Move, Move>(origin, destination);
        }

        void run() {
            cout << "What color do you want to be (B or W)?" << endl;
            char color;
            cin >> color;

            Board board = Board();
            Player player(color), computer(color=='W' ? 'B': 'W');
            Logic logic = Logic(&player, &computer, &board);

            Player* current = &player;
            while (!logic.gameOver()) {
                player.printScore();
                computer.printScore();
                board.displayBoard();

                logic.makeMove(getMove(logic.getCurrentPlayerColor()));
                cout << endl;
            }
        }
};

int main() {
    Interface interface = Interface();
    interface.run();

    return 0;
}

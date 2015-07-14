#include <iostream>
#include <string>

#include "player.hpp"
#include "ai.hpp"
#include "board.hpp"
#include "piece.hpp"
#include "logic.hpp"
#include "move.hpp"


using namespace checkers;

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Interface {
    public:
        Move getMove() {
            int row, col;
            cout << "ENTER ROW: ";
            cin >> row;

            cout << "ENTER COL: ";
            cin >> col;

            Move result = Move();
            result.row = row;
            result.col = col;
            return result;
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

                logic.makeMove(getMove());
            }
        }
};

int main() {
    Interface interface = Interface();
    interface.run();

    return 0;
}

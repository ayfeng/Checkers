#include <iostream>
#include <string>
#include <cmath>
#include <limits>

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
            //TODO BOUNDS CHCEKING
            int row, col, dest;

            cout << "===SELECTING A PIECE TO MOVE===" << endl;
            do {
                cout << "ENTER ROW: ";
                while(!(cin >> row)) {
                    cout << "INCORRECT INPUT. PLEASE TRY AGAIN." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "ENTER ROW: ";
                }

                if (!Logic::numberInBounds(row))
                    cout << "OUT OF BOUNDS. TRY AGAIN." << endl;
            } while(!Logic::numberInBounds(row));

            do {
                cout << "ENTER COL: ";
                while(!(cin >> col)) {
                    cout << "INCORRECT INPUT. PLEASE TRY AGAIN." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "ENTER COL: ";
                }

                if (!Logic::numberInBounds(col))
                    cout << "OUT OF BOUNDS. TRY AGAIN." << endl;
            } while(!Logic::numberInBounds(col));

            Move origin = Move();
            origin.row = row;
            origin.col = col;

            cout << "===SELECTING DESTINATION===" << endl;

            do {
                cout << "ENTER COLUMN TO MOVE THE PIECE TO: ";
                while(!(cin >> dest)) {
                    cout << "INCORRECT INPUT. PLEASE TRY AGAIN." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "ENTER COLUMN TO MOVE THE PIECE TO: ";
                }

                if (!Logic::numberInBounds(dest))
                    cout << "OUT OF BOUNDS. TRY AGAIN." << endl;
            } while(!Logic::numberInBounds(dest));

            Move destination = Move();
            destination.row = (color==WHITE ? min(row+1, BOARD_SIZE) : max(row-1, 0)); //TODO better boundary checking
            destination.col = dest;
            return Pair<Move, Move>(origin, destination);
        }

        void run() {
            char color;
            do {
                cout << "What color do you want to be (B or W)?: ";
                cin >> color;

                if (!(color==BLACK || color==WHITE))
                    cout << "Invalid choice. Please try again." << endl;
            } while(!(color==BLACK || color==WHITE));

            Board board = Board();
            Player player(color), computer(color=='W' ? 'B': 'W');
            Logic logic = Logic(&player, &computer, &board);

            Player* current = &player;
            while (!logic.gameOver()) {
                player.printScore();
                computer.printScore();
                board.displayBoard();
                cout << (logic.getCurrentPlayerColor()==BLACK?"BLACK":"WHITE") << " turn." << endl;

                logic.makeMove(getMove(logic.getCurrentPlayerColor()));
                cout << endl;
            }
            cout << "GAME OVER" << endl; //TODO victory message
        }
};

int main() {
    Interface interface = Interface();
    interface.run();

    return 0;
}

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using std::string;

namespace checkers {
    class Player {
        public:
            Player(char color);
            void printScore();
            char getColor() const;
            int getPoints() const;
            void incrementPointCounter();
        private:
            char color;
            int points;
    };
}
#endif

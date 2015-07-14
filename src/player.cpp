#include "player.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#define BLACK 'B'
#define WHITE 'W'

namespace checkers {
    Player::Player(char color) {
        this->color = color;
        this->points = 0;
    }

    void Player::printScore() {
        cout << "The " << (color==BLACK?"BLACK":"WHITE") << " player has captured " << getPoints() << " pieces." << endl;
    }

    char Player::getColor() const {
        return color;
    }

    int Player::getPoints() const {
        return points;
    }

    void Player::incrementPointCounter() {
        points += 1;
    }
}

#include "player.hpp"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

#define BLACK 'B'
#define WHITE 'W'
#define BOARD_SIZE 6

namespace checkers {
    Player::Player(char color) {
        this->color = color;
        this->points = 0;
    }

    void Player::printScore() {
        cout << "The " << (color==BLACK?"BLACK":"WHITE") << " player has captured " << getPoints() << " pieces." << endl;
    }

    char Player::getColor() {
        return color;
    }

    int Player::getPoints() {
        return points;
    }
}

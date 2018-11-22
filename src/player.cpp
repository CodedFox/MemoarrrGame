#include <iostream>
#include <string>

#include "player.h"
// #include "reward.h"



// A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
// Joe Remember Doe: left (active)
// Once endOfGame is true:
// Joe Remember Doe:  3 rubies
std::ostream& operator<<(std::ostream & os, const Player & p) {
    if (!p.endGame) {
        os << p.name << ": " << p.boardSide;
        
        if (p.active) {
            os << " (active)";
        } else {
            os << "inactive";
        }
    } else {
        os << p.name << ": " << p.rubies << " rubies";
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const Player::Side & s) {
    switch(s) {
        case Player::Side::top: os << "top"; break;
        case Player::Side::bottom: os << "bottom"; break;
        case Player::Side::left: os << "left"; break;
        case Player::Side::right: os << "right"; break;
        default: os << "Error - Board Side"; break;
    }
    return os;
}

// std::string Player::getName() {

//     return "";
// }

// void Player::setActive(bool) {

// }

// bool Player::isActive() {

//     return true;
// }

// int Player::getNRubies() {

//     return 0;
// }

// void Player::addReward( const Reward& ) {

// }

// void Player::setDisplayMode(bool endOfGame) {

//     endOfGame = false; // must be removed, inserted to solve variable not in use error
// }

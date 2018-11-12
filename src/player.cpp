#include <iostream>
#include <string>

#include "player.h"
#include "reward.h"
Player::Player() {}
Player::Player(std::string name, std::string bs) : playerName(name), boardSide(bs) {}
std::string Player::getName() const {

    return Player::playerName;
}

void Player::setActive(bool a) {
        Player::active = a;
}

bool Player::isActive() const {

    return Player::active;
}

int Player::getNRubies() const {

    return Player::numRubies;
}
std::string Player::getBoardSide() const {

    return Player::boardSide; 
}
void Player::addReward( const Reward& r) {
Player::numRubies += r.getNumRubies();
}

void Player::setDisplayMode(bool endOfGame) {
    std::string str = this->playerName + ":";
if (endOfGame) {
    str += std::to_string(this->numRubies);
    str += (this->numRubies>1?" rubies":" ruby");
    }
    else 
    { std::string act = this->isActive() ? " (active)" : " (inactive)";
        str += this->boardSide + act;
         }
    Player::displayMode = str;
}

std::ostream &operator<<(std::ostream &os, const Player &p){
    
    os << p.displayMode;
    return os;
}
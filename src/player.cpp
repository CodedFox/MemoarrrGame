#include <iostream>
#include <string>
#include <sstream>
#include "player.h"
#include "reward.h"
#include "config.h" //contains flags for testing
Player::Player() {}
Player::Player(std::string name, Side bs) : playerName(name), boardSide(bs) {}
std::string Player::getName() const {

    return Player::playerName;
}

void Player::setActive(bool a) {
        Player::active = a;
}

void Player::setSide(Side s) {
        Player::boardSide = s;
}

bool Player::isActive() const {

    return Player::active;
}

int Player::getNRubies() const {

    return Player::numRubies;
}
Player::Side Player::getSide() const {

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
            std::ostringstream stream;
            stream<<Player::getSide();
            std::string line = stream.str();
            str = line + act;
         }
    Player::displayMode = str;
}

std::ostream &operator<<(std::ostream &os, const Player &p){
    
    os << p.displayMode;
    return os;
}
std::ostream & operator<<(std::ostream &os, const Player::Side &bs) {
  std::string str;
  switch(bs) {     
    case Player::Side::top: str = "top"; break;
    case Player::Side::bottom: str = "bottom"; break;
    case Player::Side::left: str = "left"; break;
    case Player::Side::right: str = "right"; break;
    default: str = "Error in Board Side!"; break;
  }
  os << str;
  return os;
}
#ifdef TEST_PLAYER_
int main() {

    std::cout << "Testing Player" << std::endl;

    return 0;
}
#endif
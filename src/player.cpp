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
void Player::setNRubies(int n) {

    Player::numRubies = n;
}
Player::Side Player::getSide() const {

    return Player::boardSide; 
}
void Player::addReward( const Reward& r) {
Player::numRubies += r.getNumRubies();
}

void Player::setDisplayMode(bool endOfGame) {
    Player::displayMode = endOfGame;
}

std::ostream &operator<<(std::ostream &os, const Player &p){
        std::string str = p.playerName + ": ";
if (p.displayMode) {
    str += std::to_string(p.numRubies);
    str += (p.numRubies!=1?" rubies":" ruby");
    }
    else 
    { std::string act = p.isActive() ? " (active)" : " (inactive)";
            std::ostringstream stream;
            stream<<p.getSide();
            std::string line = stream.str();
            str += line + act;
         }
    
    os << str;
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
Player p("Bob",Player::Side::left);

std::cout << p.getName() << std::endl;
std::cout << p.getNRubies() << std::endl;
std::cout << p.getSide() << std::endl;
std::cout << p.isActive() << std::endl;
std::cout << p << std::endl;
p.setDisplayMode(true);
std::cout << p << std::endl;
p.setNRubies(3);
std::cout << p << std::endl;
p.setNRubies(1);
std::cout << p << std::endl;

std::cout << "Testing Player" << std::endl;

    return 0;
}
#endif
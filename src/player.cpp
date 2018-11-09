#include <iostream>
#include <string>

#include "player.h"
#include "reward.h"

std::string Player::getName() {

    return "";
}

void Player::setActive(bool) {

}

bool Player::isActive() {

    return true;
}

int Player::getNRubies() {

    return 0;
}

void Player::addReward( const Reward& ) {

}

void Player::setDisplayMode(bool endOfGame) {

    endOfGame = false; // must be removed, inserted to solve variable not in use error
    if(endOfGame){return;} //added to avoid set but not used
}

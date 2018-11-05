#include <iostream>
#include <string>

#include "player.h"
#include "reward.h"

std::string getName() {

    return "";
}

void setActive(bool) {

}

bool isActive() {

    return true;
}

int getNRubies() {

    return 0;
}

void addReward( const Reward& ) {

}

void setDisplayMode(bool endOfGame) {

    endOfGame = false; // must be removed, inserted to solve variable not in use error
}

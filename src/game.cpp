#include <iostream>
#include <string>

#include "game.h"
#include "player.h"
#include "card.h"
#include "config.h" //contains flags for testing
int Game::getRound() {

    return 0;
}

void Game::addPlayer( const Player& ) {

}

// Player& Game::getPlayer() {

// }

const Card* Game::getPreviousCard() {

    return nullptr;
}

const Card* Game::getCurrentCard() {

    return nullptr;
}

void Game::setCurrentCard( const Card*) {

}
#ifdef TEST_GAME_
int main() {

    std::cout << "Testing Game" << std::endl;

    return 0;
}
#endif
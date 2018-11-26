#include <iostream>
#include <string>

#include "game.h"
#include "player.h"
#include "card.h"

// void Game::addPlayer( const Player& p ) {
void Game::addPlayer( const std::string name) {
    if (players.size() < 4) {
        // players.insert(std::make_pair(p.getSide(), p));
        players.insert(std::make_pair(Side(players.size()), Player(name, Side(players.size()))));
    } else {
        throw "Maximum amount of players reached!";
    }
}

void Game::setCurrentCard( const Card* c ) {
    if (!previousCard) {
        previousCard = currentCard;
    } else {
        previousCard = const_cast<Card*>(c);
    }
    currentCard = const_cast<Card*>(c);
}

std::ostream & operator<<(std::ostream & os, const Game & g) {
    os << "=PLAYERS=" << std::endl;
    for(auto player : g.players) {
       os << player.second << std::endl;
    }
    os << std::endl << "=BOARD=" << std::endl;
    Board b = g.board;
    os << b;

    return os;
}
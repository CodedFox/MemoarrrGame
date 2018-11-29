#include <iostream>
#include <string>
#include <map>

#include "rules.h"
#include "game.h"

// returns true is previous and current card match; false otherwise.
bool Rules::isValid( const Game& g ) {
    if (g.getCurrentCard()->getAnimal() == g.getPreviousCard()->getAnimal()) {
        return true;
    }
    if (g.getCurrentCard()->getBackground() == g.getPreviousCard()->getBackground()) {
        return true;
    }
    return false;
}

// returns true if the number of rounds has reached 7.
bool Rules::gameOver( const Game& g ) {
    if (g.getRound() == 6) {
        return true;
    }
    return false;
}

// returns true if there is only one active Player left.
bool Rules::roundOver( const Game& g ) {
    Game& game = const_cast<Game&>(g);
    int count = 0;
    for (auto player : game.getPlayers()) {
        if (player.second.isActive()) {
            count++;
        }
    }
    return (count == 1);
}

const Player& Rules::getNextPlayer( const Game& g ) {
    Game& game = const_cast<Game&>(g);
    auto it = game.getCurrentPlayer();
    do {
        if(++it == game.getPlayers().end()) {
            it = game.getPlayers().begin();
        }
    } while (!((*it).second.isActive()));

    return (*it).second;
}

bool Rules::isValidSelection( Game& g, const Letter& l, const Number& n ) {
    if (!(l == Letter::C && n == Number::_3)) {
        if (!(g.isCardFaceUp(l, n))) {
            return true;
        }
    }
    return false;
}

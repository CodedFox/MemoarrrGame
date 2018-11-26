#include <iostream>
#include <string>

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
    int count = 0;
    for (auto player : g.getPlayers()) {
        if (player.second.isActive()) {
            count++;
        }
    }
    return (count == 1);
}

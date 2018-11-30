#include <iostream>
#include <string>
#include <map>

#include "rules.h"
#include "game.h"
#include "config.h"

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
    return (g.getRound() == 7);
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

    // CRAB - Take another turn
    if (game.getExpertRules() && !game.getFirstTurn() && isValid(game) && game.getCurrentCard()->getAnimal()==FaceAnimal::Crab) {
        return (*it).second;
    }
    
    // TURTLE - Skip next player
    if (game.getExpertRules() && !game.getFirstTurn() && isValid(game) && game.getCurrentCard()->getAnimal()==FaceAnimal::Turtle) {
        do {
            if(++it == game.getPlayers().end()) {
                it = game.getPlayers().begin();
            }
        } while (!((*it).second.isActive()));
    }

    // regular get next player
    do {
        if(++it == game.getPlayers().end()) {
            it = game.getPlayers().begin();
        }
    } while (!((*it).second.isActive()));

    return (*it).second;
}

bool Rules::isValidSelection( Game& g, const Letter& l, const Number& n ) {
    if ( (l == Letter::C && n == Number::_3) 
        || (g.isCardFaceUp(l, n)) 
        || (g.getExpertRules() && l == g.getBlockedPosition().first && n == g.getBlockedPosition().second)) {
            return false;
    }

    return true;
}

void Rules::applyExpertRules( Game& game ){
    Letter row;
    Number col;

     // WALRUS - block card for next player
    if (game.getCurrentCard()->getAnimal() == FaceAnimal::Walrus){
        std::cout << (*game.getCurrentPlayer()).second.getName() << ", choose a spot to block." << std::endl;           
        row = game.getRow();
        col = game.getCol();

        while (!game.validToBlock(row, col)){              
            std::cout << "You can't choose that spot." << std::endl;
            row = game.getRow();
            col = game.getCol();
        }
        game.setBlockedPosition(row, col);

    // PENGUIN - turn a card face down
    } else if (game.getCurrentCard()->getAnimal() == FaceAnimal::Penguin) {
        std::cout << (*game.getCurrentPlayer()).second.getName() << ", choose a spot to turn face down." << std::endl;           
        row = game.getRow();
        col = game.getCol();

        while (!game.validToTurnFaceDown(row,col)) {              
            std::cout << "You can't choose that spot." << std::endl;
            row = game.getRow();
            col = game.getCol();
        }

        game.turnCardDown(row, col);
        game.removeFromOrderSelected(row, col);
        std::cout << game << std::endl; 
           
    // OCTOPUS - swap a card with one of its neighbours
    } else if (game.getCurrentCard()->getAnimal()==FaceAnimal::Octopus) {
        std::cout << (*game.getCurrentPlayer()).second.getName() << ", choose a neighbour to swap with the current card." << std::endl;           
        row = game.getRow();
        col = game.getCol();

        while (!game.validToSwap(row, col)) {              
            std::cout << "You can't choose that spot" << std::endl;
            row = game.getRow();
            col = game.getCol();
        }

        game.swapCards(row, col);
        std::cout << std::endl;
        std::cout << game << std::endl; 
    } 
}

#ifdef TEST_RULES_

#include "cardDeck.h"
#include "board.h"

int main() {
    std::cout << "Testing Reward Class" << std::endl;

    try {
        CardDeck cd = cd.make_CardDeck();
        Game g(&cd, false, false);

        Rules r;

        g.addPlayer("Jon");
        g.addPlayer("Nat");
        g.addPlayer("Cornelia");
        g.addPlayer("David");

        g.setCurrentCard(g.getCard(Letter::A, Number::_1));

        std::cout << r.isValid(g) << std::endl;
        std::cout << r.roundOver(g) << std::endl;
        std::cout << r.gameOver(g) << std::endl;

        std::cout << "Testing successfully" << std::endl;

    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif

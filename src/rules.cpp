#include <iostream>
#include <string>

#include "rules.h"
#include "game.h"
#include "config.h" //contains flags for testing
// returns true is previous and current card match; false otherwise.
bool Rules::isValid(const Game& g) {
    Game& game = const_cast<Game&>(g);
    if (game.getCurrentCard()->getFaceBackground()==game.getPreviousCard()->getFaceBackground()) return true;
    if (game.getCurrentCard()->getFaceAnimal()==game.getPreviousCard()->getFaceAnimal()) return true;
    return false;
}
// returns true if the number of rounds has reached 7.
bool Rules::gameOver(const Game& g) {
    Game& game = const_cast<Game&>(g);
    return (game.getRound()==7);
}
// returns true if there is only one active Player left.
bool Rules::roundOver(const Game& g) {
    Game& game = const_cast<Game&>(g);
    int countActive(0);
    if (game.getPlayer(Player::Side::top).isActive()) countActive++;
    if (game.getPlayer(Player::Side::bottom).isActive()) countActive++;
    if (game.getPlayer(Player::Side::right).isActive()) countActive++;
    if (game.getPlayer(Player::Side::left).isActive()) countActive++;
    return (countActive == 1);
}
#ifdef TEST_RULES_
int main() {
CardDeck* cd = CardDeck::make_CardDeck();
Game game(cd,false);
Rules rules;
game.setRound(6);
rules.gameOver(game);
    std::cout<<rules.gameOver(game)<<std::endl;
    std::cout<<rules.roundOver(game)<<std::endl;
    std::cout<<game<<std::endl;
    std::cout << "Testing Rules" << std::endl;

    return 0;
}
#endif
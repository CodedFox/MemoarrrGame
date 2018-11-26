#include <iostream>
#include <string>

#include "rules.h"
#include "game.h"
#include "config.h" //contains flags for testing
// returns true is previous and current card match; false otherwise.
bool Rules::isValid(const Game& g) {
    Game& game = const_cast<Game&>(g);
    //valid if either animal or background matches
    if (game.getCurrentCard()->getFaceBackground()==game.getPreviousCard()->getFaceBackground()) return true;
    if (game.getCurrentCard()->getFaceAnimal()==game.getPreviousCard()->getFaceAnimal()) return true;
    return false;
}
// returns true if the number of rounds has reached 6 (0-indexed).
bool Rules::gameOver(const Game& g) {
    Game& game = const_cast<Game&>(g);
    return (game.getRound()==6);
}
// returns true if there is only one active Player left.
bool Rules::roundOver(const Game& g) {
    Game& game = const_cast<Game&>(g);
    int countActive(0);     
	for (auto player : game.getPlayerMap())
	{
		if (player.second.isActive()) countActive++;		
	}
    return (countActive == 1);
}
const Player& Rules::getNextPlayer(const Game& g){
    Game& game = const_cast<Game&>(g);
    auto next = game.getItCurrentPlayer();
    //advance iterator and correct if at end of list
    if( ++next == game.getPlayerMap().end()){
            next = game.getPlayerMap().begin();
    } 
    while (!((*next).second.isActive())) {  //player not active, try next one
    if( ++next == game.getPlayerMap().end()){
            next = game.getPlayerMap().begin();
        } 
    }
    if (game.getExpertRules() && game.getCurrentCard()->getFaceAnimal()==FaceAnimal::turtle){
    //next player skipped if turtle chosen in expert rules
        //advance iterator again and correct if at end of list
        if( ++next == game.getPlayerMap().end()){
            next = game.getPlayerMap().begin();
        } 
        while (!((*next).second.isActive())) {  //player not active, try next one
            if( ++next == game.getPlayerMap().end()){
                next = game.getPlayerMap().begin();
            } 
        }
    } 

    return (*next).second;
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
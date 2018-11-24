#include <iostream>
#include <string>
#include <map>
#include "game.h"
#include "player.h"
#include "card.h"
#include "config.h" //contains flags for testing
Game::Game(){}
Game::Game(CardDeck* cd, bool expert):round(0), board(cd), expertMode(expert){
previousCard = nullptr;
currentCard = nullptr;
}
int Game::getRound() {

    return round;
}
void Game::setRound(int rnd){
    round = rnd;
}
void Game::addPlayer( const Player& player) {
Game::playerMap.insert(std::make_pair(player.getSide(), player));
}

Player& Game::getPlayer(Player::Side side) {
    auto it = Game::playerMap.find(side);
//  if (it != Game::playerMap.end())
  return (*it).second;
}

const Card* Game::getPreviousCard() {

    return previousCard;
}

const Card* Game::getCurrentCard() {

    return currentCard;
}

void Game::setCurrentCard( const Card* c) {
previousCard = currentCard;
currentCard = const_cast<Card*>(c);
}
Card* Game::getCard( const Board::Letter& row, const Board::Number& col){
    return Game::board.getCard(row, col);
} //which calls the corresponding method in Board
void Game::setCard( const Board::Letter& row, const Board::Number& col, Card* card ){
    Game::board.setCard(row,col, card);
} //which calls the corresponding method in Board
// A game must be printable with the insertion operator cout << game. It should display the board and all players.
std::ostream &operator<<(std::ostream & os, Game & g){
    os<<g.board;
    return os;
}
#ifdef TEST_GAME_
int main() {
CardDeck* cd = CardDeck::make_CardDeck();
Game game(cd,false);
std::cout<<game<<std::endl;
    std::cout << "Testing Game" << std::endl;

    return 0;
}
#endif
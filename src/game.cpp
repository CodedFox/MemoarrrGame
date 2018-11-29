#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "game.h"
#include "player.h"
#include "card.h"

// void Game::addPlayer( const Player& p ) {
void Game::addPlayer( const std::string name ) {
    if (players.size() < 4) {
        // players.insert(std::make_pair(p.getSide(), p));
        players.insert(std::make_pair(Side(players.size()), Player(name, Side(players.size()))));
        if (players.size() == 1) {
            currentPlayer = players.begin();
        }
    } else {
        throw "Maximum amount of players reached!";
    }
}

void Game::setCurrentCard( const Card* c ) {
    if (previousCard != nullptr) {
        previousCard = currentCard;
    } else {
        previousCard = const_cast<Card*>(c);
    }
    currentCard = const_cast<Card*>(c);
}

void Game::revealSideCards( const Side s ) {
    switch(s) {     
        case Side::top: 
            board.turnFaceUp(Letter::A, Number::_2);
            board.turnFaceUp(Letter::A, Number::_3);
            board.turnFaceUp(Letter::A, Number::_4);
            break;
        case Side::bottom: 
            board.turnFaceUp(Letter::E, Number::_2);
            board.turnFaceUp(Letter::E, Number::_3);
            board.turnFaceUp(Letter::E, Number::_4);
            break;
        case Side::left: 
            board.turnFaceUp(Letter::B, Number::_1);
            board.turnFaceUp(Letter::C, Number::_1);
            board.turnFaceUp(Letter::D, Number::_1);
            break;
        case Side::right: 
            board.turnFaceUp(Letter::B, Number::_5);
            board.turnFaceUp(Letter::C, Number::_5);
            board.turnFaceUp(Letter::D, Number::_5);
            break; 
    }

    std::cout<< "Three cards will now be revealed to: " << getPlayer(s).getName() << std::endl;
    std::cout<< "Everyone else should close their eyes. " << getPlayer(s).getName() << ", press 'ENTER' when you are ready to see the board." << std::endl;
    std::cin.get();
    //turn off export board flag for this part if it is on
    // bool tmp = getExpertBoard();
    // setExpertBoard(false);  
    std::cout << *this << std::endl;  
    std::cout << std::endl;
    std::cout << "Press 'ENTER' when you are finished looking at the board." << std::endl;
    std::cin.get();
    std::cout << std::string( 50, '\n' ) << std::endl; //print a bunch of blank lines to hide displayed cards
    board.reset(); //turn the cards face down again
    // setExpertBoard(tmp);
}

void Game::newRound() {
    int numPlayers = players.size();
    for (int i = 0; i < numPlayers; i++) {
        players[Side(i)].setActive(true);
    }
    
    currentPlayer = std::next(players.begin(), round%numPlayers);

    round += 1;
    board.reset();
    previousCard = nullptr;
    currentCard = nullptr;
}

void Game::printWinners() {
    //put players into a vector so we can sort by rubies
    std::vector<Player> winners;    
    for(auto it = players.begin(); it != players.end(); ++it) {
        winners.push_back( it->second );
    }

    std::sort(winners.begin(), winners.end(), [](Player p1, Player p2) { return p1.getNRubies() > p2.getNRubies(); });
    
    for(auto player : winners){
       player.setDisplayMode(true);
       std::cout << player << std::endl;       
   }

   //check for ties
   if (winners[0].getNRubies() == winners[1].getNRubies()) {
        //tie
        std::cout << winners[0].getName() << " and " << winners[1].getName() << " are tied, both players have won!" << std::endl;    
    } else {
        std::cout << winners.front().getName() << " is the winner!" << std::endl;
    }       
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
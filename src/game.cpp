#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <regex>

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

Letter Game::getRow() {
    std::string str;
    std::regex regex_pattern("[a-eA-E]");
    do {
        std::cout << "Please choose a row (A-E): " ;
        std::cin >> str;
    } while(!std::regex_match(str, regex_pattern));
    char cstr = str[0];
    switch (cstr) {     
        case 'A': case 'a': return Letter::A;
        case 'B': case 'b': return Letter::B;
        case 'C': case 'c': return Letter::C;
        case 'D': case 'd': return Letter::D;
        case 'E': case 'e': return Letter::E;
        default: return Letter::A;
    }
}

Number Game::getCol() {
    std::string str;
    std::regex regex_pattern("[1-5]");

    do {
        std::cout << "Please choose a column (1-5): " ;
        std::cin >> str;
    } while(!std::regex_match(str, regex_pattern));

    int i = stoi(str);
    switch (i) {     
        case 1: return Number::_1;
        case 2: return Number::_2;
        case 3: return Number::_3;
        case 4: return Number::_4;
        case 5: return Number::_5;
        default: return Number::_1;
    }
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

bool Game::validToBlock( const Letter& row, const Number& col ) {
     //shouldn't select centre square or blocked under expert or already face up
    if (row == Letter::C && col == Number::_3) {
        return false;
    } 
    if (board.isFaceUp(row, col)) {
        return false;
    }
    return true;
}

bool Game::validToTurnFaceDown( const Letter& row, const Number& col ) {
     //shouldn't select centre square or blocked under expert or already face up
    if (row == Letter::C && col == Number::_3) {
        return false;
    } 
    if (!board.isFaceUp(row, col)) {
        return false;
    }
    return true;
}

bool Game::validToSwap(const Letter& row, const Number& col){
     //shouldn't select centre square or blocked under expert or already face up
    if (row == Letter::C && col == Number::_3) {
        return false;
    }
    if (!orderSelected.empty()) {
        Letter currRow = orderSelected.back().first;
        Number currCol = orderSelected.back().second;
        
        if ( ( (row == currRow+1 || row == currRow-1) && (col == currCol) ) 
            || ( (col == currCol+1 || col == currCol-1) && (row==currRow) ) ) {
            return true;
        }
    }
    return false;
}

void Game::removeFromOrderSelected( const Letter& row, const Number& col ) {
    orderSelected.erase(std::remove(orderSelected.begin(), orderSelected.end(), std::make_pair(row,col)), orderSelected.end());
}

void Game::swapCards( const Letter& row, const Number& col ) {
    Card* tmp = currentCard;

    if (!orderSelected.empty()) {
        Letter currRow = orderSelected.back().first;
        Number currCol = orderSelected.back().second;       
        removeFromOrderSelected(currRow, currCol);   

        if (std::find(orderSelected.begin(), orderSelected.end(), std::make_pair(row,col)) != orderSelected.end()) {
            //if swap chosen is already in list we need to update it
            std::replace (orderSelected.begin(), orderSelected.end(), std::make_pair(row,col), std::make_pair(currRow,currCol)); 
        }     

        Game::board.setCard(currRow, currCol, getCard(row,col));

        setCard(row,col,tmp);
        addSelection(row,col);
    }
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
    std::cout << std::endl;
    //check for ties
    if (winners[0].getNRubies() == winners[1].getNRubies()) {
        //tie
        std::cout << winners[0].getName() << " and " << winners[1].getName() << " are tied, both players have won!" << std::endl;    
    } else {
        std::cout << winners.front().getName() << " is the winner!" << std::endl;
    }
    std::cout << std::endl;
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
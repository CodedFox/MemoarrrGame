#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
#include <map>
#include <vector>
#include "game.h"
#include "player.h"
#include "card.h"
#include "config.h" //contains flags for testing
Game::Game(){}
Game::Game(CardDeck* cd, bool expertBd, bool expRules):round(0), board(cd), expertBoard(expertBd), expertRules(expRules){
previousCard = nullptr;
currentCard = nullptr;
blockedPosition = std::make_pair(Board::Letter::C, Board::Number::_3);  //set blocked to start in centre, only used for expert mode
}
std::map<Player::Side, Player>& Game::getPlayerMap(){
    return playerMap;
}
void Game::reveal3Cards(Player::Side side){
    //turn 3 cards face up based on side, print board, turn cards back down
    //top sees A2 A3 A4, bottom sees E2 E3 E4
    //left sees B1 C1 D1, right sees B5 C5 D5
switch(side) {     
    case Player::Side::top: 
        board.turnFaceUp(Board::A,Board::_2);
        board.turnFaceUp(Board::A,Board::_3);
        board.turnFaceUp(Board::A,Board::_4);
        break;
    case Player::Side::bottom: 
        board.turnFaceUp(Board::E,Board::_2);
        board.turnFaceUp(Board::E,Board::_3);
        board.turnFaceUp(Board::E,Board::_4);
        break;
    case Player::Side::left: 
        board.turnFaceUp(Board::B,Board::_1);
        board.turnFaceUp(Board::C,Board::_1);
        board.turnFaceUp(Board::D,Board::_1);
        break;
    case Player::Side::right: 
        board.turnFaceUp(Board::B,Board::_5);
        board.turnFaceUp(Board::C,Board::_5);
        board.turnFaceUp(Board::D,Board::_5);
        break;    
  }
  
  std::cout<< "Three cards will now be revealed to " << getPlayer(side).getName() << std::endl;
  std::cout<< "Everyone else should close their eyes. " << getPlayer(side).getName() << " press ENTER when you are ready to see the board." << std::endl;
  std::cin.get();
  //turn off export board flag for this part if it is on
  bool tmp = getExpertBoard();
  setExpertBoard(false);  
  std::cout << *this << std::endl;  
  std::cout << std::endl;
  std::cout << "Press ENTER when you are finished looking at the board." << std::endl;
  std::cin.get();
  std::cout << std::string( 50, '\n' ) << std::endl; //print a bunch of blank lines to hide displayed cards
  board.reset(); //turn the cards face down again
  setExpertBoard(tmp);
}
int Game::getRound() {
    return round;
}
void Game::setRound(int rnd){
    board.reset();
    previousCard = nullptr;
    currentCard = nullptr;
    int adjust = (rnd % Game::playerMap.size());
    itCurrentPlayer = std::next(Game::playerMap.begin(), adjust); // so that same player doesn't start every round    
    round = rnd;
    orderSelected.clear();
}
void Game::addPlayer( const Player& player) {
Game::playerMap.insert(std::make_pair(player.getSide(), player));

}

Player& Game::getPlayer(Player::Side side) {
    auto it = Game::playerMap.find(side);
  //if (it != Game::playerMap.end()){
  return (*it).second;
  
}
void Game::addSelection(Board::Letter row, Board::Number col){
    orderSelected.push_back(std::make_pair(row,col));
}
void Game::setCurrentPlayer(const Player& player){
    itCurrentPlayer = Game::playerMap.find(player.getSide());
} 
void Game::setItCurrentPlayer(const std::map<Player::Side, Player>::iterator it){        
    itCurrentPlayer = it;
}
const std::map<Player::Side, Player>::iterator Game::getItCurrentPlayer(){
    return itCurrentPlayer;
}

const Card* Game::getPreviousCard() {

    return previousCard;
}

const Card* Game::getCurrentCard() {

    return currentCard;
}

void Game::setCurrentCard( const Card* c) {

if (previousCard != nullptr) {
    previousCard = currentCard;
} else {
    //first turn, need to set previous card to card chosen
    previousCard = const_cast<Card*>(c);
}
currentCard = const_cast<Card*>(c);
}
Card* Game::getCard( const Board::Letter& row, const Board::Number& col){
    return Game::board.getCard(row, col);
} //which calls the corresponding method in Board
void Game::setCard( const Board::Letter& row, const Board::Number& col, Card* card ){
    Game::board.setCard(row, col, card);    
    Game::board.turnFaceUp(row, col);
    setCurrentCard(card);
} //which calls the corresponding method in Board

void Game::setExpertRules(bool exp){ expertRules = exp;}
bool Game::getExpertRules(){return expertRules;}
void Game::setExpertBoard(bool exp){ expertBoard = exp;}
bool Game::getExpertBoard(){return expertBoard;}
// A game must be printable with the insertion operator cout << game. It should display the board and all players.
std::ostream &operator<<(std::ostream & os, Game & g){
   // Iterate over the map using c++11 range based for loop
   for(auto element : g.playerMap){
       os<< element.second <<std::endl;
   }
   if(g.expertBoard){
    std::stringstream topString;
    std::stringstream middleString;
    std::stringstream bottomString;
    std::stringstream positionString;        
    //print expert display by looping through orderSelected
    for(auto it = g.orderSelected.begin(); it != g.orderSelected.end(); ++it) {
    /* std::cout << *it; ... */
        Card c = *(g.getCard((*it).first,(*it).second));
        if (g.board.isFaceUp((*it).first,(*it).second)){      
          topString << c(0)<<"  ";
          middleString << c(1)<<"  ";
          bottomString << c(2)<<"  ";
        } else {
         //card is face down
            topString << "zzz" << "  ";
            middleString << "zzz" << "  ";
            bottomString << "zzz" << "  ";
        }
     //os << *(g.getCard((*it).first,(*it).second));
     }
     for(auto it = g.orderSelected.begin(); it != g.orderSelected.end(); ++it) {
    /* std::cout << *it; ... */
    char character='A';
     positionString << std::string(1,(character + (*it).first)) << ((*it).second + 1) << "   ";
     }    
       os << topString.str() << std::endl;               
       os << middleString.str() << std::endl;
       os << bottomString.str() <<std::endl;
       os << std::endl;
       os << positionString.str() <<std::endl;
   } else {
    //print regular display
    os<< g.board; }
   
    return os;
}
//check if board spot can be chosen  
bool Game::validSelection(const Board::Letter& row, const Board::Number& col){
     //shouldn't select centre square or blocked under expert or already face up
    if(row == Board::Letter::C && col == Board::Number::_3){
        //centre square
        return false;
    } 
    if(Game::board.isFaceUp(row, col)){
        //already face up
        return false;
    }
    if (getExpertRules() && (blockedPosition.first == row && blockedPosition.second== col)){
        //position blocked under expert rules
        return false;
    }
    return true;
}
//check if board spot can be blocked
bool Game::validToBlock(const Board::Letter& row, const Board::Number& col){
     //shouldn't select centre square or blocked under expert or already face up
    if(row == Board::Letter::C && col == Board::Number::_3){
        //centre square
        return false;
    } 
    if(Game::board.isFaceUp(row, col)){
        //already face up
        return false;
    }
    
    return true;
}
//check if board spot can be turned face down
bool Game::validToTurnFaceDown(const Board::Letter& row, const Board::Number& col){
     //shouldn't select centre square or blocked under expert or already face up
    if(row == Board::Letter::C && col == Board::Number::_3){
        //centre square
        return false;
    } 
    if(!Game::board.isFaceUp(row, col)){
        //not already face up
        return false;
    }
    
    return true;
}

//check if valid spot to swap cards
bool Game::validToSwap(const Board::Letter& row, const Board::Number& col){
     //shouldn't select centre square or blocked under expert or already face up
    if(row == Board::Letter::C && col == Board::Number::_3){
        //centre square
        return false;
    }
     if (!orderSelected.empty()){
       Board::Letter currRow = orderSelected.back().first;
       Board::Number currCol = orderSelected.back().second;
    
        if(((row == currRow+1 || row == currRow-1) && (col==currCol)) ||
        ((col == currCol+1 || col == currCol-1) && (row==currRow)))
        {
            return true;
        }
       
       } 
    
    return false;
}
bool Game::compare(Player p1, Player p2) {
    
        return p1.getNRubies() < p2.getNRubies();
}
void Game::printOutGameOver(){
    //put players into a vector so we can sort by rubies
     std::vector <Player> v;    
    for( auto it = playerMap.begin(); it != playerMap.end(); ++it ) {
        v.push_back( it->second );
    }
    std::sort (v.begin(), v.end(), Game::compare);
    for(auto element : v){
    //TODO still need to sort this by numRubies
       element.setDisplayMode(true);
       std::cout<<element<<std::endl;       
   }
   //check for ties
   if ( v[v.size() - 2].getNRubies()==v[v.size() - 1].getNRubies()){
    //tie
    std::cout<<v[v.size() - 2].getName() << " and " << v[v.size() - 1].getName() << " are tied so both players have won!" << std::endl;    
       } else {
    std::cout<<v.back().getName() << " is the winner!" << std::endl;
       }       
}
std::string Game::getSelectedRow(){
      std::string str;
    std::regex regex_pattern("[a-eA-E]");
    do
    {
        std::cout << "Please choose a row (A-E):" ;
        std::cin >> str;
    }while(!std::regex_match(str,regex_pattern));

    return str;

}
int Game::getSelectedCol(){
      std::string str;
    std::regex regex_pattern("[1-5]");
    do
    {
        std::cout << "Please choose a column (1-5):" ;
        std::cin >> str;
    }while(!std::regex_match(str,regex_pattern));

    return stoi(str);  //subtract 1 because 0-indexed array
}
  void Game::setBlockedPosition(const Board::Letter& row, const Board::Number& col){
      blockedPosition = std::make_pair(row,col);
  }
  std::pair<Board::Letter, Board::Number> Game::getBlockedPosition(){
            return blockedPosition;
   }
   void Game::turnFaceDown(const Board::Letter& row, const Board::Number& col){
       Game::board.turnFaceDown(row,col);
   }
   void Game::removeFromOrderSelected(const Board::Letter& row, const Board::Number& col){
       //this is called erase-remove idiom
       orderSelected.erase(std::remove(orderSelected.begin(), orderSelected.end(), std::make_pair(row,col)), orderSelected.end());
   }
   void Game::swapCards(const Board::Letter& row, const Board::Number& col){
       Card* tmp = currentCard;
       if (!orderSelected.empty()){
       Board::Letter currRow = orderSelected.back().first;
       Board::Number currCol = orderSelected.back().second;
       //TODO update prior entry in orderSelected         
       removeFromOrderSelected(currRow, currCol);       
       if (std::find(orderSelected.begin(), orderSelected.end(), std::make_pair(row,col)) != orderSelected.end()){
           //if swap chosen is already in list we need to update it
       std::replace (orderSelected.begin(), orderSelected.end(), std::make_pair(row,col), std::make_pair(currRow,currCol)); }     
       Game::board.setCard(currRow, currCol, getCard(row,col));
       //Game::board.turnFaceDown(currRow, currCol);
       setCard(row,col,tmp);
       addSelection(row,col);
       }
   }
   bool Game::firstTurn(){
       return (orderSelected.size() <= 1);
   }
#ifdef TEST_GAME_
int main() {
CardDeck* cd = CardDeck::make_CardDeck();
Game game(cd,true,false);
game.addPlayer(Player("Bob",Player::Side::left));
game.addPlayer(Player("Joe",Player::Side::right));
game.addPlayer(Player("Peanut",Player::Side::top));
game.addPlayer(Player("Melora",Player::Side::bottom));
game.addSelection(Board::Letter::A, Board::Number::_2);
game.addSelection(Board::Letter::D, Board::Number::_1);
game.addSelection(Board::Letter::B, Board::Number::_3);
game.addSelection(Board::Letter::E, Board::Number::_4);
game.addSelection(Board::Letter::C, Board::Number::_5);
std::cout<<game<<std::endl;
    std::cout << "Testing Game" << std::endl;

    return 0;
}
#endif
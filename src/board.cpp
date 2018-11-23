#include <iostream>
#include <string>
#include <sstream>
//#include "deck.h"
#include "board.h"
#include "config.h" //contains flags for testing
Board::Board(){}
Board::Board(CardDeck* cd){                                
            //to take a card deck, shuffle it and then fill the board spots one by one until full
            for(int row = 0; row < 5; ++row ){
                for (int col = 0; col < 5; ++col){             
                    cardsOnBoard[row].push_back(cd->getNext());
                    faceUpBoard[row].push_back(false);
                }
            }}
bool Board::isFaceUp( const Letter&, const Number& ) {

    return true;
} 

bool Board::turnFaceUp( const Letter&, const Number& ) {

    return true;
}

bool Board::turnFaceDown( const Letter&, const Number& ) {

    return true;
}

void Board::reset() {

}
std::ostream & operator<<(std::ostream &os, Board &b) {
  std::string str;
  //stringstream 
  //3 output string streams top middle bottom row
  //need to have a middle hole
 for(int row = 0; row < 5; ++row ){
                for (int col = 0; col < 5; ++col){ 
                    std::stringstream rowString;
                    rowString << b.cardsOnBoard[row].at(col);

              os << rowString.str() << std::endl;  }}

              
         
    return os;
    }
#ifdef TEST_BOARD_
int main() {
  CardDeck* cd = CardDeck::make_CardDeck();
  Board b(cd);
    std::cout << b << std::endl;
    std::cout << "Testing Board" << std::endl;

    return 0;
}
#endif
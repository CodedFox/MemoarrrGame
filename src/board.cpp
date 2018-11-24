#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
//#include "deck.h"
#include "board.h"
#include "config.h" //contains flags for testing
Board::Board(){}
 
//The constructor for board should throw and Exception of type NoMoreCards if there are no more cards available to construct a board.
Board::Board(CardDeck* cd){                                
            //to take a card deck, shuffle it and then fill the board spots one by one until full
            cardsOnBoard.resize(5);
            cd->shuffle();
            for(int row = 0; row < 5; ++row ){                             
                for (int col = 0; col < 5; ++col){  
                    if (cd->isEmpty()){throw std::out_of_range ("No More Cards");}
                    cardsOnBoard[row].push_back(std::make_pair(cd->getNext(),false));                    
                }

            }}
/* const returns true if the card at a given position is face up. Letter and Number are enumerations. 
        Throws an exception of type OutOfRange if an invalid Letter and Number combination was given. */            
bool Board::isFaceUp( const Letter& row, const Number& col) {
    if(!(row >= A && row <= E) || !(col >= _1 && col <= _5) || (row==C && col == 3)) {
    //C3 is middle section
    throw std::out_of_range ("invalid position");}
    return cardsOnBoard[row][col].second;
} 

bool Board::turnFaceUp( const Letter& row, const Number& col) {
    if(!(row >= A && row <= E) || !(col >= _1 && col <= _5) || (row==C && col == 3)) {
    //C3 is middle section
    throw std::out_of_range ("invalid position");}
    if(cardsOnBoard[row][col].second){
    return false;
    } else {
        cardsOnBoard[row][col].second = true;
        return true;
    } 
}

bool Board::turnFaceDown( const Letter& row, const Number& col) {
    if(!(row >= A && row <= E) || !(col >= _1 && col <= _5) || (row==C && col == 3)) {
    //C3 is middle section
    throw std::out_of_range ("invalid position");}
    if(cardsOnBoard[row][col].second){
        cardsOnBoard[row][col].second = false;
        return true;
    } else {       
        return false;
    } 
}

//returns a pointer to the card at a given location. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
Card* Board::getCard( const Letter& row, const Number& col) {
    if(!(row >= A && row <= E) || !(col >= _1 && col <= _5) || (row==C && col == 3)) {
    //C3 is middle section
    throw std::out_of_range ("invalid position");}
    return cardsOnBoard[row][col].first;
}

//updates the pointer to card at a given location. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
void Board::setCard( const Letter& row, const Number& col, Card* ptrCard) {
    if(!(row >= A && row <= E) || !(col >= _1 && col <= _5) || (row==C && col == 3)) {
    //C3 is middle section
    throw std::out_of_range ("invalid position");}
    cardsOnBoard[row][col].first = ptrCard;
}
void Board::reset() {
            for(int row = 0; row < 5; ++row ){                             
                for (int col = 0; col < 5; ++col){  
                    cardsOnBoard[row][col].second = false; 
                }
            }
}
std::ostream & operator<<(std::ostream &os, Board &b) {
  std::string str;
  //stringstream 
  //3 output string streams top middle bottom row
  //need to have a middle hole
  char character='A';
 for(int row = 0; row < 5; ++row ){
    std::stringstream topString;
    std::stringstream middleString;
    std::stringstream bottomString;                
        for (int col = 0; col < 5; ++col){ 
                if (col == 0){
                topString << "  ";                                
                middleString << std::string(1,character) + " ";
                bottomString << "  ";
                character++;
                } 
                if(!(row ==2 && col ==2)){ 
                    //check we're not art middle spot              
                if(b.cardsOnBoard[row][col].second){
                        //card is face up 
                    topString << (*(b.cardsOnBoard[row][col].first))(0)<<" ";
                    middleString << (*(b.cardsOnBoard[row][col].first))(1)<<" ";
                    bottomString << (*(b.cardsOnBoard[row][col].first))(2)<<" ";
                }else{
                    //card is face down
                    topString << "zzz" << " ";
                    middleString << "zzz" << " ";
                    bottomString << "zzz" << " ";
                }
                } else {
                    //print blanks for middle spot
                    topString << "   " << " ";
                    middleString << "   " << " ";
                    bottomString << "   " << " ";
                }
        }
                os << std::endl;
                os << topString.str() << std::endl;               
                os << middleString.str() << std::endl;
                os << bottomString.str() <<std::endl;
                os << std::endl;
}

              
    os << "   1 " << "  2 " << "  3 " << "  4 " << "  5 "<< std::endl;    
    return os;
}

#ifdef TEST_BOARD_
int main() {
  std::cout << "Testing Board before" << std::endl;
  CardDeck* cd = CardDeck::make_CardDeck();
  
  Board b(cd);
    std::cout << b << std::endl;
    b.reset();
    std::cout << b << std::endl;
    b.turnFaceUp(Board::A,Board::_2);
    std::cout << b << std::endl;
    b.turnFaceUp(Board::C,Board::_3);
    std::cout << b << std::endl;
    b.turnFaceDown(Board::C,Board::_3);
    b.turnFaceDown(Board::A,Board::_2);
    std::cout << b << std::endl;
    bool tmp = b.isFaceUp(Board::A,Board::_2);
    std::cout << "Testing Board after" << tmp << std::endl;

    return 0;
}
#endif
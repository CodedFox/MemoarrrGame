#include <iostream>
#include <string>

#include "board.h"
#include "config.h" //contains flags for testing
//Board(CardDeck cd){}
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
#ifdef TEST_BOARD_
int main() {

    std::cout << "Testing Board" << std::endl;

    return 0;
}
#endif
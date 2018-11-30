#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>

#include "board.h"
#include "config.h"

Board::Board(CardDeck* cd) {
    cd->shuffle();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!(i == 2 && j == 2)) {
                if (cd->isEmpty()) {
                    throw std::out_of_range ("Error - No More Cards");
                } else {
                    gameBoard.insert(std::make_pair(std::make_pair(Letter(i), Number(j)), std::make_pair(cd->getNext(), false)));
                }
            }
        }
    }
}

bool Board::isFaceUp( const Letter& l, const Number& n ) {
    if((l == Letter::C && n == Number::_3)) {
        throw std::out_of_range ("Error - Invalid Letter and Number combination.");
    }
    return gameBoard[std::make_pair(l, n)].second;
}

bool Board::turnFaceUp( const Letter& l, const Number& n ) {
    if((l == Letter::C && n == Number::_3)) {
        throw std::out_of_range ("Error - Invalid Letter and Number combination.");
    }
    if (!gameBoard[std::make_pair(l, n)].second) {
        gameBoard[std::make_pair(l, n)].second = true;
        return true;
    } else {
        return false;
    }
}

bool Board::turnFaceDown( const Letter& l, const Number& n ) {
    if((l == Letter::C && n == Number::_3)) {
        throw std::out_of_range ("Error - Invalid Letter and Number combination.");
    }
    if (gameBoard[std::make_pair(l, n)].second) {
        gameBoard[std::make_pair(l, n)].second = false;
        return true;
    } else {
        return false;
    }
}

void Board::reset() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!(i == 2 && j == 2)) {
                if (isFaceUp(Letter(i), Number(j))) {
                    turnFaceDown(Letter(i), Number(j));
                }
            }
        }
    }
}

Card * Board::getCard( const Letter& l, const Number& n ) {
    if((l == Letter::C && n == Number::_3)) {
        throw std::out_of_range ("Error - Invalid Letter and Number combination.");
    }
    return gameBoard[std::make_pair(l, n)].first;
}

void Board::setCard( const Letter& l, const Number& n, Card* c ) {
    if((l == Letter::C && n == Number::_3)) {
        throw std::out_of_range ("Error - Invalid Letter and Number combination.");
    }
    gameBoard[std::make_pair(l, n)].first = c;
}

std::ostream & operator<<(std::ostream & os, const Letter & l) {
    switch(l) {
        case Letter::A: os << "A"; break;
        case Letter::B: os << "B"; break;
        case Letter::C: os << "C"; break;
        case Letter::D: os << "D"; break;
        case Letter::E: os << "E"; break;
        default: os << "Error - Letter"; break;
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const Number & n) {
    switch(n) {
        case Number::_1: os << "1"; break;
        case Number::_2: os << "2"; break;
        case Number::_3: os << "3"; break;
        case Number::_4: os << "4"; break;
        case Number::_5: os << "5"; break;
        default: os << "Error - Number"; break;
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, Board & b) {
     for (int i = 0; i < 5; i++) { // Letters
        for (int j = 0; j < 3; j++) { // Card print row
            if ( j == 1 ) {
                os << Letter(i) << " ";
            } else {
                os << "  ";
            }
            for (int k = 0; k < 5; k++) { // Number
                if (!(i == 2 && k == 2)) { // middle card
                    if (b.isFaceUp(Letter(i), Number(k))) {
                        os << (*b.gameBoard[std::make_pair(Letter(i), Number(k))].first)(j);
                    } else {
                        os << "z z z";
                    }
                } else {
                    os << "     ";
                }
                if (k < 4)
                    os << "  ";
            }
            os << std::endl;
        }
        os << std::endl;
    }
    os << "    " << Number(0) << "      " << Number(1) << "      " << Number(2) << "      " << Number(3) << "      " << Number(4) << std::endl;
    return os;
}

#ifdef TEST_BOARD_

int main() {
    std::cout << "Testing Board Class" << std::endl;

    try {
        Letter l = Letter::A;
        std::cout << l << std::endl;

        Number n = Number::_1;
        std::cout << n << std::endl;

        CardDeck cd = cd.make_CardDeck();
        Board b(&cd);
        std::cout << b << std::endl;

        std::cout << b.isFaceUp(l, n) << std::endl;
        b.turnFaceUp(l, n);
        std::cout << b.isFaceUp(l, n) << std::endl;
        std::cout << b << std::endl;

        b.turnFaceUp(Letter::B, Number::_2);
        b.turnFaceUp(Letter::D, Number::_4);
        b.turnFaceUp(Letter::E, Number::_5);
        std::cout << b << std::endl;

        b.turnFaceDown(Letter::A, Number::_1);
        b.turnFaceDown(Letter::E, Number::_5);
        std::cout << b << std::endl;

        b.reset();
        std::cout << b << std::endl;

        std::cout << b.getCard(l, n) << std::endl;
        b.setCard(Letter::E, Number::_1, b.getCard(l, n));
        std::cout << b.getCard(Letter::E, Number::_1) << std::endl;
        
        std::cout << "Testing successfully" << std::endl;
        
    } catch (...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif

#include <iostream>
#include <string>
#include <sstream>

#include "card.h"
#include "config.h"

std::ostream & operator<<(std::ostream & os, const FaceAnimal & fa) {
    switch(fa) {
        case FaceAnimal::Crab: os << "C"; break;
        case FaceAnimal::Penguin: os << "P"; break;
        case FaceAnimal::Octopus: os << "O"; break;
        case FaceAnimal::Turtle: os << "T"; break;
        case FaceAnimal::Walrus: os << "W"; break;
        default: os << "Error - Face Animal"; break;
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const FaceBackground & fb) {
    switch(fb) {
        case FaceBackground::Red: os << "r"; break;
        case FaceBackground::Green: os << "g"; break;
        case FaceBackground::Purple: os << "p"; break;
        case FaceBackground::Blue: os << "b"; break;
        case FaceBackground::Yellow: os << "y"; break;
        default: os << "Error - Face Background"; break;
    }
    return os;
}

std::string Card::operator()(int row) {
    std::ostringstream oss;
    if (row >= 0 && row < 3) {
        if (row%2 == 1) {
            oss << background << " " << animal << " " << background;
        } else {
            oss << background << " " << background << " " << background;
        }
    } else {
        throw std::invalid_argument( "Invalid Row" );
    }
    return oss.str();
}

#ifdef TEST_CARD_

#include "cardDeck.h"
#include "board.h"

int main() {
    std::cout << "Testing Card Class" << std::endl;

    try {
        CardDeck cd = cd.make_CardDeck();
        Board b(&cd);

        Card * c = b.getCard(Letter::A, Number::_1);

        std::cout << c->getAnimal() << std::endl;
        std::cout << c->getBackground() << std::endl;

        std::cout << (*c)(0) << std::endl;
        std::cout << (*c)(1) << std::endl;
        std::cout << (*c)(2) << std::endl;
        
        std::cout << "Testing successfully" << std::endl;
        
    } catch (...) {
        std::cout << "Testing failed << std::endl;
    }
    
    return 0;
}

#endif

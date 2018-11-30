#include <iostream>
#include <string>

#include "deck.h"
#include "config.h"

#ifdef TEST_DECK_

#include "cardDeck.h"
#include "board.h"

int main() {
    std::cout << "Testing Deck Class" << std::endl;

    try {
        CardDeck cd = cd.make_CardDeck();
        Board b(&cd);

        std::cout << b << std::endl;
        b.turnFaceUp(Letter::A, Number::_1);
        std::cout << b << std::endl;

        cd.shuffle();
        std::cout << b << std::endl;

        std::cout << cd.isEmpty() << std::endl;

        std::cout << cd.getNext() << std::endl;

        std::cout << "Testing successfully" << std::endl;

    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif
#include <iostream>
#include <string>
#include <vector>

#include "card.h"
#include "cardDeck.h"
#include "config.h"

CardDeck* CardDeck::cd = nullptr;

CardDeck& CardDeck::make_CardDeck() {
    if (!cd) {
        cd = new CardDeck();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                (*cd).cards.push_back(Card(static_cast<FaceAnimal>(i), static_cast<FaceBackground>(j)));
            }
        }
    } else {
        throw std::runtime_error( "Card Deck already created." );
    }
    return *cd;
}

#ifdef TEST_CARD_DECK_

int main() {
    std::cout << "Testing CardDeck Class" << std::endl;

    try {
        CardDeck cd = cd.make_CardDeck();

        std::cout << "Testing successfully" << std::endl;
        
    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }
}

#endif

#include <iostream>
#include <string>
#include <vector>

#include "card.h"
#include "cardDeck.h"

CardDeck* CardDeck::cd = nullptr;

CardDeck& CardDeck::make_CardDeck() {
    if (!cd) {
        cd = new CardDeck();

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                (*cd).cards.push_back(Card(static_cast<FaceAnimal>(i), static_cast<FaceBackground>(j)));
            }
        }
        (*cd).shuffle();
    } else {
        throw std::runtime_error( "Card Deck already created." );
    }
    return *cd;
}

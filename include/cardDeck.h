#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <card.h>
class Card;

#include <deck.h>
// template <> 
// class Deck<Card>;


// Design a class CardDeck derived from Deck<Card>.
// template <typename Card>
class CardDeck: public Deck<Card> {
    private:
        static CardDeck * cd;
        CardDeck(): Deck<Card>() {};

    public:
        // ~CardDeck() { delete cd; };
        static CardDeck& make_CardDeck(); // is the only public method for CardDeck. The method has to always return the same CardDeck during the execution of the program.

        // An object of type CardDeck can not be copied or assigned, and it has no public constructor.
};

#endif

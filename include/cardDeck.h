#ifndef CARD_DECK_H
#define CARD_DECK_H
#include "deck.h"
#include "card.h"
class Card;

class CardDeck : public Deck<Card> {
    private:
       static CardDeck* cardDeck;
       // An object of type CardDeck can not be copied or assigned, and it has no public constructor.
       CardDeck(){};
        CardDeck(CardDeck const&); //copy ctor private
        CardDeck& operator=(CardDeck const&); //assignment op private
        
    public:
        static CardDeck* make_CardDeck();
        
};
        

        


#endif

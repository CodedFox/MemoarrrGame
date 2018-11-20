#ifndef CARD_DECK_H
#define CARD_DECK_H
#include "deck.h"
#include "card.h"
class Card;
template <>
class Deck<Card>;
// Design a class CardDeck derived from Deck<Card>.
template<typename Card>
class CardDeck : public Deck<Card> {
    private:
       
    public:
        static CardDeck& make_CardDeck(){
            //one card for each animal/background combo
            for(int i = 0; i < 5; ++i){                
                for(int j = 0; j < 5; ++j){                    
                    //add new card to cards vector
                    CardDeck::cards.emplace(Card(i,j));
                }
            }
        } // is the only public method for CardDeck. The method has to always return the same CardDeck during the execution of the program.

        // An object of type CardDeck can not be copied or assigned, and it has no public constructor.
};

#endif

#ifndef REWARD_DECK_H
#define REWARD_DECK_H
#include "deck.h"
class Deck;
// Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
class RewardDeck : public Deck {
    private:
        

    public:
        static RewardDeck& make_RewardDeck(); // is the only public method for RewardDeck. The method has to always return the same RewardDeck during the execution of the program.

        // An object of type RewardDeck can not be copied or assigned, and it has no public constructor.  
};

#endif

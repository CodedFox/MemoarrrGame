#ifndef REWARD_DECK_H
#define REWARD_DECK_H
#include "deck.h"
class Reward;
template <>
class Deck<Reward>;
// Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
template<typename Reward>
class RewardDeck : public Deck<Reward> {
    private:
        

    public:
        static RewardDeck& make_RewardDeck(){
            
            for(int i = 0; i < 3; ++i){
                //add new reward to cards vector
                RewardDeck::cards.emplace(Reward(1));
            }
            RewardDeck::cards.emplace(Reward(2));
            RewardDeck::cards.emplace(Reward(2));
            RewardDeck::cards.emplace(Reward(3));
            RewardDeck::cards.emplace(Reward(4));
        }; // is the only public method for RewardDeck. The method has to always return the same RewardDeck during the execution of the program.

        // An object of type RewardDeck can not be copied or assigned, and it has no public constructor.  
};

#endif

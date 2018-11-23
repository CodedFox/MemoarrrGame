#ifndef REWARD_DECK_H
#define REWARD_DECK_H
#include "deck.h"
#include "reward.h"
class Reward;
// Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
class RewardDeck : public Deck<Reward> {
    private:
        static RewardDeck* rewardDeck;
        RewardDeck(){};         
           //for(int i = 0; i < 3; ++i){
                //add new reward to cards vector
           //rewardDeck->cards.emplace(Reward::Reward(1));
           

           //cards.emplace(Reward(2));
           //cards.emplace(Reward(2));
           //cards.emplace(Reward(3));
           //cards.emplace(Reward(4));
        //private so can't be called
        RewardDeck(RewardDeck const&); //copy ctor private
        RewardDeck& operator=(RewardDeck const&); //assignment private
    public:
        static RewardDeck* make_RewardDeck();
        // An object of type RewardDeck can not be copied or assigned, and it has no public constructor.  
};

#endif

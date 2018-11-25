#include <iostream>
#include <string>

#include "rewardDeck.h"

RewardDeck* RewardDeck::rd = nullptr;

RewardDeck& RewardDeck::make_RewardDeck() {
    if (!rd) {
        rd = new RewardDeck();
        (*rd).cards.push_back(Reward(1));
        (*rd).cards.push_back(Reward(1));
        (*rd).cards.push_back(Reward(1));
        (*rd).cards.push_back(Reward(2));
        (*rd).cards.push_back(Reward(2));
        (*rd).cards.push_back(Reward(3));
        (*rd).cards.push_back(Reward(4));
        (*rd).shuffle();
    } else {
        throw std::runtime_error( "Reward Deck already created." );
    }
    
    return *rd;
}
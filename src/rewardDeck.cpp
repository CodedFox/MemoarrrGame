#include <iostream>
#include <string>

#include "rewardDeck.h"
#include "config.h"

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
        rd->shuffle();
    } else {
        throw std::runtime_error( "Reward Deck already created." );
    }
    
    return *rd;
}

#ifdef TEST_REWARD_DECK_

int main() {
    std::cout << "Testing Reward Class" << std::endl;

    try {
        RewardDeck rd = rd.make_RewardDeck();

        std::cout << rd.isEmpty() << std::endl;
        std::cout << *rd.getNext() << std::endl;
        rd.shuffle();
        std::cout << *rd.getNext() << std::endl;

        std::cout << "Testing successfully" << std::endl;

    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif

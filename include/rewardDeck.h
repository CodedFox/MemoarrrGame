#ifndef REWARD_DECK_H
#define REWARD_DECK_H

#include <reward.h>
class Reward;

#include <deck.h>
// template <> 
// class Deck<Reward>;

// Design a class RewardDeck derived from Deck<Reward> with the corresponding properties to CardDeck.
// template <typename Reward>
class RewardDeck: public Deck<Reward> {
    private:
        static RewardDeck * rd;

    public:
        RewardDeck() {};
        // ~RewardDeck() {};
        static RewardDeck& make_RewardDeck();
};

#endif

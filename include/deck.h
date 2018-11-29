#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <chrono> 

// Design a class Deck<C> as an abstract factory class that will be used to create 
// a set of cards or a set of rewards. The type parameter <C> is intended to be one 
// of {Card|Reward}. The class will need the following methods:
template <typename C>
class Deck {
    protected:
        std::vector<C> cards;
        unsigned int index = 0;
        
    public:
        Deck() {};
        void shuffle(); // shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.
        bool isEmpty() const; // const returns true if the deck is empty.
        C* getNext(); // returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
};

template <typename C>
void Deck<C>::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));
}

template <typename C>
bool Deck<C>::isEmpty() const {
    if(index == cards.size()){
        return true;
    } else {
        return false;
    }
}

template <typename C>
C* Deck<C>::getNext() {
    if (!isEmpty()) {
        return &cards[index++];
    } else {
        return nullptr;
    }
}

#endif

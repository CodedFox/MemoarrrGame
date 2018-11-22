#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>

// Design a class Deck<C> as an abstract factory class that will be used to create 
// a set of cards or a set of rewards. The type parameter <C> is intended to be one 
// of {Card|Reward}. The class will need the following methods:
template <typename C>
class Deck {
    private:
        std::vector<C> cards;
        typename std::vector<C>::iterator it; //always points to next elem

    public:
        inline void shuffle() { std::random_shuffle(cards.begin(), cards.end()); }; // shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.
        bool isEmpty() const; // const returns true if the deck is empty.
        C* getNext(); // returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
};

template <typename C>
bool isEmpty() {
    if(Deck<C>::it == Deck<C>::cards.end()+1) {
        return true;
    } else {
        return false;
    }
}

template <typename C>
C* getNext() {
    if (!Deck<C>::isEmpty()){
        return &Deck<C>::it++;
    } else {
        return nullptr;
    }
}

#endif

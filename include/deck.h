#ifndef DECK_H
#define DECK_H
#include <random>
#include <algorithm>    // std::shuffle
// Design a class Deck<C> as an abstract factory class that will be used to create 
// a set of cards or a set of rewards. The type parameter <C> is intended to be one 
// of {Card|Reward}. The class will need the following methods:
template<typename C>
class Deck{
    private:
            
        int topIndex{0}; //index of vector that is currently the "top"
    public:
    std::vector<C> cards; 
// shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.    
void shuffle();

// returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
virtual C* getNext();

// const returns true if the deck is empty.
virtual bool isEmpty() const;
        
};

#endif

#ifndef DECK_H
#define DECK_H

// Design a class Deck<C> as an abstract factory class that will be used to create 
// a set of cards or a set of rewards. The type parameter <C> is intended to be one 
// of {Card|Reward}. The class will need the following methods:

void shuffle(); // shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.
Card* getNext(); // returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
bool isEmpty(); // const returns true if the deck is empty.

#endif

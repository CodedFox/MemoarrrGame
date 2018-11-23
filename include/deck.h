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
             
        unsigned int topIndex{0}; //index of vector that is currently the "top"
    public:
   std::vector<C> cards; 
// shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.    
void shuffle();

// returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
virtual C* getNext();

// const returns true if the deck is empty.
virtual bool isEmpty() const;
        
};
template<typename C>
void Deck<C>::shuffle() {
    //using shuffle instead because random_shuffle was removed in C++17    
auto rng = std::default_random_engine {};
std::shuffle(std::begin(cards), std::end(cards), rng);

}
template<typename C>
//dont need virtual keyword since it is already in h file
C* Deck<C>::getNext() {
//assume start of vector is top of deck
if (!isEmpty()){
    return &cards[topIndex++];
} else {
    return nullptr;
}
 }
  // const returns true if the deck is empty.
template<typename C>
bool Deck<C>::isEmpty() const {
    //deck is "empty" when topValue index is same as size (since 0 based)
    return (topIndex==cards.size()); 
}

#endif

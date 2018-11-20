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
        std::vector<C> cards; 
        int topIndex{0}; //index of vector that is currently the "top"
    public:
    // shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.    
void shuffle() {
    //using shuffle instead because random_shuffle was removed in C++17    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this.cards.begin(), this.cards.end(), g);

}
// returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.

C* getNext() {
//assume start of vector is top of deck
if (!this.isEmpty()){
    return &this.cards[this.topIndex++];
} else {
    return nullptr;
}
 }
  // const returns true if the deck is empty.
bool isEmpty() const {
    //deck is "empty" when topValue index is same as size (since 0 based)
    return (this.topIndex==this.cards.size()); 
}
        
};

#endif

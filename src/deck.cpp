#include <iostream>
#include <string>

#include "deck.h"
#include "config.h" //contains flags for testing
template<typename C>
void Deck<C>::shuffle() {
    //using shuffle instead because random_shuffle was removed in C++17    
auto rng = std::default_random_engine {};
std::shuffle(std::begin(Deck::Deck.cards), std::end(Deck::Deck.cards), rng);

}
template<typename C>
//dont need virtual keyword since it is already in h file
C* Deck<C>::getNext() {
//assume start of vector is top of deck
if (!Deck::Deck.isEmpty()){
    return &Deck::Deck.cards[this.topIndex++];
} else {
    return nullptr;
}
 }
  // const returns true if the deck is empty.
template<typename C>
bool Deck<C>::isEmpty() const {
    //deck is "empty" when topValue index is same as size (since 0 based)
    return (this.topIndex==this.cards.size()); 
}

#ifdef TEST_DECK_
int main() {

    std::cout << "Testing Deck" << std::endl;

    return 0;
}
#endif
#include <iostream>
#include <string>

#include "deck.h"
#include "config.h" //contains flags for testing
void Deck::shuffle() {

}

// Card* Deck::getNext() {

// }

bool Deck::isEmpty() {

    return true;
}
#ifdef TEST_DECK_
int main() {

    std::cout << "Testing Deck" << std::endl;

    return 0;
}
#endif
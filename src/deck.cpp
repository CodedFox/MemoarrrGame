#include <iostream>
#include <string>

#include "deck.h"
#include "config.h" //contains flags for testing

#ifdef TEST_DECK_
int main() {

    std::cout << "Testing Deck" << std::endl;

    return 0;
}
#endif
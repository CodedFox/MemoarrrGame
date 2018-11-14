#include <iostream>
#include <string>

#include "rules.h"
#include "game.h"
#include "config.h" //contains flags for testing
bool Rules::isValid(const Game&) {

    return true;
}

bool Rules::gameOver(const Game&) {

    return true;
}

bool Rules::roundOver(const Game&) {

    return true;
}
#ifdef TEST_RULES_
int main() {

    std::cout << "Testing Rules" << std::endl;

    return 0;
}
#endif
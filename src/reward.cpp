#include <iostream>
#include <string>

#include "reward.h"
#include "config.h" //contains flags for testing

int Reward::getNumRubies() const {
    return Reward::numRubies;
} 
#ifdef TEST_REWARD_
int main() {

    std::cout << "Testing Reward" << std::endl;

    return 0;
}
#endif
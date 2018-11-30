#include <iostream>
#include <string>

#include "reward.h"
#include "config.h"

std::ostream & operator<<(std::ostream & os, const Reward & r) {
    os << r.rubies << " rubies";
    return os;
}

#ifdef TEST_REWARD_

#include "rewardDeck.h"

int main() {
    std::cout << "Testing Reward Class" << std::endl;

    try {
        RewardDeck rd = rd.make_RewardDeck();

        std::cout << rd.getNext()->getRubies() << std::endl;

        std::cout << *rd.getNext() << std::endl;

        std::cout << "Testing successfully" << std::endl;

    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif

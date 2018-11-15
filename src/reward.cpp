#include <iostream>
#include <string>

#include "reward.h"
#include "config.h" //contains flags for testing
Reward::Reward(){}
Reward::Reward(int nr) : numRubies(nr) {}
int Reward::getNumRubies() const {
    return Reward::numRubies;
} 
std::ostream & operator<<(std::ostream &os, const Reward &r) {  
  os << r.getNumRubies();
  return os;
}
#ifdef TEST_REWARD_
int main() {
    
    std::cout << "Testing Reward" << " rubies" << std::endl;

    return 0;
}
#endif
#include <iostream>
#include <string>

#include "reward.h"

std::ostream & operator<<(std::ostream & os, const Reward & r) {
    os << r.rubies << " rubies";
    return os;
}
#include <iostream>
#include <string>

#include "player.h"
#include "config.h"

// A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
// Joe Remember Doe: left (active)
// Once endOfGame is true:
// Joe Remember Doe:  3 rubies
std::ostream& operator<<(std::ostream & os, const Side & s) {
    switch(s) {
        case Side::top: os << "top"; break;
        case Side::bottom: os << "bottom"; break;
        case Side::left: os << "left"; break;
        case Side::right: os << "right"; break;
        default: os << "Error - Board Side"; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream & os, const Player & p) {
    if (!p.endGame) {
        os << p.name << ": " << p.boardSide;
        
        if (p.active) {
            os << " (active)";
        } else {
            os << " (inactive)";
        }
    } else {
        os << p.name << ": " << p.rubies << " rubies";
    }
    return os;
}

#ifdef TEST_PLAYER_

int main() {
    std::cout << "Testing Game Class" << std::endl;

    try {
        Player p1("Jon", Side(0));
        std::cout << p1.getName() << std::endl;
        std::cout << p1 << std::endl;
        
        p1.setDisplayMode(true);
        std::cout << p1 << std::endl;

        std::cout << p1.isActive() << std::endl;
        p1.setActive(false);
        std::cout << p1.isActive() << std::endl;
        std::cout << p1.getNRubies() << std::endl;
        std::cout << p1.getSide() << std::endl;

        p1.setSide(Side::bottom);
        std::cout << p1.getSide() << std::endl;

        std::cout << "Testing successfully" << std::endl;

    } catch(...) {
        std::cout << "Testing failed" << std::endl;
    }

    return 0;
}

#endif

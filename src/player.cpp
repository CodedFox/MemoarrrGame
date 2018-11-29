#include <iostream>
#include <string>

#include "player.h"
// #include "reward.h"

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
            os << "inactive";
        }
    } else {
        os << p.name << ": " << p.rubies << " rubies";
    }
    return os;
}


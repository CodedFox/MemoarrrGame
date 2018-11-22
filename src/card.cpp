#include <iostream>
#include <string>
#include <sstream>

#include "card.h"

std::ostream & operator<<(std::ostream & os, const Card::FaceAnimal & fa) {
    switch(fa) {
        case Card::FaceAnimal::Crab: os << "C"; break;
        case Card::FaceAnimal::Penguin: os << "P"; break;
        case Card::FaceAnimal::Octopus: os << "O"; break;
        case Card::FaceAnimal::Turtle: os << "T"; break;
        case Card::FaceAnimal::Walrus: os << "W"; break;
        default: os << "Error - Face Animal"; break;
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const Card::FaceBackground & fb) {
    switch(fb) {
        case Card::FaceBackground::Red: os << "r"; break;
        case Card::FaceBackground::Green: os << "g"; break;
        case Card::FaceBackground::Purple: os << "p"; break;
        case Card::FaceBackground::Blue: os << "b"; break;
        case Card::FaceBackground::Yellow: os << "y"; break;
        default: os << "Error - Face Background"; break;
    }
    return os;
}

std::string Card::operator()(int row) {
    std::ostringstream oss;
    if (row >= 0 && row < 3) {
        if (row%2 == 1) {
            oss << background << animal << background;
        } else {
            oss << background << background << background;
        }
    } else {
        throw std::invalid_argument( "Invalid Row" );
    }
    return oss.str();
}
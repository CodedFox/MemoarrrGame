#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "reward.h"
class Reward;

// Design a class Player which combines all information for a player including name, 
// side of the board (top, bottom, left or right) and has the current count of rubies.
class Player {
    public:
        enum class Side {top, bottom, left, right};

    private:
        std::string name;
        Side boardSide; // top, bottom, left, right
        bool active = true;
        int rubies = 0;
        bool endGame = false;

    public:
        Player() {};
        Player(std::string playerName, Side s): name(playerName), boardSide(s) {};
        ~Player() {};
        inline std::string getName() const { return name; }; // const return the name of the player.
        inline void setActive(bool a) { active = a; }; // set the status of the player as active or inactive.
        inline bool isActive() const { return active; }; // returns true if the player is active.
        inline int getNRubies() const { return rubies; }; // const return the number of rubies won by this player.
        inline void addReward(const Reward&) { /* TO-DO */  }; // add a reward with a given number of rubies.
        inline void setDisplayMode(bool endOfGame) { endGame = endOfGame; };
        inline Side getSide() const { return boardSide; };
        inline void setSide(Side s) { boardSide = s; };

        friend std::ostream& operator<<(std::ostream & os, const Player & player);
        friend std::ostream& operator<<(std::ostream & os, const Side & s);
};

// A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
// Joe Remember Doe: left (active)
// Once endOfGame is true:
// Joe Remember Doe:  3 rubies
std::ostream& operator<<(std::ostream & os, const Player & player) {
    if (!player.endGame) {
        os << player.name << ": " << player.boardSide;
        
        if (player.active) {
            os << " (active)";
        } else {
            os << "inactive";
        }
    } else {
        os << player.name << ": " << player.rubies << " rubies";
    }
    return os;
}

std::ostream & operator<<(std::ostream & os, const Player::Side & s) {
    switch(s) {
        case Player::Side::top: os << "top"; break;
        case Player::Side::bottom: os << "bottom"; break;
        case Player::Side::left: os << "left"; break;
        case Player::Side::right: os << "right"; break;
        default: os << "Error - Board Side"; break;
    }
    return os;
}

#endif

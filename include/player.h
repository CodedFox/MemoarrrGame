#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "reward.h"
class Reward;

// Design a class Player which combines all information for a player including name, 
// side of the board (top, bottom, left or right) and has the current count of rubies.
class Player {
    private:
        std::string name;
        std::string boardSide; // top, bottom, left, right
        bool active = true;
        int rubies = 0;
        bool endOfGame = false;

    public:
        Player() {};
        Player(std::string playerName, std::string side): name(playerName), boardSide(side) {};
        ~Player() {};
        inline std::string getName() const { return name; }; // const return the name of the player.
        inline void setActive(bool a) { active = a; }; // set the status of the player as active or inactive.
        inline bool isActive() const { return active; }; // returns true if the player is active.
        inline int getNRubies() const { return rubies; }; // const return the number of rubies won by this player.
        inline void addReward( const Reward& ) { }; // add a reward with a given number of rubies.
        inline void setDisplayMode(bool gameEnd) { endOfGame = gameEnd; };

        friend std::ostream& operator<<(std::ostream & os, const Player & player);
};

// A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
// Joe Remember Doe: left (active)
// Once endOfGame is true:
// Joe Remember Doe:  3 rubies
std::ostream& operator<<(std::ostream & os, const Player & player) {
    if (!player.endOfGame) {
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

#endif

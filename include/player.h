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
        inline void addReward(const Reward& r) { rubies += r.getRubies(); }; // add a reward with a given number of rubies.
        inline void setDisplayMode(bool endOfGame) { endGame = endOfGame; };
        inline Side getSide() const { return boardSide; };
        inline void setSide(Side s) { boardSide = s; };

        friend std::ostream& operator<<(std::ostream & os, const Player & p);
        friend std::ostream& operator<<(std::ostream & os, const Side & s);
};

#endif

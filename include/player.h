#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "reward.h"
class Reward;

// Design a class Player which combines all information for a player including name, 
// side of the board (top, bottom, left or right) and has the current count of rubies.
class Player {
    enum class Side{top, bottom, left, right};
     friend std::ostream &operator<<(std::ostream &, const Side &);
    private:       
        std::string playerName;
        Side boardSide;  //top bottom left or right
        bool active = true;
        int numRubies = 0; //current count of rubies
        std::string displayMode;
    public:
        Player();
        Player(std::string name, Side bs);
        std::string getName() const; // const return the name of the player.
        void setActive(bool); // set the status of the player as active or inactive.
        bool isActive() const; // returns true if the player is active.
        int getNRubies() const; // const return the number of rubies won by this player.
        void setSide(Side);
        Side getSide() const;  // const return the side of the board the player is on
        void addReward( const Reward& ); // add a reward with a given number of rubies.
        void setDisplayMode(bool endOfGame);

        // A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
        // Joe Remember Doe: left (active)
        // Once endOfGame is true:
        // Joe Remember Doe:  3 rubies
        friend std::ostream &operator<<(std::ostream &, const Player &);
};

#endif

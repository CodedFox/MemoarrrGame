#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// Design a class Player which combines all information for a player including name, 
// side of the board (top, bottom, left or right) and has the current count of rubies.

string getName(); // const return the name of the player.
void setActive(bool); // set the status of the player as active or inactive.
bool isActive(); // returns true if the player is active.
int getNRubies(); // const return the number of rubies won by this player.
void addReward( const Reward& ); // add a reward with a given number of rubies.
void setDisplayMode(bool endOfGame);

// A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
// Joe Remember Doe: left (active)
// Once endOfGame is true:
// Joe Remember Doe:  3 rubies

#endif

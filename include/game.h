#ifndef GAME_H
#define GAME_H

// Design a class Game that encapsulates the current state of the game and it will have 
// a class variable of type Board. It is responsible to print the current state of the game.

int getRound(); // returns a number between 0 and 6 corresponding to the current round of the game
void addPlayer( const Player& ); // which adds a Player to this game.
Player& getPlayer();
const Card* getPreviousCard();
const Card* getCurrentCard();
void setCurrentCard( const Card*);

// A game must be printable with the insertion operator cout << game. It should display the board and all players.

#endif

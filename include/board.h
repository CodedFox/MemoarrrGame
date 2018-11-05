#ifndef BOARD_H
#define BOARD_H

// Design a class Board which holds an array of strings corresponding to the screen display of the game.

bool isFaceUp( const Letter&, const Number& ); /* const returns true if the card at a given position is face 
up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid Letter and 
Number combination was given. */
bool turnFaceUp( const Letter&, const Number& ); /* changes the state of the specified card return false if 
card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number combination 
was given. */
bool turnFaceDown( const Letter&, const Number& ); /* changes the state of the specified card return false if 
card was down already. Throws an exception of type OutOfRange if an invalid Letter and Number combination 
was given. */
void reset(); // changes the state to all cards to be face down. A board must be printable with the insertion operator cout << board.

#endif

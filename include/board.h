#ifndef BOARD_H
#define BOARD_H

#include <map>

#include "cardDeck.h"
class CardDeck;

enum class Letter {A, B, C, D, E};
enum class Number {_1, _2, _3, _4, _5};

// Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {
    private:
        std::map<std::pair<Letter, Number>, std::pair<Card *, bool>> gameBoard;

    public:
        Board() {};
        Board(CardDeck*);

        /* const returns true if the card at a given position is face up. Letter and Number are enumerations. 
        Throws an exception of type OutOfRange if an invalid Letter and Number combination was given. */
        bool isFaceUp( const Letter&, const Number& );

        /* changes the state of the specified card return false if card was up already. Throws an exception 
        of type OutOfRange if an invalid Letter and Number combination was given. */
        bool turnFaceUp( const Letter&, const Number& );

        /* changes the state of the specified card return false if card was down already. Throws an exception 
        of type OutOfRange if an invalid Letter and Number combination was given. */
        bool turnFaceDown( const Letter&, const Number& );

        /* changes the state to all cards to be face down. */
        void reset();

        /* returns a pointer to the card at a given location.
        Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.*/
        Card* getCard( const Letter&, const Number& );

        /* updates the pointer to card at a given location.
        Throws an exception of type OutOfRange if an invalid Letter and Number combination was given. */
        void setCard( const Letter&, const Number&, Card* );

        /* A board must be printable with the insertion operator cout << board. */
        friend std::ostream &operator<<(std::ostream &, Board &);

        friend std::ostream& operator<<(std::ostream & os, const Letter & l);
        friend std::ostream& operator<<(std::ostream & os, const Number & n);
};

#endif

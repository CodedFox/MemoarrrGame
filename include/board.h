#ifndef BOARD_H
#define BOARD_H
#include "card.h"

#include "cardDeck.h"
class Card;


class CardDeck;
// Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {
        enum class Letter {A,B,C,D,E};
        enum class Number {_1, _2, _3, _4, _5}; //from https://stackoverflow.com/a/13332140

    private:
    //need to store Card and faceup indicator for each position
        std::vector<std::vector<Card*>> cardsOnBoard;
        std::vector<std::vector<bool>> faceUpBoard;
    public:
        
        Board();
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

        /*A board must be printable with the insertion operator cout << board. */
        friend std::ostream &operator<<(std::ostream &, Board &);
};

#endif

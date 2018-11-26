#ifndef GAME_H
#define GAME_H

#include <map>
#include <utility>

#include "player.h"
class Player;

#include "card.h"
class Card;

#include "board.h"
class Board;

// Design a class Game that encapsulates the current state of the game and it will have 
// a class variable of type Board. It is responsible to print the current state of the game.
class Game {
    private:
        int round = 0;
        std::map<Side, Player> players;
        std::map<Side, Player>::iterator currentPlayer;
        Board board;
        Card * previousCard = nullptr;
        Card * currentCard = nullptr;

    public:
        Game() {};
        Game(CardDeck * cd): board(cd) {};
        inline int getRound() const { return round; }; // returns a number between 0 and 6 corresponding to the current round of the game
        void addPlayer( const std::string ); // which adds a Player to this game.
        inline std::map<Side, Player> getPlayers() const { return players; };
        inline const std::map<Side, Player>::iterator getCurrentPlayer() const { return currentPlayer; };
        inline Player& getPlayer( Side s ) { return players[s]; } ;
        inline const Card* getPreviousCard() const { return previousCard; };
        inline const Card* getCurrentCard() const { return currentCard; };
        void setCurrentCard( const Card* );
        inline Card* getCard( const Letter& l, const Number& n ) { return board.getCard(l, n); }; // which calls the corresponding method in Board.
        inline void setCard( const Letter& l, const Number& n, Card* c ) { board.setCard(l, n, c); }; // which calls the corresponding method in Board.
        
        // A game must be printable with the insertion operator cout << game. It should display the board and all players.
        friend std::ostream &operator<<(std::ostream & os, const Game & g);
};

#endif

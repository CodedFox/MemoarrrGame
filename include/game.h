#ifndef GAME_H
#define GAME_H
#include <map>
#include "board.h"
class Board;
#include "player.h"
class Player;

#include "card.h"
class Card;

// Design a class Game that encapsulates the current state of the game and it will have 
// a class variable of type Board. It is responsible to print the current state of the game.
class Game {
    private:
        std::map<Player::Side, Player> playerMap;
        int round;
        Board board;
        Card* previousCard;
        Card* currentCard;
        std::pair<Board::Letter, Board::Number> blockedPosition; //used for expert mode with walrus card block   
        bool expertMode;     
    public:
        Game();
        Game(CardDeck*, bool);    
        int getRound(); // returns a number between 0 and 6 corresponding to the current round of the game
        void setRound(int);
        void addPlayer( const Player& ); // which adds a Player to this game.
        Player& getPlayer(Player::Side);
        const Card* getPreviousCard();
        const Card* getCurrentCard();
        void setCurrentCard( const Card*);
        Card* getCard( const Board::Letter&, const Board::Number& ); //which calls the corresponding method in Board
        void setCard( const Board::Letter&, const Board::Number&, Card* ); //which calls the corresponding method in Board
        // A game must be printable with the insertion operator cout << game. It should display the board and all players.
        friend std::ostream &operator<<(std::ostream &, Game &);
};

#endif

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
        bool expertBoard;  //changes print of board
        bool expertRules;  //changes game play        
        std::map<Player::Side, Player>::iterator itCurrentPlayer;
        std::vector<std::pair<Board::Letter, Board::Number> > orderSelected;  //used for printing expert display mode, need to keep track of order for expert rules too
    public:
        Game();
        Game(CardDeck*, bool, bool);
        std::map<Player::Side, Player>& getPlayerMap();    
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
        void reveal3Cards(Player::Side);
        friend std::ostream &operator<<(std::ostream &, Game &);
        void setExpertRules(bool);
        bool getExpertRules();
        void setExpertBoard(bool);
        bool getExpertBoard();
        void setBlockedPosition(const Board::Letter&, const Board::Number&);
        std::pair<Board::Letter, Board::Number> getBlockedPosition();
        void setItCurrentPlayer(std::map<Player::Side, Player>::iterator);
        const std::map<Player::Side, Player>::iterator getItCurrentPlayer();
        void setCurrentPlayer(const Player&);
        bool validSelection(const Board::Letter&, const Board::Number&); //check if board spot can be chosen  
        bool validToBlock(const Board::Letter& , const Board::Number& ); //check if spot can be blocked
        bool validToTurnFaceDown(const Board::Letter& , const Board::Number& ); //check if spot can be turned face down
        bool validToSwap(const Board::Letter& row, const Board::Number& col); //check if spot is valid to swap
        void printOutGameOver(); //print out list of players and overall winner
        static bool compare(Player, Player); //to sort by num rubies at end
        void addSelection(Board::Letter row, Board::Number col); //add selection to orderSelected for expert display mode
        static std::string getSelectedRow(); //helper function to check user input
        static int getSelectedCol(); //helper function to check user input
        void turnFaceDown(const Board::Letter& row, const Board::Number& col);
        void removeFromOrderSelected(const Board::Letter& , const Board::Number&); //removes item from orderSelected so it won't be displayed in expert display mode
        void swapCards(const Board::Letter& , const Board::Number&); //swaps card at given position with current card
        bool firstTurn(); //true if this is first turn of the round (no expert rule should apply on first turn)
};

#endif

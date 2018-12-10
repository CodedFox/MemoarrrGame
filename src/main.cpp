#include <iostream>
#include <string>
#include <regex>

#include "board.h"
#include "card.h"
#include "cardDeck.h"
#include "deck.h"
#include "game.h"
#include "player.h"
#include "reward.h"
#include "rewardDeck.h"
#include "rules.h"
#include "config.h"

#if !defined(TEST_BOARD_) && !defined(TEST_CARD_) && !defined(TEST_CARD_DECK_) && \
    !defined(TEST_DECK_) && !defined(TEST_GAME_) && !defined(TEST_PLAYER_) && \
    !defined(TEST_REWARD_) && !defined(TEST_REWARD_DECK_) && !defined(TEST_RULES_)

int inputPlayer() {
    std::string str;
    std::regex regex_pattern("[2-4]");
    do {
        std::cout << "Please enter the number of players (2-4): " ;
        std::cin >> str;
    } while( !std::cin.fail() && !std::regex_match(str, regex_pattern) );

    return stoi(str);
}

bool askExpert(std::string word){
    std::string str;
    std::regex regex_pattern("[yYnN]");
    do {
        std::cout << "Would you like to play with the expert " << word << "? [y/n]" << std::endl;
        std::cin >> str;
    } while( !std::cin.fail() && !std::regex_match(str, regex_pattern) );
    if (str == "y" || str == "Y") {
        return true;
    }
    return false;
}

std::string getPlayerName(int playerNum){
    std::string str;
    do {
        std::cout << "Please enter a name for player " << (playerNum) << ": ";
        std::cin >> str;
    } while(std::cin.fail());

    return str;
}

int main() {
    std::cout << "= Welcome to Memoarrr! =" << std::endl;
    std::cout << std::endl;

    bool expertBoardFlag = askExpert("board");
    bool expertRulesFlag = askExpert("rules");

    // Ask player to choose game version, number of players and names of players.
    int numPlayers = inputPlayer();
    std::cout << std::endl;

    // Create the corresponding players, rules, cards and board for the game.
    CardDeck cd = cd.make_CardDeck();
    RewardDeck rd = rd.make_RewardDeck();

    Game game(&cd, expertBoardFlag, expertRulesFlag);
    Rules rules;

    for (int i = 0; i < numPlayers; i++) {
        game.addPlayer(getPlayerName(i+1));
        std::cout << std::endl;
    }

    // Display game (will show board and all players)
    std::cout << game << std::endl;
    std::cin.get();

    // while Rules.gameOver is false
    while (!rules.gameOver(game)) {

        // update status of cards in board as face down
        // update status of all players in game as active
        game.newRound();

        std::cout << "==ROUND " << game.getRound() << "==" << std::endl;
        std::cout << std::endl;

        std::cout << "=CARD PREVIEW=" << std::endl;
        // for each player
        for (int i = 0; i < numPlayers; i++) {
            // Temporarily reveal 3 cards directly in front of the player
            game.revealSideCards(Side(i));
        }

        std::cout << game << std::endl;
        std::cout << std::endl;

        // while Rules.roundOver is false
        while (!rules.roundOver(game)) {
            // # next active player takes a turn
            std::cout<< (*game.getCurrentPlayer()).second.getName() << " it is your turn." << std::endl;

            // get selection of card to turn face up from active player update board in game
            Letter row = game.getRow();
            Number col = game.getCol();


            bool valid = false;
            while (!valid) {
                if (rules.isValidSelection(game, row, col)) {
                    valid = true;
                } else {
                    std::cout << "You can't choose that spot! Choose another." << std::endl;
                    row = game.getRow();
                    col = game.getCol();
                }
            }

            game.setBlockedPosition(Letter::C, Number::_3);

            game.setCurrentCard(game.getCard(row, col));
            game.addCardToOrder(row, col);

            std::cout << std::endl;

            game.turnCardUp(row, col);
            std::cout << game << std::endl;
            std::cout << std::endl;

            // if Rules.isValid(card) is false
            if (!rules.isValid(game)) {

                // # player is no longer part of the current round
                std::cout << "Your cards didn't match. You're out of this round " << (*game.getCurrentPlayer()).second.getName() << "!" << std::endl;
                std::cout << "Press 'ENTER' to continue." << std::endl;
                std::cin.get();
                std::cin.get();

                // current player becomes inactive
                game.getCurrentPlayer()->second.setActive(false);

            } else if (game.getExpertRules() && !game.getFirstTurn()) {
                // move is valid and expert rules are selected, need to deal with octopus, penguin, walrus
                // crab and turtle are handled in getNextPlayer 
                rules.applyExpertRules(game);
                std::cout << std::endl;
            }

            game.setCurrentPlayer(rules.getNextPlayer(game));
            game.setFirstTurn(false);
        }

        game.setCurrentPlayer(rules.getNextPlayer(game));
        game.getCurrentPlayer()->second.addReward(*rd.getNext());

        std::cout << std::endl;
        std::cout << "Congratulations " << (*game.getCurrentPlayer()).second.getName() << ", you won this round!" << std::endl;
        std::cout << std::endl;

        if(!rules.gameOver(game)){
            std::cout << "Round over. Press 'ENTER' to start the next round!" << std::endl;
            std::cin.get();
            std::cout << std::endl;
        }
    }

    std::cout << "=GAME OVER=" << std::endl;
    // print players with their number of rubies sorted from least to most rubies
    // print overall winner

    game.printWinners();

    return 0;
}

#endif

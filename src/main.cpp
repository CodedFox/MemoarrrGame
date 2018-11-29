#include <iostream>
#include <string>
#include <regex>

#include "board.h"
#include "card.h"
#include "cardDeck.h"
#include "deck.h"
#include "expertBoard.h"
#include "expertRules.h"
#include "game.h"
#include "player.h"
#include "reward.h"
#include "rewardDeck.h"
#include "rules.h"

int inputPlayer() {
    std::string str;
    std::regex regex_pattern("[2-4]");
    do {
        std::cout << "Please enter the number of players (2-4): " ;
        std::cin >> str;
    } while(!std::regex_match(str, regex_pattern));

    return stoi(str);
}

std::string getPlayerName(int playerNum){
    std::string str;
    do {
        std::cout << "Please enter a name for player " << (playerNum) << ": ";
        std::cin >> str;
    } while(std::cin.fail());

    return str;
}

Letter getRow() {
    std::string str;
    std::regex regex_pattern("[a-eA-E]");
    do {
        std::cout << "Please choose a row (A-E): " ;
        std::cin >> str;
    } while(!std::regex_match(str, regex_pattern));
    char cstr = str[0];
    switch (cstr) {     
        case 'A': case 'a': return Letter::A;
        case 'B': case 'b': return Letter::B;
        case 'C': case 'c': return Letter::C;
        case 'D': case 'd': return Letter::D;
        case 'E': case 'e': return Letter::E;
        default: return Letter::A;
    }
}

Number getCol() {
    std::string str;
    std::regex regex_pattern("[1-5]");

    do {
        std::cout << "Please choose a column (1-5): " ;
        std::cin >> str;
    } while(!std::regex_match(str, regex_pattern));

    int i = stoi(str);
    switch (i) {     
        case 1: return Number::_1;
        case 2: return Number::_2;
        case 3: return Number::_3;
        case 4: return Number::_4;
        case 5: return Number::_5;
        default: return Number::_1;
    }
}

int main() {
    std::cout << "= Welcome to Memoarrr! =" << std::endl;
    std::cout << std::endl;

    // Ask player to choose game version, number of players and names of players.
    int numPlayers = inputPlayer();
    std::cout << std::endl;

    // Create the corresponding players, rules, cards and board for the game.
    CardDeck cd = cd.make_CardDeck();
    RewardDeck rd = rd.make_RewardDeck();

    Game game(&cd);
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

        // while Rules.roundOver is false
        while (!rules.roundOver(game)) {
            
            std::cout << game << std::endl;
            std::cout << std::endl;

            // # next active player takes a turn
            std::cout<< (*game.getCurrentPlayer()).second.getName() << " it is your turn." << std::endl;

            // get selection of card to turn face up from active player update board in game
            Letter row = getRow();
            Number col = getCol();

            bool valid = false;
            while (!valid) {
                if (rules.isValidSelection(game, row, col)) {
                    valid = true;
                    game.setCurrentCard(game.getCard(row, col));
                } else {
                    std::cout << "You can't choose that spot! Choose another." << std::endl;
                    row = getRow();
                    col = getCol();
                }
            }
            std::cout << std::endl;

            // if Rules.isValid(card) is false
            if (!rules.isValid(game)) {
                game.turnCardUp(row, col);
                std::cout << game << std::endl;

                // # player is no longer part of the current round
                std::cout << "Fail. You're out of this round " << (*game.getCurrentPlayer()).second.getName() << "!" << std::endl;

                game.turnCardDown(row, col);

                // current player becomes inactive
                game.getCurrentPlayer()->second.setActive(false);
            } else {
                game.turnCardUp(row, col);
                // display game
                std::cout << game << std::endl;
            }
            game.setCurrentPlayer(rules.getNextPlayer(game));
            std::cout << "Test" << std::endl;
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





    // Player p1("Jon", Side(0));
    // std::cout << p1 << std::endl;
    
    // p1.setDisplayMode(true);
    // std::cout << p1 << std::endl;

    // std::map<int, std::pair<int, bool>> m;
    // m.insert(std::make_pair(0, std::make_pair(8, false)));
    // std::cout << m[0].first << std::endl;
    // std::cout << m[0].second << std::endl;

    // CardDeck cd = cd.make_CardDeck();
    // Game g(&cd);
    // g.addPlayer("Jon");
    // g.addPlayer("Nat");
    // g.addPlayer("Cornelia");
    // g.addPlayer("David");

    // std::cout << b.isFaceUp(Letter::A, Number::_1) << std::endl;
    // std::cout << b.turnFaceUp(Letter::A, Number::_1) << std::endl;
    // std::cout << b.turnFaceUp(Letter::C, Number::_2) << std::endl;
    // std::cout << b.turnFaceUp(Letter::D, Number::_5) << std::endl;
    // std::cout << b.turnFaceUp(Letter::E, Number::_4) << std::endl;
    // std::cout << b.turnFaceUp(Letter::B, Number::_3) << std::endl;
    // std::cout << b.turnFaceUp(Letter::C, Number::_3) << std::endl;
    // std::cout << b.isFaceUp(Letter::A, Number::_1) << std::endl;
    // b.reset();
    // std::cout << b.isFaceUp(Letter::A, Number::_1) << std::endl;

    // std::cout << g << std::endl;

    // Card c = *cd.getNext();

    // std::cout << c(0) << std::endl;
    // std::cout << c(1) << std::endl;
    // std::cout << c(2) << std::endl;

    // CardDeck cd = cd.make_CardDeck();
    // std::cout << cd.isEmpty() << std::endl;
    // cd.shuffle();

    // Card c = *cd.getNext();
    // std::cout << c(0) << std::endl;
    // std::cout << c(1) << std::endl;
    // std::cout << c(2) << std::endl;
    // c = *cd.getNext();
    // std::cout << c(0) << std::endl;
    // std::cout << c(1) << std::endl;
    // std::cout << c(2) << std::endl;

    // RewardDeck rd = rd.make_RewardDeck();
    // std::cout << rd.isEmpty() << std::endl;
    // rd.shuffle();

    // Reward r = *rd.getNext();
    // std::cout << r << std::endl;
    // r = *rd.getNext();
    // std::cout << r << std::endl;

    // Card c(FaceAnimal(0), FaceBackground(0));

    // std::cout << c(0) << std::endl;
    // std::cout << c(1) << std::endl;
    // std::cout << c(2) << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

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

int main() {

    std::cout << "Memoarrr!" << std::endl;
    
    Player p1("Jon", Side(0));
    std::cout << p1 << std::endl;
    
    p1.setDisplayMode(true);
    std::cout << p1 << std::endl;

    std::map<int, std::pair<int, bool>> m;
    m.insert(std::make_pair(0, std::make_pair(8, false)));
    std::cout << m[0].first << std::endl;
    std::cout << m[0].second << std::endl;

    CardDeck cd = cd.make_CardDeck();
    Game g(&cd);
    g.addPlayer("Jon");
    g.addPlayer("Nat");
    g.addPlayer("Cornelia");
    g.addPlayer("David");

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

    std::cout << g << std::endl;

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

// Ask player to choose game version, number of players and names of players.
// Create the corresponding players, rules, cards and board for the game.
// Display game (will show board and all players)
// while Rules.gameOver is false
//     update status of cards in board as face down
//     update status of all players in game as active
//     for each player
//         Temporarily reveal 3 cards directly in front of the player
//     while Rules.roundOver is false
//         # next active player takes a turn
//         get selection of card to turn face up from active player update board in game
//         if Rules.isValid(card) is false
//             # player is no longer part of the current round
//             current player becomes inactive
//         display game
//     Remaining active player receives reward (rubies)
// print players with their number of rubies sorted from least to most rubies
// print overall winner

    return 0;
}

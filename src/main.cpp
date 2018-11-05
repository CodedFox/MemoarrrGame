#include <iostream>

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

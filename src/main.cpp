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
#include "config.h" //contains flags for testing
#if  !defined(TEST_BOARD_) && !defined(TEST_CARD_) &&  !defined(TEST_CARD_DECK_) &&  \
 !defined(TEST_DECK_) &&  !defined(TEST_EXPERT_BOARD_) &&  !defined(TEST_EXPERT_RULES_) && \
 !defined(TEST_GAME_) &&  !defined(TEST_PLAYER_) &&  !defined(TEST_REWARD_) && \
 !defined(TEST_REWARD_DECK_) &&  !defined(TEST_REWARD_DECK_) &&  !defined(TEST_RULES_)

int inputNumber()
{
    std::string str;
    std::regex regex_pattern("[2-4]");
    do
    {
        std::cout << "Please enter the number of players (2-4):" ;
        std::cin >> str;
    }while(!std::regex_match(str,regex_pattern));

    return stoi(str);
}
std::string getPlayerName(int numP){
    std::string str;
    do {
        std::cout << "Please enter name for player " << (numP+1) << ":" << std::endl;
        std::cin >> str;
    } while(std::cin.fail());

    return str;
}
bool askExpert(std::string word ){
    char answer;
do {
    std::cout << "Would you like to play with the expert " << word << "? [y/n]" << std::endl;
    std::cin >> answer;
} while( !std::cin.fail() && answer!='y' && answer!='n' && answer!='N' && answer!='Y' );
if (answer == 'y' || answer =='Y') return true;
return false;
}
std::string getSelectedRow(){
      std::string str;
    std::regex regex_pattern("[a-eA-E]");
    do
    {
        std::cout << "Please choose a row (A-E):" ;
        std::cin >> str;
    }while(!std::regex_match(str,regex_pattern));

    return str;

}
int getSelectedCol(){
      std::string str;
    std::regex regex_pattern("[1-5]");
    do
    {
        std::cout << "Please choose a column (1-5):" ;
        std::cin >> str;
    }while(!std::regex_match(str,regex_pattern));

    return stoi(str);  //subtract 1 because 0-indexed array
}
int main() {
   
   std::cout << "Welcome to Memoarrr!" << std::endl;  
   // Ask player to choose game version, number of players and names of players.
   bool expertBoardFlag = askExpert("board");
   bool expertRulesFlag = askExpert("rules");
   int numPlayers = inputNumber();
   // Create the corresponding players, rules, cards and board for the game.
   CardDeck* cd = CardDeck::make_CardDeck(); 
   RewardDeck* rd = RewardDeck::make_RewardDeck();   
   Game game(cd, expertBoardFlag, expertRulesFlag);  //may need to move rules flag to rules class
   Rules rules;
   for(int i = 0; i<numPlayers; ++i){
       std::string pName = getPlayerName(i);
       Player player(pName,static_cast<Player::Side>(i));
       game.addPlayer(player);       
   }
   std::cin.get();
int roundCounter(0);  
// Display game (will show board and all players)
std::cout<<game<<std::endl;   
// while Rules.gameOver is false  
while(!rules.gameOver(game)){
    //     update status of cards in board as face down
    game.Game::setRound(roundCounter); //set round also resets board, currentPlayer iterator, and currentcard
    //     update status of all players in game as active
    std::cout<<"Starting ROUND " << (game.Game::getRound() + 1) << std::endl;
   for(int i = 0; i<numPlayers; ++i){              
        game.getPlayer(static_cast<Player::Side>(i)).setActive(true);
    //     for each player
    //         Temporarily reveal 3 cards directly in front of the player
        game.reveal3Cards(static_cast<Player::Side>(i));              
    }
    
    while (!rules.roundOver(game)){
    //         # next active player takes a turn        
    //         get selection of card to turn face up from active player update board in game
           
           std::cout<< (*game.getItCurrentPlayer()).second.getName() << " it is your turn" << std::endl;
           
           Board::Letter row = Board::convertStrToLetter(getSelectedRow());
           Board::Number col = Board::convertIntToNumber(getSelectedCol());
           while (!game.validSelection(row,col)){              
               std::cout<<"You can't choose that spot"<< std::endl;
                row = Board::convertStrToLetter(getSelectedRow());
                col = Board::convertIntToNumber(getSelectedCol());
           } 
           
           game.setCard(row, col, game.getCard(row, col));
           game.addSelection(row,col);
           //TODO more logic here top play game
           if (!rules.isValid(game)){
            //# player is no longer part of the current round
            //current player becomes inactive
            std::cout << "You're out of this round " << (*game.getItCurrentPlayer()).second.getName() << std::endl;
                (*game.getItCurrentPlayer()).second.setActive(false);                    
            }
             
        game.setCurrentPlayer(rules.getNextPlayer(game));    
    //  display game
        std::cout<<game<<std::endl; 
    }
    //  Remaining active player receives reward (rubies)
       (*game.getItCurrentPlayer()).second.addReward(*(rd->getNext()));
       std::cout<<"Congratulations " << (*game.getItCurrentPlayer()).second.getName() << " you won this round!" << std::endl;
        roundCounter++;
        if(!rules.gameOver(game)){
        std::cout<<"Round over.  Press ENTER to start the next round"<<std::endl;
        std::cin.get();       } 
        
}

std::cout << "GAME OVER" << std::endl;
// print players with their number of rubies sorted from least to most rubies
// and print overall winner
game.printOutGameOver();


    return 0;
}
#endif
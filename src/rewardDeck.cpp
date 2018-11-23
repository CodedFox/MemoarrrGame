#include <iostream>
#include <string>
#include "deck.h"
#include "rewardDeck.h"
#include "config.h" //contains flags for testing
//global pointer for only one instance of class
RewardDeck* RewardDeck::rewardDeck = nullptr;
//this is called to create an instance of the class
RewardDeck* RewardDeck::make_RewardDeck(){
            if (!rewardDeck){
               //we need to make a deck since it hasn't been made yet
               rewardDeck = new RewardDeck();
            for(int i = 0; i < 3; ++i){
                //add new reward to cards vector
           
           (*RewardDeck::rewardDeck).cards.push_back(Reward(1));}
(*RewardDeck::rewardDeck).cards.push_back(Reward(2));
(*RewardDeck::rewardDeck).cards.push_back(Reward(2));
(*RewardDeck::rewardDeck).cards.push_back(Reward(3));
(*RewardDeck::rewardDeck).cards.push_back(Reward(4));
 
           } 
           return rewardDeck;}
 // is the only public method for RewardDeck. The method has to always return the same RewardDeck during the execution of the program.
//to use RewardDeck::make_RewardDeck()->getNext();
#ifdef TEST_REWARD_DECK_
int main() {
for(int i =0; i<7;++i){
    std::cout <<*(RewardDeck::make_RewardDeck()->getNext()) << std::endl;}
    std::cout << "Testing Reward Deck" << std::endl;

    return 0;
}
#endif
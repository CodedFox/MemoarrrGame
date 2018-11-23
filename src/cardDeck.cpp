#include <iostream>
#include <string>
#include "deck.h"
#include "cardDeck.h"
#include "config.h" //contains flags for testing
//global pointer for only one instance of class
CardDeck* CardDeck::cardDeck = nullptr;
       
CardDeck* CardDeck::make_CardDeck(){
           if (!cardDeck){
               //we need to make a carddeck since it hasn't been made yet
               cardDeck = new CardDeck();
                for(int i = 0; i < 5; ++i){                
                for(int j = 0; j < 5; ++j){                    
                    //add new card to cards vector
                    Card::FaceAnimal fa = static_cast<Card::FaceAnimal>(i);
                    Card::FaceBackground fb = static_cast<Card::FaceBackground>(j);                   
                    (*CardDeck::cardDeck).cards.push_back(Card(fa,fb));
                }
            }
           } 
           return cardDeck;} // is the only public method for CardDeck. The method has to always return the same CardDeck during the execution of the program.
//to use elsewhere //to use CardDeck::make_CardDeck()->getNext();
#ifdef TEST_CARD_DECK_
int main() {
    std::cout << CardDeck::make_CardDeck()->getNext() << std::endl;
    std::cout << CardDeck::make_CardDeck()->getNext() << std::endl;
    std::cout << CardDeck::make_CardDeck()->getNext() << std::endl;
    std::cout << CardDeck::make_CardDeck()->getNext() << std::endl;
    std::cout << "Testing Card Deck" << std::endl;

    return 0;
}
#endif
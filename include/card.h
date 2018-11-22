#ifndef CARD_H
#define CARD_H

#include <iostream>
// #include <string>

    // Design a class Card which can take a face of one of the five possible animals and 
    // one of the five background colours. 
class Card {
    private:
        enum class FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
        enum class FaceBackground {Red, Green, Purple, Blue, Yellow};
        // Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.

        FaceAnimal animal;
        FaceBackground background;

        // An object of type Card can not be copied or assigned and needs a private constructor 
        // but will give CardDeck (see below) friend access.
        Card() {};
        // Card c(Penguin,Red); // This constructor will be private
        Card(FaceAnimal fa, FaceBackground fb): animal(fa), background(fb) {};
        ~Card() {};

    public:
        // A card must also be “printable” as one string per row with the method:
        // for (int row = 0; row <c.getNRows(); ++row ) {
        //      std::string rowString = c(row);
        //      std::cout << rowString << std::endl;
        // }
        
        inline FaceAnimal getAnimal() const { return animal; };
        inline FaceBackground getBackground() const { return background; };

        friend std::ostream& operator<<(std::ostream & os, const FaceAnimal & fa);
        friend std::ostream& operator<<(std::ostream & os, const FaceBackground & fb);
        
        std::string operator()(int row);
};

#endif

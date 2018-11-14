#ifndef CARD_H
#define CARD_H

    // Design a class Card which can take a face of one of the five possible animals and 
    // one of the five background colours. A card must also be “printable” as one string 
    // per row
class Card {
// Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground
//enum class FaceAnimal : char {walrus='W', penguin='P', turtle='T', octopus='O', crab='C'};
enum class FaceAnimal{walrus, penguin, turtle, octopus, crab};
//enum class FaceBackground : char {red='r', green='g', purple='p', blue ='b', yellow='y'};
enum class FaceBackground{red, green, purple, blue, yellow};
  friend std::ostream &operator<<(std::ostream &, const Card::FaceAnimal &);
  friend std::ostream &operator<<(std::ostream &, const Card::FaceBackground &);
  friend std::ostream &operator<<(std::ostream &, const Card &);

    private:
        FaceAnimal animal;
        FaceBackground background;
        int numRows{3};
       
        // An object of type Card can not be copied or assigned and needs a private constructor 
        // but will give CardDeck friend access.
        Card();
        Card(FaceAnimal fa, FaceBackground fb) : animal(fa), background(fb){};
    public:
        int getNRows() const {return numRows;};
        FaceAnimal getFaceAnimal() const {return animal;};
        FaceBackground getFaceBackground() const{return background;};
        //overload function call
        std::string operator()(int);
        
};

#endif

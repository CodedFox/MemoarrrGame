#ifndef CARD_H
#define CARD_H

    // Design a class Card which can take a face of one of the five possible animals and 
    // one of the five background colours. A card must also be “printable” as one string 
    // per row with the method:
class Card {
// Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.
enum class FaceAnimal{walrus='W', penguin='P', turtle='T', octopus='O', crab='C'};
enum class FaceBackground{red='r', green='g', purple='p', blue ='b', yellow='y', blank='z'};
    private:
        

    public:
        // Card c(Penguin,Red); // This constructor will be private
        // for (int row = 0; row <c.getNRows(); ++row ) {
        //      std::string rowString = c(row);
        //      std::cout << rowString << std::endl;
        // }

        
        // An object of type Card can not be copied or assigned and needs a private constructor 
        // but will give CardDeck (see below) friend access.
};

#endif

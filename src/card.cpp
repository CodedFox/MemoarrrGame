#include <iostream>
#include <string>
#include <sstream>

#include "card.h"
#include "config.h" //contains flags for testing
std::ostream & operator<<(std::ostream &os, const FaceAnimal &fa) {
  std::string str;
  switch(fa) {     
    case FaceAnimal::walrus: str = "W"; break;
    case FaceAnimal::penguin: str = "P"; break;
    case FaceAnimal::turtle: str = "T"; break;
    case FaceAnimal::octopus: str = "O"; break;
    case FaceAnimal::crab: str = "C"; break;
    default: str = "Error in Animal Face!"; break;
  }
  os << str;
  return os;
}
std::ostream & operator<<(std::ostream &os, const FaceBackground &fb) {
  std::string str;
  switch(fb) {     
    case FaceBackground::red: str = "rrr"; break;
    case FaceBackground::green: str = "ggg"; break;
    case FaceBackground::purple: str = "ppp"; break;
    case FaceBackground::blue: str = "bbb"; break;
    case FaceBackground::yellow: str = "yyy"; break;
    default: str = "Error in Animal Background!"; break;
  }
  os << str;
  return os;
}
std::ostream & operator<<(std::ostream &os, Card &c) {
  std::string str;
//overload function call to allow for printing as described in project specification:
 for (int row = 0; row <c.getNRows(); ++row ) {
              std::string rowString = c(row);
              os << rowString << std::endl;
         }
    return os;
    }
        std::string Card::operator()(int r){
                //default to rows with just background
            std::ostringstream stream;
            stream<<Card::getFaceBackground();
            std::string line = stream.str();
            if(r!=0 && r!=(Card::getNRows()-1)){
                //middle row with background and animal, consider changing to be variable to allow for different number of rows
                std::ostringstream streamanimal;
                streamanimal<<Card::getFaceAnimal();
                line.replace(1,1,streamanimal.str());
            }
            return line;
        }


#ifdef TEST_CARD_
int main() {
Card test1 = Card(FaceAnimal::walrus, FaceBackground::red);
Card test2 = Card(FaceAnimal::walrus, FaceBackground::blue);
std::cout << test1 << std::endl;
std::cout << test2 << std::endl;
    std::cout << "Testing Card" << std::endl;

    return 0;
}
#endif
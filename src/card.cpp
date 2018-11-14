#include <iostream>
#include <string>
#include <sstream>

#include "card.h"
#include "config.h" //contains flags for testing
std::ostream & operator<<(std::ostream &os, const Card::FaceAnimal &fa) {
  std::string str;
  switch(fa) {     
    case Card::FaceAnimal::walrus: str = "W"; break;
    case Card::FaceAnimal::penguin: str = "P"; break;
    case Card::FaceAnimal::turtle: str = "T"; break;
    case Card::FaceAnimal::octopus: str = "O"; break;
    case Card::FaceAnimal::crab: str = "C"; break;
    default: str = "Error in Animal Face!"; break;
  }
  os << str;
  return os;
}
std::ostream & operator<<(std::ostream &os, const Card::FaceBackground &fb) {
  std::string str;
  switch(fb) {     
    case Card::FaceBackground::red: str = "rrr"; break;
    case Card::FaceBackground::green: str = "ggg"; break;
    case Card::FaceBackground::purple: str = "ppp"; break;
    case Card::FaceBackground::blue: str = "bbb"; break;
    case Card::FaceBackground::yellow: str = "yyy"; break;
    default: str = "Error in Animal Background!"; break;
  }
  os << str;
  return os;
}
//overload function call to allow for printing as described in project specification:
/*        for (int row = 0; row <c.getNRows(); ++row ) {
              std::string rowString = c(row);
              std::cout << rowString << std::endl;
         }*/
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

    std::cout << "Testing Card" << std::endl;

    return 0;
}
#endif
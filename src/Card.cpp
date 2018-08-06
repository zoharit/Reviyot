#include "../include/Card.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;



// constructor gets a shape and sets it to this shape

Card::Card(Shape s) : shape(s), shapeName() {
   
    
    switch(shape) {
        case Club:
            shapeName = "C";
            break;
        case Diamond:
            shapeName = "D";
            break;
        case Heart:
            shapeName = "H";
            break;
        case Spade:
            shapeName = "S";
            break;
    }
    

}


    
string Card::toString() {
    return "Your shape is " +std::string(shapeName);
}

Card::~Card() {
//     cout << "delete this regular card" << endl;
}

// int Card::getNumber() const {};

string Card::getShape() const {
    return shapeName;
}


bool Card::operator==( Card& other) {
    if (&other != this) {
      if(this->getNumber() == other.getNumber()) {
        if(this->getShape() == other.getShape()) {
            return true;
        }
    }
    return false;
  }
  return true;
}




    
    





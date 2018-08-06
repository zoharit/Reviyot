#include "../include/Card.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;



FigureCard::FigureCard(Shape s,Figure f) : Card(s),figure(f) , figureName(), number() {
        switch(figure) {
            case King:
                figureName = "K";
                setNumber(-2);
                break;
            case Queen:
                figureName = "Q";
                setNumber(-3);
                break;
            case Jack:
                figureName = "J";
               setNumber(-4);
                break;
            case Ace:
                figureName = "A";
                setNumber(-1);
                break;
        }
        
}

FigureCard::~FigureCard() {
//     cout << "delete this Figure card" << endl;
}

int FigureCard::getNumber() const {
    return this->number;
}

void FigureCard::setNumber(int num) {
  number= num ;
}

string FigureCard::toString() {
    return (std::string(this->figureName) + std::string(this->shapeName) );
    
    
}

Card* FigureCard::clone() {
    Card* ret = new FigureCard(*this);
    return ret;
}

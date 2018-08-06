#include "../include/Card.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


NumericCard::NumericCard(Shape s, int n) : Card(s) , number(n){

}

NumericCard::~NumericCard() {
}


string NumericCard::toString() {
    return (std::to_string(this->number) + std::string(this->shapeName));
}

int NumericCard::getNumber() const {
    return this->number;
} 

void NumericCard :: setNumber(int num){
    number=num;   
}



Card* NumericCard::clone() {
    Card* ret = new NumericCard(*this);
    return ret;
}
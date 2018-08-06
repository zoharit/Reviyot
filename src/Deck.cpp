
#include "../include/Deck.h"
#include "../include/Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;



//Deck constructor

Deck::Deck( string& deckAsString) : deckOfCards()   {
    
    //run through the deck and put every word in a unit. no spaces.
    
    std::istringstream buf(deckAsString);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> deckOfCardsAsString(beg, end);
    
    //run through the deck and make every string into a card
    //and push into out deck
    
    string numberOfCard;
    char shapeOfCard;
    int shapeAsShape;
    int numberOfCardAsInt;
   
    for(int i=deckOfCardsAsString.size()-1; i >= 0 ; i -= 1) {
        numberOfCard = deckOfCardsAsString[i].substr(0, deckOfCardsAsString[i].length()-1);
        shapeOfCard= deckOfCardsAsString[i].at( deckOfCardsAsString[i].length()-1 );
        if(shapeOfCard == 'C') {
            shapeAsShape = 0;
        } else  if(shapeOfCard == 'D') {
            shapeAsShape = 1;
        }
          else  if(shapeOfCard == 'H') {
            shapeAsShape = 2;
        }
          else if(shapeOfCard == 'S') {
            shapeAsShape = 3;
        }
    

        //change the char into int
        if( numberOfCard != "J" && numberOfCard != "Q" && numberOfCard != "K" && numberOfCard != "A") {
            numberOfCardAsInt = stoi(numberOfCard);
        }

        
        if(numberOfCard == "J") {
            deckOfCards.push_back(new FigureCard( (Shape)shapeAsShape, Jack));
        } else if(numberOfCard == "Q") {
            deckOfCards.push_back(new FigureCard( (Shape)shapeAsShape, Queen));
        } else if(numberOfCard == "K") {
            deckOfCards.push_back(new FigureCard( (Shape)shapeAsShape, King));
        } else if(numberOfCard == "A") {
            deckOfCards.push_back(new FigureCard( (Shape)shapeAsShape, Ace));
        } else {
            deckOfCards.push_back(new NumericCard( (Shape)shapeAsShape, numberOfCardAsInt ));
            
        }
    }
    

}

Deck::Deck() : deckOfCards() {}
    
Deck::~Deck (){
//     cout <<"delete the deck!!!"<<endl;
    clean();
}
    
void Deck::clean(){

//     for (std::vector<Card*>::iterator it=deckOfCards.begin(); it != deckOfCards.end(); ++it){'
    for(unsigned i=0 ; i<deckOfCards.size(); i++) {
         Card* curCard = deckOfCards.at(i);
         delete curCard;

    }

}
    
 //copy constructor   
Deck::Deck(const Deck & other) 
: deckOfCards()   {
        copy(other);
}


Deck* Deck::clone() const{
    Deck* ans =new Deck(*this);   
    return ans;
}




int Deck::getNumberOfCards() const {
    return deckOfCards.size();
}


Deck& Deck::operator=(const Deck & other){
    if (this != &other){
        clean();
        deckOfCards.clear();
        copy(other);
        }
        return *this;
}

 
void Deck::copy(const Deck& other ) {
   // deckOfCards=other.getDeck();
    for (unsigned i=0; i<other.getDeck().size(); i++) {
        deckOfCards.push_back(other.getDeck()[i]->clone());
        
    }
}
//////////
string Deck::toString() {

    std::vector<Card*>::reverse_iterator it = deckOfCards.rbegin();
    string ss="";
    for(it = deckOfCards.rbegin(); it !=deckOfCards.rend(); ++it) {
        ss+=(*it)->toString();
        if( it != deckOfCards.rend() ) {
            ss += " ";
        }
    }
    
   return ss;

}



Card* Deck::fetchCard() {
    Card* temp = deckOfCards.back();
    deckOfCards.pop_back();

    return temp;
}

vector<Card*> Deck::getDeck() const{
    return deckOfCards;
}




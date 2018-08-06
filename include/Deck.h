#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include "../include/Card.h"
#include <vector>

using namespace std;

class Deck {
private:
    vector<Card*> deckOfCards;
    
   

	
    
public:
        Deck(string &deckAsString);
        Deck(const Deck & other);
        Deck();
        Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
        virtual ~Deck();
        void clean();
        void copy(const Deck& other) ;
        Deck* clone() const;
	int getNumberOfCards() const; // Get the number of cards in the deck
        vector<Card*> getDeck() const;
        
        string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
        //maybe need to change the order of showing the cards
        Deck& operator=(const Deck & other);
        
};

#endif

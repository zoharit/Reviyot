#ifndef HAND_H_
#define HAND_H_
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"
using namespace std;

class Hand {
private:
	// Declare here the collection of "Card *" of the hand
        list<Card*> myHand;
        void clean();

public:
        Hand(); // constructor
        virtual ~Hand(); // deconstructor
	Hand(const Hand& other);
        Hand& operator=(const Hand& other);
        void copyHand( const Hand& other);
        vector<Card*> removeSameCards(int num);

        
        
        bool addCard(Card* &card);
	list<Card*> getHand() const; 
        void setHand(list<Card*> &myHand); 
	string toString() ; // Return a list of the cards, separated by space, in one line, in a sorted order, ex: "2S 5D 10H"
        static bool compareCards(const Card & s1,const Card & s2); // compare and see which is worth more

        virtual Hand* cloneHand() const;
        bool addCard(Card &card);
        bool removeCard( Card &card);
        bool search ( Card &card);
        bool searchNumber ( int num);
        std::list<Card*>::iterator findPlace( Card& card);
        bool needToOut(Card &card);

};

#endif

#include "../include/Card.h"
#include "../include/Player.h"

#include "../include/Hand.h"
#include "../include/Game.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <list>

using namespace std;



Hand::Hand() : myHand() {
}

Hand::Hand(const Hand& other): myHand() {
    copyHand(other);
}
    

Hand& Hand::operator=(const Hand& other) {
            if (this!=&other){
                clean();
                myHand.clear();
                copyHand(other);
            }
        return *this;
}

void Hand::clean() {
     for (std::list<Card*>::iterator it=myHand.begin(); it != myHand.end(); it++){
        //delete myHand[it];
         Card* curCard = (*it);
         delete curCard;
    }
}


Hand::~Hand()  {
    clean();
//     cout << "delete this hand"<<endl;
    
}

void Hand::copyHand( const Hand& other ) {
        list<Card*> temp = other.getHand();
        
        std::list<Card*>::iterator it = temp.begin();
        for(std::list<Card*>::iterator it= temp.begin(); it != temp.end(); it++) {
            myHand.push_back( (*it)->clone() );
        }

}


Hand* Hand::cloneHand() const{

    Hand* ans =new Hand(*this); 
    return ans;
}


list<Card*> Hand::getHand() const {
    return myHand;
    
}

string Hand::toString() {
    std::list<Card*>::iterator iter, end;
    string ss="";
    for(iter = myHand.begin(), end = myHand.end() ; iter != end; ++iter) {
 
        ss+=(*iter)->toString();
        if( iter != end ) {
            ss+= " ";
        }
    }
    
   return ss;
}


bool Hand::compareCards(const Card & s1,const Card & s2)
{
        char shapeOfs1 = s1.getShape().at(0);
        char shapeOfs2 = s2.getShape().at(0);
        
        
    if(s1.getNumber() == s2.getNumber()) { 
        return (shapeOfs1 > shapeOfs2);
    } 
    else if( (s1.getNumber() < 0) && s2.getNumber() <0) {
            return (s1.getNumber() > s2.getNumber() );
    } 
    else if( (s1.getNumber() > 0) && s2.getNumber() > 0) {
            return (s1.getNumber() > s2.getNumber() );
    } 
    else if( (s1.getNumber() < 0) && s2.getNumber() >0) {
            return (true);
    } 
    else return false;

        
}

bool Hand::addCard( Card &card) {
    if(search(card)) {
        cout<< " card is already in hand "<<endl;
        return 0;
    } else {
        std::list<Card*>::iterator Iplace = findPlace(card);
        myHand.insert(Iplace, &card);
        needToOut(card);
        return 1;
    }
}

bool Hand::needToOut(Card &card){
    std::list<Card*>::iterator iter, end, firstIndex, firstIndexTemp;
    bool ans=false;
    bool firstTime = true;
    int i=0;
    for(iter = myHand.begin(), end = myHand.end() ; iter != end; ++iter) {
        if ((*iter)->getNumber()==card.getNumber()){
            if(firstTime) {
                firstIndex = iter;
                firstTime = false;
            }
            i++;
        }
    }
    firstIndexTemp = firstIndex;
        if(i==4){
            //erase the cards
            for(int i=0; i<=3 ;i++) {
                Card* curCard = (*firstIndexTemp);
                delete curCard;
                firstIndexTemp = next(firstIndexTemp);
            }
             myHand.erase( firstIndex, next(next(next(next(firstIndex)))) );
        }
return ans;
}

vector<Card*> Hand::removeSameCards(int num){
    vector<Card*> tempo;
    std::list<Card*>::reverse_iterator findIter, firstIndex, lastIndex; 
    std::list<Card*>::iterator it, endit;
    
    
    for(findIter=myHand.rbegin(); findIter!=myHand.rend(); findIter++) {   
        if((*findIter)->getNumber() == num) {
            firstIndex = findIter;
            tempo.push_back((*findIter));

        }
    }
    it = firstIndex.base();
    endit = it;
    for( unsigned i =0; i<tempo.size(); i++) {
        ++endit;
    }
    
    lastIndex = firstIndex;
    myHand.erase(--it, --endit  );
    
    return tempo;
}

bool Hand::searchNumber ( int num) {
    for(std::list<Card*>::iterator findIter = myHand.begin(); findIter!=myHand.end(); findIter++) {
        if( (**findIter).getNumber() == num ) return true;
    
    }
    return false;
}
        
        
        
bool Hand::removeCard( Card &card) {
    if(search(card)) {
        std::list<Card*>::iterator Iplace = findPlace(card);
        myHand.erase( std::prev(Iplace) );
        return 1;
    } else {
        return 0;
    }
}

bool Hand::search ( Card &card) {
    for(std::list<Card*>::iterator findIter = myHand.begin(); findIter!=myHand.end(); findIter++) {
        if( (**findIter == card) ) return true;
    
    }
    return false;
}



std::list<Card*>::iterator Hand::findPlace( Card& card) {
    std::list<Card*>::iterator findIter;
    for(findIter = myHand.begin(); findIter!=myHand.end(); ++findIter) {
        if( compareCards((**findIter), card )) return findIter;
    }
    return findIter;
}




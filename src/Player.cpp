#include "../include/Player.h"
#include "../include/Hand.h"
#include "../include/Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <sstream>
#include <iterator>
#include <limits>

using namespace std;

Player::Player(  string _name, int _position, int _type ):Hand(), name(_name), position(_position), type(_type) {
    
}

Player::Player( const Player & other) : Hand(other), name(other.getName()), position(other.getPosition()), type(other.getType()) {
}
Player::~Player() {}

    
bool Player::addCardToPlayer(Card &card){
 return addCard(card);   
}

bool Player::removeCardFromPlayer(Card &card){
    return removeCard(card);
}

string Player::toString (){
    string ss;
    ss = getName()+":" + Hand::toString();
    return ss;
}

int Player::getPosition() const{
    return position;
}

int Player::getType() const{
    return type;
}

string Player::getName() const{
    return name;
}


    

//Player 1 *******************************************************************************************************************************

PlayerType1::PlayerType1( string _name, int _position, int _type) : Player(_name, _position, _type) {
}

PlayerType1::PlayerType1( const PlayerType1 & other): Player(other) {
}
    


int PlayerType1::requestCard()  { 
    int tempValue = 0;
    int maxValue = 0;
    int maxValueTemp = 0;
    int quantity = 1;
    int tempQuantity = 1;
    
    
    list<Card*> list1= getHand();
    std::list<Card*>::iterator it = list1.begin();
    
    for(it = list1.begin(); it !=list1.end(); ++it) {
        if( (*it)->getNumber() == tempValue) {
            tempQuantity++;
        } else {
            tempQuantity = 1;
        } 
        maxValueTemp = (*it)->getNumber();

        if(quantity <= tempQuantity) {
             quantity = tempQuantity;
             maxValue= maxValueTemp;
        }
        tempValue = (*it)->getNumber();
    }
    return maxValue;
}

Player* PlayerType1::clone() const {
    Player* ans = new PlayerType1(*this);
    return ans;
}

void PlayerType1::copy(const  PlayerType1& other ) {
}

Player* PlayerType1::fromWhoToAsk(vector<Player*>& players) {
     unsigned max =0;
     Player* temp;
     for(unsigned i =0; i<players.size(); i++) {
         if(players[i]->getHand().size() >= max && this->position != players[i]->getPosition()) {
             max = players[i]->getHand().size();
             temp = players[i];
         }
     }
     return temp;
}
    

    

//Player 2 *******************************************************************************************************************************


PlayerType2::PlayerType2(string _name, int _position, int _type) : Player(_name, _position, _type)  {
}
PlayerType2::PlayerType2( const PlayerType2 & other): Player(other) {
}
    int PlayerType2::requestCard()  {
    
     list<Card*> list1= getHand();
    std::list<Card*>::reverse_iterator it = list1.rbegin();
    std::list<Card*>::reverse_iterator it2;

    int minValue = (*list1.rbegin())->getNumber();
    int minValueTemp = (*list1.rbegin())->getNumber();
    int quantity = std::numeric_limits<int>::max();
    int tempQuantity = 0;
    
    
    for(it = list1.rbegin(); it !=list1.rend(); it++) {
        for(it2 = it; it2 !=list1.rend(); ++it2) {
            if( next(it2) != list1.rend() && (*next(it2))->getNumber() == (*it)->getNumber() ) {
                tempQuantity++;
                it = next(it);
            }
//             if(tempQuantity <= quantity){
//                 quantity = tempQuantity;
//                 minValue= minValueTemp;
//             }
        }
            
        minValueTemp = (*it)->getNumber();
        if(tempQuantity <= quantity ) {
             quantity = tempQuantity;
             minValue= minValueTemp;
        }
        tempQuantity = 0;
    }
    return minValue;
}


Player* PlayerType2::clone() const{
    Player* ans = new PlayerType2(*this);   
    return ans;
}
void PlayerType2::copy(const  PlayerType2& other ) {
        copyHand(other);
}

Player* PlayerType2::fromWhoToAsk(vector<Player*>& players) {
unsigned max =0;
     Player* temp;
     for(unsigned i =0; i<players.size(); i++) {
         if(players[i]->getHand().size() >= max && this->position != players[i]->getPosition()) {
             max = players[i]->getHand().size();
             temp = players[i];
         }
     }
     return temp;
}

//Player 3 *******************************************************************************************************************************

    
PlayerType3::PlayerType3(string _name, int _position, int _type) : Player(_name, _position, _type), askPlayer(0) {

}
PlayerType3::PlayerType3( const PlayerType3 & other): Player(other), askPlayer(other.getAskPlayer()) {
}
int PlayerType3::requestCard()  {
    return getHand().back()->getNumber();
}


Player* PlayerType3::clone() const {
    Player* ans =new PlayerType3(*this);
    return ans;
}

void PlayerType3::copy(const  PlayerType3& other ) {
        copyHand(other);
}

Player* PlayerType3::fromWhoToAsk(vector<Player*>& players) {
       askPlayer++; 
   

       if( ( (askPlayer-1)%players.size() ) == (unsigned)position-1) askPlayer++;
       
       return players[(askPlayer-1)%players.size()]; 
}

int PlayerType3::getAskPlayer() const {
    return askPlayer;
}
//Player 4 *******************************************************************************************************************************


PlayerType4::PlayerType4(string _name, int _position, int _type) : Player(_name, _position, _type) , askPlayer(0) {
}
PlayerType4::PlayerType4( const PlayerType4 & other): Player(other), askPlayer(other.getAskPlayer()) {
}


int PlayerType4::requestCard()  {
    return getHand().front()->getNumber();
}



Player* PlayerType4::clone() const {
    Player* ans =new PlayerType4(*this);   
    return ans;
}
void PlayerType4::copy(const  PlayerType4& other ) {
        copyHand(other);
}

Player* PlayerType4::fromWhoToAsk(vector<Player*>& players) {
       askPlayer++; 
       
       if( ( (askPlayer-1)%players.size() ) == (unsigned)position-1) askPlayer++;
       
       return players[(askPlayer-1)%players.size()]; 
}

int PlayerType4::getAskPlayer() const {
    return askPlayer;
}
#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "../include/Hand.h"
using namespace std;

class Player : public Hand {
private:
protected:
        const string name;
        const int position;
        const int type;


    
public:
    
    Player(string _name, int _position,int _type);
    Player( const Player & other);
    ~Player();
    bool addCardToPlayer(Card &card);
    bool removeCardFromPlayer(Card &card);
    string toString();
    
    virtual int requestCard() = 0;
    virtual Player* clone() const =0;    
    virtual Player* fromWhoToAsk(vector<Player*>& players) = 0; 
    
    int getPosition() const;
    int getType() const;
    string getName() const;
   
    
};

class PlayerType1 : public Player {  //For strategy 1
    private:
    public:
        PlayerType1(string _name, int _position, int _type);
        PlayerType1( const PlayerType1 & other);
        void copy( const PlayerType1& other );
        Player* clone() const;
        int requestCard() ;
        Player* fromWhoToAsk(vector<Player*>& players);



//...
};

class PlayerType2 : public Player {  //For strategy 2
    private:
    public:
        PlayerType2(string _name, int _position,int _type);
        PlayerType2( const PlayerType2 & other);
        void copy( const PlayerType2& other );
        Player* clone() const;
        int requestCard() ;
        Player* fromWhoToAsk(vector<Player*>& players);

//...
};

class PlayerType3 : public Player {  //For strategy 3
    private:
            int askPlayer;
    public:
        PlayerType3(string _name, int _position,int _type);
        PlayerType3( const PlayerType3 & other);
        void copy( const PlayerType3& other );
        Player* clone() const;
        int requestCard();
        Player* fromWhoToAsk(vector<Player*>& players);
        
        int getAskPlayer() const;

};

class PlayerType4 : public Player {  //For strategy 4
    private:
            int askPlayer;
     public:
        PlayerType4(string _name, int _position,int _type);
        PlayerType4( const PlayerType4 & other);
        void copy( const PlayerType4& other );
        Player* clone() const;
        int requestCard();
        Player* fromWhoToAsk(vector<Player*>& players);
        
        int getAskPlayer() const;

};

#endif

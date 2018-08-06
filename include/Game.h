#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
        int turnNumber = 1;
        int nextToPlay = 1;
        bool gameOn = true;
        int verbal;
        int highNumericValue;
        


public:
	Game(char* configurationFile);
        Game& operator=(const Game& other);
        Game(const Game & other);
        virtual ~Game();
        void clean();
        void copy(const Game& other) ;
        Game* clone() const;
        vector<Player*> getPlayers() const;

        
       string winnerName(vector<Player*>& winners);
       vector<Player *> winners;
       Deck getDeck() const;
       int getVerbal() const ;
       int getHighNumeric() const;
       int getTurnNumber() const;
       
       void dealCards();



       string changeToRoyal(int num);

        
        
        
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
        void printNumberOfTurns(); //Print the number of played turns at any given time.  
        
        
        
        int getNumOfPlayers() const;
        void createPlayers(std::vector<std::string> &nameString, std::vector<std::string> &typeString); 
};

#endif

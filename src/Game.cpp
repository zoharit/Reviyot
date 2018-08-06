#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Game.h"
#include <iostream>
#include<fstream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <algorithm>



using namespace std;

Game::Game(char* configurationFile) : players(), deck(), turnNumber(1), nextToPlay(1), verbal(),highNumericValue(), winners() {
    
    char hashTag = '#';
    char tempChar;
    
    ifstream file;
    file.open(configurationFile);
     if(!file)
        cout<<"problem opening file"<<endl;


    string content;
    string initialDeck;
    
    std::vector<std::string> playersString;
    std::vector<std::string> linesOfText;
    
    
    

   while ( getline(file, content) ) {
        if(content.length() != 0) {
            tempChar = content.at(0);
            if( tempChar == hashTag ) { 
//                 cout << "dont want this " << content <<endl;
            } else {
                linesOfText.push_back(content); 
            }
        }
            
    }
    file.close();
    
    
    
    
 
    
    verbal = std::stoi(linesOfText[0]);
    highNumericValue = std::stoi(linesOfText[1]);
    initialDeck = linesOfText[2];
    
    
    for(unsigned i=3; i<linesOfText.size(); i++) {
        playersString.push_back(linesOfText[i]); 
    }
    
    
    std::vector<std::string> nameString;
    std::vector<std::string> typeString;

     for(unsigned i=0; i<playersString.size(); i++) {
        int spac = playersString[i].find(" " , 0);
        nameString.push_back (playersString[i].substr(0, spac )) ;
        typeString.push_back (playersString[i].substr(spac+1)) ;
     }
          


    
    createPlayers(nameString, typeString);
    deck = Deck(initialDeck); 
    
    

     
}


Game::~Game() {
     clean();
}


void Game::clean(){
    for(unsigned i=0 ; i<getPlayers().size(); i++) {
         Player* curPlayer = getPlayers()[i];
         delete curPlayer;
    }
}
    
Game::Game(const Game & other) : players(), deck(other.getDeck()), turnNumber(other.getTurnNumber()), nextToPlay(1), verbal(other.getVerbal()),highNumericValue(other.getHighNumeric()), winners() {
    copy(other);
}

Game* Game::clone() const{
    Game* ans =new Game(*this);   
    return ans;
}

Game& Game::operator=(const Game& other) {
    if (this != &other){
        clean();
        players.clear();
        copy(other);
        }
        return *this;
}

void Game::copy( const Game& other ) {
        for (unsigned i=0; i<other.getPlayers().size(); i++) {
                players.push_back( other.getPlayers()[i]->clone() );
        }
        

}


vector<Player*> Game::getPlayers() const {
    return players;
}


Deck Game::getDeck() const {
    return deck;
}

int Game::getVerbal() const {
    return verbal;
}

int Game::getHighNumeric() const {
    return highNumericValue;
}
int Game::getTurnNumber() const {
    return turnNumber;
}
void Game::createPlayers(std::vector<std::string> &nameString, std::vector<std::string> &typeString) {
     //create players

    for(unsigned i=0; i<nameString.size(); i++) {
        Player* temp;
        if( typeString[i] == "1") {
            temp = new PlayerType1(nameString[i], i+1, 1);
        } else if( typeString[i] == "2") {
            temp = new PlayerType2(nameString[i], i+1 ,2);
        } else if( typeString[i] == "3") {
            temp = new PlayerType3(nameString[i], i+1, 3);
        } else if( typeString[i] == "4") {
            temp = new PlayerType4(nameString[i], i+1, 4);
        }
        players.push_back(temp);
     }
     
}
    



void Game::dealCards() {
        for(unsigned j = 0; j< players.size(); j++) {
            for(unsigned i=0;i < 7;i++) { 
                Card* tmp = deck.fetchCard();
                players[j]->addCard(*tmp);
            }
        }
 }




void Game::init() {
     turnNumber = 1;
    nextToPlay = 1;
    gameOn = true;
    
    dealCards();
}


void Game::play() {
    
    
    
    int numFromDeck=0;
    vector<Card*> tempVec;
    
    while(gameOn) {
        Player* myTurn = players[((turnNumber-1)%players.size())];
        Player* askFrom = players[((turnNumber-1)%players.size())]->fromWhoToAsk(players);
        
        if( verbal == 1) {
            printNumberOfTurns();
            printState();
            cout << myTurn->getName() << " asked "<< askFrom->getName() << " for the value "<< changeToRoyal( myTurn->requestCard() )<<endl;
            cout << endl;
        }
        
        
        if ( askFrom->searchNumber( myTurn->requestCard() ) ) {
            tempVec = askFrom->removeSameCards( myTurn->requestCard() );
            numFromDeck = tempVec.size();
            for(int i=0; i<numFromDeck; i++) {
                myTurn->addCard( *(tempVec.back()) );
                tempVec.pop_back();
            }
        }
        
        if(numFromDeck == 0) { 
            if(deck.getDeck().size() > 0) {
                myTurn->addCard( *(deck.fetchCard()) );
            }
        } else {
            for(int i=0; i<numFromDeck; i++) {
                if(deck.getDeck().size() > 0) {
                    askFrom->addCard( *(deck.fetchCard()) );
                }
            }
        }
        
        numFromDeck = 0;
        tempVec.clear();
        

        for(unsigned i=0; i<players.size(); i++) {
            if(players[i]->getHand().size() == 0) {
                Player* tempi = players[i];
                winners.push_back(tempi);
                gameOn = false;
            }
        }
       

       turnNumber++;

    }
    turnNumber--;
}

string Game::changeToRoyal(int num) {
    string temp;
    if(num == -1) temp = "A";
    else if(num == -2) temp = "K";
    else if(num == -3) temp = "Q";
    else if(num == -4) temp = "J";
    else {
        temp = std::to_string(num);
    }
    return temp;
}

        
void Game::printState() {
     cout << "Deck: "<< deck.toString() << endl;
     for(unsigned i=0; i<players.size(); i++) {
        cout << players[i]->toString() << endl;
     }
         
}  

// //Print the state of the game as described in the assignment.
void Game::printWinner() {
    cout << "***** The Winner is: "<< winnerName(winners) << " *****"<<endl;
}      //Print the winner of the game as describe in the assignment.
void Game::printNumberOfTurns() {
    cout << "Number of Turns:"<<turnNumber<<endl;
} //Print the number of played turns at any given time.  
        
        
        
string Game::winnerName(vector<Player*> &winners) {
    string ss = "";
    
    for(unsigned i=0; i<winners.size(); i++) {
        ss += winners[i]->getName();
        if(i != winners.size()-1) {
            ss += " and ";
        }
    }
    return ss;
}
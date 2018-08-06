#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
	Club= 0,
	Diamond ,
	Heart,
	Spade
};

enum Figure {
	Jack=-4,
	Queen=-3,
	King=-2,
	Ace=-1
};

class Card {
private:
  Shape shape;
protected:
  string shapeName;
    
public:
  Card(Shape s);  
  virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
  virtual ~Card();
  virtual int getNumber() const = 0;
  void setNumber(int num);
  string getShape() const;
  virtual Card* clone()=0;
  bool operator==( Card& card);
  

};


//Figure head class
class FigureCard : public Card {
private:
	Figure figure;
        string figureName;
        int number;
        Card* clone();
public:
        FigureCard(Shape s,Figure f);
        
        
        string toString();
        int getNumber() const;
        void setNumber(int num);
        string getFigureName() const;
        virtual ~FigureCard();
};



//Numberic Card Class

class NumericCard : public Card {
private:
        int number;
        Card* clone();
public:
        NumericCard(Shape s, int n);
        
        
        
        string toString();
        int getNumber() const;
        void setNumber(int num);
        virtual ~NumericCard(); 
};

#endif





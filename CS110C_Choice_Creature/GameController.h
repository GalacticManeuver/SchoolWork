#ifndef _GAME_CONTROLLER
#define _GAME_CONTROLLER

#include "Card.h"
#include "myBag.h"
#include "Fight.h"
#include "Hand.h"
#include <string>
using namespace std;

/**
  A GameController is an object that holds and uses the other objects used in this card game program.
  @file GameController.h
  @file GameController.cpp
  @auther Joselin Lybrand
*/
class GameController {
	
  private:
    Hand player1;
	Card opponent;
	Card temp;
	myBag deck;
	Fight fight;
	
  public:

    void generateCards(const char* filename) const;
    int stringToNumber(const string input) const;
    bool readGeneratedCards(const char* filename);
    void appendPlayer1HandToFile(const char* filename) const;
	void appendOpponentCardToFile(const char* filename) const;
	void sortPlayer1By(const int sortType);
  
};


#include "GameController.cpp"
#endif
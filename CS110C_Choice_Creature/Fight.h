#ifndef _FIGHT
#define _FIGHT

#include "Card.h"


/**
  A Fight is a list of cards, with the first being the defender and the rest
  being attacks, that has a function to resolve the fight (based on the values
  of the cards in the list). It also has a function to display the list to console.
  @file Fight.h
  @file Fight.cpp
  @auther Joselin Lybrand
*/
class Fight {
  private:
    const Card blank;
    Card* creatureArray;
    int arraySize;
    int bottom;

  public:
    Fight();
    Fight(const Card& attacker, const Card& defender);
    ~Fight();

    void addCreature(const Card& creature);
    Card* fight();
    void displayCreatures() const;
    void reset();

};//fight

#include "Fight.cpp"
#endif

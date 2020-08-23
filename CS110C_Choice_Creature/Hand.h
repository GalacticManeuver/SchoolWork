#ifndef _HAND
#define _HAND

#include "myBag.h"

/**
  A Hand is a list of cards that can be sorted based on how they would best
  be used to counter a target card.
  @file Hand.h
  @file Hand.cpp
  @auther Joselin Lybrand
*/
class Hand : protected myBag {
  private:
    void quickSortArrays(int* intArr, Card* CardArr, int first, int last);

  public:
    Hand();
    Hand(const Hand& aHand);
    ~Hand();
    void recieve(const Card& target);
    void displayHand();
	void appendHandToFile(const char* filename) const;

    void sortByCounteringOffensive(const Card& target);
    void sortByCounteringDefensive(const Card& target);

};

#include "Hand.cpp"
#endif

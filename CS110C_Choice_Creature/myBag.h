#ifndef _MY_BAG
#define _MY_BAG

#include "Node.h"
#include "Card.h"

/**
  A myBag is a stack of Cards, that can be shuffled.
  @file myBag.h
  @file myBag.cpp
  @auther Joselin Lybrand
*/
class myBag {
  protected:
    const Card blank;
    Node<Card>* headPtr;
    int itemCount;

  public:
    myBag();
    myBag(const myBag& aBag);
    ~myBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    void add(const Card& target);
	bool add(const Card& target, int position);
    Card remove();
    void findAll(const Card& target);
    void shuffle();

};//myBag

#include "myBag.cpp"
#endif

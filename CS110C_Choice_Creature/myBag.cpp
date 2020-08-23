#include "myBag.h"
#include "Node.h"
#include <cstdlib>

/** constructor for myBag.
  @post   sets headPtr to nullptr and itemCount to 0.
*/
myBag::myBag() : headPtr(nullptr), itemCount(0) {
}//default constructor

myBag::myBag(const myBag& aBag) {

/*
  if(aBag.itemCount > 0) {
    Node<Card>* tempPtr = new Node<Card>;
    tempPtr->setItem(aBag.headPtr->getItem());
    this->headPtr = tempPtr;

    for(int i = 1; i < aBag.itemCount; ++i) {
      
    }
  }
  else {
    this->headPtr = nullptr;
    this->itemCount = 0;
  }
*/
}//copy constructor

/** deconstructs myBag.
  @post   deallocates the dynamic memory myBag uses.
*/
myBag::~myBag() {

  Node<Card>* tempPtr;
  while(headPtr) {
    tempPtr = headPtr;
    headPtr = headPtr->getNext();
    tempPtr->setNext(nullptr);
    delete tempPtr;
  }//while(headPtr)

}//deconstructor


/** gets the current size of the stack.
  @return   returns the size of the stack.
*/
int myBag::getCurrentSize() const {
  return itemCount;
}//getCurrentSize()

/** checks if myBag is empty.
  @return   returns true if myBag is empty and false if myBag has stuff.
*/
bool myBag::isEmpty() const {
  if(headPtr)
    return false;
  return true;
}

/** adds a card to myBag.
  @param target   the card that's added to mybag.
  @post   myBag has the target card added to it, and itemcount is progessed by 1.
*/
void myBag::add(const Card& target) {
  Node<Card>* tempPtr = new Node<Card>;
  tempPtr->setItem(target);
  tempPtr->setNext(headPtr);
  headPtr = tempPtr;
  ++itemCount;
}//add()

/** puts a Card into myBag into a specific position
  @param target   the card that's added to mybag.
  @param position    is how many positions from the top you want the card to be.
  @post   if the position is valid myBag has the target card added to it, and
    itemcount is progessed by 1, otherwise nothing happens.
  @return   returns true if card is added, and false if nothing happens.
*/
bool myBag::add(const Card& target, int position) {

  if(position > itemCount)
    return false;

  Node<Card>* tempPtr = new Node<Card>;
  tempPtr->setItem(target);
  
  Node<Card>* travelingPtr = headPtr;
  for(int i = 0; i < itemCount; ++i) {
    travelingPtr = travelingPtr->getNext();
  }
  tempPtr->setNext(travelingPtr);
  travelingPtr->setNext(tempPtr);
  ++itemCount;

  return true;

}//add()

/** removes the top card of the deck and returns it (if there is one).
  @post   one less card in myBag, or no change if myBag is empty.
  @return   returns the card removed from the myBag, if nothing was removed
    returns a blank card.
*/
Card myBag::remove() {
  if(headPtr) {
    Node<Card>* tempPtr = headPtr;
    headPtr = headPtr->getNext();
    tempPtr->setNext(nullptr);
    Card copyCard = tempPtr->getItem();
    delete tempPtr;
    return copyCard;
  }
  return blank;
}//remove()

void myBag::findAll(const Card& target) {

  //code

}//findAll(const Card& target)

/** Randomizes the order of the card in myBag
  @post   the order of cards in myBag is randomized
*/
void myBag::shuffle() {

  if(headPtr) {

    Node<Card>* tempHeadPtr = nullptr;
    Node<Card>* tempLocationPtr1 = headPtr;
    Node<Card>* tempLocationPtr2 = nullptr;
    int tempItemCount = itemCount;
    int i = 0;
    int j = 0;
    int selected = rand() % tempItemCount;

    for(j = 0; j < selected-1; ++j) {
      tempLocationPtr1 = tempLocationPtr1->getNext();
    }//for
    if(selected == 0) {
      tempHeadPtr = headPtr;
      headPtr = headPtr->getNext();
      tempLocationPtr2 = tempHeadPtr;
      tempLocationPtr2->setNext(nullptr);
    }
    else {
      tempHeadPtr = tempLocationPtr1->getNext();
      tempLocationPtr1->setNext(tempHeadPtr->getNext());
      tempLocationPtr2 = tempHeadPtr;
      tempLocationPtr2->setNext(nullptr);
    }
    --tempItemCount;

    for(i = 0; i < itemCount-1; ++i) {
      selected = rand() % tempItemCount;
      tempLocationPtr1 = headPtr;
      for(j = 0; j < selected-1; ++j) {
        tempLocationPtr1 = tempLocationPtr1->getNext();
      }//for

      if(selected == 0) {
        tempLocationPtr2->setNext(headPtr);
        headPtr = headPtr->getNext();
        tempLocationPtr2 = tempLocationPtr2->getNext();
        tempLocationPtr2->setNext(nullptr);
      }//if
      else {
        tempLocationPtr2->setNext(tempLocationPtr1->getNext());
        tempLocationPtr2 = tempLocationPtr2->getNext();
        tempLocationPtr1->setNext(tempLocationPtr2->getNext());
        tempLocationPtr2->setNext(nullptr);
      }//else
      --tempItemCount;
    }//for
    headPtr = tempHeadPtr;
    tempHeadPtr = nullptr;
    tempLocationPtr1 = nullptr;
    tempLocationPtr2 = nullptr;
  }//if
}//shuffle()


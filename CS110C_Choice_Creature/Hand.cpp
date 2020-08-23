#include "Hand.h"
#include <iostream>
#include <fstream>
using namespace std;



/** Hand constructor.
  @post   the headPtr is set to nullptr and the itemCount is set to 0.
*/
Hand::Hand() {
  headPtr = nullptr;
  itemCount = 0;
}//default constructor

Hand::Hand(const Hand& aHand) {}//will complete later

/** Hand deconstructor.
  @post   deallocates all dynamic memory used.
*/
Hand::~Hand() {
  Node<Card>* tempPtr;
  while(headPtr) {
    tempPtr = headPtr;
    headPtr = headPtr->getNext();
    tempPtr->setNext(nullptr);
    delete tempPtr;
  }//while(headPtr)
}//destructor


/** cycles through the hand displaying every card.
  @post   all cards in hand are printed to console.
*/
void Hand::displayHand() {
  Node<Card>* tempPtr = headPtr;
  Card tempCard;
  for(;tempPtr; tempPtr = tempPtr->getNext()) {
    tempCard = tempPtr->getItem();
    tempCard.displayCard();
    printf("\n");
  }//for
}//displayHand

/** cycles through the hand appending every card to file.
  @post   all cards in hand are printed to file.
*/
void Hand::appendHandToFile(const char* filename) const {
  Node<Card>* tempPtr = headPtr;
  Card tempCard;
  ofstream fout;
  
  for(;tempPtr; tempPtr = tempPtr->getNext()) {
    tempCard = tempPtr->getItem();
    tempCard.appendCardToFile(filename);
	fout.open(filename, ofstream::out | ofstream::app);
	if(fout.good())
      fout << endl;
    fout.close();
  }//for
}//displayHand

/** uses myBag's add to add a card to hand's linked list.
  @param target   a card to be added to hand.
  @post   the target card is added to the hand.
*/
void Hand::recieve(const Card& target) {
  this->add(target);
}//recieve

/** Sorts an array of Cards based on an array of integers that have the same.
  number of values and where each index corresponds to the index of the other array.
  @param intArr   an array of integers with the same number of indexes as CardArr.
  @param CardArr   an array of cards with the same number of indexes as intArr.
  @param first   the integer that indecates the beggining of the array.
  @param last   the integer that indecates the end of the array.
  @post both arrays sorted.
*/
void Hand::quickSortArrays(int* intArr, Card* CardArr, int first, int last) {

  if(first+1 == last) {
    if(intArr[first] > intArr[last]) {
      int tempInt = intArr[first];
      intArr[first] = intArr[last];
      intArr[last] = tempInt;

      Card tempCard = CardArr[first];
      CardArr[first] = CardArr[last];
      CardArr[last] = tempCard;
    }//if
  }//if

  else if(first < last) {
    int mid = first + ((last - first)/2);

    int tempInt = intArr[mid];
    intArr[mid] = intArr[first];
    intArr[first] = tempInt;

    Card tempCard = CardArr[mid];
    CardArr[mid] = CardArr[first];
    CardArr[first] = tempCard;

    int i, j;
    int swap = 0;
    for(i = first+1, j = last; i <= j;) {
      if(intArr[i] <= intArr[first])
        ++i;
      else
        ++swap;

      if(intArr[j] >= intArr[first])
        --j;
      else
        ++swap;

      if(swap == 2) {
        tempInt = intArr[i];
        intArr[i] = intArr[j];
        intArr[j] = tempInt;

        tempCard = CardArr[i];
        CardArr[i] = CardArr[j];
        CardArr[j] = tempCard;
      }//if
      swap = 0;
    }//for

    tempInt = intArr[first];
    intArr[first] = intArr[i-1];
    intArr[i-1] = tempInt;

    tempCard = CardArr[first];
    CardArr[first] = CardArr[i-1];
    CardArr[i-1] = tempCard;

    quickSortArrays(intArr, CardArr, first, i-2);
    quickSortArrays(intArr, CardArr, i, last);
  }//if

}//quickSortArrays()

/** sorts hand by best counter, weighted for offense attempts to get the cheapest
  card that will kill and survive though if a card is signifcantly to expensive,
  or a card can't do both it picks based on partially meeting objectives.
  @param target   the Card that the hand is being sorted against.
  @post   the Hand is sorted against the target card.
*/
void Hand::sortByCounteringOffensive(const Card& target) {
  int weightValue[itemCount] = { 0 };
  Card copyOfHand[itemCount];
  int i = 0;
  for(i = 0; i < itemCount; ++i) {
    copyOfHand[i] = this->remove();
  }//for
  for(i = 0; i < itemCount; ++i) {
    int willSurvive = copyOfHand[i].getToughness() - target.getPower();
    int willKill = copyOfHand[i].getPower() - target.getToughness();
    int tempcmc = copyOfHand[i].getcmc();

    if(willSurvive > 0)
      weightValue[i] += 300 + willSurvive;
    else
      weightValue[i] -= 300 - willSurvive;

    if(willKill >= 0)
      weightValue[i] += 500 + willKill;
    else
      weightValue[i] -= 500 - willKill;

    if(tempcmc > 0) {
      if(weightValue[i] > 0)
        weightValue[i] /= tempcmc;
      else
        weightValue[i] *= tempcmc;
    }//if
    else
      weightValue[i] += 200;
  }//for
  quickSortArrays(weightValue, copyOfHand, 0, itemCount-1);
  int tempLength = itemCount;
  itemCount = 0;
  for(i = 0; i < tempLength; ++i) {
    this->add(copyOfHand[i]);
  }//for
}//sortByCounteringOffensive

/** sorts hand by best counter, weighted for defense attempts to get the cheapest
  card that will kill and survive though if a card is signifcantly to expensive,
  or a card can't do both it picks based on partially meeting objectives.
  @param target   the Card that the hand is being sorted against.
  @post   the Hand is sorted against the target card.
*/
void Hand::sortByCounteringDefensive(const Card& target) {
  int weightValue[itemCount] = { 0 };
  Card copyOfHand[itemCount];
  int i = 0;

  for(i = 0; i < itemCount; ++i) {
    copyOfHand[i] = this->remove();
  }//for

  for(i = 0; i < itemCount; ++i) {
    int willSurvive = copyOfHand[i].getToughness() - target.getPower();
    int willKill = copyOfHand[i].getPower() - target.getToughness();
    int tempcmc = copyOfHand[i].getcmc();

    if(willSurvive > 0)
      weightValue[i] += 500 + willSurvive;
    else
      weightValue[i] -= 500;

    if(willKill >= 0)
      weightValue[i] += 300 + willKill;
    else
      weightValue[i] -= 300;

    if(tempcmc > 0) {
      if(weightValue[i] > 0)
        weightValue[i] /= tempcmc;
      else
        weightValue[i] *= tempcmc;
    }//if
    else
      weightValue[i] += 200;
  }//for

  quickSortArrays(weightValue, copyOfHand, 0, itemCount-1);

  int tempLength = itemCount;
  itemCount = 0;
  for(i = 0; i < tempLength; ++i) {
    this->add(copyOfHand[i]);
  }//for
}//sortByCounteringDefensive




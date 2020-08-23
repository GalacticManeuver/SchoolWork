#include "Fight.h"
#include "Card.h"
#include <iostream>


/** fight constructor
  @post   sets the creatureArray to it's default value, 3 blank cards.
*/
Fight::Fight() : arraySize(3), bottom(0) {

  creatureArray = new Card[3];
  creatureArray[0] = blank;

}//Fight()


/** fight construct with attacker and defender.
  @param attacker   a card that is a creature, this will be the attacker.
  @param defender   a card that is a creature, this will be the defender.
  @pre   this constructor assumes both the attacker and defender are creatures.
  @post   the creatureArray has both the attacker and defender cards in it.
*/
Fight::Fight(const Card& attacker, const Card& defender) : arraySize(3) {

  creatureArray = new Card[3];
  creatureArray[0] = attacker;
  creatureArray[1] = defender;
  creatureArray[2] = blank;

}//Fight(const Card* attacker, const Card* defender)


/** 
*/
Fight::~Fight() {

  if(creatureArray)
    delete[] creatureArray;
  creatureArray = nullptr;

}//~Fight()





/** Adds a creature to the creatureArray.
  @param creature   A card that is added to creatureArray if it's a creature.
  @post   creatureArray has one more card in it if the inputted card is a creature.
*/
void Fight::addCreature(const Card& creature) {

  //if it's not a creature
  if(creature.getCardType() != 1) {
    char* check = creature.getCardName();
    printf("%s is not a creature.\n", check);
    delete[] check;
    check = nullptr;
    return;
  }//if

  ++bottom;

  if(arraySize-1 < bottom) {
    Card* tempPtr = creatureArray;

    arraySize *= 2;

    creatureArray = new Card[arraySize];

    for(int i = 0; i < (arraySize/2); ++i) {
      creatureArray[i] = tempPtr[i]; }

    delete[] tempPtr;
    tempPtr = nullptr;
  }//increasing size of array

  creatureArray[bottom-1] = creature;
  creatureArray[bottom] = blank;

}//addCreature(const Card& creature)


/** Calculates the fight, based on the creatures currently in creatureArray.
  there can only be 1 attacker, but there can be an arbitrary number of defenders.
  @post   Outputs to the console which cards live or die, and changes their
    currentHP value to what it should be based on they damage they took.
*/
Card* Fight::fight() {


  Card* creatureArrayCopy = nullptr;
  char* check = creatureArray[0].getCardName();
  if(!check) {
    printf("There is no attacker!\n");
    return nullptr;
  }//if
  delete[] check;
  check = nullptr;
  check = creatureArray[1].getCardName();
  if(!check) {
    printf("Attack is uncontested!\n");
    creatureArrayCopy = new Card[2];
    creatureArrayCopy[0] = creatureArray[0];
    return creatureArrayCopy;
  }//if
  delete[] check;
  check = nullptr;

  int i = 0;
  int arrayLength;
  int attackPower;
  int defendPower;
  //getting the length of the creature array
  for(arrayLength = 0, check = creatureArray[0].getCardName(); check;
   ++arrayLength, check = creatureArray[arrayLength].getCardName())
    delete[] check;
  delete[]check;

  //creating a list of creatures with first strike damage
  int firstStrikeList[arrayLength+1];
  firstStrikeList[arrayLength] = 0;
  for(i = 0; i < arrayLength; ++i) {
    firstStrikeList[i] = 0;
    char* tempString = creatureArray[i].getCardEffectOnPlay();
    if(tempString) {
      for(int j = 0; tempString[j] != '\0'; ++j) {
        if(tempString[j] == ':') {
          if(tempString[j+1] == 'F' && tempString[j+2] == 'i') {
            firstStrikeList[i] = 1;
            ++firstStrikeList[arrayLength];
          }//if
          else if(tempString[j+1] == 'D' && tempString[j+2] == 'o') {
            firstStrikeList[i] = 2;
            ++firstStrikeList[arrayLength];
          }//else if
        }//if
      }//for
      delete[] tempString;
      tempString = nullptr;
    }//if
  }//for

  //first strike speed combat
  if(firstStrikeList[arrayLength] != 0) {
    if(firstStrikeList[0] != 0)
      attackPower = creatureArray[0].getPower() + creatureArray[0].getCounter11();
    defendPower = 0;

    for(i = 1, check = creatureArray[1].getCardName(); check; ++i,
     check = creatureArray[i].getCardName()) {
      if(firstStrikeList[i] != 0)
        defendPower += creatureArray[i].getPower() + creatureArray[i].getCounter11();
      delete[] check;
    }//for

    creatureArray[0].setCurrentHP(creatureArray[0].getCurrentHP() - defendPower);
    if(creatureArray[0].getCurrentHP() <= 0)
      printf("Attacker is Dead!\n");
    else
      printf("Attacker Survives!\n");

    for(i = 1, check = creatureArray[1].getCardName(); check; ++i,
     check = creatureArray[i].getCardName()) {
      delete[] check;
      int currentDefender = creatureArray[i].getCurrentHP();
      attackPower -= currentDefender;
      if(attackPower >= 0) {
        creatureArray[i].setCurrentHP(0);
        printf("Defender %i is Dead!\n", i);
      }//if
      else {
        creatureArray[i].setCurrentHP(currentDefender - (currentDefender + attackPower));
        break;
      }
    }//for
    for(; i < bottom; ++i)
      printf("Defender %i Survives!\n", i);
  }//if



  //normal speed combat
  if(creatureArray[0].getCurrentHP() + creatureArray[0].getCounter11() > 0) {
    if(firstStrikeList[0] != 1)
      attackPower = creatureArray[0].getPower() + creatureArray[0].getCounter11();
    defendPower = 0;

    for(i = 1, check = creatureArray[1].getCardName(); check; ++i,
     check = creatureArray[i].getCardName()) {
      delete[] check;
      if(firstStrikeList[i] != 1)
        defendPower += creatureArray[i].getPower() + creatureArray[i].getCounter11();
    }//for

    creatureArray[0].setCurrentHP(creatureArray[0].getCurrentHP() - defendPower);
    if(creatureArray[0].getCurrentHP() <= 0)
      printf("Attacker is Dead!\n");
    else
      printf("Attacker Survives!\n");

    for(i = 1, check = creatureArray[1].getCardName(); check; ++i,
     check = creatureArray[i].getCardName()) {
      delete[] check;
      int currentDefender = creatureArray[i].getCurrentHP();
      attackPower -= currentDefender;
      if(attackPower >= 0) {
        creatureArray[i].setCurrentHP(0);
        printf("Defender %i is Dead!\n", i);
      }//if
      else {
        creatureArray[i].setCurrentHP(currentDefender - (currentDefender + attackPower));
        break;
      }
    }//for
    for(; i < bottom; ++i)
      printf("Defender %i Survives!\n", i);
  }//if

  creatureArrayCopy = new Card[arrayLength+1];
  for(int j = 0; j < arrayLength; ++j)
    creatureArrayCopy[j] = creatureArray[j];
  creatureArray[arrayLength] = blank;

  check = nullptr;
  return creatureArrayCopy;

}//fight()


/** displays all the creatures in fight's creatureArray.
  @post   the console has the cards in creatureArray values' printed on it.
*/
void Fight::displayCreatures() const {

  for(int i = 0; i < bottom; ++i) {
    creatureArray[i].displayCard();
    printf("\n");
  }
}//displayCreatures()


/** resets fight's creatureArray to default values.
  @post   the memory for the creatureArray is deallocated, then allocates memory
    for the default creatureArray.
*/
void Fight::reset() {

  if(creatureArray) {
    delete[] creatureArray;
    creatureArray = nullptr;
  }//if

  arraySize = 3;
  bottom = 0;

  creatureArray = new Card[3];
  creatureArray[0] = blank;

}//reset()


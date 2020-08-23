
#include "Card.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


/** constructs the card with default values.
  @post   all pointers used for dynamic memory are set to nullptr and all
    integers are set to 0.
*/
Card::Card() : cardKeyWords(nullptr), cardText(nullptr), cardEffectOnPlay(nullptr),
  instantSpeed(nullptr), sorcerySpeed(nullptr), cardName(nullptr), counter11(0),
  cmc(0), power(0), toughness(0), currentHP(0), cardKeyWordsLength(0),
  cardNameLength(0), cardTextLength(0), cardType(0) {

  manaCost[0] = 0;
  manaCost[1] = 0;
  manaCost[2] = 0;
  manaCost[3] = 0;
  manaCost[4] = 0;
  manaCost[5] = 0;
  manaCost[6] = 0;

}//default constructor


/** Copies the values from target card into this card.
  @param target   the Card that is being copied.
  @post   this card now has the same values as the target.
*/
Card::Card(const Card& target) : cardKeyWords(nullptr), cardText(nullptr),
  cardEffectOnPlay(nullptr), instantSpeed(nullptr), sorcerySpeed(nullptr),
  cardName(nullptr) {
  char* tempPtrString = nullptr;
  int* tempPtrInt = nullptr;

  tempPtrString = target.getCardEffectOnPlay();
  if(tempPtrString) {
    this->setCardEffectOnPlay(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrString = target.getInstantSpeed();
  if(tempPtrString) {
    this->setInstantSpeed(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrString = target.getSorcerySpeed();
  if(tempPtrString) {
    this->setSorcerySpeed(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrInt = target.getManaCost();
  this->setManaCost(tempPtrInt);
  delete[] tempPtrInt;

  this->setToughness(target.getToughness());
  this->setPower(target.getPower());
  this->setCurrentHP(target.getCurrentHP());
  this->setCounter11(target.getCounter11());
  this->setCardType(target.getCardType());

  tempPtrString = target.getCardKeyWords();
  if(tempPtrString) {
    this->setCardKeyWords(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrString = target.getCardName();
  if(tempPtrString) {
    this->setCardName(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrString = target.getCardText();
  if(tempPtrString) {
    this->setCardText(tempPtrString);
    delete[] tempPtrString;
  }//if

  tempPtrString = nullptr;
  tempPtrInt = nullptr;
}//copy constructor

/** deconstructs the card.
  @post all dynamic memory used is deallocated.
*/
Card::~Card() {
  if(cardKeyWords) {
    delete[] cardKeyWords;
    cardKeyWords = nullptr;
  }//if

  if(cardText) {
    delete[] cardText;
    cardText = nullptr;
  }//if

  if(cardEffectOnPlay) {
    delete[] cardEffectOnPlay;
    cardEffectOnPlay = nullptr;
  }//if

  if(instantSpeed) {
    delete[] instantSpeed;
    instantSpeed = nullptr;
  }//if

  if(sorcerySpeed) {
    delete[] sorcerySpeed;
    sorcerySpeed = nullptr;
  }//if

  if(cardName) {
    delete[] cardName;
    cardName = nullptr;
  }//if
}//destructor

void Card::useCardEffectOnPlay() const {
  //code will be added here
}//useCardEffectOnPlay()

/** gets the cardEffectOnPlay.
  @post   if cardEffectOnPlay has a value allocates some dynamic memory that is
    a copy of cardEffectOnPlay, otherwise does nothing.
  @return   if cardEffectOnPlay has a value returns a pointer to the dynamic
    memory that is a copy of cardEffectOnPlay, otherwise returns nullptr.
*/
char* Card::getCardEffectOnPlay() const {
  if(cardEffectOnPlay) {
    int i = 0;
    for(; cardEffectOnPlay[i] != '\0'; ++i);
    ++i;

    char* copyCardEffectOnPlay = new char[i];

    for(int j = 0; j < i; ++j)
      copyCardEffectOnPlay[j] = cardEffectOnPlay[j];

    return copyCardEffectOnPlay;
  }//if
  return nullptr;
}//getInstantSpeed()

/** sets the value of cardEffectOnPlay.
  @param newCardEffectOnPlay   a c style string that is copied to cardEffectOnPlay.
  @post   if newCardEffectOnPlay string has value, copies the value from
    newCardEffectOnPlay into cardEffectOnPlay.
*/
void Card::setCardEffectOnPlay(const char* newCardEffectOnPlay) {
  if(newCardEffectOnPlay) {
    if(cardEffectOnPlay)
      delete[] cardEffectOnPlay;

    int i = 0;
    for(; newCardEffectOnPlay[i] != '\0'; ++i);
    ++i;

    cardEffectOnPlay = new char[i];
    for(int j = 0; j < i; ++j)
      cardEffectOnPlay[j] = newCardEffectOnPlay[j];
  }//if
  else {
    if(cardEffectOnPlay) {
      delete[] cardEffectOnPlay;
      cardEffectOnPlay = nullptr;
    }//if
  }//else
}//setCardEffectOnPlay()


void Card::useInstantSpeed() const {
  //code will be added here
}//useInstantSpeed()

/** gets the instantSpeed.
  @post   if instantSpeed has a value allocates some dynamic memory that is
    a copy of instantSpeed, otherwise does nothing.
  @return   if instantSpeed has a value returns a pointer to the dynamic
    memory that is a copy of instantSpeed, otherwise returns nullptr.
*/
char* Card::getInstantSpeed() const {
  if(instantSpeed) {
    int i = 0;
    for(; instantSpeed[i] != '\0'; ++i);
    ++i;

    char* copyInstantSpeed = new char[i];

    for(int j = 0; j < i; ++j)
      copyInstantSpeed[j] = instantSpeed[j];

    return copyInstantSpeed;
  }//if
  return nullptr;
}//getInstantSpeed()

/** sets the value of instantSpeed.
  @param newInstantSpeed   a c style string that is copied to instantSpeed.
  @post   if newInstantSpeed string has value, copies the value from
    newInstantSpeed into instantSpeed.
*/
void Card::setInstantSpeed(const char* newInstantSpeed) {
  if(newInstantSpeed) {
    if(instantSpeed)
      delete[] instantSpeed;

    int i = 0;
    for(; newInstantSpeed[i] != '\0'; ++i);
    ++i;

    instantSpeed = new char[i];
    for(int j = 0; j < i; ++j)
      instantSpeed[j] = newInstantSpeed[j];
  }//if
  else {
    if(instantSpeed) {
      delete[] instantSpeed;
      instantSpeed = nullptr;
    }//if
  }//else
}//setInstantSpeed()


void Card::useSorcerySpeed() const {
  //code will be added here
}//useSorcerySpeed()

/** gets the sorcerySpeed.
  @post   if sorcerySpeed has a value allocates some dynamic memory that is
    a copy of sorcerySpeed, otherwise does nothing.
  @return   if sorcerySpeed has a value returns a pointer to the dynamic
    memory that is a copy of sorcerySpeed, otherwise returns nullptr.
*/
char* Card::getSorcerySpeed() const {

  if(sorcerySpeed) {
    int i = 0;
    for(; sorcerySpeed[i] != '\0'; ++i);
    ++i;

    char* copySorcerySpeed = new char[i];

    for(int j = 0; j < i; ++j)
      copySorcerySpeed[j] = sorcerySpeed[j];

    return copySorcerySpeed;
  }
  return nullptr;
}//getSorcerySpeed()

/** sets the value of sorcerySpeed.
  @param newSorcerySpeed   a c style string that is copied to sorcerySpeed.
  @post   if newSorcerySpeed string has value, copies the value from
    newSorcerySpeed into sorcerySpeed.
*/
void Card::setSorcerySpeed(const char* newSorcerySpeed) {
  if(newSorcerySpeed) {
    if(sorcerySpeed)
      delete[] sorcerySpeed;

    int i = 0;
    for(; newSorcerySpeed[i] != '\0'; ++i);
    ++i;

    sorcerySpeed = new char[i];
    for(int j = 0; j < i; ++j)
      sorcerySpeed[j] = newSorcerySpeed[j];
  }//if
  else {
    if(sorcerySpeed) {
      delete[] sorcerySpeed;
      sorcerySpeed = nullptr;
    }//if
  }//else
}//setSorcerySpeed()



/** sets the values of the manaCost array and calculates the value of cmc.
  @param newManaCost   an Array of 7 integers to be copied into manaCost.
  @post   the values of manaCost are set to the values of newManaCost, cmc is
    set to be equal to the combined value of the values of newManaCost.
*/
void Card::setManaCost(const int* newManaCost) {
  manaCost[0] = newManaCost [0];
  manaCost[1] = newManaCost [1];
  manaCost[2] = newManaCost [2];
  manaCost[3] = newManaCost [3];
  manaCost[4] = newManaCost [4];
  manaCost[5] = newManaCost [5];
  manaCost[6] = newManaCost [6];
  cmc = manaCost[0] + manaCost[1] + manaCost[2] + manaCost[3] + manaCost[4] + manaCost[5] + manaCost[6];
}//setManaCost()

/** gets the value of manaCost.
  @post   allocates dynamic memory with values equal to the values in manaCost.
  @return   returns a pointer to the dynamic memory with the copied values.
*/
int* Card::getManaCost() const {
  int* copyManaCost = new int[7];

  copyManaCost[0] = manaCost [0];
  copyManaCost[1] = manaCost [1];
  copyManaCost[2] = manaCost [2];
  copyManaCost[3] = manaCost [3];
  copyManaCost[4] = manaCost [4];
  copyManaCost[5] = manaCost [5];
  copyManaCost[6] = manaCost [6];

  return copyManaCost;
}//getManaCost()

/** gets the value of cmc.
  @return   returns the value of cmc.
*/
int Card::getcmc() const {
  return cmc;
}//getManaCost()



/** sets the value of counter11.
  @param newCounter11   the value to be copied into counter11.
  @post   newCounter11's value is copied into counter11.
*/
void Card::setCounter11(const int newCounter11) {
  counter11 = newCounter11;
}//addCounter11

/** gets the value of counter11.
  @return   returns the value of counter11.
*/
int Card::getCounter11() const {
  return counter11;
}

/** sets the value of currentHP.
  @param newHP   the value to be copied into currentHP.
  @post   newHP's value is copied into currentHP.
*/
void Card::setCurrentHP(const int newHP) {
  currentHP = newHP;
}//setCurrentHP()

/** gets the value of currentHP.
  @return   returns the value of currentHP.
*/
int Card::getCurrentHP() const {
  return currentHP;
}//getToughness()

/** sets the value of toughness.
  @param newToughness   the value to be copied into toughness.
  @post   newToughness's value is copied into toughness.
*/
void Card::setToughness(const int newToughness) {
  toughness = newToughness;
}//setToughness()

/** gets the value of toughness.
  @return   returns the value of toughness.
*/
int Card::getToughness() const {
  return toughness;
}//getToughness()

/** sets the value of power.
  @param newPower   the value to be copied into power.
  @post   newPower's value is copied into power.
*/
void Card::setPower(const int newPower) {
  power = newPower;
}//setPower()

/** gets the value of power.
  @return   returns the value of power.
*/
int Card::getPower() const {
  return power;
}//getPower()



/** sets the value of cardType.
  @param newCardType   the value to be copied into cardType.
  @post   newCardType's value is copied into cardType.
*/
void Card::setCardType(const int newCardType) {
  cardType = newCardType;
}//setPower()

/** gets the value of cardType.
  @return   returns the value of cardType.
*/
int Card::getCardType() const {
  return cardType;
}//getPower()



/** sets the value of cardKeyWords.
  @param newCardKeyWords   a c style string that is copied to cardKeyWords.
  @post   if newCardKeyWords string has value, copies the value from
    newCardKeyWords into cardKeyWords.
*/
void Card::setCardKeyWords(const char* newCardKeyWords) {
  if(newCardKeyWords) {
    if(cardKeyWords)
      delete[] cardKeyWords;

    int i = 0;
    for(; newCardKeyWords[i] != '\0'; ++i);
    ++i;

    cardKeyWords = new char[i];
    for(int j = 0; j < i; ++j)
      cardKeyWords[j] = newCardKeyWords[j];
    cardKeyWordsLength = i;
  }//if
  else {
    if(cardKeyWords) {
      delete[] cardKeyWords;
      cardKeyWords = nullptr;
    }//if
  }//else
}//setCardKeyWords()

/** gets the cardKeyWords.
  @post   if cardKeyWords has a value allocates some dynamic memory that is
    a copy of cardKeyWords, otherwise does nothing.
  @return   if cardKeyWords has a value returns a pointer to the dynamic
    memory that is a copy of cardKeyWords, otherwise returns nullptr.
*/
char* Card::getCardKeyWords() const {

  if(cardKeyWords) {
    char* copyCardKeyWords = new char[cardKeyWordsLength];

    for(int i = 0; i < cardKeyWordsLength; ++i)
      copyCardKeyWords[i] = cardKeyWords[i];

    return copyCardKeyWords;
  }//if
  return nullptr;
}//getCardKeyWords()



/** sets the value of cardText.
  @param newCardText   a c style string that is copied to cardText.
  @post   if newCardText string has value, copies the value from
    newCardText into cardText.
*/
void Card::setCardText(const char* newCardText) {
  if(newCardText) {
    if(cardText)
      delete[] cardText;

    int i = 0;
    for(; newCardText[i] != '\0'; ++i);
    ++i;

    cardText = new char[i];
    for(int j = 0; j < i; ++j)
      cardText[j] = newCardText[j];
    cardTextLength = i;
  }//if
  else {
    if(cardText) {
      delete[] cardText;
      cardText = nullptr;
    }//if
  }//else
}//setCardText()

/** gets the cardText.
  @post   if cardText has a value allocates some dynamic memory that is
    a copy of cardText, otherwise does nothing.
  @return   if cardText has a value returns a pointer to the dynamic
    memory that is a copy of cardText, otherwise returns nullptr.
*/
char* Card::getCardText() const {

  if(cardText) {
    char* copyCardText = new char[cardTextLength];

    for(int i = 0; i < cardTextLength; ++i)
      copyCardText[i] = cardText[i];

    return copyCardText;
  }
  return nullptr;
}//getCardText()



/** sets the value of cardName.
  @param newCardName   a c style string that is copied to cardName.
  @post   if newCardName string has value, copies the value from
    newCardName into cardName.
*/
void Card::setCardName(const char* newCardName) {
  if(newCardName) {
    if(cardName)
      delete[] cardName;

    int i = 0;
    for(; newCardName[i] != '\0'; ++i);
    ++i;

    cardName = new char[i];
    for(int j = 0; j < i; ++j)
      cardName[j] = newCardName[j];
    cardNameLength = i;
  }//if
  else {
    if(cardName) {
      delete[] cardName;
      cardName = nullptr;
    }//if
  }//else
}//setCardText()

/** gets the cardName.
  @post   if cardName has a value allocates some dynamic memory that is
    a copy of cardName, otherwise does nothing.
  @return   if cardName has a value returns a pointer to the dynamic
    memory that is a copy of cardText, otherwise returns nullptr.
*/
char* Card::getCardName() const {

  if(cardName) {
    char* copyCardName = new char[cardNameLength];

    for(int i = 0; i < cardNameLength; ++i)
      copyCardName[i] = cardName[i];

    return copyCardName;
  }
  return nullptr;
}//getCardText()



/** Copies the values from target card into this card.
  @param target   the Card that is being copied.
  @post   this card now has the same values as the target.
*/
void Card::operator=(const Card& target) {
  char* tempPtrString = nullptr;
  int* tempPtrInt = nullptr;

  tempPtrString = target.getCardEffectOnPlay();
  if(tempPtrString) {
    this->setCardEffectOnPlay(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->cardEffectOnPlay) {
      delete[] this->cardEffectOnPlay;
      this->cardEffectOnPlay = nullptr;
    }//if
  }//else

  tempPtrString = target.getInstantSpeed();
  if(tempPtrString) {
    this->setInstantSpeed(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->instantSpeed) {
      delete[] this->instantSpeed;
      this->instantSpeed = nullptr;
    }//if
  }//else

  tempPtrString = target.getSorcerySpeed();
  if(tempPtrString) {
    this->setSorcerySpeed(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->sorcerySpeed) {
      delete[] this->sorcerySpeed;
      this->sorcerySpeed = nullptr;
    }//if
  }//else

  tempPtrInt = target.getManaCost();
  this->setManaCost(tempPtrInt);
  delete[] tempPtrInt;

  this->setToughness(target.getToughness());
  this->setPower(target.getPower());
  this->setCurrentHP(target.getCurrentHP());
  this->setCounter11(target.getCounter11());
  this->setCardType(target.getCardType());

  tempPtrString = target.getCardKeyWords();
  if(tempPtrString) {
    this->setCardKeyWords(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->cardKeyWords) {
      delete[] this->cardKeyWords;
      this->cardKeyWords = nullptr;
    }//if
  }//else

  tempPtrString = target.getCardName();
  if(tempPtrString) {
    this->setCardName(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->cardName) {
      delete[] this->cardName;
      this->cardName = nullptr;
    }//if
  }//else

  tempPtrString = target.getCardText();
  if(tempPtrString) {
    this->setCardText(tempPtrString);
    delete[] tempPtrString;
  }//if
  else {
    if(this->cardText) {
      delete[] this->cardText;
      this->cardText = nullptr;
    }//if
  }//else

  tempPtrString = nullptr;
  tempPtrInt = nullptr;
}//overload =



/** prints to console the values of card.
  @post   the console has this cards values printed on it.
*/
void Card::displayCard() const {
  if(cardName)
    printf("  Card Name:      %s\n", cardName);

  int i;
  printf("  Mana Cost:      ");
  if(cmc > 0) {
    for(i = 0; i < manaCost[0]; ++i)
      printf("R");
    for(i = 0; i < manaCost[1]; ++i)
      printf("B");
    for(i = 0; i < manaCost[2]; ++i)
      printf("G");
    for(i = 0; i < manaCost[3]; ++i)
      printf("W");
    for(i = 0; i < manaCost[4]; ++i)
      printf("U");
    for(i = 0; i < manaCost[5]; ++i)
      printf("C");
    if(manaCost[6] > 0)
      printf("%i", manaCost[6]);
    else
      for(i = 0; i > manaCost[6]; --i)
        printf("X");
    printf("\n");
  }//if
  else
    printf("0\n");

  printf("  Power:          %i\n", power);
  printf("  Toughness:      %i\n", toughness);

  if(cardKeyWords)
    printf("  Key Words:      %s\n", cardKeyWords);

  if(cardText)
    printf("  Card Text:      %s\n", cardText);

  printf("  +1/+1 Counters: %i\n", counter11);
  printf("  Current HP:     %i\n", currentHP);

  printf("    Below is programming stuff\n");
  printf("%i\n", cardType);

  if(cardEffectOnPlay)
    printf("%s\n", cardEffectOnPlay);

  if(instantSpeed)
    printf("%s\n", instantSpeed);

  if(sorcerySpeed)
    printf("%s\n", sorcerySpeed);
}//displayCard()


/** appends in file the values of card.
  @param filename   the file that's written to
  @post   the console has this cards values printed on it.
*/
void Card::appendCardToFile(const char* filename) const {
  ofstream fout;
  fout.open(filename, ofstream::out | ofstream::app);
  if(!fout.good())
    return;

  if(cardName)
    fout << "  Card Name:      " << cardName << endl;

  int i;
  fout << "  Mana Cost:      ";
  if(cmc > 0) {
    for(i = 0; i < manaCost[0]; ++i)
      fout << "R";
    for(i = 0; i < manaCost[1]; ++i)
      fout << "B";
    for(i = 0; i < manaCost[2]; ++i)
      fout << "G";
    for(i = 0; i < manaCost[3]; ++i)
      fout << "W";
    for(i = 0; i < manaCost[4]; ++i)
      fout << "U";
    for(i = 0; i < manaCost[5]; ++i)
      fout << "C";
    if(manaCost[6] > 0)
      fout << manaCost[6];
    else
      for(i = 0; i > manaCost[6]; --i)
        fout << "X";
    fout << endl;
  }//if
  else
    fout << "0" << endl;

  fout << "  Power:          " << power << endl;
  fout << "  Toughness:      " << toughness << endl;

  if(cardKeyWords)
    fout << "  Key Words:      " << cardKeyWords << endl;

  if(cardText)
    fout << "  Card Text:      " << cardText << endl;

  fout << "  +1/+1 Counters: " << counter11 << endl;
  fout << "  Current HP:     " << currentHP << endl;

/*
  fout << "    Below is programming stuff" << endl;
  fout << cardType << endl;

  if(cardEffectOnPlay)
    fout << cardEffectOnPlay << endl;

  if(instantSpeed)
    fout << instantSpeed << endl;

  if(sorcerySpeed)
    fout << sorcerySpeed << endl;
*/
}//appendCardToFile()






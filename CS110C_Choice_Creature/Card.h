
#ifndef _CARD
#define _CARD

/**
  A card is a collection of data and the functions used to access that data.
  It also has a display function, and overloaded = operator.
  @file Card.h
  @file Card.cpp
  @auther Joselin Lybrand
*/
class Card {
  private:
    //how much mana of each type needed to cast the spell
    //0 = red, 1 = blue, 2 = black, 3 = green, 4 = white, 5 = colorless, 6 = any
    //if any is -1 then the card has a x manacost, -2 = xx, etc.
    int manaCost[7];
    //the combined numbers of the manacost, where x = 0 (it doesn't count negative)
    int cmc;

    //the power of the card
    int power;
    //the toughness of the card
    int toughness;
    //current hit points of the card
    int currentHP;
    //number of +1/+1 counters
    int counter11;

    //wether the card is an instant, sorcery, creature, enchantment, artifact,
    //land, legendary, and probably more.
    int cardType;
    //the entire list of keywords in the card
    char* cardKeyWords;
    int cardKeyWordsLength;
    //the actual text of the card, isn't used in logic, only used for player to read
    char* cardName;
    int cardNameLength;
    char* cardText;
    int cardTextLength;

    //code that is parsed by the cardEffectOnPlay() method
    char* cardEffectOnPlay;
    //code that is parsed by the instantSpeed() method
    char* instantSpeed;
    //code that is parsed by the sorcerySpeed() method
    char* sorcerySpeed;

  public:
    Card();
    Card(const Card& target);
    ~Card();

    //what happens when this card is played
    void useCardEffectOnPlay() const;
    char* getCardEffectOnPlay() const;
    void setCardEffectOnPlay(const char* newCardEffectOnPlay);

    //if this card has instant speed effects, and if so what they do
    void useInstantSpeed() const;
    char* getInstantSpeed() const;
    void setInstantSpeed(const char* newInstantSpeed);

    //if this card has sorcery speed effects, and if so what they do
    void useSorcerySpeed() const;
    char* getSorcerySpeed() const;
    void setSorcerySpeed(const char* newSorcerySpeed);

    //sets the manaCost and cmc because cmc is derived from manaCost
    void setManaCost(const int* newManaCost);
    int* getManaCost() const;
    int getcmc() const;

    void setCounter11(const int newCounter11);
    int getCounter11() const;

    void setCurrentHP(const int newHP);
    int getCurrentHP() const;

    void setToughness(const int newToughness);
    int getToughness() const;

    void setPower(const int newPower);
    int getPower() const;

    void setCardType(const int newCardType);
    int getCardType() const;

    //use a space between keywords
    void setCardKeyWords(const char* newCardKeyWords);
    char* getCardKeyWords() const;

    void setCardText(const char* newCardText);
    char* getCardText() const;

    void setCardName(const char* newCardName);
    char* getCardName() const;

    void operator=(const Card& target);

    void displayCard() const;
	
	void appendCardToFile(const char* filename) const;

};//Card

#include "Card.cpp"
#endif

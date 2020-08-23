/*
#include "Card.h"
#include "myBag.h"
#include "Fight.h"
#include "Hand.h"
#include <cstdlib>
#include <string>
#include <cassert>
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include "GameController.h"
using namespace std;

int main() {
  srand(time(NULL));
  
  ofstream fout;
  

  GameController mtg;

  mtg.generateCards("testfile.csv");

  mtg.readGeneratedCards("testfile.csv");
  
  fout.open("outputfile.txt");
  fout << "~* Your Hand *~\n\n";
  fout.close();

  mtg.appendPlayer1HandToFile("outputfile.txt");
  
  fout.open("outputfile.txt", ofstream::out | ofstream::app);
  fout << "\n~* Opponent's Card *~\n\n";
  fout.close();

  mtg.appendOpponentCardToFile("outputfile.txt");

  mtg.sortPlayer1By(1);
  
  fout.open("outputfile.txt", ofstream::out | ofstream::app);
  fout << "\n\n~* Sorted *~\n\n";
  fout.close();
  
  mtg.appendPlayer1HandToFile("outputfile.txt");
  
/*

  Card temp;

  int manaCost[7] = { 0 };
  int i = 0;

  opponent.setCardEffectOnPlay("N/A\0");
  opponent.setInstantSpeed("N/A\0");
  opponent.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 1;
  opponent.setManaCost(manaCost);
  opponent.setPower(rand() % 5+1);
  opponent.setToughness(rand() % 5+1);
  opponent.setCurrentHP(opponent.getToughness());
  opponent.setCardType(1);
  opponent.setCardKeyWords("Creature\0");
  opponent.setCardName("Your Opponent\0");
  opponent.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;



  temp.setCardEffectOnPlay("N/A\0");
  temp.setInstantSpeed("N/A\0");
  temp.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  temp.setManaCost(manaCost);
  temp.setPower(1);
  temp.setToughness(1);
  temp.setCurrentHP(1);
  temp.setCardType(1);
  temp.setCardKeyWords("Creature\0");
  temp.setCardName("Little Guy\0");
  temp.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;
  player1.recieve(temp);

  temp.setCardEffectOnPlay("N/A\0");
  temp.setInstantSpeed("N/A\0");
  temp.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 1;
  temp.setManaCost(manaCost);
  temp.setPower(2);
  temp.setToughness(2);
  temp.setCurrentHP(2);
  temp.setCardType(1);
  temp.setCardKeyWords("Creature\0");
  temp.setCardName("Medium Guy\0");
  temp.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;
  player1.recieve(temp);

  temp.setCardEffectOnPlay("N/A\0");
  temp.setInstantSpeed("N/A\0");
  temp.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 1;
  temp.setManaCost(manaCost);
  temp.setPower(3);
  temp.setToughness(1);
  temp.setCurrentHP(1);
  temp.setCardType(1);
  temp.setCardKeyWords("Creature\0");
  temp.setCardName("Attack Guy\0");
  temp.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;
  player1.recieve(temp);

  temp.setCardEffectOnPlay("N/A\0");
  temp.setInstantSpeed("N/A\0");
  temp.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 1;
  temp.setManaCost(manaCost);
  temp.setPower(1);
  temp.setToughness(3);
  temp.setCurrentHP(3);
  temp.setCardType(1);
  temp.setCardKeyWords("Creature\0");
  temp.setCardName("Defense Guy\0");
  temp.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;
  player1.recieve(temp);

  temp.setCardEffectOnPlay("N/A\0");
  temp.setInstantSpeed("N/A\0");
  temp.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 2;
  temp.setManaCost(manaCost);
  temp.setPower(4);
  temp.setToughness(4);
  temp.setCurrentHP(4);
  temp.setCardType(1);
  temp.setCardKeyWords("Creature\0");
  temp.setCardName("Big Guy\0");
  temp.setCardText("N/A\0");
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;
  player1.recieve(temp);

  printf("\n~* Your Hand *~\n\n");

  player1.displayHand();

  printf("\n~* Opponent's Card *~\n\n");

  opponent.displayCard();

  player1.sortByCounteringOffensive(opponent);
  printf("\n~* Sorted *~\n\n");

  player1.displayHand();
*/

/*
{
  {
  myBag deck;

  Card test;

  int manaCost[7] = { 0 };
  int i = 0;

  printf("Before card creation.\n");

  //inputting info for a Seacoast Drake
  test.setCardEffectOnPlay(":Flying\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[1] = 1;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(1);
  test.setToughness(3);
  test.setCurrentHP(3);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Drake\0");
  test.setCardName("Seacoast Drake\0");
  test.setCardText("Flying\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 1 done.\n");

  //inputting info for Dire Fleet Daredevil
  test.setCardEffectOnPlay(":FirstStrike\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[0] = 1;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(2);
  test.setToughness(1);
  test.setCurrentHP(1);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Human Pirate\0");
  test.setCardName("Dire Fleet Daredevil\0");
  test.setCardText("First strike\nWhen Dire Fleet Daredevil enters the battlefield, exile target instant or sorcery card from an opponent's graveyard. You may cast that card this turn, and you may spend mana as though it were mana of any type to cast that spell. If that card would be put into a graveyard this turn, exile it instead.\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 2 done.\n");

  //inputting info for Flayer Drone
  test.setCardEffectOnPlay(":Devoid :FirstStrike\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[0] = 1;
  manaCost[2] = 1;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(3);
  test.setToughness(1);
  test.setCurrentHP(1);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Eldrazi Drone\0");
  test.setCardName("Flayer Drone\0");
  test.setCardText("Devoid (This card has no color)\nFirst Strike\nWhenever another colorless creature enters the battlefield under your control, target opponent loses 1 life\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 3 done.\n");

  //inputting info for Fencing Ace
  test.setCardEffectOnPlay(":DoubleStrike\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[4] = 1;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(1);
  test.setToughness(1);
  test.setCurrentHP(1);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Human Soldier\0");
  test.setCardName("Fencing Ace\0");
  test.setCardText("Double Strike\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 4 done.\n");

  //inputting info for Garruk's Companion
  test.setCardEffectOnPlay(":Trample\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[3] = 2;
  test.setManaCost(manaCost);
  test.setPower(3);
  test.setToughness(2);
  test.setCurrentHP(2);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Beast\0");
  test.setCardName("Garruk's Companion\0");
  test.setCardText("Trample\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 5 done.\n");

  //inputting info for Anurid Barkripper
  test.setCardEffectOnPlay(":Threshold Self [+2/+2]\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[3] = 2;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(2);
  test.setToughness(2);
  test.setCurrentHP(2);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Beast\0");
  test.setCardName("Anurid Barkripper\0");
  test.setCardText("Threshold - Anurid Barkripper gets +2/+2. (You have threshold as long as seven or more cards are in your graveyard.)\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 6 done.\n");

  //inputting info for Lightning Bolt
  test.setCardEffectOnPlay(":Target Creature OR Player Damage 3\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[0] = 1;
  test.setManaCost(manaCost);
  test.setPower(0);
  test.setToughness(0);
  test.setCurrentHP(0);
  test.setCardType(2);
  test.setCardKeyWords("Instant\0");
  test.setCardName("Lightning Bolt\0");
  test.setCardText("Lightning Bolt deals 3 damage to target creature or player\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 7 done.\n");

  //inputting info for Basic Green Land
  test.setCardEffectOnPlay("N/A\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed(":Tap Green\0");
  test.setManaCost(manaCost);
  test.setPower(0);
  test.setToughness(0);
  test.setCurrentHP(0);
  test.setCardType(5);
  test.setCardKeyWords("Land\0");
  test.setCardName("Forest\0");
  test.setCardText("N/A\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 8 done.\n");

  //inputting info for Shining Aerosaur
  test.setCardEffectOnPlay(":Flying\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[4] = 1;
  manaCost[6] = 4;
  test.setManaCost(manaCost);
  test.setPower(3);
  test.setToughness(4);
  test.setCurrentHP(4);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Dinosaur\0");
  test.setCardName("Shining Aerosaur\0");
  test.setCardText("Flying\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 9 done.\n");

  //inputting info for Raptor Companion
  test.setCardEffectOnPlay("N/A\0");
  test.setInstantSpeed("N/A\0");
  test.setSorcerySpeed("N/A\0");
  manaCost[4] = 1;
  manaCost[6] = 1;
  test.setManaCost(manaCost);
  test.setPower(3);
  test.setToughness(1);
  test.setCurrentHP(1);
  test.setCardType(1);
  test.setCardKeyWords("Creature - Dinosaur\0");
  test.setCardName("Raptor Companion\0");
  test.setCardText("N/A\0");
  deck.add(test);
  for(i = 0; i < 7; ++i)
    manaCost[i] = 0;

  printf("Card 10 done.\n");
  
  printf("Finished card creation.\n");

  Fight club;
  Card* creatureArray = nullptr;
  printf("\nFirst fight.-----------------------\n\n");

  printf("temp = deck.remove()\n");
  Card temp = deck.remove();
  printf("club.addCreature(temp)\n");
  club.addCreature(temp);
  printf("temp = deck.remove()\n");
  temp = deck.remove();
  printf("club.addCreature(temp)\n");
  club.addCreature(temp);
  printf("temp = deck.remove()\n");
  temp = deck.remove();
  printf("club.addCreature(temp)\n");
  club.addCreature(temp);

  creatureArray = club.fight();
  printf("\n");
  club.displayCreatures();
  club.reset();

  assert(creatureArray);
  assert(creatureArray[0].getCurrentHP() + creatureArray[0].getCounter11() == -2);
  assert(creatureArray[1].getCurrentHP() + creatureArray[1].getCounter11() == 1);
  delete[] creatureArray;

  printf("\nFight's done, new fight.-----------\n\n");
  printf("\nsecond fight.----------------------\n\n");

  printf("temp = deck.remove()+++++++++++++1\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++1\n");
  club.addCreature(temp);
  printf("temp = deck.remove()+++++++++++++2\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++2\n");
  club.addCreature(temp);
  printf("temp = deck.remove()+++++++++++++3\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++3\n");
  club.addCreature(temp);


  creatureArray = club.fight();
  printf("\n");
  club.displayCreatures();
  club.reset();
  assert(creatureArray);
  assert(creatureArray[0].getCurrentHP() + creatureArray[0].getCounter11() == -1);
  assert(creatureArray[1].getCurrentHP() + creatureArray[1].getCounter11() == 0);
  delete[] creatureArray;

  printf("\nFight's done, new fight.-----------\n\n");
  printf("\nThird fight.-----------------------\n\n");

  printf("temp = deck.remove()+++++++++++++1\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++1\n");
  club.addCreature(temp);
  printf("temp = deck.remove()+++++++++++++2\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++2\n");
  club.addCreature(temp);
  printf("temp = deck.remove()+++++++++++++3\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++3\n");
  club.addCreature(temp);
  printf("temp = deck.remove()+++++++++++++4\n");
  temp = deck.remove();
  printf("club.addCreature(temp)+++++++++++4\n");
  club.addCreature(temp);

  creatureArray = club.fight();
  printf("\n");
  club.displayCreatures();
  club.reset();
  assert(creatureArray);
  assert(creatureArray[0].getCurrentHP() + creatureArray[0].getCounter11() == -4);
  assert(creatureArray[1].getCurrentHP() + creatureArray[1].getCounter11() == 0);
  assert(creatureArray[2].getCurrentHP() + creatureArray[2].getCounter11() == 1);
  assert(creatureArray[3].getCurrentHP() + creatureArray[3].getCounter11() == 3);
  delete[] creatureArray;

  printf("Fight has ended.---------------------\n");

  }

  printf("The program has finished.------------\n");

}
*/
  return 0;
}//main()

#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>

//testing of initializeGame function

int main(){
    printf("*********************BEGIN UNIT TESTS OF INITIALIZEGAME()*********************\n\n");
    
    struct gameState T;
   // int bad_k1[10] = {adventurer, bad, embargo, village, minion, mine, cutpurse,
   //        sea_hag, tribute, smithy};
    int bad_k2[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int good_k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    //REMOVED BECAUSE GETS CAUGHT AT COMPILE TIME
    //Test against bad kingdom cards
    //if(initializeGame(2, bad_k1, 5, &T) != -1)
    //    {printf("FAIL Did not catch bad kingdom card\n");}
 
    //Test against repeat kingdomCards
    if(initializeGame(2, bad_k2, 5, &T) != -1)
        {printf("FAIL Did not catch repeat kingdom card\n");}
    
    //Test against bad number of players
    if(initializeGame(-1, good_k, 5, &T) != -1)
        {printf("FAIL Did not catch invalid number of players\n");}
    
    //Initialize good game
    if(initializeGame(2, good_k, 5, &T) == -1)
        {printf("FAIL Returned -1 on correct input\n");}
 
 //check numplayers
 if(T.numPlayers != 2){
     printf("FAIL number of players does not equal 2\n");
 }

//check number of curse cards
 if(T.supplyCount[curse] != 10){
     printf("FAIL number of curse cards is incorrect\n");
 }

 //check number of Victory cards
  
  if(T.supplyCount[estate] != 8 ||
      T.supplyCount[duchy] != 8 ||
      T.supplyCount[province] != 8)
      {
          printf("FAIL number of Victory cards is incorrect\n");
      }
    
  //check number of Treasure cards
  if(T.supplyCount[copper] != 46 ||
  T.supplyCount[silver] != 40 ||
  T.supplyCount[gold] != 30){
      printf("FAIL number of Treasure cards is incorrect\n");
  }

  //check number of Kingdom cards
  if(T.supplyCount[gardens] != 8){
      printf("FAIL incorrect Victory card settings\n");
  }
  if(T.supplyCount[great_hall] != -1){
      printf("FAIL did not set unused card to -1\n");
  }
  if(T.supplyCount[adventurer] != 10 ||
  T.supplyCount[sea_hag] != 10){
      printf("FAIL did not correctly set supply counts\n");
  }

  //check each player has correct number of cards in deck
  if(T.deckCount[0] != 10 || T.deckCount[1] != 10){
      printf("Player 1 deck count: %d Player 2 deck count: %d\n", T.deckCount[0], T.deckCount[1]);
      printf("FAIL incorrect number of cards in deck\n");
  }
  printf("**********************TESTS COMPLETE*************************\n\n");
  
  return 0;
}
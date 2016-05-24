/******************************************************************************
** cardtest4.c 
** Emily Snyder
** Spring 2016
** CS 362-400
** This file contains unit tests for the Council Room card 
******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PLAYERS 4
#define PILES 3  // hand, discard, deck

void cardCounts(struct gameState*, int[PLAYERS+1][PILES]);
void otherPlayerCounts(int, int[PLAYERS+1][PILES], int[PLAYERS+1][PILES]);

void testNone(struct gameState*, int);
void printResults(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);  

enum pile {
  hand = 0,
  deck,
  discard,
  played 
};

int main() {
 
  struct gameState state;
  int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, 
                          remodel, smithy, village, baron, great_hall};
  int randomSeed = 1000;   // example unittest
  int player;
  int bonus;
  int countsBefore[PLAYERS+1][3];
  int countsAfter[PLAYERS+1][3];
  int i;
  int deckSize;
  int handSize;
  int playedCount;
  int discardSize;
  int handPos = 0;
  int buysBefore;
  int buysAfter;
 
  memset(&state, '\0', sizeof(struct gameState)); // clear game state

  printf("****************************************************************\n");
  printf("***                     COUNCIL ROOM                         ***\n");
  printf("****************************************************************\n");
  initializeGame(PLAYERS, kingdomCards, randomSeed, &state);
  player = state.whoseTurn;
  deckSize = state.deckCount[player];
  handSize = state.handCount[player];
  playedCount = state.playedCardCount;
  discardSize = state.discardCount[player];

  for (i = 0; i < handSize; i++) {
    state.hand[player][i] = minion;
  }

  for (i = 0; i < deckSize; i++) {
    if (i == handPos) {
      state.deck[player][i] = great_hall;
    }
    else {
      state.deck[player][i] = mine;
    }
  }

  cardCounts(&state, countsBefore);
  buysBefore = state.numBuys;
  cardEffect(council_room, -1, -1, -1, &state, handPos, &bonus);
  buysAfter = state.numBuys;
  cardCounts(&state, countsAfter);

  // After: hand + 4, numBuys + 1, discard card

  printResults(handSize, state.handCount[player], handSize + 3, deckSize, 
               state.deckCount[player], deckSize - 4, discardSize, 
               state.discardCount[player], discardSize + 1, playedCount, 
               state.playedCardCount, playedCount + 1, buysBefore, 
               buysAfter, buysBefore + 1);

  otherPlayerCounts(player, countsBefore, countsAfter);

  return 0;
}


void printResults(  
  int  handBefore, 
  int  handAfter, 
  int handDesired,
  int  deckBefore, 
  int  deckAfter, 
  int deckDesired,
  int  discardBefore,
  int  discardAfter, 
  int discardDesired,
  int  playedBefore, 
  int playedAfter, 
  int playedDesired,
  int buysBefore,
  int buysAfter,
  int buysDesired
  )
{
  printf("\tBefore\tAfter\n");

  printf("Hand\t%d\t%d", handBefore, handAfter);
  if (handAfter != handDesired) {
    printf("\tERROR - should be %d\n", handDesired);
  }
  else {
    printf("\n");
  }

  printf("Deck\t%d\t%d", deckBefore, deckAfter);
  if (deckAfter != deckDesired) {
    printf("\tERROR - should be %d\n", deckDesired);
  }
  else {
    printf("\n");
  }

  printf("Discard\t%d\t%d", discardBefore, discardAfter);
  if (discardAfter != discardDesired) {
    printf("\tERROR - should be %d\n", discardDesired);
  }
  else {
    printf("\n");
  }
  printf("Played\t%d\t%d", playedBefore, playedAfter);
  if (playedAfter != playedDesired) {
    printf("\tERROR - should be %d\n", playedDesired);
  }
  else {
    printf("\n");
  }
  printf("Buys\t%d\t%d", buysBefore, buysAfter);
  if (buysAfter != buysDesired) {
    printf("\tERROR - should be %d\n", buysDesired);
  }
  else {
    printf("\n");
  }
}

void cardCounts(
  struct gameState  *state, 
  int               counts[PLAYERS+1][PILES]
  ) 
{
   
  int i;

  for (i = 0; i < PLAYERS; i++) {
    counts[i][0] = state->handCount[i];
    counts[i][1] = state->deckCount[i];
    counts[i][2] = state->discardCount[i];
  }
  counts[i][0] = state->playedCardCount;    
}

void otherPlayerCounts(
  int  currentPlayer, 
  int countsBefore[PLAYERS+1][PILES], 
  int countsAfter[PLAYERS+1][PILES]
  ) 
{
  
  int i;
  int bugFound = 0;

  printf("\n------- Status of Other Players' Piles -------\n");
  for (i = 0; i < PLAYERS; i++) {  
    printf("Player %d", i);
    if (i != currentPlayer) {
      printf("\tBefore\tAfter\n");
      printf("  Hand\t\t%d\t%d\n", countsBefore[i][hand], countsAfter[i][hand]); 
      if (countsAfter[i][hand] != countsBefore[i][hand] + 1) {
        printf("ERROR - should added 1 card\n");
         bugFound = 1;
      }
      printf("  Deck\t\t%d\t%d\n", countsBefore[i][deck], countsAfter[i][deck]); 
      if (countsAfter[i][deck] != countsBefore[i][deck] - 1) {
        printf("ERROR - should drawn 1 card\n");
         bugFound = 1;
      }
      printf("  Discard\t%d\t%d\n", countsBefore[i][discard], countsAfter[i][discard]); 
      if (countsAfter[i][discard] != countsBefore[i][discard]) {
        printf("ERROR - should not be altered\n");
         bugFound = 1;
      }
    }
    else {
      printf(" - current player\n");
    }
  }
  if (!bugFound) {
    printf("SUCCESS - other players' piles are not changed\n");
  }
}

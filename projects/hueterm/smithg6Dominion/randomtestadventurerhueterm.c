/**
Michael Hueter
CS 362 Assignment 4
randomtestadventurer.c - fuzzing the adventurer card
**/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 9000

int testAssert(int expected, int actual, char *a){
  if (expected != actual){
    printf ("\n ! ASSERTION FAILED: EXPECTED %s == %d, NOT %d. \n", a, expected, actual);
    return 1;
  }
  // printf ("\n PASSED: %s == %d.\n", a, actual);
  return 0;
}

int main() {
  /************ initial set up ************/
  int adventurerStatus; // did adventurer exit with 1 or 0
  int cards[27] = {adventurer, ambassador, baron, copper, council_room,
                  curse, cutpurse, duchy,  embargo, estate, feast,
                  gardens, gold, great_hall, mine,  minion, outpost,
                  province, remodel, salvager, sea_hag, smithy,
                  silver, steward, treasure_map, tribute, village};
  // keep track of test failures
  int executionFailures = 0;
  int handSizeFailures = 0;
  int treasureFailures = 0;
  int player2Failures = 0;
  int discardFailures = 0;
  int totalFailures = 0;

  int hasTreasure; // does the player have any treasure
  int i, x, y, z = 0; // iterators
  int k[10]; // kingdom cards
  k[0] = adventurer; // ensure adventurer is always present
  k[1] = copper; // ensure a treasure card is always present
  int numberOfPlayers;
  int seed;
  struct gameState G;

  srand(time(NULL));

  printf ("\n************** RANDOM TESTING Adventurer Card **************\n");
  /************ begin test cycle ************/
  for (i = 0; i < NUM_TESTS; i++){
    printf("\n----- Iteration Number %d -----\n", i+1);
    /************ random test initialization ************/
    memset(&G, 0, sizeof(struct gameState));   // clear the game state
    numberOfPlayers = (rand() % (MAX_PLAYERS - 1)) + 2; // 2 <= players <= MAX
    printf("\n Number of Players: %d", numberOfPlayers);
    int randomIndex;
    // set 9 out of 10 kingdom cards randomly
    printf("\n Cards in play: %d %d", k[0], k[1]);
    for (x = 2; x < 10; x++){
      randomIndex = (rand() % 27) + 1; // exclude adventurer
      k[x] = cards[randomIndex];
      printf (" %d", k[x]);
    }
    seed = rand() % 1000 + 1; // new random seed each time
    printf("\n Random Seed: %d \n", seed);
    initializeGame(numberOfPlayers, k, seed, &G);
    // random deck and hand size
    int deckSize = rand() % MAX_DECK + 1;
    int handSize = rand() % MAX_HAND - 1; // must have room for 2 cards
    // set player 1's hand and deck sizes
    int randomCard;

    G.deckCount[0] = deckSize;
    for (y = 0; y < deckSize; y++){
      randomCard = rand() % 10;
      G.deck[0][y] = randomCard; // load the deck with random cards
    }

    G.handCount[0] = handSize;
    G.hand[0][0] = adventurer; // Player 1 always needs an adventurer
    for (z = 1; z < handSize; z++){
      randomCard = rand() % 10;
      G.hand[0][y] = randomCard; // load the hand with random cards
    }
    printf("\n RESULTS: \n");
    /************ run tests ************/
    adventurerStatus = cardAdventurer(0, &G);
    executionFailures += testAssert(0, adventurerStatus, "Adventurer card executes and returns 0");
    handSizeFailures += testAssert(handSize, G.handCount[0], "Player 1 hand size");
    // test first drawn card for treasure
    if (G.hand[0][handSize-2] == copper || G.hand[0][handSize-2] == silver || G.hand[0][handSize-2] == gold ){
      hasTreasure = 1;
    }
    else {
      hasTreasure = 0;
    }
    treasureFailures += testAssert(1, hasTreasure, "Player 1's n-2 card should be treasure");
    // test second drawn card for treasure
    if (G.hand[0][handSize-1] == copper || G.hand[0][handSize-1] == silver || G.hand[0][handSize-1] == gold ){
      hasTreasure = 1;
    }
    else {
      hasTreasure = 0;
    }
    treasureFailures += testAssert(1, hasTreasure, "Player 1's n-1 card should be treasure");

    // test player 2 status
    player2Failures += testAssert(0, G.handCount[1], "Player 2's hand should be 0");
    player2Failures += testAssert(10, G.deckCount[1], "Player 2's deck should be unchanged at 10");
    player2Failures += testAssert(0, G.discardCount[1], "Player 2's discard pile should be 0");

    // End turn and check discarded pile
    endTurn(&G);
    discardFailures += testAssert(handSize, G.discardCount[0], "Player 1 should have discarded all cards");

  }


  printf ("\n------- RANDOM TESTING Adventurer Card COMPLETE -------\n");
  totalFailures = executionFailures + handSizeFailures + treasureFailures + player2Failures + discardFailures;
  if(totalFailures == 0){
    printf("  All assertions passed!\n\n");
  }
  else{
    printf ("\n EXECUTION FAILURES: %d \n", executionFailures);
    printf ("\n HAND SIZE FAILURES: %d \n", handSizeFailures);
    printf ("\n TREASURE FAILURES:  %d \n", treasureFailures);
    printf ("\n PLAYER 2 FAILURES:  %d \n", player2Failures);
    printf ("\n DISCARD FAILURES:  %d \n", discardFailures);
    printf ("\n ------------------------------\n");
    printf ("\n TOTAL FAILURES:     %d \n\n", totalFailures);
  }
  return 0;
}

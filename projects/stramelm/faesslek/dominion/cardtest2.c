#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("CARD TEST #2: ADVENTURER\n");

  // setup dummy game with 2 players
  int np = 2;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
    sea_hag, tribute, smithy};
  int seed = 222; // arbitrary seed value
  struct gameState* state = malloc(sizeof(struct gameState));
  initializeGame(np, k, seed, state);

  // -------------------------------------------------------------------------------------
  // REQT: THIS ISN'T A TEST PER SE, BUT I WANT TO MOVE THE INITIAL DECK CARDS TO DISCARD
  //       FOR PLAYER 1 TO FORCE A SHUFFLE (FOR BETTER LINE/BRANCH COVERAGE)
  // -------------------------------------------------------------------------------------
  int pNum = 1;
  int i;

  /* printf("PRETEST: HAND=%d, DECK=%d, DISC=%d\n",
    state->handCount[pNum], state->deckCount[pNum], state->discardCount[pNum]);
  for (i = 0; i < state->deckCount[pNum]; i++) {
    printf("PRETEST: DECK CARD=%d\n", state->deck[pNum][i]);
  }
  for (i = 0; i < state->discardCount[pNum]; i++) {
    printf("PRETEST: DISCARD CARD=%d\n", state->discard[pNum][i]);
  }
  for (i = 0; i < state->deckCount[pNum]; i++) {
    state->discard[pNum][i] = state->deck[pNum][i];
  } */

  i = state->deckCount[pNum];
  state->deckCount[pNum] = state->discardCount[pNum];
  state->discardCount[pNum] = i;

  /* printf("PRETEST: HAND=%d, DECK=%d, DISC=%d\n",
    state->handCount[pNum], state->deckCount[pNum], state->discardCount[pNum]);
  for (i = 0; i < state->deckCount[pNum]; i++) {
    printf("PRETEST: DECK CARD=%d\n", state->deck[pNum][i]);
  }
  for (i = 0; i < state->discardCount[pNum]; i++) {
    printf("PRETEST: DISCARD CARD=%d\n", state->discard[pNum][i]);
  } */

  // make copy of gamestate
  struct gameState* copy = malloc(sizeof(struct gameState));
  memcpy(copy, state, sizeof(struct gameState));

  // use adventurer card for player 2 (index 1)
  //int r = adventurerCardEffect(1, state);
  adventurerCardEffect(state, 1); // refactored to match Kelby's function call

  // -------------------------------------------------------------------------------------
  // REQT: FUNCTION SUCCESSFULLY COMPLETES
  // -------------------------------------------------------------------------------------
  
  /*
  if (r == 0) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CARD EXECUTION\n");
  */

  // -------------------------------------------------------------------------------------
  // REQT: CURRENT PLAYER SHOULD REC'V 2 TOTAL CARDS, BUT ADVENTURER TO BE DISCARDED, NET 1
  // -------------------------------------------------------------------------------------
  int before = copy->handCount[pNum];
  int after = state->handCount[pNum];
  if (after - before == 1) { // TOTAL CARDS
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS +1 CARDS\n");

  // -------------------------------------------------------------------------------------
  // REQT: BOTH CARDS REC'VD BY CURRENT PLAYER SHOULD BE TREASURE CARDS
  // -------------------------------------------------------------------------------------
  before = 0;
  after = 0;
  int card;
  for (i = 0; i < copy->handCount[pNum]; i++) {
	card = copy->hand[pNum][i];
    if (card >= 4 && card <= 6) {
      before++;
	}
  }
  for (i = 0; i < state->handCount[pNum]; i++) {
	card = state->hand[pNum][i];
    if (card >= 4 && card <= 6) {
      after++;
	}
  }  if (after - before == 2) { // TREASURE CARDS
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER TREASURE CARDS IN HAND WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS +2 TREASURE CARDS\n");

  // -------------------------------------------------------------------------------------
  // REQT: 2 CARDS SHOULD COME FROM HIS OWN PILE, BUT ADVENTURER WILL BE ADDED BACK TO THE DISCARD, NET -1
  // -------------------------------------------------------------------------------------
  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (before - after == 1) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: CURRENT PLAYER CARDS IN DECK/DISCARD WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS -1 CARDS\n");

  // -------------------------------------------------------------------------------------
  // REQT: NO STATE CHANGE FOR OTHER PLAYER (player 1, index 0)
  // -------------------------------------------------------------------------------------
  pNum = 0;
  before = copy->handCount[pNum];
  after = state->handCount[pNum];
  if (after == before) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN HAND WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS NO CHANGE\n");

  before = copy->discardCount[pNum] + copy->deckCount[pNum];
  after = state->discardCount[pNum] + state->deckCount[pNum];
  if (after == before) {
    printf("PASS");
  }
  else {
    printf("FAIL");
  }
  printf("ED: OTHER PLAYER CARDS IN DECK/DISCARD WENT FROM %d TO %d\n", before, after);
  printf("        EXPECTATION IS NO CHANGE\n");

  // -------------------------------------------------------------------------------------
  // REQT: NO STATE CHANGE FOR VICTORY CARD PILE
  // -------------------------------------------------------------------------------------
  int changed = -1;
  for (i = 1; i <= 3; i++) {
    before = copy->supplyCount[i];
    after = state->supplyCount[i];
    if (before != after) {
      changed = 0;
      break;
    }
  }
  if (changed == -1) {
    printf("PASSED: NO CHANGE TO VICTORY CARD PILE\n");
  }
  else {
    printf("FAILED: VICTORY CARD PILE CHANGED\n");
  }
  printf("        EXPECTATION IS NO CHANGE\n");

  // -------------------------------------------------------------------------------------
  // REQT: NO STATE CHANGE FOR KINGDOM CARD PILE
  // -------------------------------------------------------------------------------------
  changed = -1;
  for (i = 7; i <= 26; i++) {
    before = copy->supplyCount[i];
    after = state->supplyCount[i];
    if (before != after) {
      changed = 0;
      break;
    }
  }
  if (changed == -1) {
    printf("PASSED: NO CHANGE TO KINGDOM CARD PILE\n");
  }
  else {
    printf("FAILED: KINGDOM CARD PILE CHANGED\n");
  }
  printf("        EXPECTATION IS NO CHANGE\n");

  // clean up
  printf("--------------------\n");
  free(state);
  free(copy);
  return 0;
}

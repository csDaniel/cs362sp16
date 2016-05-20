#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//This is a unit test for the Card Smithy.
//1. Adds 3 cards to the current player's hand.
//2. The 3 cards have to come from the player's deck.
//3. Other players state must be unchanged. 
//4. No state change should occur to the victory and kingdom card piles. 
int main () {

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState expected, actual;
  int numPlayers = 2;
  int seed = 500;
  int player = 1;  
  int handpos = 0;


  initializeGame(numPlayers, k, seed, &actual);
  actual.hand[player][0] = smithy;  
  actual.whoseTurn = player;
  actual.handCount[player] = 1;
  //Copy the game state to the post game state test case.
  memcpy(&expected, &actual, sizeof(struct gameState));
  assert(memcmp(&actual, &expected, sizeof(struct gameState)) == 0);
  printf("Both PRE & POST GAME STATES ARE EQUIVALENT before calling the function.\n");
  printf("Actual Deck Count Before Calling the Function: %i\n", actual.deckCount[player]);
  printf("Actual Hand Count Before Calling the Function: %i\n", actual.handCount[player]);
  //Set up the Expected Results.
  int discardedSmithy = 1;
  int newCards = 3;
  int bonus = 0;

  if( smithy_card(player, &actual, handpos, &bonus) == 0){
	printf("The smithy card was called successfully.\n");
  }else{
	printf("The smithy card failed to be called.i\n");
  }

  //Set up Expected Results.
  expected.deckCount[player] -= newCards;
  expected.handCount[player] = expected.handCount[player] - discardedSmithy + newCards;

  assert( actual.hand[player][handpos] != smithy );
  printf("The smithy card was discarded.");

 //smithyCard(currentplayer, &actual, handPos);  
  //1. +3 cards to the current player's hand. 
  printf( "Actual Deck Count: %i Expected Deck Count: %i\n", actual.deckCount[player], expected.deckCount[player]);
  assert( actual.deckCount[player] == expected.deckCount[player]);
  printf("The cards were drawn from the player's own deck.\n");
 
 //2. +3 cards -1 Discarded Smithy Card.
  printf("Actual Hand Count: %i Expected Hand Count: %i", actual.handCount[player], expected.handCount[player]); 
  assert( actual.handCount[player] == expected.handCount[player]); 
  printf("The player's hand count matched before and after the call to the function.\n");
  assert( actual.hand[player][handpos] != smithy );
  printf("The smithy card was discarded.");

 
  return 0;
}




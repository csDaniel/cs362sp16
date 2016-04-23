/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* cardtest2.c
* Lauren Crees
* Description: Tests the card adventurer.
* * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main()
{
	int seed = 1000;
  int numPlayers = 2;
  int player = 0;
  int z = 0;
  int drawntreasure = 0;
  int cardDrawn = 0;
  int temphand[MAX_HAND];
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
  struct gameState G, testG;

  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));

	printf("* * * * * * * * * * Testing adventurer * * * * * * * * * *\n");

	printf("Test 1: Player's hand should have two more cards\n");
	int cardsHandBefore = testG.handCount[player];
	adventurerEffect(drawntreasure, &testG, player, cardDrawn, z, temphand);
	assert(testG.handCount[player] == (cardsHandBefore + 2));

	printf("Test 2: Deck should have less cards\n");
	assert(testG.deckCount[player] < G.deckCount[player]);

	printf("Test 3: Discard should be same or have more cards\n");
	assert(testG.discardCount[player] >= G.discardCount[player]);

	printf("Test 4: Discard + 2 = difference in deck amount\n");
	assert(testG.deckCount[player] == (G.deckCount[player] - (testG.discardCount[player] + 2)));

	printf("Test 5: Other players should be in same state as before\n");
	player = 1;
	printf("Hand Count is same\n");
	assert(testG.handCount[player] == G.handCount[player]);
	int j;
	printf("Hand is same\n");
	for (j = 0; j < G.handCount[player]; j++)
		assert(testG.hand[player][j] == G.hand[player][j]);
	printf("Deck Count is same\n");
	assert(testG.deckCount[player] == G.deckCount[player]);
	printf("Deck is same\n");
	for (j = 0; j < G.deckCount[player]; j++)
		assert(testG.deck[player][j] == G.deck[player][j]);
	printf("Discard Count is same\n");
	assert(testG.discardCount[player] == G.discardCount[player]);
	printf("Discard is same\n");
	for (j = 0; j < G.discardCount[player]; j++)
		assert(testG.discard[player][j] == G.discard[player][j]);

	printf("Success! Tests for adventurer pass!\n");

	return 0;
}
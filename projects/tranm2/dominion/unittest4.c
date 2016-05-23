/*
 * unittest4.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> 
#include <stdlib.h>
#include <stdbool.h>

#define TESTFUNC "gainCard"
#define DISCARD 0
#define DECK 1 
#define HAND 2 

int main() 
{
    int thisPlayer = 0;
    int card;
    srand(time(NULL));
    int seed = (rand()%500)+500;
    int numPlayers = 2;
	struct gameState G, testG;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Function: %s ----------------\n", TESTFUNC);

		// ----------- TEST 1 - Not enough card to draw, add to discard --------------
	printf("\nTEST 1: supplyCount = 0, toFlag = 0 \n");
	card = k[rand()%10];
	G.supplyCount[card] = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, DISCARD, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

		// ----------- TEST 2 - Not enough card to draw, add to deck --------------
	printf("\nTEST 2: supplyCount = 0, toFlag = 1 \n");
	card = k[rand()%10];
	G.supplyCount[card] = 0;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, DECK, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

		// ----------- TEST 3 - Not enough card to draw, add to hand --------------
	printf("\nTEST 3: supplyCount = 0, toFlag = 2 \n");
	card = k[rand()%10];
	G.supplyCount[card] = 0;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, HAND, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

		// ----------- TEST 4 - Enough card to draw, add to discard --------------
	printf("\nTEST 4: supplyCount > 0, toFlag = 0 \n");
	card = k[rand()%10];
	G.supplyCount[card] = (rand()%10)+1;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, DISCARD, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]+1);

		// ----------- TEST 5 - Enough card to draw, add to deck --------------
	printf("\nTEST 5: supplyCount > 0, toFlag = 1 \n");
	card = k[rand()%10];
	G.supplyCount[card] = (rand()%10)+1;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, DECK, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]+1);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]+1);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

		// ----------- TEST 6 - Enough card to draw, add to hand --------------
	printf("\nTEST 6: supplyCount > 0, toFlag = 2 \n");
	card = k[rand()%10];
	G.supplyCount[card] = (rand()%10)+1;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);

	gainCard(card, &testG, HAND, thisPlayer);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]+1);
	printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]+1);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);

	return 0;
}



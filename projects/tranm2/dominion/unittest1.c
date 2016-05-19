/*
 * unittest1.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> 
#include <stdlib.h>

#define TESTFUNC "buyCard"
#define MAX_COINS 15
#define ITERATION 5

int main() 
{
    int newCards = 0;
    int discarded = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int cardBought, counter;

    srand(time(NULL));
    int seed = (rand()%500)+500;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNC);

	// ----------- TEST 1: Not enough buy --------------
	printf("\nTEST 1: Not enough buy - buy=0, coins=MAX_COINS, arbitrary card\n");

	// copy the game state to a test case
	G.coins = MAX_COINS;
	G.numBuys = 0;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);

	buyCard(k[rand()%10], &testG);

	printf("-AFTER\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
	assert(testG.coins == G.coins);

	// ----------- TEST 2: card not available --------------
	printf("\nTEST 2: Not enough buy - buy=1, coins=MAX_COINS, card not available\n");

	// copy the game state to a test case
	G.coins = MAX_COINS;
	G.numBuys = 1;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);

	cardBought = k[rand()%10];
	testG.supplyCount[cardBought] = 0;
	buyCard(cardBought, &testG);

	printf("-AFTER\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
	assert(testG.coins == G.coins);

	// ----------- TEST 3: card not available --------------
	printf("\nTEST 3: Not enough coin - buy=1, coins=0, random\n");

	// copy the game state to a test case
	G.coins = 0;
	G.numBuys = 1;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);

	cardBought = k[rand()%10];
	buyCard(cardBought, &testG);

	printf("-AFTER\n");
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);
	assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
	assert(testG.coins == G.coins);

	// ----------- TEST 4: random testing --------------
	printf("\nTEST 4: Random Testing\n");

	// copy the game state to a test case
	G.coins = rand()%(MAX_COINS+3); // 3 to 15
	G.numBuys = rand()%5 + 1;	// 1 or 5
	memcpy(&testG, &G, sizeof(struct gameState));
	counter = ITERATION;

	while (counter > 0 && testG.coins >= 3)
	{
		printf("-BEFORE\n");
		printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
		printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
		printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);

		cardBought = k[rand()%10];
		if (buyCard(cardBought, &testG) == 0)
		{
			G.discardCount[thisPlayer] += 1;
			G.coins -= getCost(cardBought);
			G.numBuys -= 1;
			printf("Bought (%d)\n",cardBought);
		}

		printf("-AFTER\n");
		printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] - newCards + shuffledCards);
		printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
		printf("Buy avail = %d, expected = %d\n", testG.numBuys, G.numBuys);
		assert(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer]);
		assert(testG.coins == G.coins);
		assert(testG.numBuys == G.numBuys);		
		counter -= 1;
	}


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);


	return 0;
}



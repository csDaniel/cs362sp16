/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Assignement 3
 * Description: cardtest1 - adventurer
 * *******************************************************************************************/

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "embargo"

int main() {
    int newCards = 0;
	int discarded = 0;
	int newTreasureCards = 0;
	int newActions = 0;
	int newCoins = 0;
    int xtraCoins = 0;
    int shuffledCards = 0;
	int newEmbargoTokens = 1;
    int i, j, m;
    int handpos = 5, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	//smithy = line 831
	printf("TEST: +2 coins\n"); 
	printf("TEST: +1 embargo tokens\n"); 
	newCards = 0;
	discarded = 1;
	newCoins = 2;
	int before_treasureCardCount = 0,
		after_treasureCardCount = 0;
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	gainCard(embargo, &testG, 2, thisPlayer);
	choice1 = 1;
	printf("\nBefore:[");
	for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
	{
		printf("card=%d; ", testG.hand[thisPlayer][x]);
		if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
			before_treasureCardCount++;
	}
	printf("]\n");
	int before_handCount = testG.handCount[thisPlayer];
	int before_discardCount = testG.discardCount[thisPlayer];
	int before_deckCount = testG.deckCount[thisPlayer];
	int before_actions = testG.numActions;
	int before_coins = testG.coins;
	int before_embargoTokens = testG.embargoTokens[choice1];
	cardEffect(embargo, choice1, choice2, choice3, &testG, handpos, &bonus);
	int after_embargoTokens = testG.embargoTokens[choice1];
	int after_coins = testG.coins;
	int after_actions = testG.numActions;
	int after_handCount = testG.handCount[thisPlayer];
	int after_discardCount = testG.discardCount[thisPlayer];
	int after_deckCount = testG.deckCount[thisPlayer];
	printf("After:[");
	for(int x = 0; x<testG.handCount[thisPlayer]; x++ )
	{
		printf("card=%d; ", testG.hand[thisPlayer][x]);
		if(testG.hand[thisPlayer][x] == 4 || testG.hand[thisPlayer][x] == 5 || testG.hand[thisPlayer][x] == 6)
			after_treasureCardCount++;
	}
	printf("]\n");
	//test actions
	printf("\naction count before=%d; action count after=%d; expected=%d ", before_actions, after_actions, before_actions + newActions);
	if(after_actions == (before_actions + newActions))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	//test hand count
	printf("hand count before=%d; hand count after=%d; expected=%d ", before_handCount, after_handCount,before_handCount + newCards - discarded);
	if(after_handCount == (before_handCount + newCards - discarded))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	//test coins
	printf("coin count before=%d; coin count after=%d; expected=%d ", before_coins, after_coins, before_coins + newCoins );
	if(after_coins == (before_coins + newCoins))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	//embargo tokens
	printf("embargo tokens count before=%d; embargo tokens count after=%d; expected=%d ", before_embargoTokens, after_embargoTokens, before_embargoTokens + newEmbargoTokens);
	if(after_embargoTokens == (before_embargoTokens + newEmbargoTokens))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	//test hand count
	printf("discount count before=%d; discount count after=%d; expected=%d ", before_discardCount, after_discardCount, before_discardCount + discarded);
	if(after_discardCount == (before_discardCount + 1))
		printf("PASSED\n");
	else
		printf("FAILED\n");
	
	printf("\Discarded:[");
	for(int x = 0; x<testG.discardCount[thisPlayer]; x++ )
	{
		printf("card=%d; ", testG.discard[thisPlayer][x]);
	}
	printf("]\n");
	//test treasure count
	printf("treaure card count before =%d; treaure card count after=%d; expected=%d ", before_treasureCardCount, 
		after_treasureCardCount, before_treasureCardCount + newTreasureCards);
	if(after_treasureCardCount == (before_treasureCardCount + newTreasureCards))
		printf("PASSED\n");
	else
		printf("FAILED\n");

	
	
	printf("\nTesting complete.\n");
	return 0;
}


/*
Behnam Saeedi
Saeedib
93227697
Unit test
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define UNITTEST "Adventurer"

int main(int argc, char ** argv)
{
	srand(time(NULL));
	//Generating player:
	int out;
	int seed = 1000;
	for(int counter = 0; counter < 1000; counter++)
	{
		int numPlayers = rand() % 4 + 1;
		int thisPlayer = 0;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		// generating a random state
		memcpy(&testG, &G, sizeof(struct gameState));
		int count;
		count = testG.handCount[thisPlayer];
		for(int i = 0; i < count; i++)
			testG.hand[thisPlayer][i] = estate;
		for(int i = 0; i < 25; i++)
			testG.supplyCount[i] = 10;
		testG.hand[thisPlayer][0] = gold;	//3
		testG.hand[thisPlayer][1] = silver;	//2
		testG.hand[thisPlayer][2] = copper;	//1
		testG.hand[thisPlayer][2] = rand() % 10;
		testG.supplyCount[province] = rand() % 5 + 1;

		printf("\n\nTesting card: %s\n\n", UNITTEST);


		printf("Test 1: Checking the function.\n");
		updateCoins(thisPlayer,&testG,0);
		out = testG.coins;
		printf("This should return Adventurer new coins in card: %d (should be 5)\n",out);
		if(out != 5)
			printf("Failed! Miss trigger on Copper, silver or gold cars ** count is %d.\n", out);
		out = getCost(adventurer);
		assert(out == 6);
		//play_adventurer(currentPlayer, state, drawntreasure, cardDrawn, temphand, z)
		out = play_adventurer(thisPlayer,&testG,0,0,&G.hand,0);
		out = getCost(adventurer);
		assert(out == 6);
		printf("This should return the value of Adventurer card: %d\n",out);
		out = updateCoins(thisPlayer,&testG,0);
		out = testG.coins;
		printf("This should return Adventurer new coins in card: %d (should be 7)\n",out);
		//assert(out == 8);
	//	printf("Test 1 Passed\n");
	}
	return 0;	//No bugs found
}

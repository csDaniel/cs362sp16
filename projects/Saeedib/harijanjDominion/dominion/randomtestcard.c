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

#define UNITTEST "Smithy"

int main(int argc, char ** argv)
{
	srand(time(NULL));
	int out;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	int count;
	struct gameState G, testG;

	//Generating player:
	for(int counter = 0; counter < 1000; counter++)
	{
		int numPlayers = rand() % 4 + 1;
		int thisPlayer = rand() % 4;
		int seed = rand() % 500 + 500;

		initializeGame(numPlayers, k, seed, &G);

		memcpy(&testG, &G, sizeof(struct gameState));
		count = G.handCount[thisPlayer];
		count = testG.handCount[thisPlayer];
		printf("Hand count for testG is: %d.\n",count);

		for(int i = 0; i < count; i++)
			testG.hand[thisPlayer][i] = estate;
		for(int i = 0; i < 25; i++)
			testG.supplyCount[i] = 10;

		G.hand[thisPlayer][0] = gold;
		G.hand[thisPlayer][1] = silver;
		G.hand[thisPlayer][2] = copper;
		G.discardCount[thisPlayer] = 0;
		testG.hand[thisPlayer][0] = gold;
		testG.hand[thisPlayer][1] = silver;
		testG.hand[thisPlayer][2] = copper;
		testG.discardCount[thisPlayer] = 0;

		smithyCard(&testG, rand() % 4);
		out = getCost(smithy);
		printf("smithy function should return cost of smithy card : %d.\n",out);
		assert(out==4);
		printf("New Hand count is: %d. it should be %d\n",testG.handCount[thisPlayer],G.handCount[thisPlayer] + 2);
		printf("Discard count is: %d.\n",testG.discardCount[thisPlayer]);
	}
	return 0;
}

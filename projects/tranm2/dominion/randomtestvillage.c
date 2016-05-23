/*
 * randomtestvillage.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestvillage.out: randomtestvillage.c dominion.o rngs.o
 *      gcc -o randomtestvillage.out -g  randomtestvillage.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

#define TESTCARD "village"
#define ITERATION 4


int main()
{
	struct gameState G, testG;
	int x, handPos;
	int thisPlayer;//=0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  	srand(time(NULL));
  	printf ("Starting tested game.\n");
  	
  	initializeGame(MAX_PLAYERS, k, rand()%500+500, &G);

	for (x=0; x<ITERATION; x++)
	{
		srand(x+time(NULL)+5);
		thisPlayer = 0;
		handPos = rand()%5;
		G.hand[thisPlayer][handPos] = village;

		printf("------ Testing Card: %s - Test %d -------\n", TESTCARD, x+1);
		//thisPlayer = x;
		printf ("Player %d played %s.\n", thisPlayer, TESTCARD);

		memcpy(&testG, &G, sizeof(struct gameState));

		cardEffect(village,0,0,0, &testG, handPos,0);

		//compare. note: village goes to discard right after being played
		printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]); 
		printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]-1); 
		printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1); 
		printf("Action count = %d, expected = %d\n", testG.numActions, G.numActions+2); 

		if (testG.handCount[thisPlayer] != G.handCount[thisPlayer]) 
			printf("FAILED - Incorrect hand count!\n");
		if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer]-1)
			printf("FAILED - Incorrect deck count!\n");
		if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer]+1)	
			printf("FAILED - Incorrect discard count!\n");
		if (testG.numActions != (G.numActions+2)) 
			printf("FAILED - Invalid action count\n");
	}
	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}
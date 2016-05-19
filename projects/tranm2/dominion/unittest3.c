/*
 * unittest3.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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

#define TESTFUNC "shuffle"
#define ITERATION 5
#define MAX_CARD 10

int main() 
{
    int thisPlayer = 0;
    int i, j;
    bool passed = true;
    srand(time(NULL));
    int seed = (rand()%500)+500;
    int numPlayers = 2;
	struct gameState G, testG;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Function: %s ----------------\n", TESTFUNC);

	// ----------- TEST 3: choice1 = 3 = trash two cards --------------
	//set deckCount
	G.deckCount[thisPlayer] = MAX_CARD;
	printf("Deck Starting State:\n");
	//Randomly fill deck G
	for (i=0; i<MAX_CARD; i++)
	{
		G.deck[thisPlayer][i] = k[rand()%10];
		printf("%d - (%d)\n", i, G.deck[thisPlayer][i]);
	}

	for(j=0; j<ITERATION; j++)
	{
		//---loop
		printf("\nIteration %d starting..\n",j);
		//copy deck G to testG
		memcpy(&testG, &G, sizeof(struct gameState));
		//shuffle deck testG
		printf("Shuffling deck\n");
		shuffle(thisPlayer, &testG);
		//compare deck testG with G
		printf("Compare deck state with the previous\n");
		for (i=0; i<MAX_CARD; i++)
		{
			//printf("%d - (%d)\t(%d)\n", i, G.deck[thisPlayer][i], testG.deck[thisPlayer][i]);
			//assert(memcmp(testG.deck[thisPlayer], G.deck[thisPlayer], sizeof(MAX_CARD)) != 0);
			if(testG.deck[thisPlayer][i] != G.deck[thisPlayer][i])
			{
				passed = true;
				break;	
			}
			else
				passed = false;
		}
		assert(passed);
		printf("PASSED.\n");
		//copy deck testG to G
		memcpy(&G, &testG, sizeof(struct gameState));
		//---end loop		
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);


	return 0;
}



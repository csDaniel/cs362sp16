/*
 * unittest2.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> 
#include <stdlib.h>

#define TESTFUNC "playCard"

int main() 
{

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int thisPlayer = 0;

    srand(time(NULL));
    int seed = (rand()%500)+500;
    int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Function: %s ----------------\n", TESTFUNC);

	// ----------- TEST 1 --------------
	printf("\nTEST 1: numActions = 0\n");
	G.hand[thisPlayer][handpos] = k[rand()%10];
	// copy the game state to a test case
	G.numActions = 0;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);

	playCard(handpos, choice1, choice2, choice3, &testG);

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);
	assert(testG.numActions == G.numActions);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	// ----------- TEST 2: 1 action point available --------------
	printf("\nTEST 2: numActions = 1\n");
	G.hand[thisPlayer][handpos] = k[rand()%10];
	// copy the game state to a test case
	G.numActions = 1;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);

	if(playCard(handpos, choice1, choice2, choice3, &testG) == 0)
	{
		printf("Played (%d)\n",G.hand[thisPlayer][handpos]);
		cardEffect(G.hand[thisPlayer][handpos], choice1, choice2, choice3, &G, handpos, &bonus);
		//G.handCount[thisPlayer]--;
		G.numActions--;
	}

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);
	assert(testG.numActions == G.numActions);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	// ----------- TEST 3: 1+ action point available --------------
	printf("\nTEST 3: numActions > 1\n");
	G.hand[thisPlayer][handpos] = k[rand()%10];
	// copy the game state to a test case
	G.numActions = rand()%10 + 2;
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("-BEFORE\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);

	if(playCard(handpos, choice1, choice2, choice3, &testG) == 0)
	{
		printf("Played (%d)\n",G.hand[thisPlayer][handpos]);
		cardEffect(G.hand[thisPlayer][handpos], choice1, choice2, choice3, &G, handpos, &bonus);
		//G.handCount[thisPlayer]--;
		G.numActions--;
	}

	printf("-AFTER\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("Action avail = %d, expected = %d\n", testG.numActions, G.numActions);
	assert(testG.numActions == G.numActions);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);

	
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNC);


	return 0;
}



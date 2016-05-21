/*
 * cardtest2.c
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h> 

#define TESTCARD "smithy"
#define CUR_DECK 10
#define ITERATIONS 10

int main() {

    int i=0,j=0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    
    int seed = (rand()%500)+500;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	srand(time(NULL));
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for(j=0; j<ITERATIONS; j++)
	{
		printf("Iteration %d Test\n",j);
		// setup deck - discard - hand pile
		G.deckCount[thisPlayer] = CUR_DECK;
		G.discardCount[thisPlayer] = 0;
		printf("Deck Content: \n");
		for (i=0; i<CUR_DECK; i++)
		{
			G.deck[thisPlayer][i] = k[rand()%10]; // randomly fill up deck
			printf("(%d) ", G.deck[thisPlayer][i]);
		}
		// prepare hand
		G.hand[thisPlayer][handpos] = smithy;

		// print hand
		printf("\nHand Content:\n");
		printf("-BEFORE\n");
		for (i=0; i<G.handCount[thisPlayer]; i++)
			printf("(%d) ", G.hand[thisPlayer][i]);
		printf("\n");

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		// play smithy
		cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

		printf("-AFTER\n");
		// check hand
		for (i=0; i<testG.handCount[thisPlayer]; i++)
			printf("(%d) ", testG.hand[thisPlayer][i]);

		printf("\nHand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]+2); 
		printf("Deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]-3); 
		printf("Discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+1); 
		if (testG.handCount[thisPlayer] != G.handCount[thisPlayer]+2) 
			printf("FAILED - Incorrect hand count!\n");
		if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer]-3)
			printf("FAILED - Incorrect deck count!\n");
		if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer]+1)		
			printf("FAILED - Incorrect discard count!\n\n");
	}
	
	printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}



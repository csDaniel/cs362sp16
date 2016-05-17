/*
 * randomtestadventurer.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer.out -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "adventurer"
#define ITERATION 4


int main()
{
	struct gameState G, testG;
	int i,x;
	int thisPlayer=0, discard_cards, xtra_coins;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
  	srand(time(NULL));
  	printf ("Starting tested game.\n");
  	
  	initializeGame(MAX_PLAYERS, k, rand()%500+500, &G);
	
	for (x=0; x<ITERATION; x++)
	{
		discard_cards=0;
		xtra_coins=0;
		printf("------ Testing Card: %s - Test %d -------\n", TESTCARD, x+1);
		thisPlayer = x;
		printf ("Player %d played %s.\n", thisPlayer, TESTCARD);

		//get deck content
		printf("Deck Content Before: \n");
		for (i=0; i<G.deckCount[thisPlayer]; i++)
			printf("(%d) ", G.deck[thisPlayer][i]);
		printf("\n");

		//cond before adventurer
		updateCoins(thisPlayer, &G, 0);
		memcpy(&testG, &G, sizeof(struct gameState));
		//printf("coins-%d\n",G.coins);
		//play adventurer
		adventurer_effect(thisPlayer, &testG);

		//cond after adventurer
		discard_cards = G.deckCount[thisPlayer] - testG.deckCount[thisPlayer];
		
		printf("Deck Content After: \n");
		for (i=0; i<testG.deckCount[thisPlayer]; i++)
			printf("(%d) ", testG.deck[thisPlayer][i]);
		printf("\n");

		//Get the difference in extra coins and discarded cards
		for (i=testG.deckCount[thisPlayer]; i<G.deckCount[thisPlayer]; i++)
		{
			if (G.deck[thisPlayer][i] == gold)
			{
				xtra_coins += 3;
				discard_cards -=1;
			}
			else if (G.deck[thisPlayer][i] == silver)
			{
				xtra_coins += 2;
				discard_cards -=1;
			}
			else if (G.deck[thisPlayer][i] == copper)
			{
				xtra_coins += 1;
				discard_cards -=1;
			}
			//printf("dcard=%d ,coins=%d\n", discard_cards, xtra_coins);
		}
		
		discard_cards += 1; //plus 1 for adventurer card

		//compare
		updateCoins(thisPlayer, &testG, 0);
		printf("Coins count = %d, expected = %d\n", testG.coins, G.coins+xtra_coins); 
		printf("Discarded count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+discard_cards); 

		if (testG.coins != (G.coins + xtra_coins)) 
			printf("FAILED - Invalid coin count\n");
		if (testG.discardCount[thisPlayer] != (G.discardCount[thisPlayer]+discard_cards)) 
			printf("FAILED - Invalid discarded card count\n");

	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}
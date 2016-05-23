//test for numHandCount

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, discardCount, deckCount, numHand, handPos;
    int score;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

	//memset(&G, 23, sizeof(struct gameState));   // clear the game state
	//r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	for (p = 0; p < numPlayer; p++)
    {
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
		G.handCount[p] = 5;
		for (handCount = 5; handCount >= 0; handCount--) //iterate desired hand number for player
        {
			
			if (handCount < 5)
			{
			discardCard(handPos, p, &G, 0);
			}
			numHand = G.handCount[p];
			printf("Test player %d with %d card(s) in hand \n", p, handCount);
			printf("Function returns %d expecting %d card(s) in hand \n", numHand, handCount);
			assert(handCount == numHand);
			
		}
		

	//memset(&G, 23, sizeof(struct gameState));   // clear the game state
	//r = initializeGame(numPlayer, k, seed, &G); // initialize a new game	
	}
printf("All tests passed!\n");	
return 0; }

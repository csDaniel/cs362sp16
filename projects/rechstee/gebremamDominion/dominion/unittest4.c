//test for whoseTurn

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
    int numPlayer = 4;
    int p, r, handCount, discardCount, deckCount, turn;
    int score;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	for (i = 0; i < numPlayer; i++)
	{
	turn = whoseTurn(&G);
	printf("Test player %d 's turn should be the turn #: %d \n", i, turn);
	assert(i == turn);
	endTurn(&G);
	}
	}


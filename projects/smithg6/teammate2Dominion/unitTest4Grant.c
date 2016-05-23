#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#include <math.h>


int main()
{
	printf("Testing the isGameOver function\n");
	int seed = 10;
	int numPlayer = 2;

	

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	struct gameState game;

	int i, l, j, p, r, handCount;

	memset(&game, 23, sizeof(struct gameState));

	p = 0;
	int cardNum;
	handCount = 2;

	//initialize a new game
	r = initializeGame(numPlayer, k, seed, &game);
		game.handCount[p] = handCount;


	if(r == -1)
	{
		exit(0);
	}


	//set stack of province card value == 0
	game.supplyCount[province] = 0;
	i = isGameOver(&game);

	if(i == 1)
	{
		printf("Game is over, test was successful.\n");
	}

	//set stack of province cards to be negative, expect an error
	game.supplyCount[province] = -5;
	j = isGameOver(&game);

	if(j == 1)
	{
		printf("Test passed, game recognized corrupted state and ended game.\n");
	}
	

	//Test that acceptable province value does not end game
	game.supplyCount[province] = 4;
	l = isGameOver(&game);

	if(l == 0)
	{
		printf("Test passed on acceptable value, game is not over.\n");
	}

	return 0;
}
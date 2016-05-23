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
	printf("Testing the getCost function");
	int seed = 10;
	int numPlayer = 2;

	

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	struct gameState game;

	int i, j, p, r, handCount;

	memset(&game, 23, sizeof(struct gameState));


	p = 1;
	int cardNum;
	handCount = 2;

	//initialize a new game
	r = initializeGame(numPlayer, k, seed, &game);
		game.handCount[p] = handCount;


	if(r == -1)
	{
		exit(0);
	}

	//This is a test to make sure that the cost of adventurer is correctly returned.
	cardNum = 7;
	i = getCost(cardNum);

	if(i != 6)
	{
		printf("Something went wrong! Adventurer should cost 6.\n");
	}

	if(i == 6)
	{
		printf("This test passed: Return values are appropriate\n");	
	}


	//This is a test to see if a corrupted card value will succeed or fail
	cardNum = 48;
	j = getCost(cardNum);

	if(j)
	{
		printf("This test passed. \ngetCost returned a default value %d for a card that doesn't exist\n", j);
	} else
		{
			printf("This test failed and returned a valid value for an invalid card.\n");	
		}
	return 0;
}
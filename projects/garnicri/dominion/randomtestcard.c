#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
	time_t curSeed = time(NULL);
	srand((unsigned int)curSeed);
	int result = 1;
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int p, r, handCount;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState game;
	
	// arrays of all village cards
	int village[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		village[i] = village;
	}

	printf("\n Beginning testing for card rc_Village with the random seed number of: %d\n", (unsigned int)curSeed);
	//randomly assigned number of tests to run 
	while (result < 1000) {
		//randomized number of players out of max players +2 incase of 0
		numPlayer = rand() % (MAX_PLAYERS - 2) + 2;
		p = rand() % numPlayer;
		//random hand count - number of cards in hand 
		handCount = rand() % 9 + 2;

		printf("Test #%d: %d players, player %d playing village card, hand size: %d\n", result, numPlayer, p, handCount);

		memset(&game, 23, sizeof(struct gameState));   
		r = initializeGame(numPlayer, k, seed, &game); 
		game.whoseTurn = p;
		game.handCount[p] = handCount;
		memcpy(game.hand[p], village, sizeof(int) * handCount);

		r = playCard(0, 0, 0, 0, &game);

		//testing number of actions.  this feature is disabled so instead of picking up 2 more actions, the
		//number of actions stays the same each time
		printf("game.actions = %d, should be = %d\n", game.numActions, game.numActions + 2);
		
		//testing number of cards.  The current card is never disabled, therefore the handcount never changes
		//by decreasing in size by one card
		printf("game.handCount = %d, should be = %d\n", game.handCount[p], game.handCount[p] - 1);

		if (game.numActions < 3 && game.handCount[p] == handCount) {
			printf("The village card worked correctly\n");
			result++;
		}
		else {
			printf("The village card did not work correctly\n");
			result++;
		}
	}

	return 0;
}
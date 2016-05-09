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
	
	// arrays of all adventurers
	int adven[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		adven[i] = adventurer;
	}

	printf("\n Beginning testing for card rc_Adventurer with the random seed number of: %d\n", (unsigned int)curSeed);
	//randomly assigned number of tests to run 
	while (result < 1000) {
		//randomized number of players out of max players +2 incase of 0
		numPlayer = rand() % (MAX_PLAYERS - 2) + 2;
		p = rand() % numPlayer;
		//random hand count - number of cards in hand 
		handCount = rand() % 9 + 2;

		printf("Test #%d: %d players, player %d playing adventurer card, hand size: %d\n", result, numPlayer, p, handCount);

		memset(&game, 23, sizeof(struct gameState));   
		r = initializeGame(numPlayer, k, seed, &game); 
		game.whoseTurn = p;
		game.handCount[p] = handCount;
		memcpy(game.hand[p], adven, sizeof(int) * handCount);

		r = playCard(0, 0, 0, 0, &game);

		printf("Test if gold card issued for hand: %d\n", game.handCount[p]);
		
		//loop through cards in current players hand to make sure no gold cards exist
		int i = 0;
		for (i = 0; i < game.handCount[p]; i++){
			if (game.hand[p][i] == gold) {
				printf("The adventure card did not work correctly.  Gold card issued.\n");
				result++;
			}
			else{
				printf("The adventure card worked correctly.  Gold card not issued.\n");
				result++;
			}
		}
		
	}

	return 0;
}
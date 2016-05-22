#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


int myAssert(int statement) {
	if (statement != 0) {
		printf("RESULT: PASSED\n");
		return 0;
	}
	else {
		printf("RESULT: FAILED\n");
		return 1;
	}
}

int checkCouncilRoom(struct gameState *game, int thisPlayer) {
	int r, i, numFails = 0, deckCountBefore;
	struct gameState testGame;
	game->whoseTurn = thisPlayer;

	deckCountBefore = game->deckCount[thisPlayer];

	memcpy(&testGame, game, sizeof(struct gameState));

	r = cardEffect(council_room, 0, 0, 0, game, 0, 0);
	printf("Checking that cardEffect returns 0:\n");

	numFails += myAssert(r == 0);


	printf("Checking handCount:\n");
	numFails += myAssert(game->handCount[thisPlayer] == testGame.handCount[thisPlayer] + 3);

	printf("deckCount now = %d\n", game->deckCount[thisPlayer]);


	if (deckCountBefore >= 4) {
		printf("Checking deckCount:\n");
		numFails += myAssert(game->deckCount[thisPlayer] == testGame.deckCount[thisPlayer] - 4);

		printf("Checking discardCount:\n");
		numFails += myAssert(game->discardCount[thisPlayer] == testGame.discardCount[thisPlayer]);
	}
	else {
		// account for reshuffling the discard pile
		printf("Checking deckCount and discardCount:\n");
		numFails += myAssert(game->discardCount[thisPlayer] + game->deckCount[thisPlayer] == testGame.discardCount[thisPlayer] + testGame.deckCount[thisPlayer] - 4);
	}
	printf("Checking buys:\n");
	numFails += myAssert(game->numBuys == testGame.numBuys + 1);


	printf("Checking that the card has been added to played pile:\n");
	numFails += myAssert(game->playedCardCount == testGame.playedCardCount + 1);

	printf("\nTesting other players' state:\n");
	// Check other players' state
	for (i = 0; i < game->numPlayers; ++i) {
		if (i != thisPlayer) {
			printf("\nChecking Player Number %d:\n", i);

			printf("Checking handCount\n");
			numFails += myAssert(game->handCount[i] == testGame.handCount[i] + 1);

			printf("Checking deckCount\n");
			numFails += myAssert(game->deckCount[i] == testGame.deckCount[i] - 1);

			printf("Checking discardCount\n");
			numFails += myAssert(game->discardCount[i] == testGame.discardCount[i]);
		}
	}

	printf("\nTesting victory and kingdom cards:\n");
	// check that the victory and kingdom card piles are ok
	for (i = 0; i <= treasure_map; ++i){
		numFails += myAssert(game->supplyCount[i] == testGame.supplyCount[i]);
	}

	printf("Number of failures during this function call: %d\n", numFails);


	return numFails;
}



int main() {

	int n, i, j, p;

	int numFails = 0;

	struct gameState G;


	printf("Random Tester: Testing Council Room Card\n");

	srand(time(NULL));

	for (n = 0; n < 2000; ++n) {
		printf("******************************************************************\n\n");
		printf("\nTEST NUMBER %d\n\n", n + 1);

		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = rand() % 256 + 1;
		}

		G.numPlayers = 3;
		G.playedCardCount = 0;
		G.numBuys = 0;

		// generate random state for all players
		for (j = 0; j < G.numPlayers; ++j) {
			G.deckCount[j] = rand() % MAX_DECK + 1;
			G.discardCount[j] = rand() % MAX_DECK + 1;
			G.handCount[j] = rand() % MAX_HAND + 1;

			for (i = 0; i < G.deckCount[j]; ++i) {
				G.deck[j][i] = rand() % treasure_map + 1;
			}

			for (i = 0; i < G.discardCount[j]; ++i) {
				G.discard[j][i] = rand() % treasure_map + 1;
			}

			for (i = 0; i < G.handCount[j]; ++i) {
				G.hand[j][i] = rand() % treasure_map + 1;
			}
		}

		p = rand() % G.numPlayers;
		printf("Player: %d\n", p);


		numFails += checkCouncilRoom(&G, p);

	}

	printf("\nTotal Number of Failures: %d\n\n\n", numFails);


	return 0;
}
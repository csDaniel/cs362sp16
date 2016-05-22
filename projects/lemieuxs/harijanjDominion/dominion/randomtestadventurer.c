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

int checkAdventurer(struct gameState *game, int thisPlayer) {
	int r, i, treasureBefore = 0, treasureAfter = 0, adventurerFound = 0, numFails = 0;
	struct gameState testGame;

	game->whoseTurn = thisPlayer;

	memcpy(&testGame, game, sizeof(struct gameState));


	// keep track of how many treasure cards are in hand before
	for (i = 0; i < game->handCount[thisPlayer]; ++i) {
		if (game->hand[thisPlayer][i] == copper || game->hand[thisPlayer][i] == silver || game->hand[thisPlayer][i] == gold)
			treasureBefore++;
	}


	r = cardEffect(adventurer, 0, 0, 0, game, 0, 0);
	printf("Checking that cardEffect returns 0:\n");
	numFails += myAssert(r == 0);


	printf("Checking +2 treasure:\n");
	// check that there are two more treasure in hand than there were before
	for (i = 0; i < game->handCount[thisPlayer]; ++i) {
		if (game->hand[thisPlayer][i] == copper || game->hand[thisPlayer][i] == silver || game->hand[thisPlayer][i] == gold)
			treasureAfter++;
	}

	numFails += myAssert(treasureBefore + 2 == treasureAfter);


	printf("Checking discardCount and deckCount:\n");
	numFails += myAssert(game->discardCount[thisPlayer] + game->deckCount[thisPlayer] == testGame.discardCount[thisPlayer] + testGame.deckCount[thisPlayer] - 2);

	// check that the adventurer card has been added to played pile
	printf("Checking that Adventurer has been added to played pile:\n");
	for (i = 0; i < game->playedCardCount; ++i) {
		if (game->playedCards[i] == adventurer)
			adventurerFound = 1;
	}

	numFails += myAssert(adventurerFound == 1);

	printf("Checking that playedCardCount has been incremented by 1:\n");

	numFails += myAssert(game->playedCardCount == testGame.playedCardCount + 1);

	printf("\nTesting other players' state:\n");

	// check that other players' state hasn't been modified

	// Check other players' state
	for (i = 0; i < game->numPlayers; ++i) {
		if (i != thisPlayer) {
			printf("\nChecking Player Number %d:\n", i);

			printf("Checking handCount\n");
			numFails += myAssert(game->handCount[i] == testGame.handCount[i]);

			printf("Checking deckCount\n");
			numFails += myAssert(game->deckCount[i] == testGame.deckCount[i]);

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

	struct gameState G;


	int n, i, p;

	int numFails = 0;

	printf("Random Tester: Testing Adventurer Card\n");
	
	srand(time(NULL));

	for (n = 0; n < 2000; ++n) {
		printf("******************************************************************\n\n");
		printf("\nTEST NUMBER %d\n\n", n + 1);

		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = rand() % 256 + 1;
		}

		G.numPlayers = 3;
		G.playedCardCount = 0;

		p = rand() % G.numPlayers;
		G.deckCount[p] = rand() % MAX_DECK + 1;
		G.discardCount[p] = rand() % MAX_DECK + 1;
		G.handCount[p] = rand() % MAX_HAND + 1;

		printf("Player: %d\n", p);

		for (i = 0; i < G.deckCount[p]; ++i) {
			G.deck[p][i] = rand() % treasure_map + 1;
		}

		for (i = 0; i < G.discardCount[p]; ++i) {
			G.discard[p][i] = rand() % treasure_map + 1;
		}

		for (i = 0; i < G.handCount[p]; ++i) {
			G.hand[p][i] = rand() % treasure_map + 1;
		}

		numFails += checkAdventurer(&G, p);

	}

	printf("\nTotal Number of Failures: %d\n\n\n", numFails);

	return 0;
}
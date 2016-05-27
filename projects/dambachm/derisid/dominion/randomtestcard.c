#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
	struct gameState G, testG;
	int numPlayers = 1;
	int seed = 1000;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	int numOfTests = 100;
	int numOfCards = 10;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	srand(seed);
	int player;
	int i;
	for (i = 0; i < numOfTests; i++) {
		printf("Test Number %i\n", i);
		player = rand() % 4;
		G.whoseTurn = player;
		G.playedCardCount = 0;
		G.deckCount[player] = rand() % 25;
		int j;
		for (j = 0; j < G.deckCount[player]; j++) {
			int card = rand() % numOfCards;
			G.deck[player][j] = card;
		}
		G.discardCount[player] = rand() % 25;
		for (j = 0; j < G.discardCount[player]; j++) {
			int card = rand() % numOfCards;
			G.discard[player][j] = card;
		}
		G.handCount[player] = 5;
		int handpos = rand() % 5;
		G.hand[player][handpos] = smithy;
		for (j = 0; j < G.handCount[player]; j++) {
			if (j == handpos) {
				continue;
			}
			int card = rand() % numOfCards;
			G.hand[player][j] = card;
		}

		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(13, 0, 0, 0, &G, handpos, 0);

		if (testG.deckCount[player] > 3) {
			if ((G.handCount[player] != testG.handCount[player] + 2)) {
				printf("Test Failed! Expected hand count: %i, Actual hand count: %i\n",
						testG.handCount[player] + 2, G.handCount[player]);
			} else if ((G.discardCount[player] != testG.discardCount[player])) {
				printf("Test Failed! Expected discard count: %i, Actual discard count: %i\n",
						testG.discardCount[player], G.discardCount[player]);
			} else if ((G.deckCount[player] != testG.deckCount[player] - 3)) {
				printf("Test Failed! Expected deck count: %i, Actual deck count: %i\n",
						testG.deckCount[player] - 3, G.deckCount[player]);
			} else {
				printf("Test Passed!!!\n");
			}
		} else if (testG.deckCount[player] + testG.discardCount[player] >= 3) {
			if ((G.handCount[player] != testG.handCount[player] + 2)) {
				printf("Test Failed! Expected hand count: %i, Actual hand count: %i\n",
						testG.handCount[player] + 2, G.handCount[player]);
			} else if ((G.discardCount[player] != 0)) {
				printf("Test Failed! Expected discard count: %i, Actual discard count: %i\n",
						0, G.discardCount[player]);
			} else if ((G.deckCount[player] != testG.discardCount[player] - 3 + testG.deckCount[player])) {
				printf("Test Failed! Expected deck count: %i, Actual deck count: %i\n",
						testG.discardCount[player] - 3 + testG.deckCount[player], G.deckCount[player]);
			} else {
				printf("Test Passed!!!\n");
			}
		} else {
			if ((G.handCount[player] != testG.handCount[player] + testG.discardCount[player] + testG.deckCount[player])) {
				printf("Test Failed! Expected hand count: %i, Actual hand count: %i\n",
						testG.handCount[player] + testG.discardCount[player] + testG.deckCount[player], G.handCount[player]);
			} else if ((G.discardCount[player] != 0)) {
				printf("Test Failed! Expected discard count: %i, Actual discard count: %i\n",
						0, G.discardCount[player]);
			} else if ((G.deckCount[player] != 0)) {
				printf("Test Failed! Expected deck count: %i, Actual deck count: %i\n",
						0, G.deckCount[player]);
			} else {
				printf("Test Passed!!!\n");
			}
		}

		printf("\n");
	}

	return 0;
}

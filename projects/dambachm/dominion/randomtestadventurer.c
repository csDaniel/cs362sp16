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
	int treasury = 0;
	int discardTreasury = 0;
	int seed = 1000;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	int numOfTests = 100;
	int numOfCards = 10;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	srand(time(NULL));
	int player;
	int firsttreasury;
	int secondtreasury;
	int i;
	for (i = 0; i < numOfTests; i++) {
		printf("Test Number %i\n", i);
		treasury = 0;
		discardTreasury = 0;
		player = rand() % 4;
		G.whoseTurn = player;
		G.handCount[player] = 5;
		G.deckCount[player] = rand() % 25;
		int j;
		for (j = 0; j < G.deckCount[player]; j++) {
			int card = rand() % numOfCards;
			G.deck[player][j] = card;
			if ((card == copper) || (card == silver) || (card == gold)) {
				treasury++;
			}
		}
		G.discardCount[player] = rand() % 25;
		for (j = 0; j < G.discardCount[player]; j++) {
			int card = rand() % numOfCards;
			G.discard[player][j] = card;
			if ((card == copper) || (card == silver) || (card == gold)) {
				discardTreasury++;
			}
		}
		for (j = 0; j < G.handCount[player]; j++) {
			int card = rand() % numOfCards;
			G.hand[player][j] = card;
		}
		if (treasury + discardTreasury < 2) {
			printf("Test Failed! Stuck in infinite loop!\n\n");
			continue;
		}
		memcpy(&testG, &G, sizeof(struct gameState));
		playAdventurer(&G);
		int fewerDeckCards = 0;
		int treas = 0;
		for (j = testG.deckCount[player] - 1; j >= 0; j--) {
			int card;
			card = testG.deck[player][j];
			if ((card == copper) || (card == silver) || (card == gold)) {
				treas++;
			} else {
				fewerDeckCards++;
			}
			if (treas == 2) {
				break;
			}
		}

		if (treasury < 2) {
			printf("Reshuffel required\n");
			if ((G.handCount[player] == testG.handCount[player] + 2)) {
				if (G.handCount[player] > 7) {
					printf("Test Failed! Too many cards in hand\n");
				} else {
					printf("Test Passed\n");
				}
			} else {
				printf("Test Failed! Expected hand count: %i, Actual hand count: %i\n",
						testG.handCount[player] + treasury + discardTreasury, G.handCount[player]);
			}
		} else {
			if ((G.handCount[player] != testG.handCount[player] + 2)) {
				printf("Test Failed! Expected hand count: %i, Actual hand count: %i\n",
						testG.handCount[player] + 2, G.handCount[player]);
			} else if ((G.discardCount[player] != testG.discardCount[player] + fewerDeckCards)) {
				printf("Test Failed! Expected discard count: %i, Actual discard count: %i\n",
						testG.discardCount[player] + fewerDeckCards, G.discardCount[player]);
			} else if ((G.deckCount[player] != testG.deckCount[player] - fewerDeckCards - 2)) {
				printf("Test Failed! Expected deck count: %i, Actual deck count: %i\n",
						testG.deckCount[player] - fewerDeckCards - 2, G.deckCount[player]);
			} else {
				printf("Test Passed!!!\n");
			}
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

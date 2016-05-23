#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	struct gameState G, testG;
	int numPlayers = 1;
	int seed = 1000;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
			tribute, smithy, council_room };
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	int player = 1;
	int fail = 0;
	printf("Test for Adventurer\n");

	printf("Test One\n");
	G.handCount[player] = 5;
	int handpos = 1;
	G.whoseTurn = player;

	G.playedCardCount = 0;
	G.hand[player][0] = 13;
	G.hand[player][1] = 1;
	G.hand[player][2] = 16;
	G.hand[player][3] = 3;
	G.hand[player][4] = 9;

	G.deckCount[player] = 3;
	G.deck[player][0] = 4;
	G.deck[player][1] = 8;
	G.deck[player][2] = 5;

	G.discardCount[player] = 5;
	G.discard[player][0] = 8;
	G.discard[player][1] = 4;
	G.discard[player][2] = 4;
	G.discard[player][3] = 2;
	G.discard[player][4] = 5;

	cardEffect(7, 0, 0, 0, &G, handpos, 0);

	if (G.handCount[player] != 6) {
		printf("Test Failed! Hand count should be 6 but is %i\n", G.handCount[player]);
		fail = 1;
	}
	if (G.discardCount[player] != 6) {
		printf("Test Failed! Discard count should be 6 but is %i\n", G.discardCount[player]);
		fail = 1;
	}
	if (G.deckCount[player] != 0) {
		printf("Test Failed! Deck count should be 0 but is %i\n", G.deckCount[player]);
		fail = 1;
	}
	if (fail == 0) {
		printf("Test Passed!!\n");
	}

	printf("Test two\n");
	initializeGame(numPlayers, k, seed, &G);
	fail = 0;
	G.playedCardCount = 0;
	G.whoseTurn = player;

	G.handCount[player] = 5;
	G.hand[player][0] = 13;
	G.hand[player][1] = 1;
	G.hand[player][2] = 16;
	G.hand[player][3] = 3;
	G.hand[player][4] = 9;

	G.deckCount[player] = 1;
	G.deck[player][0] = 14;

	G.discardCount[player] = 5;
	G.discard[player][0] = 8;
	G.discard[player][1] = 4;
	G.discard[player][2] = 4;
	G.discard[player][3] = 2;
	G.discard[player][4] = 5;

	cardEffect(7, 0, 0, 0, &G, handpos, 0);

	if (G.handCount[player] != 6) {
		printf("Test Failed! Hand count should be 6 but is %i\n", G.handCount[player]);
		fail = 1;
	}
	if (fail == 0) {
		printf("Test Passed!!\n");
	}

	printf("Test Three\n");
	initializeGame(numPlayers, k, seed, &G);
	fail = 0;
	G.playedCardCount = 0;
	G.whoseTurn = player;

	G.handCount[player] = 5;
	G.hand[player][0] = 13;
	G.hand[player][1] = 1;
	G.hand[player][2] = 16;
	G.hand[player][3] = 3;
	G.hand[player][4] = 9;

	G.deckCount[player] = 1;
	G.deck[player][0] = 14;

	G.discardCount[player] = 1;
	G.discard[player][0] = 8;

	cardEffect(7, 0, 0, 0, &G, handpos, 0);

	if (G.handCount[player] != 4) {
		printf("Test Failed! Hand count should be 4 but is %i\n", G.handCount[player]);
		fail = 1;
	}
	if (fail == 0) {
		printf("Test Passed!!\n");
	}

	printf("\n\n");
	return 0;
}


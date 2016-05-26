/*************************************************************************
* Mark Rushmere
* Assignment 3
* Description: Test for village Card
*************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "remodel"

int main() {

    int i, j;
    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// Test 1: 1 card has been drawn
	printf("TEST 1: Test return value of negative one for card cost +3\n");
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[thisPlayer][0] = copper;
	testG.hand[thisPlayer][1] = copper;
	testG.hand[thisPlayer][2] = copper;
	testG.hand[thisPlayer][3] = copper;
	testG.hand[thisPlayer][4] = copper;
	int cardUno = copper;
	int cardDos = adventurer;
	int returnVal;
	returnVal = cardEffect(remodel, cardUno, cardDos, 0, &testG, 0, 0);

	if(returnVal == -1) {
		printf("SUCCESS\n");
	}
	else {
		printf("FAILURE\n");
	}

	



	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}

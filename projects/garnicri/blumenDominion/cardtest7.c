/**
cardtest7_outpost.c: Tests the outpost card

// Basic requirements
1. ...
2. the outpost card is trashed rather than discarded

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"       //*******************>>>> change me

void cardtest7_outpost() {
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 7;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
	struct gameState G, testG;
	int k[10] = {smithy, adventurer, feast, council_room, outpost, village, remodel, mine, cutpurse, embargo};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// apply the play to the testG game state
	cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	int newCards_thisPlayer = 4;
	int newCards_otherPlayer = 1;
	xtraCoins = 0;

    // ----------- TEST 1: Village Card ends up in discard pile --------------
    printf("TEST 7: Village Card ends up in discard pile\n");
    m = testG.discardCount[thisPlayer] - G.discardCount[thisPlayer]; // number of cards discarded during play
    j = 0;
    printf(" One of the discarded cards is expected to be %d. Here are the discarded cards: ", village);
    for (i=1; i<=m; i++) {
        printf(" %d, ", testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ]);
        if (testG.discard[thisPlayer][ testG.discardCount[thisPlayer] -i ] == village){
            j = 1;
        }
    }
    if (j == 1) {
        printf(" test passed.\n");
    } else {
        printf(" TEST FAILED.\n");
    }

    // ----------- TEST 2: Hand count for the player is decremented by 1 --------------
    printf("TEST 8: Hand count for the player is decremented by 1\n");
    printf(" hand count = %d, expected = %d, ", testG.handCount[thisPlayer], G.handCount[thisPlayer] -1);
    if (testG.handCount[thisPlayer] == (G.handCount[thisPlayer] -1)){
        printf(" test passed.\n");
    } else {
        printf(" TEST FAILED.\n");
    }

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}



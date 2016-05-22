/**
cardtest6_village.c: Tests the village card

// Basic requirements
1. Current player should receive exactly 1 cards.
2. 1 card should come from his own pile.
3. Current player's number of actions should be incremented by 2
4. No state change should occur to the other player's hand
5. No state change should occur to the other player's deck
6. No state change should occur to the curse, treasury, victory and kingdom card piles
7. Village Card ends up in discard pile
8. Hand count for the player is decremented by 1

Some possible errors:
(1) the function only allows for one action instead of two
(2) the card used is not discarded but either remains in hand or is trashed

**/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"       //*******************>>>> change me

void cardtest6_village() {
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
	int k[10] = {smithy, adventurer, feast, council_room, gardens, village, remodel, mine, cutpurse, embargo};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	// apply the play to the testG game state
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);        //*******************>>>> change me

    // variables that reflect expected outcome
	int newCards_thisPlayer = 4;
	int newCards_otherPlayer = 1;
	xtraCoins = 0;

    // ----------- TEST 1: +1 card1 in player's hand --------------
	printf("TEST 1: +4 cards in player's hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards_thisPlayer - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards_thisPlayer - discarded);

    // ----------- TEST 2: -1 card1 in player's deck --------------
	printf("TEST 2: -4 cards in player's deck\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards_thisPlayer + shuffledCards);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards_thisPlayer + shuffledCards);

    // ----------- TEST 3: +2 actions for player -------------- ///
	printf("TEST 3: +2 actions for player\n");
	printf("number of actions = %d, expected = %d\n", testG.numActiona, G.numActions + 2);
	//assert(testG.numBuys == G.numBuys + 2);

    // ----------- TEST 4: no change to other player's hand --------------
	printf("TEST 4: no change to other player's hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer];

    // ----------- TEST 5: no change to other player's deck --------------
	printf("TEST 5: no change to other player's deck\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	assert(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer];

    // ----------- TEST 6: No state change should occur to the curse, treasury, victory and kingdom card piles. --------------
	printf("TEST 6: No state change should occur to the curse, treasury, victory and kingdom card piles.\n");
    for (i = curse; i <= treasure_map; i++) {    //loop over all possible cards in dominion universe (see enum def in dominion.h)
        assert(testG.supplyCount[i] == G.supplyCount[i]);
    }
    printf("Confirmed: no change to other supplies of curse, kingdom, victory or treasury cards.\n");

    // ----------- TEST 7: Village Card ends up in discard pile --------------
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

    // ----------- TEST 8: Hand count for the player is decremented by 1 --------------
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



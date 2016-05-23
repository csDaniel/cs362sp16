/*
Aaron Sealy
Quiz 2
CS 362
Spring 2016

Tests Great Hall card

Tested behavior: The player draws one card from his deck and adds it to his hand.
The player also gains an action. The card is discarded after use.
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i = 0;
	int j,  x;
	int handPos = 3;
	int seed = 1000;
	int numPlayers = 2;
	int p = 0;
	int HC = 4;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int maxHandPos = 5;
    struct gameState T, G;

    /////// Announce testing
    printf("Testing Great Hall card:\n");

    //Clean gamestates
    memset(&T, 23, sizeof(struct gameState));
    memset(&G, 23, sizeof(struct gameState));

    // Initialize game
    x = initializeGame(numPlayers, k, seed, &T);

    //set hand count
    T.handCount[p] = HC;

    // Copy original game state T into G
    memcpy(&G, &T, sizeof(struct gameState));

    // Play Great Hall
    playGreatHall(&G, handPos);

    // Variables for expected values of handc count, played cards, and deck count
    int handC = (T.handCount[i] + 1);
    int playedC = (T.playedCardCount + 1);
    int deckC = (T.deckCount[i] - 1);
    int actionsC = (T.numActions + 1);
    int countF = 0;

            // Print results
            printf("TEST 1: played count = %d. Expected result = %d.\n", G.playedCardCount, playedC);

			// Error message if played cards unexpected
			if (G.playedCardCount != playedC){
                printf("TEST 1 FAILED!\n");
                countF++;
			}

            // Print results
            printf("TEST 2: deck count= %d. Expected result = %d.\n", G.deckCount[i], deckC);

			// Error message if deck count unexpected
			if (G.deckCount[i] != deckC){
                printf("TEST 2 FAILED!\n");
                countF++;
			}

            // Print results
            printf("TEST 3: number actions = %d. Expected result = %d.\n", G.numActions, actionsC);

			// Error message if number of actions unexpected
			if (G.numActions != actionsC){
                printf("TEST 3 FAILED!\n");
                countF++;
			}

			// Print passed message if all tests passed
			if (countF == 0){
                printf("All 3 tests passed!\n");
			}
    return 0;
}


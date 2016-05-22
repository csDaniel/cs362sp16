/**************************************************************************************************
* Mark Rushmere
* CS 362
* Assignment 4
* Description: This is a random tester for the playAdventurer() in dominion.c.
* 
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define MAX_TESTS 1000
#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_PLAYERS 4

#define TESTCARD "village"
#define PRINT_ALL 0

// function to randomize the gamestate
void randomizeGameState(struct gameState *state) {
	// Declare Variables
	int i, j;
	int seed = rand();
	int numPlayers = (rand() % 3) + 2; // Number in range 2-4

	// Select the cards that will be put into the deck
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	// Make sure that the number of players <= 4
	assert(numPlayers <= 4);
	initializeGame(numPlayers, k, seed, state);

	// Randomly choose the cards in each player's deck, discard, and hand
	for(i = 0; i < numPlayers; i++) {
		state->deckCount[i] = floor(Random() * MAX_DECK);
        state->discardCount[i] = floor(Random() * MAX_DECK);
        state->handCount[i] = floor(Random() * MAX_HAND);

        for(j = 0; j < state->deckCount[j]; j++) {
        	state->deck[i][j] = floor(Random() * treasure_map);
        }

        for(j = 0; j < state->discardCount[j]; j++) {
        	state->discard[i][j] = floor(Random() * treasure_map);
        }

        for(j = 0; j < state->handCount[j]; j++) {
        	state->hand[i][j] = floor(Random() * treasure_map);
        }

	}
}


int main() {
	// Seed random number
	srand(time(NULL));

	// Declare all necessary variables
	int i;
	int numPlayers, curPlayer;
	struct gameState G, testG;
	memset(&G, 0, sizeof(struct gameState));
	memset(&testG, 0, sizeof(struct gameState));


	printf("----------------- Random Testing Card: %s ----------------\n", TESTCARD);

	// Now the main loop to execute MAX_TESTS number of random tests
	for(i = 0; i < MAX_TESTS; i++) {

			printf("----------------- %d ----------------\n", i);
			int j, m, n;
			int failure = 0;

			bzero(&G, sizeof(struct gameState));
			bzero(&testG, sizeof(struct gameState));

			// Randomize the cards
			randomizeGameState(&G);

			// Choose a player at random
			numPlayers = G.numPlayers;
			curPlayer = rand() % numPlayers;
			G.whoseTurn = curPlayer;

			// Put a adventurer card in their hand
			G.hand[curPlayer][0] = village;

			// Make a copy of the game state
			memcpy(&testG, &G, sizeof(struct gameState));			


			/**************************************************
			* START OF TEST CASES FOR EACH RANDOMIZED GAME STATE
			***************************************************/

			// Play village
			cardEffect(village, 0, 0, 0, &testG, 0, 0);

			// Test 1: 1 card has been drawn
			#if (PRINT_ALL == 1)
				printf("TEST 1: Verify 1 card has been drawn\n");
			#endif
			// Should have the same number of card in hand before and after card is played
			if(testG.handCount[curPlayer] == G.handCount[curPlayer]) {
				#if (PRINT_ALL == 1)
					printf("SUCCESS\n");
				#endif
			}
			else {
				printf("Test 1 FAILURE\n");
				failure = 1;
			}

			// Test 2: Verify that the card came from own pile
			// Assert that other player's decks are the same as before and currentPlayer's deck is decremeted by 1
			#if (PRINT_ALL == 1)
				printf("TEST 2: Verify card is from own deck and other decks are unchanged\n");
			#endif
			for(j = 0; j < numPlayers; j++) {
				if(j == curPlayer) {
					if(testG.deckCount[j] == G.deckCount[j] -1) {
						#if (PRINT_ALL == 1)
							printf("SUCCESS\n");
						#endif
					}
					else {
						printf("Test 2 FAILURE\n");
						failure = 1;
					}

				}
				// testG and G should be the same for all other players
				else {
					if(testG.deckCount[j] == G.deckCount[j]) {
						printf("SUCCESS\n");
					}
					else {
						printf("Test 2 FAILURE\n");
						failure = 1;
					}
				}
			}

			//Test 3: Verify that 2 actions have been added
			#if (PRINT_ALL == 1)
				printf("TEST 3: Verify 2 actions have been added\n");
			#endif
			if(testG.numActions == G.numActions + 1) {
				#if (PRINT_ALL == 1)
					printf("SUCCESS\n");
				#endif
			}
			else {
				printf("FAILURE\n");
			}

	}



	return 0;
}

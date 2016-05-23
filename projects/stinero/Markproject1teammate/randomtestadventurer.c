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

#define MAX_HAND 500
#define MAX_DECK 500
#define MAX_PLAYERS 4

#define TESTCARD "adventurer"
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
	// Declare all necessary variables
	int i;
	int seed = 1000;
	int maxTests = 1000;
	int numPlayers, curPlayer;
	struct gameState G, testG;

	memset(&G, 0, sizeof(struct gameState));
	memset(&testG, 0, sizeof(struct gameState));


	// Seed random number
	srand(time(NULL));


	printf("----------------- Random Testing Card: %s ----------------\n", TESTCARD);

	// Now the main loop to execute MAX_TESTS number of random tests
	for(i = 0; i < maxTests; i++) {
		printf("Iteration %d\n", i);
		int j, m, n, p;
		int failure = 0;
		int treasureCount = 0;
		int treasureDeckCount = 0;

		bzero(&G, sizeof(struct gameState));
		bzero(&testG, sizeof(struct gameState));

		// Randomize the cards
		randomizeGameState(&G);

		// Choose a player at random
		numPlayers = G.numPlayers;
		curPlayer = rand() % numPlayers;
		G.whoseTurn = curPlayer;

		// Put a adventurer card in their hand
		G.hand[curPlayer][0] = adventurer;

		// Make a copy of the game state
		memcpy(&testG, &G, sizeof(struct gameState));			

		// find the number of treasure cards in the current player's hand
		for(j = 0; j < testG.handCount[curPlayer]; j++) {
			if(testG.hand[curPlayer][j] == copper || testG.hand[curPlayer][j] == silver || testG.hand[curPlayer][j] == gold) {
				treasureCount++;
			}
		}

		// find the number of treasure cards in the current player's deck
		for(j = 0; j < testG.deckCount[curPlayer]; j++) {
			if(testG.deck[curPlayer][j] == copper || testG.hand[curPlayer][j] == silver || testG.hand[curPlayer][j] == gold) {
				treasureCount++;
				treasureDeckCount++;
			}
		}

		// find the number of treasure cards in the current player's hand
		for(j = 0; j < testG.handCount[curPlayer]; j++) {
			if(testG.hand[curPlayer][j] == copper || testG.hand[curPlayer][j] == silver || testG.hand[curPlayer][j] == gold) {
				treasureCount++;
			}
		}

		// Now treasureCount should be the total number of treasure card for the current player

		/**************************************************
		* START OF TEST CASES FOR EACH RANDOMIZED GAME STATE
		***************************************************/

		// Play adventurer
		cardEffect(adventurer, 0, 0, 0, &testG, 0, 0);

		// Test 1: Verify 2 Cards have been drawn and that they are both treasure cards
		#if (PRINT_ALL == 1)
			printf("TEST 1: Verify 2 cards have been drawn\n");
			// Only 1 cards gained in hand, becuase adventurer card is discarded
			printf("hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer] + 1);
		#endif
		// This tests that there were two cards in the case that there are at least 2 treasure cards in the deck
		if(testG.handCount[curPlayer] == G.handCount[curPlayer] + 1 && treasureDeckCount >= 2) {
			#if(PRINT_ALL == 1)
	        	printf("SUCCESS\n");
	        #endif
	    }
	    // Case there was only 1 treasure card in the players deck
	    else if(testG.handCount[curPlayer] == G.handCount[curPlayer] && treasureDeckCount == 1) {
	    	#if(PRINT_ALL == 1)
	        	printf("SUCCESS\n");
	        #endif
	    }

	    // Case there were no treasure cards in the players deck
	    else if(testG.handCount[curPlayer] == G.handCount[curPlayer] -1 && treasureDeckCount == 0) {
	    	#if(PRINT_ALL == 1)
	        	printf("SUCCESS\n");
	        #endif
	    }
	    // Always print out the failures and the game state if there is one
	    else {
	        printf("TEST 1 FAILURE\n");
	        failure = 1;
	        
		}

		// Test 2: Verify they are treasure cards
		#if (PRINT_ALL == 1)
			printf("TEST 2: Verify they are treasure Cards\n");
		#endif
		// This tests that there were two cards in the case that there are at least 2 treasure cards in the deck
		int handCount = testG.handCount[curPlayer];
		if(treasureDeckCount >= 2) {
			if((testG.hand[curPlayer][handCount-1] == copper || testG.hand[curPlayer][handCount-1] == silver || testG.hand[curPlayer][handCount-1] == gold)
				&& (testG.hand[curPlayer][handCount-2] == copper || testG.hand[curPlayer][handCount-2] == silver || testG.hand[curPlayer][handCount-2] == gold)) {
				#if(PRINT_ALL == 1)
		        	printf("SUCCESS\n");
		        #endif
	    	}

		}

		else if(treasureDeckCount == 1) {
			if(testG.hand[curPlayer][handCount-1] == copper || testG.hand[curPlayer][handCount-1] == silver || testG.hand[curPlayer][handCount-1] == gold) {
				#if(PRINT_ALL == 1)
		        	printf("SUCCESS\n");
		        #endif
	    	}
		}

		else if(treasureDeckCount == 0) {
			if(testG.handCount[curPlayer] == G.handCount[curPlayer] -1) {
				#if(PRINT_ALL == 1)
		        	printf("SUCCESS\n");
		        #endif
	    	}
		}
	    // Always print out the failures and the game state if there is one
	    else {
	        printf("TEST 2 FAILURE on iteration %d\n", i);
	        failure = 1;
	        
		}


		// Test 3: Verify that the other player's states are the same
		#if(PRINT_ALL == 1)
			printf("TEST 3: Verify the other player's states have not changed\n");
		#endif
		for(p = 0; p < numPlayers; p++) {
			if(p != curPlayer) {

				// Check that all of the cards in the other player's deck are the same
				int curPlayerDeckCount = G.deckCount[p];
				for(j = 0; j < curPlayerDeckCount; j++) {
					if(G.deck[p][j] == testG.deck[p][j]) {
						#if(PRINT_ALL == 1)
				        	printf("SUCCESS\n");
				        #endif
				    }
				    else {
				        printf("TEST 3 FAILURE\n");
	    			}

				}
				// Check hand
				if(G.handCount == testG.handCount) {
			        printf("SUCCESS\n");
			    }
			    else {
			        printf("TEST 3 FAILURE\n");
			    }
			}
		}
	}


	return 0;
}

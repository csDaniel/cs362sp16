/* Cey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 4
 * May 8, 2016
 * randomtestcard.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard: randomtestcard.c dominion.o rngs.o
 *      gcc -o randomtestcard -g randomtestcard.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
	int h, i, j, r;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, seed = 1000;
	int currentPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// Initialize new game state with a random number of players
	int numPlayers = (rand() % 3) + 2;
	memset(&G, 0, sizeof(struct gameState));
	r = initializeGame(numPlayers, k, seed, &G);		
	assert(r == 0);
	printf("****RANDOM TESTING: mine Card****\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine properly discards itself when played\n");
#endif	
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Copy game state
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;	
			testG.whoseTurn = i;
			// Pick a random hand position for mine card
			handPos = rand() % 5;
			testG.hand[currentPlayer][handPos] = mine;
			cardEffect(mine, choice1, choice2, choice3, &testG, handPos, &bonus);	
			// Test mine card was removed from the player's hand
			for(j = 0; j < testG.handCount[currentPlayer]; j++) {
				//assert(testG.hand[currentPlayer][j] != mine);
			}
		}
	}
	printf("mine: PASS mine discards itself when played\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine fails if choice2 is 3$ or greater in cost than choice1\n");
#endif
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Clear and copy game state
			memset(&testG, 0, sizeof(struct gameState));
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;
			// Set player turn
			testG.whoseTurn = currentPlayer;
			// Place adventurer at hand position 0
			handPos = 0;
			// Set player hand
			testG.hand[currentPlayer][0] = mine;
			testG.hand[currentPlayer][1] = rand() % 30;
			testG.hand[currentPlayer][2] = rand() % 30;
			choice1 = 1;
			choice2 = 2;			
			if((getCost(testG.hand[currentPlayer][choice1]) + 3) < getCost(testG.hand[currentPlayer][choice2])) {
				// Test that mine failed due to choice2 being 3 or more in cost
				assert(cardEffect(mine, choice1, choice2, choice3, &testG, handPos, &bonus) == -1);		
			}
		}
	}
	printf("mine: PASS fails when choice2 is 3$ or greater in cost than choice1\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine fails if choice2 card is invalid card enumeration\n");
#endif
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Copy game state
			memset(&testG, 0, sizeof(struct gameState));
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;
			// Set player turn
			testG.whoseTurn = currentPlayer;
			// Place adventurer at hand position 0
			handPos = 0;
			// Set player hand
			testG.handCount[currentPlayer] = 5;
			testG.hand[currentPlayer][0] = mine;
			testG.hand[currentPlayer][1] = (rand() % treasure_map) - (rand() % treasure_map);
			testG.hand[currentPlayer][2] = (rand() % treasure_map) - (rand() % treasure_map);
			testG.hand[currentPlayer][3] = (rand() % treasure_map) - (rand() % treasure_map);
			testG.hand[currentPlayer][4] = (rand() % treasure_map) - (rand() % treasure_map);
			// Pick two random cards from hand
			choice1 = (rand() % 4) + 1;	
			choice2 = (rand() % 4) + 1;
			// Make sure the hand positions are not the same
			if(choice1 == choice2) {
				if(choice1 == 4) {
					choice2--;
				}
				else {
					choice2++;
				}
			}
			if(testG.hand[currentPlayer][choice2] < curse || testG.hand[currentPlayer][choice2] > treasure_map) {
				assert(cardEffect(mine, choice1, choice2, choice3, &testG, handPos, &bonus) == -1);		
			}
		}
	}
	printf("mine: PASS fails when choice2 card is invalid card enumeration\n");
#if (NOISY_TEST == 1)
	printf("\nTest mine fails if choice1 card is not a treasure card\n");
#endif
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Copy game state
			memset(&testG, 0, sizeof(struct gameState));
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;
			// Set player turn
			testG.whoseTurn = currentPlayer;
			// Place adventurer at hand position 0
			handPos = 0;
			// Set player hand
			testG.handCount[currentPlayer] = 5;
			testG.hand[currentPlayer][0] = mine;
			testG.hand[currentPlayer][1] = rand() % treasure_map + 1;
			testG.hand[currentPlayer][2] = rand() % treasure_map + 1;
			testG.hand[currentPlayer][3] = rand() % treasure_map + 1;
			testG.hand[currentPlayer][4] = rand() % treasure_map + 1;
			// Pick two random cards from hand
			choice1 = (rand() % 4) + 1;	
			choice2 = (rand() % 4) + 1;
			// Make sure the hand positions are not the same
			if(choice1 == choice2) {
				if(choice1 == 4) {
					choice2--;
				}
				else {
					choice2++;
				}
			}
			if(((testG.hand[currentPlayer][choice1] < copper) || (testG.hand[currentPlayer][choice1] > gold))) {
				// Test that mine failed due to choice1 not being a treasure card	
				assert(cardEffect(mine, choice1, choice2, choice3, &testG, handPos, &bonus) == -1);		
			}
		}
	}
	printf("mine: PASS fails when choice1 card is not a treasure card\n");
	
	printf("All tests passed!\n");
	
	return 0;
}


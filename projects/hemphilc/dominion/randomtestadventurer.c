/* Cey Hemphill
 * hemphilc@oregonstate.edu
 * CS362_400 - Software Engineering II
 * Assignment 4
 * May 8, 2016
 * randomtestadventurer.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
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
	int h, i, j, r, randPos1, randPos2, randDeckCount;
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
	printf("****RANDOM TESTING: adventurer Card****\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer properly discards itself when played\n");
#endif	
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Copy game state
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;	
			testG.whoseTurn = i;
			// Pick a random hand position for adventurer card
			handPos = rand() % 5;	
			testG.hand[currentPlayer][handPos] = adventurer;
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);	
			// Test adventurer card was removed from the player's hand
			for(j = 0; j < testG.handCount[currentPlayer]; j++) {
				assert(testG.hand[currentPlayer][j] != adventurer);
			}
		}
	}
	printf("adventurer: PASS adventurer discards itself when played\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer correctly increments/decrements player's handCount/deckCount\n");
#endif	
	// Set each player's hand and deck	
	for(h = 0; h < 2000; h++) {
		// Copy game state
		memset(&testG, 0, sizeof(struct gameState));
		memcpy(&testG, &G, sizeof(struct gameState));
		for(i = 0; i < numPlayers; i++) {
			currentPlayer = i;
			// Pick a random hand position for adventurer card
			handPos = rand() % 5;
			testG.hand[currentPlayer][handPos] = adventurer;
			// Set player deck
			testG.deckCount[currentPlayer] = 10;
			testG.deck[currentPlayer][0] = estate;	
			testG.deck[currentPlayer][1] = estate;
			testG.deck[currentPlayer][2] = estate;
			testG.deck[currentPlayer][3] = estate;
			testG.deck[currentPlayer][4] = estate;
			testG.deck[currentPlayer][5] = estate;
			testG.deck[currentPlayer][6] = estate;
			testG.deck[currentPlayer][7] = estate;
			testG.deck[currentPlayer][8] = estate;
			testG.deck[currentPlayer][9] = estate;
			// Insert two random treasure cards at random positions in the deck
			randPos1 = rand() % 10;
			randPos2 = rand() % 10;
			// Make sure the hand positions are not the same
			if(randPos1 == randPos2) {
				if(randPos1 == 9) {
					randPos2--;
				}
				else {
					randPos2++;
				}
			}
			// Insert treasure cards into random positions in the deck
			testG.deck[currentPlayer][randPos1] = silver;	
			testG.deck[currentPlayer][randPos2] = gold;
			testG.whoseTurn = currentPlayer;
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);
			// Test handCount incremented, deckCount decremented
			assert(testG.handCount[currentPlayer] = G.handCount[currentPlayer] + 2);
			assert(testG.deckCount[currentPlayer] = G.deckCount[currentPlayer] - 2);
		}
	}
	printf("adventurer: PASS correctly increments handCount and decrements deckCount when played\n");
#if (NOISY_TEST == 1)
	printf("\nTest adventurer shuffles when deck count is 0\n");
#endif
	for(h = 0; h < 2000; h++) {
		for(i = 0; i < numPlayers; i++) {
			// Copy game state
			memset(&testG, 0, sizeof(struct gameState));
			memcpy(&testG, &G, sizeof(struct gameState));
			currentPlayer = i;
			// Place adventurer at hand position 0
			handPos = 0;
			// Set player hand
			testG.handCount[currentPlayer] = 1;
			testG.hand[currentPlayer][0] = adventurer;
			// Set random deck count values
			randDeckCount = rand() % MAX_DECK;
			testG.deckCount[currentPlayer] = randDeckCount;	
			testG.discardCount[currentPlayer] = 5;
			testG.discard[currentPlayer][0] = estate;
			testG.discard[currentPlayer][1] = smithy;
			testG.discard[currentPlayer][2] = council_room;
			testG.discard[currentPlayer][3] = mine;
			testG.discard[currentPlayer][4] = cutpurse;			
#if (NOISY_TEST == 1)
			printf("%d. %d\n", i, testG.handCount[currentPlayer]);
			printf("%d. %d\n", i, testG.deckCount[currentPlayer]);
			printf("%d. %d\n", i, testG.discardCount[currentPlayer]);
#endif			
			// Set player turn
			testG.whoseTurn = currentPlayer;
			cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);		
#if (NOISY_TEST == 1)
			printf("%d. post hand %d\n", i, testG.handCount[currentPlayer]);
			printf("%d. post deck %d\n", i, testG.deckCount[currentPlayer]);
			printf("%d. post discardCount %d\n\n", i, testG.discardCount[currentPlayer]);
#endif
			// Test when deckCount is 0, shuffle occurs	
			if(randDeckCount == 0) {
				assert((testG.discard[currentPlayer][0] != estate) ||
					(testG.discard[currentPlayer][1] != smithy) ||
					(testG.discard[currentPlayer][2] != council_room) ||
					(testG.discard[currentPlayer][3] != mine) ||
					(testG.discard[currentPlayer][4] != cutpurse));
			}
		}
	}
	printf("adventurer: PASS only shuffles when deck count is 0\n");

	printf("All tests passed!\n");
	
	return 0;
}


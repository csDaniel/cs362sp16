#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Smithy"
#define NUM_TESTS 1024

int main() {
	
	srand(time(NULL));

	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	int i, pass, fail, players, currPlayer, seed, count;
	int handPos = 0;

	for(i = 0; i < NUM_TESTS; i++) {
		
		//initialize game state
		players = 2 + rand() % (4 + 1 - 2);
		currPlayer = rand() % players;
		seed = rand();
		initializeGame(players, k, seed, &G);
		
		//draw cards, discard smithy played
		G.handCount[currPlayer] = 1 + rand() % 5;
		count = G.handCount[currPlayer];
		smithyCard(players, &G, handPos);
		
		//smithy effectively gives a total of 2 more cards after being played
		//this is because the card effect draws three, and discards itself
		//net total of +2 cards in handCount
		if(count + 2 == G.handCount[currPlayer]) {
			pass++;
			//printf("Test #%d Passed!\nHandCount Before - %d\nHandCount After - %d\n", i, count, G.handCount[currPlayer]);
		} else {
			fail++;
			//printf("Test #%d Failed!\nHandCount Before - %d\nHandCount After - %d\n", i, count, G.handCount[currPlayer]);
		}
	}
	
	printf("Tests Passed: %d\n", pass);
	printf("Tests Failed: %d\n", fail);
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);

	return 0;
}
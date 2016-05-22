#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_TESTS 1000;

int main(int argc, char const *argv[]) {
	
	printf("\n--------------------Random Testing: Village Card-------------------------\n\n");
	
	//Declare kingdom cards & game state variables
	int k[10] = {adventurer, council_room, village, feast, gardens, mine, tribute, smithy, embargo, great_hall};
	int numPlayers;
	int currentPlayer;
	int handPos = 0;
	int bonus = 0;
	int seed;
	int testNumActions;
	int testHandCount;
	
	//Testing variables, initialized to zero
	int testsPassed = 0;
	int testsFailed = 0;
	
	struct gameState G;
	
	for (int i = 0; i < 1000; ++i) 
	{
		numPlayers = (rand() % (MAX_PLAYERS - 2)) + 2;
        currentPlayer = rand() % numPlayers;
        seed = rand();
		
		initializeGame(numPlayers, k, seed, &G);
		
		//Set game state variables
		G.whoseTurn = currentPlayer;
        G.numActions = 1;
        G.discardCount[currentPlayer] = 0;
		G.handCount[currentPlayer] = 5;
		
		//Set testing metrics
		testNumActions = G.numActions;
		testHandCount = G.handCount[currentPlayer];
		
		
		//Call village
		cardEffect(village, 0, 0, 0, &G, handPos, &bonus);
		
		
		//Check that num actions aren't equal to before call to village
		if(G.numActions == testNumActions) {
			testsFailed++;
		}
		else {
			testsPassed++;
		}
		
		//Ensure hand count is still the same!
		if(G.handCount[currentPlayer] != testHandCount) {
			testsFailed++;
		}
		else {
			testsPassed++;
		}
				
	}
	
	//Results
    printf("Total number of PASSED tests out of 2,000: %i\n", testsPassed);
    printf("Total number of FAILED tests out of 2,000: %i\n", testsFailed);
	
	return 0;
	
}
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
	
	printf("\n--------------------Random Testing: Adventurer Card-------------------------\n\n");
	
	srand(time(NULL));
	
	//Declare kingdom cards & game state variables
	int k[10] = {adventurer, council_room, village, feast, gardens, mine, tribute, smithy, embargo, great_hall};
	int numPlayers;
	int currentPlayer;
	int handPos;
	int bonus;
	int seed;
	
	//Testing variables, initialized to zero
	int testsPassed = 0;
	int testsFailed = 0;
	
	struct gameState G;
	
	//Random testing loop, runs 1,000 times
    for (int i = 0; i < 1000; ++i)
    {  
        numPlayers = (rand() % (MAX_PLAYERS - 2)) + 2;
        currentPlayer = rand() % numPlayers;
        seed = rand();
		handPos = rand() % 4;
		bonus = 0;

        initializeGame(numPlayers, k, seed, &G);

		//Set game state variables
		G.whoseTurn = currentPlayer;
        G.numActions = 1;
        G.discardCount[currentPlayer] = 0;

        //Random deck
        G.deckCount[currentPlayer] = (rand() % MAX_DECK) + 1;

        G.handCount[currentPlayer] = 5;
		
		int beforeCalled = G.handCount[currentPlayer];
	
		//Call adventurer
		cardEffect(adventurer, 1, 1, 1, &G, handPos, &bonus);
    
		//Should fail, my refactored Dominion adds 3 treasure and not 2
        if (G.handCount[currentPlayer] != beforeCalled + 1) {
            testsFailed++;
        } 
		else {
			testsPassed++;
        }
        
		//Should mostly fail, due to my refactored Adventurer card
        if (G.discardCount[currentPlayer] != (G.handCount[currentPlayer] - G.deckCount[currentPlayer] - 2)) {
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
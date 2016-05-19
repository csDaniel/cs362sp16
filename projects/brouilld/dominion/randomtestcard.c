

#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"
#include "UnitTest_Random_DefinedTests.h"


void village_Setup(struct gameState *state, int currentPlayer, int cardType){
	int i;
	int j;


	state->deckCount[currentPlayer] = 0;
	state->supplyCount[cardType] = copper;

	for (j = 0; j < 15; j++)
	{
		state->deck[currentPlayer][j] = copper;
		state->deckCount[currentPlayer]++;
	}

	state->deck[currentPlayer][15] = cardType;
	state->deckCount[currentPlayer]++;
	
}

void testRandom_village(int numOfRuns, int randomNumActions, int randomTopDeck, int blank, int blank2){

	// Test Suite Setup: Test variables
	time_t t;
	int startingCount;
	int endingCount;
	int cardDrawn;
	int currentPlayer;
	int cardType = 6;
	int i = 0;
	int startingActions;
	int endingActions;
	struct gameState *currentState = newGame();
	currentState->numPlayers = 1;
	currentState->whoseTurn = 1;
	currentState->numBuys = 2;

	srand((unsigned)time(&t));

	for (i = 0; i < numOfRuns; i++)
	{

		/*
		* TEST: Random Test: Village Card
		*/
			// Before Test Setup
			if (randomNumActions == 1){
				currentState->numActions = randomSetup(1, 5);
			}
			if (randomTopDeck == 1){
				cardType = randomSetup(0, 25);
			}


			village_Setup(currentState, currentPlayer, cardType);
			startingCount = currentState->handCount[currentPlayer];
			startingActions = currentState->numActions;

			// Test
			card_village(currentPlayer, currentState, 3);
			endingCount = (currentState->handCount[currentPlayer] - startingCount);
			endingActions = currentState->numActions ;

			assertTest(endingCount, 1, "'Village' Random Testing: +1 Card");
			assertTest(endingActions, (startingActions + 2), "'Village' Random Testing: +2 Actions");

			// After Test Cleanup
			currentState->numActions = 1; // Default setting;
	}
}


//void card_village(int currentPlayer, struct gameState *state, int handPos){
//	//+1 Card
//	drawCard(currentPlayer, state);
//
//	//+2 Actions
//	state->numActions = state->numActions + 2;
//
//	//discard played card from hand
//	discardCard(handPos, currentPlayer, state, 0);
//}

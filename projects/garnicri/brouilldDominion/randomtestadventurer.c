
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"
#include "UnitTest_Random_DefinedTests.h"

// cardType: Copper == 0, Silver == 3, Gold == 6
void setup(struct gameState *state, int currentPlayer, int deckCount, int cardType){
	int i;
	int j;


	state->deckCount[currentPlayer] = 0;
	state->supplyCount[cardType] = deckCount;

	for (j = 0; j < deckCount - 1; j++)
	{
		state->deck[currentPlayer][j] = cardType;
		state->deckCount[currentPlayer]++;
	}


}

void testRandom_adventurer(int numOfRuns, int randomNumPlayers, int randomWhoseTurn, int randomDeckCount, int randomCardType){

	// Test Suite Setup: Test variables
	time_t t;
	int startingCount;
	int endingCount;
	int cardDrawn;
	int currentPlayer;
	int cardType = 6;
	int i = 0;
	int deckCount = 15;
	int drawntreasure = 0;
	struct gameState *currentState = newGame();
	int temphand[MAX_HAND];

	currentState->numPlayers = 1;
	currentState->whoseTurn = 1;

	srand((unsigned)time(&t));

	for (i = 0; i < numOfRuns; i++)
	{

		/*
		* TEST: Random Test: Adventurer Card
		*/

		// Before Test Setup
		if (randomNumPlayers == 1){
			currentState->numPlayers = randomSetup(1, 5);
		}
		if (randomWhoseTurn == 1){
			currentState->whoseTurn = randomSetup(1, 5);
		}
		if (randomDeckCount == 1){
			deckCount = randomSetup(1, 20);
		}
		if (randomCardType == 1){
			cardType = randomSetup(4, 3);
		}

		currentPlayer = whoseTurn(currentState);
		setup(currentState, currentPlayer, deckCount, cardType);
		startingCount = currentState->handCount[currentPlayer];

		// Test
		card_adventurer(currentPlayer, currentState);
		endingCount = (currentState->handCount[currentPlayer] - startingCount);
		assertTest(endingCount, 2, "'Adventurer' adds 2 treasure cards to hand");

		// After Test Cleanup
		currentState->deckCount[currentPlayer] = 1;
	}
}
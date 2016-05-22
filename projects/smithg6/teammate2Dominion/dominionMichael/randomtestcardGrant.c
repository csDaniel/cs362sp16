/*
----------------------------------------------------
Grant Smith
CS362
Assignment 4
This is a random test generator to test the functionality of the
village card. It will randomly generate a game state to input into
the cardAdventurer function and compare expected results with actual
results and report unexpected failures.
----------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define DEBUGSET 1

int main()
{
	//Initialize variables needed to setup gameState
	struct gameState state, backGameState;
	
	//Kingdom cards to initialize game
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, 
							mine, cutpurse, sea_hag, tribute, smithy};

	//control vars
	int j, k, p = 0;
	int countNum = 0;

	//test vars
	int randomSeed = 10000;
	int numberOfTests = 100;
	int currentPlayer = 0;
	int numberOfFailures = 0;
	int numberOfPasses = 0;

	//test for draw card
	int preCardsInHand = 0;
	int postCardsInHand = 0;
	int isValidDraw = 1;

	//test for action increase
	int preActions = 0;
	int postActions = 0;
	int isValidActions = 1;

	//gamestate vars
	int numPlayers = 2;
	int handPos;

	while(countNum < numberOfTests){
		if(DEBUGSET)
			printf("\nRunning test!\n");


		//use of floor to ensure whole number after use of random number gen
		numPlayers = ((rand() % 3) + 1);
		
		memset(&state, 23, sizeof(struct state));

		//initialize game and check for success.
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);

		//random hand size for currentPlayer
		state.handCount[currentPlayer] = ((rand() % 10) + 1);
		for(j = 0; j < state.handCount[currentPlayer]; j++)
		{
			state.hand[currentPlayer][j] = (rand() % 26);
		}

		for(j = 0; j < state.handCount[currentPlayer]; j++)
		{
			if(state.hand[currentPlayer][j] == village)
			{
				handPos = j;
				break;
			}
		}

		handPos = 0;

		//ensure one of the cards in hand is Village
		//state.hand[currentPlayer][j] = village;

		j = k = p = 0;

		//set vars to pre card-play state to verify against later
		preActions = state.numActions;
		preCardsInHand = state.handCount[currentPlayer];

		//backup gamestate for verification later
		memcpy(&backGameState, &state, sizeof(struct gameState));

		playVillageCard(&state, handPos);

		//set vars to post card-play state
		postActions = state.numActions;
		postCardsInHand = state.handCount[currentPlayer];

		//actions should increase after village is played
		if(preActions == postActions || preActions <= postActions)
		{
			isValidActions = 0;
		}

		//card total should remain the same after this card,
		//as a single card is played, but one is gained
		if(preCardsInHand < postCardsInHand || preCardsInHand > postCardsInHand)
		{
			isValidDraw = 0;
		}


		if(isValidActions == 0 || isValidDraw == 0)
		{
			printf("Test# %i\n", countNum + 1);
			printf("\nFunction Tested: cardVillage(%i, &state);\n", currentPlayer );
			printf("\nCards in starting hand: \n");
			for(j = 0; j < backGameState.handCount[currentPlayer]; j++)
			{
				printf("%i, ", backGameState.hand[currentPlayer][j]);
			}
			printf("\n");
			printf("Random Seed: %i\n", randomSeed);
			printf("Failed Item(s): \n");
			if(isValidActions == 0)
				{
					printf("Invalid actions increment. \n");
				} 

			if(isValidDraw == 0)
				{
					printf("Invalid cards in hand. \n");
				}
			numberOfFailures++;
		} else {
			numberOfPasses++;
		}

		randomSeed++;

		countNum++;
	}

	printf("\nTotal Tests: %i\n", numberOfTests);
	printf("Total Passed: %i\n", numberOfPasses);
	printf("Total Failed: %i\n", numberOfFailures);

	return 0;
}
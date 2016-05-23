/*
----------------------------------------------------
Grant Smith
CS362
Assignment 4
This is a random test generator to test the functionality of the
adventurer card. It will randomly generate a game state to input into
the cardAdventurer function and compare expected results with actual
results and report unexpected failures. The test will check for the 
total number of treasure and nonTreasure cards in the deck
to ensure that the proper number of cards were drawn as part of the
adventure card's function.
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
	int i, j, k, p = 0;
	int countNum = 0;

	//test vars
	int randomSeed = 10000;
	int numberOfTests = 100;
	int isValidDeck = 1;
	int isValidDrawTreasure = 1;
	int isValidDeckNonTreasure = 1;
	int postTreasureCount = 0;
	int postNonTreasureCount = 0;
	int totalTreasureCount = 0;
	int totalNonTreasureCount = 0;
	int treasureCount = 0;
	int currentPlayer = 0;
	int numberOfFailures = 0;
	int numberOfPasses = 0;
	int tempHand[MAX_HAND];
	int startingDeckCount = 0;
	int postDeckCount = 0;
	int isAdventurer = 0;

	//gamestate vars
	int success;
	int numPlayers = 2;

	while(countNum < numberOfTests){
		if(DEBUGSET)
			printf("\nRunning test!\n");

		isValidDeck = 1;
		isValidDeckNonTreasure = 1;
		totalTreasureCount = 0;
		totalNonTreasureCount = 0; 
		postTreasureCount = 0;
		postNonTreasureCount = 0;

		//use of floor to ensure whole number after use of random number gen
		numPlayers = ((rand() % 3) + 1);
		
		memset(&state, 23, sizeof(state));

		//initialize game and check for success.
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);

		//random hand size for currentPlayer
		state.handCount[currentPlayer] = ((rand() % 10) + 1);
		for(j = 0; j < state.handCount[currentPlayer]; j++)
		{
			state.hand[currentPlayer][j] = (rand() % 26);
			if(state.hand[currentPlayer][j] == adventurer)
			{
				isAdventurer = 1;
			}
		}

		if(isAdventurer)
		{
			printf("adventurer is present\n");
		}

		//Ensure that at least one card is the adventurer
		//state.hand[currentPlayer][j] = adventurer;

		i = j = k = p = 0;

		startingDeckCount = state.deckCount[currentPlayer];

		//Get total number of treasure cards in deck to verify against later
		for (p = startingDeckCount; p >= 0; p--)
			{
				if((state.deck[currentPlayer][i]) == copper ||
				   (state.deck[currentPlayer][i]) == silver ||
				   (state.deck[currentPlayer][i]) == gold) 
					{
						totalTreasureCount++;
					}else{
						totalNonTreasureCount++;
					}
			}


		//backup gamestate for verification later
		memcpy(&backGameState, &state, sizeof(struct gameState));

		//call adventurer card function
		adventurerFunction(currentPlayer, &state);

		postDeckCount = state.deckCount[currentPlayer];

		//Get total treasures available in deck post-function to compare values
		for (j = postDeckCount; j >= 0; j--)
			{
				if((state.deck[currentPlayer][k]) == copper ||
					(state.deck[currentPlayer][k]) == silver ||
					(state.deck[currentPlayer][k]) == gold) 
					{
						postTreasureCount++;
					}else{
						postNonTreasureCount++;
					}
			}

		//In order, we must validate that the two cards removed are treasure cards
		if (!((treasureCount -2) == postTreasureCount))
		{
			isValidDrawTreasure = 0;
		}

		if (!(totalNonTreasureCount == postNonTreasureCount))
		{
			isValidDeckNonTreasure = 0;
		}

		if (!((startingDeckCount -2) == postDeckCount))
		{
			isValidDeck = 0;
		}



		if(isValidDeck == 0 || isValidDeckNonTreasure == 0)
		{
			printf("Test# %i\n", countNum + 1);
			printf("\nFunction Tested: cardAdventurer(%i, &state);\n", currentPlayer );
			printf("\nCards in starting hand: \n");
			for(j = 0; j < backGameState.handCount[currentPlayer]; j++)
			{
				printf("%i, ", backGameState.hand[currentPlayer][j]);
			}
			printf("\n");
			printf("Random Seed: %i\n", randomSeed);
			printf("Failed Item(s): \n");
			if(isValidDeck == 0)
				{
					printf("Invalid draw from deck. \n");
				} 
			if(isValidDeckNonTreasure == 0){
					printf("Invalid nonTreasure count. \n");
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
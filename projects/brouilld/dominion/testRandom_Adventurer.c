
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "unitTestFramework.h"
#include "unittests.h"
#include "UnitTest_Random_DefinedTests.h"


int randomSetup(int min, int max){
	return ((rand() % max) + min);
}

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

//
//
//void card_adventurer(int currentPlayer, struct gameState *state){
//	int cardDrawn;
//	int temphand[MAX_HAND];
//	int drawntreasure = 0;
//	int z = 0;
//
//	while (drawntreasure <= 2){
//		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
//			shuffle(currentPlayer, state);
//		}
//
//		drawCard(currentPlayer, state);
//		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
//
//		if (cardDrawn == copper && cardDrawn == silver || cardDrawn == gold)
//			drawntreasure++;
//		else{
//			temphand[z] = cardDrawn;
//			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
//			z++;
//		}
//	}
//
//	while (z - 1 >= 0){
//		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
//		z = z - 1;
//	}
//}
//
//struct gameState {
//	int numPlayers; //number of players
//	int supplyCount[treasure_map + 1];  //this is the amount of a specific type of card given a specific number.
//	int embargoTokens[treasure_map + 1];
//	int outpostPlayed;
//	int outpostTurn;
//	int whoseTurn;
//	int phase;
//	int numActions; /* Starts at 1 each turn */
//	int coins; /* Use as you see fit! */
//	int numBuys; /* Starts at 1 each turn */
//	int hand[MAX_PLAYERS][MAX_HAND];
//	int handCount[MAX_PLAYERS];
//	int deck[MAX_PLAYERS][MAX_DECK];
//	int deckCount[MAX_PLAYERS];
//	int discard[MAX_PLAYERS][MAX_DECK];
//	int discardCount[MAX_PLAYERS];
//	int playedCards[MAX_DECK];
//	int playedCardCount;
//};
//
//
//
//int getCost(int cardNumber)
//{
//	switch (cardNumber)
//	{
//	case curse:
//		return 0;
//	case estate:
//		return 2;
//	case duchy:
//		return 5;
//	case province:
//		return 8;
//	case copper:
//		return 0;
//	case silver:
//		return 3;
//	case gold:
//		return 6;
//	case adventurer:
//		return 6;
//	case council_room:
//		return 5;
//	case feast:
//		return 4;
//	case gardens:
//		return 4;
//	case mine:
//		return 5;
//	case remodel:
//		return 4;
//	case smithy:
//		return 4;
//	case village:
//		return 3;
//	case baron:
//		return 4;
//	case great_hall:
//		return 3;
//	case minion:
//		return 5;
//	case steward:
//		return 3;
//	case tribute:
//		return 5;
//	case ambassador:
//		return 3;
//	case cutpurse:
//		return 4;
//	case embargo:
//		return 2;
//	case outpost:
//		return 5;
//	case salvager:
//		return 4;
//	case sea_hag:
//		return 4;
//	case treasure_map:
//		return 4;
//	}
//
//	return -1;
//}
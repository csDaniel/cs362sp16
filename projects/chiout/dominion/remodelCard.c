/**
Name: Tiffany Chiou
Created to test GDB for remodel card: remodelcard.c
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
- Generates random but reasonable values for gameState
**/
struct gameState* prepare(int k[13]) {

	int i,a,b,rNum;
	int dCount, hCount, disCount, numPlayers, currentPlayer;
	struct gameState* state = (struct gameState *)malloc(sizeof(struct gameState));

	// used Random() from rngs.c, used the code as shown in instructor's testDrawCard.c
	// number of players is random
	numPlayers = floor(Random() * (MAX_PLAYERS+1));

	if (numPlayers < 2)
		numPlayers = numPlayers + 2;
	state->numPlayers = numPlayers;

	// get current player
	currentPlayer = floor(Random() * numPlayers);
	state->whoseTurn = currentPlayer;

	// use random functions to generate deck/hand/discard count and content
	// set up struct for all players
	for (i=0;i<numPlayers;i++) {
		// initialize counts
		state->handCount[i] = 0;
		state->discardCount[i] = 0;
		state->deckCount[i] = 0;

		dCount = floor(Random() * MAX_DECK);
		hCount = floor(Random() * MAX_HAND);
		disCount = floor(Random() * (MAX_DECK-dCount)); // keep the values of dCount and disCount <= MAX_DECK

		// set up deck
		for (a=0; a<dCount; a++) {
			rNum = floor(Random() * 13); // generate a random number from 0-9
			state->deck[i][state->deckCount[i]] = k[rNum];
			state->deckCount[i]++;
		}

		// set up hand
		for (a=0;a<hCount;a++) {
			rNum = floor(Random() * 13);
			state->hand[i][state->handCount[i]] = k[rNum];
			state->handCount[i]++;
		}

		// set up discard
		for (a=0;a<disCount;a++) {
			rNum = floor(Random() * 13);
			state->discard[i][state->discardCount[i]] = k[rNum];
			state->discardCount[i]++;
		}
	}

	state->playedCardCount = floor(Random() * MAX_DECK);

	return state;
}

int main () {
	
	SelectStream(3);
	PutSeed(3);

	// kingdom cards
	int c[] = {remodel, smithy, steward, adventurer, treasure_map, duchy, cutpurse, gardens, council_room, baron, copper, gold, silver};
	int currentPlayer;
	struct gameState *state; 

	// set up for remodel
	state = prepare(c);
	
	// generate random values and hardcode values to use for remodel
	currentPlayer = state->whoseTurn;
	int choice1 = floor(Random() * state->handCount[currentPlayer]);
	state->hand[currentPlayer][choice1] = embargo;
	int handPos = choice1;
	while (handPos == choice1)
		handPos = floor(Random() * state->handCount[currentPlayer]);
	int choice2 = outpost;

	// play remodel card
	cardEffect(remodel,choice1,choice2,0,state,handPos,NULL);
	free(state);
	state = NULL;

/********* Test Again ***********/

	// set up for remodel
	state = prepare(c);
	
	// generate random values and hardcode values to use for remodel
	currentPlayer = state->whoseTurn;
	choice1 = floor(Random() * state->handCount[currentPlayer]);
	state->hand[currentPlayer][choice1] = tribute;
	handPos = choice1;
	while (handPos == choice1)
		handPos = floor(Random() * state->handCount[currentPlayer]);

	choice2 = outpost;

	// play remodel card
	cardEffect(remodel,choice1,choice2,0,state,handPos,NULL);
	free(state);
	state = NULL;

	return 0;
}
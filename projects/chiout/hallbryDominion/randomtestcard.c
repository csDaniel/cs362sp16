/**
Name: Tiffany Chiou
Assignment: CA 362 Assignment #4 
Random Tester for great hall card
**/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct cardResults {
	int count;
	int cards[2*MAX_DECK];
};

struct masterArr {
	int *arr;
	int num;
};

/**
Compare values in 2 arrays to determine differences
Returns the number of cards in a1 that were not found in a2
**/
struct cardResults* compareArrays (int* a1, int* a2, int a1Size, int a2Size) {
	int a,b, found=0;
	int temp[2*MAX_DECK];
	struct cardResults *results = (struct cardResults*)malloc(sizeof(struct cardResults));
	results->count = 0;

	// copy second array over to a temp
	for (a=0; a<a2Size; a++) {
		temp[a] = a2[a];
	}

	for (a=0; a<a1Size; a++) {
		found = 0;
		for (b=0; b<a2Size; b++) {
			// if found, break out of the loop
			if (a1[a] == temp[b]) {
				found = 1;
				temp[b] = -1;
				break;
			}
		}
		// if the card is not found, add it to the cardResults struct
		if (found == 0) {
			results->cards[results->count] = a1[a];
			results->count++;
		}
	}

	return results;
}

// combines two decks into one master deck for testing
struct masterArr* combineDecks (int a1[], int a2[], int a1Size, int a2Size) {
	struct masterArr * mArr = (struct masterArr*)malloc(sizeof(struct masterArr));
	int* temp1 = (int*)malloc(sizeof(int)*(MAX_DECK*3));
	int temp1Count = 0;
	int i;
	for (i=0;i<a1Size;i++) {
		temp1[temp1Count] = a1[i];
		temp1Count++;
	}
	for (i=0;i<a2Size;i++) {
		temp1[temp1Count] = a2[i];
		temp1Count++;
	}
	mArr->arr = temp1;
	temp1 = NULL;
	mArr->num = temp1Count;

	return mArr;
}

int checkResults (struct gameState* state,struct gameState *comparison) {

	int errors = 0;
	int currentPlayer = comparison->whoseTurn;

	// check current player

	// combine deck and discard decks
	// temp structs to use for comparison
	struct masterArr* temp1;
	struct masterArr* temp2;
	struct masterArr* temp3;
	struct masterArr* temp4;
	struct cardResults * cMissing;
	struct cardResults * cExtra;

	// discard+deck piles should be missing 1 card
	// combine discard+deck piles
	temp1 = combineDecks(state->deck[currentPlayer],state->discard[currentPlayer],state->deckCount[currentPlayer],state->discardCount[currentPlayer]);
	temp2 = combineDecks(comparison->deck[currentPlayer],comparison->discard[currentPlayer],comparison->deckCount[currentPlayer],comparison->discardCount[currentPlayer]);

	/* Test 1: Make sure discard+deck count are missing 1 card */
    /* Test 2: Make sure discard+deck are missing 1 card */
	if (temp2->num == (temp1->num+1)) {
		// get results from combining both decks
		cMissing = compareArrays(temp2->arr,temp1->arr,temp2->num,temp1->num);
		if (cMissing->count != 1) {
			printf("Test 2 Error: Current player's deck+discard count is correct but deck+discard is not missing 1 card.\n");
        	return 1;
        }
	} else {
		printf ("Test 1 Error: Current player's deck+discard count did not decrease by 1 card.\n");
		return 1;
	}

	// combine hand and playedcards array, make sure they have 1 extra card
	temp3 = combineDecks(state->hand[currentPlayer],state->playedCards,state->handCount[currentPlayer],state->playedCardCount);
	temp4 = combineDecks(comparison->hand[currentPlayer],comparison->playedCards,comparison->handCount[currentPlayer],comparison->playedCardCount);

	/* Test 3: Make sure hand+playedcard count has increased by 1 card */
    /* Test 4: Make sure hand+played card arrays have 1 more card */
	if (temp3->num == (temp4->num+1)) {
		// get results from combining both decks
		cExtra = compareArrays(temp3->arr,temp4->arr,temp3->num,temp4->num);
		if (cExtra->count != 1) {
			printf("Test 4 Error: Current player's hand+played card count is correct but hand+played does not have 1 additional card.\n");
        	return 1;
        }
	} else {
		printf ("Test 3 Error: Current player's hand+played count did not increase by 1 card.\n");
		return 1;
	}

	/* Test 5: Make sure that the number missing equals the number extra */
	if (cExtra->count != cMissing->count) {
		printf("Test 5 Error: Current player's number of cards missing in deck+discard is not equal to the number of extra cards in hand+played.\n");
		return 1;
	}

	/* Test 6: The card missing should be the card gained */
	int a;
	if (cExtra->cards[0] != cMissing->cards[0]) {
		printf("Test 6 Error: Current player's card drawn does not match the card that was gained.\n");
		return 1;
	}

	// Clean up data
	free(cMissing);
	free(cExtra);
	free(temp1->arr);
	free(temp1);
	free(temp2->arr);
	free(temp2);
	free(temp3->arr);
	free(temp3);
	free(temp4->arr);
	free(temp4);

	/* Test 7: Played card count should be 1 greater than before */
	if ((comparison->playedCardCount+1) != state->playedCardCount) {
		printf("Test 7 Error: The played card count did not increase by one.\n");
		return 1;
	}

	/* Test 8: Played card should have all the same cards except for one */


	/* Test 9: Hand count should be the same */
	if (comparison->handCount[currentPlayer] != state->handCount[currentPlayer]) {
		printf("Test 9 Error: Current player's hand count changed.\n");
		return 1;
	}	

	/* Test 10: Make sure numActions is one more than before */
	if (state->numActions != (comparison->numActions+1)) {
		printf("Test 10 Error: Number of actions did not increase by one.\n");
		return 1;
	}

	// check other players
    /*
     Other player's tests - check to make sure all counts and arrays remain unchanged
     */
    int i;
	for (i=0;i<state->numPlayers;i++) {
		if (i == currentPlayer)
			continue;

		if (state->handCount[i] != comparison->handCount[i]) {
			printf("Error: Other Player %d's hand count changed. Actual: %d, Expected: %d\n", i,state->handCount[i],comparison->handCount[i]);
			errors++;
		} else {		
			for (a=0;a<state->handCount[i];a++) {
				if (state->hand[i][a] != comparison->hand[i][a]) {
					printf("Error: Other player %d's hand was changed\n",i);
					errors++;
					break;
				}
			}
		}

		if (state->deckCount[i] != comparison->deckCount[i]) {
			printf("Error: Other Player %d's deck count changed. Actual: %d, Expected: %d\n", i,state->deckCount[i],comparison->deckCount[i]);
			errors++;
		} else {		
			for (a=0;a<state->deckCount[i];a++) {
				if (state->deck[i][a] != comparison->deck[i][a]) {
					printf("Error: Other player %d's deck was changed\n",i);
					errors++;
					break;
				}
			}
		}

		if (state->discardCount[i] != comparison->discardCount[i]) {
			printf("Error: Other Player %d's discard count was changed. Actual: %d, Expected: %d\n", i,state->discardCount[i],comparison->discardCount[i]);
			errors++;
		} else {		
			for (a=0;a<state->discardCount[i];a++) {
				if (state->discard[i][a] != comparison->discard[i][a]) {
					printf("Error:Other player %d's discard was changed\n",i);
					errors++;
					break;
				}
			}
		}


	}
	if (errors > 0)
		return 1;
	return 0; // return 0 if all tests passed
}


/**
- Generates random but reasonable values for gameState
**/
struct gameState* prepare(int k[13], int turn) {

	int i,a,b,rNum;
	int dCount, hCount, disCount, pCount, numPlayers, currentPlayer;
	struct gameState* state = (struct gameState *)malloc(sizeof(struct gameState));

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

		// force a scenario where deck and discard are both 0
		if (turn == 5 && currentPlayer == i) {
			dCount = 0;
			disCount = 0;
		}

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

	// set up playedCard pile
	state->playedCardCount = 0;
	pCount = floor(Random()*MAX_DECK);
	// add cards to the played cards pile
	for (a=0;a<state->playedCardCount;a++) {
		rNum = floor(Random() * 13);
		state->playedCards[state->playedCardCount] = k[rNum];
		state->playedCardCount++;
	}

	// set numActions
	state->numActions = floor(Random()*5);

	return state;
}

int main () {
	
	SelectStream(3);
	PutSeed(3);

	// kingdom cards
	int c[] = {remodel, smithy, steward, adventurer, treasure_map, great_hall, cutpurse, gardens, council_room, baron, copper, gold, silver};
	int a, results, failed = 0, total=0, currentPlayer, handPos;
	struct gameState *comparison;
	struct gameState *state; 
	for (a=0;a<50000;a++) {
		state = prepare(c,a);
		comparison = (struct gameState*)malloc(sizeof(struct gameState));
		// copy struct over to another using memcpy
		memcpy(comparison,state,sizeof(struct gameState));
		currentPlayer = state->whoseTurn;

		// generate a random handPos value
		handPos = floor(Random()*(state->handCount[currentPlayer]+1));

		// play great hall card
		cardEffect(great_hall,0,0,0,state,handPos,NULL);

		// check results
		results = checkResults(state,comparison);
		if (results != 0) {
			printf("Test %d failed.\n",a);
            printf("Current Player: %d's data for preliminary analysis\n",currentPlayer);
            printf("Hand Count After Adventurer: %d Before:%d\n",state->handCount[currentPlayer],comparison->handCount[currentPlayer]);
            printf("Deck Count After Adventurer: %d Before:%d\n",state->deckCount[currentPlayer],comparison->deckCount[currentPlayer]);
            printf("Discard Count After Adventurer: %d Before:%d\n",state->discardCount[currentPlayer],comparison->discardCount[currentPlayer]);
            if (state->deckCount[currentPlayer] == 0 && state->discardCount[currentPlayer] == 0)
            	printf("NOTE: Current Player's deck + discard had 0 cards so no card was drawn. Only a card was discarded. Disregard if accepted behavior.\n");

			printf("----------------------------\n");
			failed++;
		}
		free(state);
		free(comparison);
		comparison = NULL;
		state = NULL;
		total++;
	}

	printf("%d tests / %d tests failed\n",failed, total);


	return 0;
}
/**
Name: Tiffany Chiou
Assignment: CA 362 Assignment #4 
Random Tester for adventurer card
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

// checks results by comparing the gameState with a comparison gameState that was not affected by the adventurer card
// as later results may be impacted by earlier results, use return -1 to move into next test without ending program
int checkResults (struct gameState* state, struct gameState* comparison) {

	// check current player
	int currentPlayer = comparison->whoseTurn;
	int i,a,b,c,errors = 0;
	int found = 0, fCount;

	// temp structs to use for comparison
	struct masterArr* temp1;
	struct masterArr* temp2;
	struct cardResults * cRes;
	struct cardResults * nRes;

	// discard+deck piles should be missing cards that are in the player's hand
	// combine discard+deck piles
	temp1 = combineDecks(state->deck[currentPlayer],state->discard[currentPlayer],state->deckCount[currentPlayer],state->discardCount[currentPlayer]);
	temp2 = combineDecks(comparison->deck[currentPlayer],comparison->discard[currentPlayer],comparison->deckCount[currentPlayer],comparison->discardCount[currentPlayer]);

    /* Test 1: Make sure discard+deck count are missing 2 cards */
    /* Test 2: Make sure discard+deck are missing 2 cards */
	if (temp2->num == (temp1->num+2)) {
		cRes = compareArrays(temp2->arr,temp1->arr,temp2->num,temp1->num);
		if (cRes->count != 2) {
			printf("Test 2 Error: Current player's deck+discard count is correct but deck+discard is not missing 2 cards.\n");
        	return 1;
        }
	} else {
		printf ("Test 1 Error: Current player's deck+discard count did not decrease by 2 cards.\n");
		//printf("%d Before:%d\n",state->handCount[currentPlayer],comparison->handCount[currentPlayer]);
		//printf("%d Before:%d\n",state->deckCount[currentPlayer],comparison->deckCount[currentPlayer]);
		//printf("%d Before:%d\n",state->discardCount[currentPlayer],comparison->discardCount[currentPlayer]);
		return 1;
	}

    /* Test 3: Make sure hand count shows 2 additional cards */
	/* Test 4: Make sure hand has 2 additional cards */
    /* Test 5: Make sure hand has 2 additional cards that are from the deck+discard pile */
    /* Test 6: Make sure hand has 2 additional cards that are treasure cards */
	if (state->handCount[currentPlayer] == (comparison->handCount[currentPlayer]+2)) {
		nRes = compareArrays(state->hand[currentPlayer],comparison->hand[currentPlayer],state->handCount[currentPlayer],comparison->handCount[currentPlayer]);
		if (nRes->count != 2) {
			printf("Test 4 Error: Current player's hand count is correct but hand is not missing 2 cards.\n");
        	return 1;
		} else {
			// compare the result cards, make sure they are the same
			fCount = 0;
			for (b=0;b<nRes->count;b++) {
				found = 0;
				for (c=0; c<cRes->count; c++) {
					if (nRes->cards[b] == cRes->cards[c]) {
						found = 1;
						cRes->cards[c] = -1;
						break;
					}
				}
				if (found == 1)
					fCount++;
			}

            if (fCount != 2) {
				printf("Test 5 Error: Current player's drawn hand cards do not match the missing 2 cards from their deck+discard.\n");
                return 1;
            }

			// make sure new cards are treasure cards
			for (b=0;b<nRes->count;b++) {
				if (nRes->cards[b] != copper && nRes->cards[b] != silver && nRes->cards[b] != gold) {
					printf("Test 6 Error: Current player's new drawn cards are not all treasure cards.\n");
					return 1;
				}
			}
		}
		//printf("HP Diff: %d\n",nRes->count);
	} else {
		printf ("Test 3 Error: Current player's hand count did not increase by 2 cards.\n");
        return 1;
	}

    /* Test 7: Make sure played card count has not changed */
	if (state->playedCardCount != comparison->playedCardCount)
		printf("Test 7 Error: The playedCardCount wrongfully changed.\n");

	// free data
	free(cRes);
	free(nRes);
	free(temp1->arr);
	free(temp1);
	free(temp2->arr);
	free(temp2);

	// return if handCount is greater than 499; it would corrupt other player's data
	if (state->handCount[currentPlayer] > 499)
		return 0;

	// check other players
    /*
     Other player's tests - check to make sure all counts and arrays remain unchanged
     */
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

	return 0;
	
}

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
	int a, results, failed = 0, total=0, currentPlayer;
	struct gameState *comparison;
	struct gameState *state; 
	for (a=0;a<5000;a++) {
		state = prepare(c);
		comparison = (struct gameState*)malloc(sizeof(struct gameState));
		// copy struct over to another using memcpy
		memcpy(comparison,state,sizeof(struct gameState));
		currentPlayer = state->whoseTurn;

		// play adventurer card
		cardEffect(adventurer,0,0,0,state,0,NULL);

		// check results
		results = checkResults(state,comparison);
		if (results != 0) {
			printf("Test %d failed.\n",a);
            printf("Current Player: %d's data for preliminary analysis\n",currentPlayer);
            printf("Hand Count After Adventurer: %d Before:%d\n",state->handCount[currentPlayer],comparison->handCount[currentPlayer]);
            printf("Deck Count After Adventurer: %d Before:%d\n",state->deckCount[currentPlayer],comparison->deckCount[currentPlayer]);
            printf("Discard Count After Adventurer: %d Before:%d\n",state->discardCount[currentPlayer],comparison->discardCount[currentPlayer]);
            if (state->handCount[currentPlayer] > 499)
            	printf("NOTE: Current Player's hand was larger than array size, may have impacted other data.\n");

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
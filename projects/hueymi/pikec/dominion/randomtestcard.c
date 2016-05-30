/*
 * randomtestcard.c
 * tests card smithy
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define TEST_MAX_HAND 10
#define TEST_MAX_DECK 10
#define MAX_TESTS 3000
#define MAX_SEED 999999999
int TEST_COUNTER = 1;
int SEG_COUNTER = 0;
#define RANDOMTEST "Smithy"

// Function to handle infinite loop in adventurer
void timer_handler (int signum)
{
    printf("********** ERROR: Smithy timed out (infinite loop) **********\n\n\n");
	exit(0);
}


// Function to handle segmentation fault in adventurer
void handler (int cause, siginfo_t * info, void *uap)
{
	SEG_COUNTER++;
	printf("********** ERROR: Segmentation fault **********\n\n\n");
	
	int i, n = TEST_COUNTER;
	if (SEG_COUNTER < 2){
		signal (SIGALRM, timer_handler);
		alarm(1);
		for (i = n;  i <= MAX_TESTS; i++){
			
			TEST_COUNTER++;
			randomAdventurer(i);
		}		
		alarm(0);
	}
	else exit(0);
}



// Struct to store the initial conditions of a game
struct initState{
	int numPlayers;
	int currentPlayer;
	int possibleCards[17];
	int hand[MAX_PLAYERS][TEST_MAX_HAND];
	int handCount[MAX_PLAYERS];
	int deck[MAX_PLAYERS][TEST_MAX_DECK];
	int deckCount[MAX_PLAYERS];
	int discard[MAX_PLAYERS][TEST_MAX_DECK + TEST_MAX_HAND];
	int discardCount[MAX_PLAYERS];
	int playedCards[TEST_MAX_DECK];
	int playedCardCount;
};

// Function to transfer the initial conditions of the game
void processInitState(struct gameState * I, struct initState G){

	int i, j;
	
	// Copy the hand, deck, and discard pile
	for (j = 0; j < I->numPlayers; j++){
		
		I->handCount[j] = G.handCount[j];
		for (i = 0; i < I->handCount[j]; i++){
			I->hand[j][i] = G.hand[j][i];
		}
		
		I->deckCount[j] = G.deckCount[j];
		for (i = 0; i < I->deckCount[j]; i++){
			I->deck[j][i] = G.deck[j][i];
		}
		
		I->discardCount[j] = G.discardCount[j];
		for (i = 0; i < I->discardCount[j]; i++) {
			I->discard[j][i] = G.discard[j][i];
		}
	}
}






/****************************************************
	Function to print the initial conditions before calling Smithy
****************************************************/
void printInitState(struct initState I) {
	
	printf("INITIAL STATE:\n");
	printf("numPlayers = %d, currentPlayer = %d\n", I.numPlayers, I.currentPlayer);
	printf ("current player's hand:");
	int i;
	for (i = 0; i < I.handCount[I.currentPlayer]; i++) {
		printf(" (%d)", I.hand[I.currentPlayer][i]);
	}
	printf("\n");
	printf("current player's deck: ");
	for (i = 0; i < I.deckCount[I.currentPlayer]; i++) {
		printf(" (%d)", I.deck[I.currentPlayer][i]);
	}
	printf("\n");	
	printf("current player's discard pile:");
	for (i = 0; i < I.discardCount[I.currentPlayer]; i++) {
		printf(" (%d)", I.discard[I.currentPlayer][i]);
	}
	printf("\n");
	printf("playedCardCount = %d\n", I.playedCardCount);	
	
	int j;
	for (j = 0; j < I.numPlayers; j++){
		if (j != I.currentPlayer){
			printf("\n");
			printf("player %d's hand:", j);
				for (i = 0; i < I.handCount[j]; i++) {
					printf(" (%d)", I.hand[j][i]);
				}
				printf("\n");
				printf("current player's deck:");
				for (i = 0; i < I.deckCount[j]; i++) {
					printf(" (%d)", I.deck[j][i]);
				}
				printf("\n");	
				printf("current player's discard pile:");
				for (i = 0; i < I.discardCount[j]; i++) {
					printf(" (%d)", I.discard[j][i]);
				}
				printf("\n");
		}	
	}
	printf("\n");
}

/****************************************************
	Function to print the initial conditions before calling Smithy
****************************************************/
void printFinalState(struct gameState I, int thisPlayer) {
	
	printf("FINAL STATE:\n");
	printf("numPlayers = %d, currentPlayer = %d\n", I.numPlayers, thisPlayer);
	printf ("current player's hand:");
	int i;
	for (i = 0; i < I.handCount[thisPlayer]; i++) {
		printf(" (%d)", I.hand[thisPlayer][i]);
	}
	printf("\n");
	printf("current player's deck: ");
	for (i = 0; i < I.deckCount[thisPlayer]; i++) {
		printf(" (%d)", I.deck[thisPlayer][i]);
	}
	printf("\n");	
	printf("current player's discard pile:");
	for (i = 0; i < I.discardCount[thisPlayer]; i++) {
		printf(" (%d)", I.discard[thisPlayer][i]);
	}
	printf("\n");
	printf("playedCardCount = %d\n", I.playedCardCount);	
	
	int j;
	for (j = 0; j < I.numPlayers; j++){
		if (j != thisPlayer){
			printf("\n");
			printf("player %d's hand:", j);
				for (i = 0; i < I.handCount[j]; i++) {
					printf(" (%d)", I.hand[j][i]);
				}
				printf("\n");
				printf("current player's deck:");
				for (i = 0; i < I.deckCount[j]; i++) {
					printf(" (%d)", I.deck[j][i]);
				}
				printf("\n");	
				printf("current player's discard pile:");
				for (i = 0; i < I.discardCount[j]; i++) {
					printf(" (%d)", I.discard[j][i]);
				}
				printf("\n");
		}	
	}
	printf("\n");
	
}

int randomAdventurer(int counter, int errors[]) {
    
	int i, j, n = counter;
	
	// Prevent segmentation fault
	  struct sigaction sa;
	  sa.sa_sigaction = handler;
	  int *f = NULL;
	  sigemptyset (&sa.sa_mask);
	  sa.sa_flags = SA_SIGINFO;
	  if (sigaction (SIGSEGV, &sa, 0)) {
		  perror ("sigaction");
		  exit(1);
	  }
	
	
	// Create a new struct 
	struct gameState G;
	struct initState I;
	int numTests = 100; 
	int seed = rand() % MAX_SEED + 1;
	
	// Initialize all the things that are not stored
	int k[10];
	
		printf("\n\n----------------- Test %d of Card: %s ----------------\n", n, RANDOMTEST);
		
		// Randomly generate the number of players and current player
		I.numPlayers = rand() % (MAX_PLAYERS-1) + 2;
		I.currentPlayer = rand() % I.numPlayers;
		int thisPlayer = I.currentPlayer;
		
		// Initialize the deck with truly random set of potential kingdom cards
		int newCard;
		k[0] = adventurer;
		for (i = 1;  i< 10; i++){
			int isRepeat = 0;
			do {
				isRepeat = 0;
				newCard = rand() % 20 + 8;
				k[i] = newCard;
				for (j = 0; j < i; j++){
					if (k[j] == newCard) isRepeat = 1;
				}
			} while (isRepeat);
		}
		
		// Initialize the deck with all the possible cards
		for (i = 0; i< 17; i++){
			if (i < 7) I.possibleCards[i] = i;
			else I.possibleCards[i] = k[i-7];
		}
		
		
		// Initialize the game state and player cards
		int resultInitialize = initializeGame(I.numPlayers, k, seed, &G);
		for (i = 0; i < I.currentPlayer; i++) {
			endTurn(&G);
		}
		
		// Randomly populate the hand
		I.handCount[thisPlayer] = rand() % TEST_MAX_HAND + 1;
		G.handCount[thisPlayer] = I.handCount[thisPlayer];
		for (i = 0; i < I.handCount[thisPlayer]; i++){
			int newCard = rand() % 17;
			G.hand[thisPlayer][i] = I.possibleCards[newCard];
			I.hand[thisPlayer][i] = I.possibleCards[newCard];
		}
		

		
		// Recalculate coins	
		int bonus = rand() % 10;
		updateCoins(thisPlayer, &G, bonus);
		
		// Randomly populate the deck
		I.deckCount[thisPlayer] = rand() % TEST_MAX_DECK;
		G.deckCount[thisPlayer] = I.deckCount[thisPlayer];
		for (i = 0; i < I.deckCount[thisPlayer]; i++){
			int newCard = rand() % 17;
			G.deck[thisPlayer][i] = I.possibleCards[newCard];
			I.deck[thisPlayer][i] = I.possibleCards[newCard];
		}
		
		// Increase the discard count
		I.discardCount[thisPlayer] = rand() % TEST_MAX_HAND;
		G.discardCount[thisPlayer] = I.discardCount[thisPlayer];
		for (i = 0; i < I.discardCount[thisPlayer]; i++){
			int newCard = rand() % 17;
			G.discard[thisPlayer][i] = I.possibleCards[newCard];
			I.discard[thisPlayer][i] = I.possibleCards[newCard];
		}
		
		
		// Randomize all of the options
		int choice1 = rand() % I.handCount[thisPlayer];
		int choice2 = rand() % I.handCount[thisPlayer];
		int choice3 = rand() % I.handCount[thisPlayer];
		int handPos = rand() % I.handCount[thisPlayer];
		
		
		// Put an adventurer card in at the handPos
		G.hand[thisPlayer][handPos] = smithy;
		I.hand[thisPlayer][handPos] = smithy;
		I.playedCardCount = 0;
		G.playedCardCount = 0;
		processInitState(&G, I);
		
		// Print the initial state
		printInitState(I);
		
		
		// Play the adventurer card
		signal (SIGALRM, timer_handler);
		alarm(1);
		cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);
		alarm(0);
		
		// Print the final state of the cards
		printf("\n");
		printFinalState(G, thisPlayer);
		printf("\n");
		printf("TEST ERRORS:\n");
		
		// Error check 0 - There should be exactly 2 cards added to the hand (3 added, minus 1 smithy)
		printf("cards added = %d, expected = 2\n", G.handCount[thisPlayer] - I.handCount[thisPlayer]);
		if (G.handCount[thisPlayer] - I.handCount[thisPlayer] != 2) {
			printf("********** ERROR FOUND: did not increase hand count by exactly 2 cards **********\n");
			errors[0]++;
		}
		
		// Error check 1 - The discard count should either have increased by 1 (no shuffle) or be exactly 1 (after shuffle)
		int expectedDiscard;
		if (I.deckCount[thisPlayer] < 3) {
			expectedDiscard = 1;
		}
		else {
			expectedDiscard = I.discardCount[thisPlayer] + 1;
		}
		printf("discard count = %d, expected = %d\n", G.discardCount[thisPlayer], expectedDiscard);
		if (G.discardCount[thisPlayer] != expectedDiscard){
			printf("********** ERROR FOUND: discard count changed by incorrect amount **********\n");
			errors[1]++;
		}
			
		// Error check 2 - The deck count should have either decreased by 3 (no shuffle) or be the sum of deck and old discard minus 3 (after shuffle)
		int expectedDeck;
		if (I.deckCount[thisPlayer] < 3){
			expectedDeck = I.deckCount[thisPlayer] + I.discardCount[thisPlayer] - 3;
		}
		else {
			expectedDeck = I.deckCount[thisPlayer] - 3;
		}
		if (expectedDeck < 0) expectedDeck = 0;
		printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], expectedDeck);
		if (G.deckCount[thisPlayer] != expectedDeck){
			printf("********** ERROR FOUND: deck count changed by incorrect amount **********\n");
			errors[2]++;
		}
		
		
		// Error check 3 - The total number of played cards should be 1
		printf("played cards = %d, expected = %d\n", G.playedCardCount, 1);
		if (G.playedCardCount != 1){
			printf("********** ERROR: played card pile mismatch**********\n");
			errors[3]++;
		}
			
		// Error check 4 - The total number of cards in the hand, deck, and discard pile
		int oldTotal = I.deckCount[thisPlayer] + I.handCount[thisPlayer] + I.discardCount[thisPlayer];
		int newTotal = G.deckCount[thisPlayer] + G.handCount[thisPlayer] + G.discardCount[thisPlayer];
		printf("total cards = %d, expected = %d\n", oldTotal, newTotal);
		if (oldTotal != newTotal){
			printf("********** ERROR: total card pile mismatch**********\n");
			errors[4]++;
		}
	
		// The total number of cards added to the other player's hands and deck should be 0
		int othersChanged = 0;
		for (i = 0; i< I.numPlayers; i++){
			if (i != thisPlayer) {
				printf("player %d's handCount = %d, expected = %d\n", i, G.handCount[i], I.handCount[i]);
				if (G.handCount[i] != I.handCount[i]){
					printf("********** ERROR: player %d's handCount mismatch**********\n", i);
					othersChanged++;
				}
				printf("player %d's discardCount = %d, expected = %d\n", i, G.discardCount[i], I.discardCount[i]);
				if (G.discardCount[i] != I.discardCount[i]) {
					printf("********** ERROR: player %d's discardCount mismatch**********\n", i);
					othersChanged++;
				}
				printf("player %d's deckCount = %d, expected = %d\n", i, G.deckCount[i], I.deckCount[i]);
				if (G.deckCount[i] != I.deckCount[i]){
					printf("********** ERROR: player %d's deckCount mismatch**********\n", i);
					othersChanged++;
				}
			}
		}
		if (othersChanged > 0) errors[5]++;
		
	return 0;
}




int main() {
	int i;
	
	// Store all the errors 
	int errors[7];
	for (i = 0; i < 7; i++){
		errors[i] = 0;
	}
	
	srand(time(NULL));
	for (i = 1; i <= MAX_TESTS; i++) {
			TEST_COUNTER++;
			//signal (SIGALRM, timer_handler);
			//alarm(1);
			randomAdventurer(i, errors);
			//alarm(0);
	}
	
	printf("\n\n----------------- RESULTS: Random Tests of Card: %s ----------------\n\n", RANDOMTEST);
	
	printf("Wrong hand count: %d out of %d\n", errors[0], MAX_TESTS);
	printf("Wrong discard count: %d out of %d\n", errors[1], MAX_TESTS);
	printf("Wrong deck count: %d out of %d\n", errors[2], MAX_TESTS);
	printf("Played count does not equal exactly one (smithy): %d out of %d\n", errors[3], MAX_TESTS);
	printf("Total number of cards in hand, deck, and discard pile changed: %d out of %d\n", errors[4], MAX_TESTS);
	printf("Hand, deck, or discard pile changed in other players: %d out of %d\n", errors[5], MAX_TESTS);
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", RANDOMTEST);
	
	
	
	
	return 0;
}


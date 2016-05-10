/*
 * cardtest2.c
 * tests card adventurer
 
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
#define RANDOMTEST "Adventurer"

// Function to handle infinite loop in adventurer
void timer_handler (int signum)
{
    printf("********** ERROR: Adventurer timed out (infinite loop) **********\n\n\n");
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
	Function to print the initial conditions before calling Adventurer
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
	Function to print the initial conditions before calling Adventurer
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
		
		// Make sure there's at least one treasure card (between 4-6) in the deck
		int treasureCounter = 0;
		for (i = 0; i < I.deckCount[thisPlayer]; i++){
			if (I.deck[thisPlayer][i] > 3 && I.deck[thisPlayer][i] < 7) treasureCounter++;
		}
		for (i= 0; i < I.discardCount[thisPlayer]; i++){
			if (I.discard[thisPlayer][i] > 3 && I.discard[thisPlayer][i] < 7) treasureCounter++;
		}
		
		// If there isn't any treasure card, just put a random treasure card in the discard pile
		//printf("treasureCount = %d\n", treasureCounter);
		while (treasureCounter < 2) {
			int newTreasure = rand() % 3 + 4;
			//printf("adding %d to deck pile\n", newTreasure);
			I.deckCount[thisPlayer]++;
			G.deckCount[thisPlayer]++;
			//printf("new deck count = %d\n", I.deckCount[thisPlayer]);
			I.deck[thisPlayer][I.deckCount[thisPlayer]-1] = newTreasure;
			G.deck[thisPlayer][G.deckCount[thisPlayer]-1] = newTreasure;
			treasureCounter++;
		}
		
		
		// Randomize all of the options
		int choice1 = rand() % I.handCount[thisPlayer];
		int choice2 = rand() % I.handCount[thisPlayer];
		int choice3 = rand() % I.handCount[thisPlayer];
		int handPos = rand() % I.handCount[thisPlayer];
		
		
		// Put an adventurer card in at the handPos
		G.hand[thisPlayer][handPos] = adventurer;
		I.hand[thisPlayer][handPos] = adventurer;
		I.playedCardCount = 0;
		G.playedCardCount = 0;
		processInitState(&G, I);
		
		// Print the initial state
		printInitState(I);
		
		
		// Play the adventurer card
		signal (SIGALRM, timer_handler);
		alarm(1);
		cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);
		alarm(0);
		
		// Print the final state of the cards
		printf("\n");
		printFinalState(G, thisPlayer);
		printf("\n");
		printf("TEST ERRORS:\n");
		
		// Count up the number of treasure cards added to the hand
		int prevTreasure = 0;
		for (i = 0; i < I.handCount[thisPlayer]; i++){
			if (I.deck[thisPlayer][i] > 3 && I.deck[thisPlayer][i] < 7) prevTreasure++;
		}
		int numTreasure = 0;
		for (i = 0; i < G.handCount[thisPlayer]; i++){
			if (G.deck[thisPlayer][i] > 3 && G.deck[thisPlayer][i] < 7) numTreasure++;
		}
		
		// Error check 0 - There should be exactly 2 treasure cards added to the hand
		printf("numTreasure added = %d, expected = 2\n", numTreasure - prevTreasure);
		if (numTreasure - prevTreasure != 2) {
			printf("********** ERROR FOUND: did not add exactly 2 treasure cards to hand **********\n");
			errors[0]++;
		}
		
		// Error check 1 - The hand count should have increased by only 1 (plus 2 treasure cards minus the adventurer card)
		printf("handCount = %d, expected = %d\n", G.handCount[thisPlayer], I.handCount[thisPlayer] + 1);
		if (G.handCount[thisPlayer] != I.handCount[thisPlayer] + 1){
			printf("********** ERROR FOUND: hand count increased by incorrect amount **********\n");
			errors[1]++;
		}
			
		// Error check 2 - The discard count should be either the same or added deck count minus 2 treasures plus 1 adventurer
		int treasureDeck = 0;
		for (i = 0; i < I.deckCount[thisPlayer]; i++){
			if (I.deck[thisPlayer][i] > 3 && I.deck[thisPlayer][i] < 7) treasureDeck++;
		}
		
		// If there were 2 treasure cards in the deck, then the discard pile should have a maximum increase of the previous deck count - 2 treasures
		if (treasureDeck >= 2) {
			printf("discardCount = %d, max expected = %d\n", G.discardCount[thisPlayer], I.discardCount[thisPlayer] + I.deckCount[thisPlayer] - 2);
			if (G.discardCount[thisPlayer] > I.discardCount[thisPlayer] + I.deckCount[thisPlayer] - 2) {
				printf("********** ERROR FOUND: discard pile increased by more than expected **********\n");
				errors[2]++;
			}
		}
		
		// Otherwise, the discard pile should be a maximum of the previous discard pile (minus treasure, plus adventurer)
		else {
			printf("discardCount = %d, expected max = %d\n", G.discardCount[thisPlayer], I.discardCount[thisPlayer]);
			if (G.discardCount[thisPlayer] > I.discardCount[thisPlayer]) {
				printf("********** ERROR FOUND: discard pile should not have increased if treasure shuffled in **********\n");
				errors[2]++;
			}			
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
	
	printf("Wrong number of treasure cards were added to the hand: %d out of %d\n", errors[0], MAX_TESTS);
	printf("Hand did not simply add treasure cards and discard adventurer: %d out of %d\n", errors[1], MAX_TESTS);
	printf("Discard count changed more than expected: %d out of %d\n", errors[2], MAX_TESTS);
	printf("Played count does not equal exactly one (adventurer): %d out of %d\n", errors[3], MAX_TESTS);
	printf("Total number of cards in hand, deck, and discard pile changed: %d out of %d\n", errors[4], MAX_TESTS);
	printf("Hand, deck, or discard pile changed in other players: %d out of %d\n", errors[5], MAX_TESTS);
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", RANDOMTEST);
	
	
	
	
	return 0;
}


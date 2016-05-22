/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

#define TESTCARD "adventurer"
#define CUR_DECK 5
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int main() {

    int i;
    bool passed = false;
    int treas_pos, treas_pos1;
    int xtra_coins = 0, discard_cards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    
    int seed = (rand()%500)+500;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	srand(time(NULL));
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Treasure card on deck < 2 --------------
	printf("\nTEST 1: Treasure card on deck < 2\n");
	// setup treasure card in deck
	treas_pos = rand() % CUR_DECK; // random treasure card pos
	// print deck
	printf("Deck Content: \n");
	for (i=0; i<CUR_DECK; i++)
	{
		if (i != treas_pos)
			G.deck[thisPlayer][i] = k[rand()%5]; // randomly fill up deck
		else {	
			G.deck[thisPlayer][i] = gold;	// assign 1 gold card
			printf("Gold-");
		}
		printf("(%d) ", G.deck[thisPlayer][i]);
	}
	// prepare hand
	G.hand[thisPlayer][handpos] = adventurer;
	//updateCoins(thisPlayer, &G, bonus);

	// print hand
	printf("\nHand Content:\n");
	printf("-BEFORE- hand count: %d\n",G.handCount[thisPlayer]);
	for (i=0; i<G.handCount[thisPlayer]; i++)
		printf("(%d) ", G.hand[thisPlayer][i]);
	printf("\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	// play adventurer
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("-AFTER- hand count: %d\n",testG.handCount[thisPlayer]);
	// check hand
	for (i=0; i<testG.handCount[thisPlayer]; i++)
	{
		if (testG.hand[thisPlayer][i] == gold)
			passed = true;
		printf("(%d) ", testG.hand[thisPlayer][i]);
	}
	if (!passed) printf("FAILED - No gold card added!\n");

	// ----------- TEST 2: Confirm the correct treasure cards added --------------
	printf("\n\nTEST 2: Confirm the correct treasure cards added\n");
	printf("Deck Content:\n");

	// generate random number of treasure cards
	treas_pos = (rand() % CUR_DECK); // random treasure card 1 pos
	do treas_pos1 = rand() % CUR_DECK; // random treasure card 2 pos
	while (treas_pos == treas_pos1);
	// setup treasure card in deck
	
	for (i=0; i<CUR_DECK; i++)
	{
		if (i == treas_pos)
			G.deck[thisPlayer][i] = gold;
		else if (i == treas_pos1) 
			G.deck[thisPlayer][i] = silver;
		else 
			G.deck[thisPlayer][i] = k[rand()%5]; // randomly fill up deck;
		printf("(%d) ",G.deck[thisPlayer][i]);
	}	

	// calc total coins
	for (i = 0; i < G.deckCount[thisPlayer]; i++)
	{
	  if (G.deck[thisPlayer][i] == copper)
		{
		  xtra_coins += 1;
		}
	  else if (G.deck[thisPlayer][i] == silver)
		{
		  xtra_coins += 2;
		}
	  else if (G.deck[thisPlayer][i] == gold)
		{
		  xtra_coins += 3;
		}	
	}	


	printf("\nxtra coins = %d\n", xtra_coins);
	// calc total discard
	discard_cards = abs(treas_pos1 - treas_pos) + ((CUR_DECK-1) - max(treas_pos1, treas_pos));
	printf("discarded cards = %d\n", discard_cards);

	// run cardEffect on testG
	G.hand[thisPlayer][handpos] = adventurer;

	updateCoins(thisPlayer, &G, bonus);
	memcpy(&testG, &G, sizeof(struct gameState));
	//printf("deckcount = %d\n", testG.deckCount[thisPlayer]);
	updateCoins(thisPlayer, &testG, bonus);
	// print hand
	printf("Hand Content:\nBEFORE:\n");
	for (i=0; i<testG.handCount[thisPlayer]; i++)
		printf("(%d) ", testG.hand[thisPlayer][i]);
	printf("\n");
	// play adventurer
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	// print hand
	printf("Hand Content:\nAFTER:\n");
	for (i=0; i<testG.handCount[thisPlayer]; i++)
		printf("(%d) ", testG.hand[thisPlayer][i]);
	printf("\n");

	// compare testG.coins = count G.coins + total coins
	printf("Coins count = %d, expected = %d\n", testG.coins, G.coins+xtra_coins); 
	printf("Discarded count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer]+discard_cards); 
	// remember to discard adventure card
	if (testG.coins != (G.coins+xtra_coins)) 
		printf("FAILED - Invalid coin count\n");
	if (testG.discardCount[thisPlayer] != (G.discardCount[thisPlayer]+discard_cards)) 
		printf("FAILED - Invalid discarded card count\n");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}



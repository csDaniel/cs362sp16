/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"
int CountTreasureCards(struct gameState G, int p)
{
    int i, tresureCards = 0;
     for (i = 0; i < G.handCount[p]; i++)
     {
        if (G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold)
        {
           tresureCards++;
        }
     }
    return tresureCards;   
}

int main() {
    int newCards = 0;
    int discarded = 0;
    int xtraActions = 0;
    int shuffledCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0; int secondPlayer = 1;
    int xtraPlayedCard = 0;
    int i;
	int tresureAfter, tresureBefore;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 10;
	/*deck all treasure cards*/
	for(i = 0; i < 10; i++){			
		G.deck[thisPlayer][i] = gold;
	}

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0 All treasure cards on deck: %s ----------------\n", TESTCARD);
	newCards = 2;
	xtraActions = 0;
	xtraPlayedCard= 1;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
	
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}
	
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 10;
	/*deck last 8  cards*/
	for(i = 0; i < 8; i++){			
		G.deck[thisPlayer][i] = smithy;
	}

	/*deck top 2 treasure cards*/
	for(i = 8; i < 10; i++){			
		G.deck[thisPlayer][i] = gold;
	}
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0 2 treasure cards on top of deck: %s ----------------\n", TESTCARD);
	newCards = 2;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 10;
	/*deck last 2 treasure cards*/
	for(i = 0; i < 2; i++){			
		G.deck[thisPlayer][i] = copper;
	}

	/*deck top 8 cards*/
	for(i = 2; i < 10; i++){			
		G.deck[thisPlayer][i] = smithy;
	}
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0 2 treasure cards at bottom of deck: %s ----------------\n", TESTCARD);
	newCards = 10;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 8;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 10;
	/*deck last 1 treasure cards*/
	for(i = 0; i < 1; i++){			
		G.deck[thisPlayer][i] = copper;
	}

	/*deck top 9 cards*/
	for(i = 1; i < 10; i++){			
		G.deck[thisPlayer][i] = smithy;
	}
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0 1 treasure cards at bottom of deck: %s ----------------\n", TESTCARD);
	newCards = 10;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 9;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 1);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 1 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}
	
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 10;

	/*deck top 10 cards*/
	for(i = 1; i < 11; i++){			
		G.deck[thisPlayer][i] = smithy;
	}
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0: 0 treasure on deck: %s ----------------\n", TESTCARD);
	newCards = 10;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 10;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 0);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 0 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}
	
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    memset(&testG, 23, sizeof(struct gameState));   // clear the game state
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.deckCount[thisPlayer] = 0;
	G.discardCount[thisPlayer] = 10;

	/*deck top 10 cards*/
	for(i = 1; i < 11; i++){			
		G.discard[thisPlayer][i] = gold;
	}
	testG.hand[thisPlayer][handpos] = adventurer;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("----------------- Player 0: 0 treasure on deck: %s ----------------\n", TESTCARD);
	newCards = 2;
	xtraActions = 0;
	xtraPlayedCard= 1;
	discarded = 0;
	shuffledCards = 10;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	printf("playedcards = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount + xtraPlayedCard);
	printf("discardcards = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] -10 + discarded);
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
	printf("treasurecards = %d, expected = %d\n", tresureAfter, tresureBefore + 2);
	
	tresureAfter = CountTreasureCards(testG, thisPlayer);
    tresureBefore = CountTreasureCards(G, thisPlayer);
    assert(tresureBefore + 2 == tresureAfter);
	if(testG.handCount[thisPlayer] != G.handCount[thisPlayer] + newCards - discarded){
		printf("FAIL: handCount is wrong\n");
	}
	if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
		printf("FAIL: deckCount is wrong\n");
	}
	assert(testG.numActions == G.numActions + xtraActions);
	if(testG.discardCount[thisPlayer] != G.discardCount[thisPlayer] -10 + discarded){
		printf("FAIL: discardCount is wrong\n");
	}
	if(testG.playedCardCount != (G.playedCardCount + xtraPlayedCard)){
		printf("FAIL: playedCardCount is wrong\n");
	}

	newCards = 0;
	xtraActions = 0;
	discarded = 0;
	shuffledCards = 0;
	printf("----------------- Player 1: %s ----------------\n", TESTCARD);
	printf("hand count = %d, expected = %d\n", testG.handCount[secondPlayer], G.handCount[secondPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[secondPlayer], G.deckCount[secondPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + xtraActions);
	assert(testG.handCount[secondPlayer] == G.handCount[secondPlayer] + newCards - discarded);
	assert(testG.deckCount[secondPlayer] == G.deckCount[secondPlayer] - newCards + shuffledCards);
	assert(testG.numActions == G.numActions + xtraActions);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
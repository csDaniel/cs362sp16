/*  * cardtest1.c: Adventurer  *  */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#define TESTCARD "adventurer"
int main() {     
	int newCards = 0;     
	int discarded = 1;     
	int drawnTreasure = 0, cardDrawn = 0;     
	int shuffledCards = 0;
    int i, j, m;     
	int handpos = 0, bonus = 0;     
	int remove1, remove2;     
	int seed = 1000;     
	int numPlayers = 2; 
	int temphand;
	int thisPlayer = 0;
	int xtraCoins;
struct gameState G, testG; 
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
// initialize a game state and player cards 
initializeGame(numPlayers, k, seed, &G);
initializeGame(numPlayers, k, seed, &testG);
printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
// ----------- TEST 1: choice1 = 1 = +2 cards --------------printf("TEST 1: choice1 = 1 = +2 cards\n");
// copy the game state to a test case 
memcpy(&testG, &G, sizeof(struct gameState));  
playAdventurer( &testG, thisPlayer, drawnTreasure, cardDrawn,temphand, i);     
newCards = 2; 
xtraCoins = 0; 
printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);
printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins); 
assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards);

assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
assert(testG.coins == G.coins + xtraCoins); 
printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
return 0;
}
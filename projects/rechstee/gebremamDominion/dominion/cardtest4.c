/*  * cardtest4.c: Outpost  *  */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#define TESTCARD "Outpost"
int main() {     
	int newCards = 0;     
	int discarded = 0;     
	int drawnTreasure = 0, cardDrawn = 0; 
	int choice1, choice2, choice3;
	int shuffledCards = 0;
    int i, j, m;     
	int handpos = 0, bonus = 0;     
	int remove1, remove2;     
	int seed = 1000;     
	int numPlayers = 2; 
	int temphand;
	int thisPlayer = 0;
	int xtraCoins;
	int outpostUse;
struct gameState G, testG; 
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
// initialize a game state and player cards 
initializeGame(numPlayers, k, seed, &G);
initializeGame(numPlayers, k, seed, &testG);
printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
// ----------- TEST 1:1 = +1 action --------------printf("TEST 1: +3 cards\n");
// copy the game state to a test case 
memcpy(&testG, &G, sizeof(struct gameState));  
cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
newCards = 1; 
discarded = 1;
xtraCoins = 0;
outpostUse = 1;
printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] - discarded);
printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer]);
printf("outpost count = %d, expected = %d\n", testG.outpostPlayed, G.outpostPlayed + outpostUse);


assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] - discarded);

assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer]);

assert(testG.outpostPlayed == G.outpostPlayed + outpostUse);

printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
return 0;
}
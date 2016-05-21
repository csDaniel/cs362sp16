#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"


int main () {

	int effect;
	int numCards; 
	printf("Testing Smithy.\n");

	struct gameState G;
	int k[10] = {adventurer, great_hall, embargo, village, minion, duchy, feast,
	       steward, estate, smithy};


	int p1, beginningHand, endingHand, testVal;
	//initialize to 2 players to show hand updates 		
	initializeGame(2, k, 5, &G);

	p1 = 0; //player 1, position 0; 
	beginningHand = G.handCount[p1];
	printf("Beginning Hand: %i\n", beginningHand);
	effect = cardEffect(smithy, 0, 0, 0, &G, 1, 0);
	endingHand = G.handCount[p1];
	printf("Ending Hand: %i\n", endingHand);
	testVal = endingHand - beginningHand;
	printf("TestVal: %i\n", testVal);
	printf("Function Success Test: "); 
	assert(effect == 0);
	printf("PASSED\n");
	
	printf("Card Draw Sub Test: 3 Drawn, 1 Discarded, Net +2 Cards to Hand: ");
	if (testVal == 2){
	printf("PASSED\n");
	}
	else{
		printf("FAIL, expected Net +2 Cards, Result +%i cards\n", testVal);
	}

	return 0;
}

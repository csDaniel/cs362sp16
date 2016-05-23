#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//smithy
int testEffectSmithy(struct gameState *G){

	smithyEffect(0, G, 2, 0);

	if (G->handCount[0] == 7){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}
	
	if (G->playedCardCount == 1){
		printf("SUCCESS! Correct playedCardCount.\n");
	}else{
		printf("FAIL! Incorrect playedCardCount.\n");
	}
	
	if (G->deckCount[0] == 2){
		printf("SUCCESS! Correct deckCount.\n");
	}else{
		printf("FAIL! Incorrect deckCount.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEffectSmithy(&G);

	return 0;
}
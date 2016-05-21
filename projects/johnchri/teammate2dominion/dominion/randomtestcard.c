#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int testEffectCouncilRoom(struct gameState *G){

	int i;
	time_t tm;
	int randNum;
	int numTreasures = 0;
	int oldNumTreasures;

	srand(time(&tm));
	printf("%d\n", G->deckCount[0]);
	

	//add 20 cards to player 1's deck
	for (i = 0; i < 20; i++){
		randNum = 4;
		gainCard(randNum,G,1,0);
	}
	printf("%d\n", G->deckCount[0]);
	G->numBuys = 0;
	G->handCount[1] = 0;

	playCouncil_Room(G, 0);

	if(G->numBuys == 1){
		printf("SUCCESS! Num buys was increased.\n");
	}else{
		printf("FAIL! Num buys was not increased.\n");
	}

	if(G->handCount[0] == 8){
		printf("SUCCESS! Correct handcount.\n");
	}else{
		printf("FAIL! incorrect handcount.\n");
	}

	if(G->deckCount[0] == 21){
		printf("SUCCESS! Correct deckcount.\n");
	}else{
		printf("FAIL! incorrect deckcount %d.\n", G->deckCount[0]);
	}

	if(G->playedCardCount == 1){
		printf("SUCCESS! Correct discardcount.\n");
	}else{
		printf("FAIL! incorrect discardcount.\n");
	}

	if(G->handCount[1] == 1){
		printf("SUCCESS! Correct handCount for player 2.\n");
	}else{
		printf("FAIL! Incorrect handCount for player 2.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEffectCouncilRoom(&G);

	return 0;
}
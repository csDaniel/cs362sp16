#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int testEffectAdventurer(struct gameState *G){

	int i;
	time_t tm;
	int randNum;
	int numTreasures = 0;
	int oldNumTreasures;
	int temphand[MAX_HAND];

	srand(time(&tm));

	//add random cards to player each players deck
	//cards can be any activatable card or coin card
	for (i = 0; i < 20; i++){
		randNum = (rand() % 23) + 4;
		gainCard(randNum,G,1,0);

	}
	for (i = 0; i < 20; i++){
		randNum = (rand() % 23) + 4;
		gainCard(randNum,G,1,1);

	}

	//finds number of treasure cards in the players deck
	for(i = 0; i < G->deckCount[0]; i++){
		if (G->deck[0][i] == copper){
			numTreasures++;
		}else if(G->deck[0][i] == silver){
			numTreasures++;
		}else if(G->deck[0][i] == gold){
			numTreasures++;
		}
	}
	oldNumTreasures = numTreasures;
	
	adventurerEffect(0, G, 0, 0, 0, temphand);

	//tests handcount is increased by 1
	if(G->handCount[0] == 6){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}
	//tests cards are added to the discard pile
	if(G->discardCount[0] != 0){
		printf("SUCCESS! Discards increased.\n");
	}else{
		printf("FAIL! Incorrect coins.\n");
	}

	//finds the new amount of treasure cards in the players deck
	numTreasures = 0;
	for(i = 0; i < G->deckCount[0]; i++){
		if (G->deck[0][i] == copper){
			numTreasures++;
		}else if(G->deck[0][i] == silver){
			numTreasures++;
		}else if(G->deck[0][i] == gold){
			numTreasures++;
		}
	}

	if (numTreasures == oldNumTreasures - 2){
		printf("SUCCESS! Num treasures decreased by 2.\n");
	}else{
		printf("FAIL! Num treasure not correct.\n");
	}

	endTurn(G);
	//Player 1------------------------------------------------------------------------

	//finds number of treasure cards in the players deck
	numTreasures = 0;
	for(i = 0; i < G->deckCount[1]; i++){
		if (G->deck[1][i] == copper){
			numTreasures++;
		}else if(G->deck[1][i] == silver){
			numTreasures++;
		}else if(G->deck[1][i] == gold){
			numTreasures++;
		}
	}
	oldNumTreasures = numTreasures;

	adventurerEffect(0, G, 1, 0, 0, temphand);

	//tests handcount is increased by 1
	if(G->handCount[1] == 6){
		printf("SUCCESS! Correct handCount.\n");
	}else{
		printf("FAIL! Incorrect handCount.\n");
	}
	//tests cards are added to the discard pile
	if(G->discardCount[1] != 0){
		printf("SUCCESS! Discards increased.\n");
	}else{
		printf("FAIL! Discards not increased.\n");
	}

	//finds the new amount of treasure cards in the players deck
	numTreasures = 0;
	for(i = 0; i < G->deckCount[1]; i++){
		if (G->deck[1][i] == copper){
			numTreasures++;
		}else if(G->deck[1][i] == silver){
			numTreasures++;
		}else if(G->deck[1][i] == gold){
			numTreasures++;
		}
	}

	if (numTreasures == oldNumTreasures - 2){
		printf("SUCCESS! Num treasures decreased by 2.\n");
	}else{
		printf("FAIL! Num treasure not correct.\n");
	}

	return 0;

}

int main(int argc, char* argv[]) {

	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		   sea_hag, tribute, smithy};

	initializeGame(2, k, 9, &G);

	testEffectAdventurer(&G);

	return 0;
}
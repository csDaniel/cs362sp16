
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
struct gameState * randomizeGame();
void testFunctionality(struct gameState *state, int playerCount);
void testTopCardAndHand(struct gameState *state);
void victoryPoints(struct gameState *state);


void victoryPoints(struct gameState *state)
{

	int i;
	int bonus;
	int scores[state->numPlayers];
	int formatting;
	bonus = 0;

	for(i = 0; i < state->numPlayers; i++)
	{
		scores[i] = scoreFor(i, state) - 1 ;
		if(i == state->whoseTurn){
			scores[i] = scores[i] + 1;
		}
	}

	cardEffect(sea_hag, 0,0,0, state, 0, &bonus);


	for(i = 0; i < state->numPlayers; i++)
	{
		if(!(scores[i] == scoreFor(i, state))){
			printf(".");
			formatting++;
			if(formatting == 10){
				formatting = 0;
				printf("\n");
			}
		}

	}

}

void testTopCardAndHand(struct gameState *G)
{
	int i;
	int Before[MAX_HAND];
	int After[MAX_HAND];
	int turn;
	int bonus;
	int changedCards;

	bonus = 0;

	changedCards = 0;

	turn = G->whoseTurn;
	if(G->whoseTurn >= G->numPlayers - 1){
		turn = 0;
	}
	else{
		turn = G->whoseTurn + 1;
	}

	for(i = 0; i < G->deckCount[turn]; i++){
		Before[i] = G->deck[turn][i];
	}

	cardEffect(sea_hag, 0,0,0, G, 0, &bonus);

	for(i = 0; i < G->deckCount[turn]; i++){
		After[i] = G->deck[turn][i];
	}

	for(i = 0; i < G->deckCount[turn]; i++){
		if(After[i] != Before[i])
		{
			changedCards++;
		}
	}
	if(changedCards > 1)
	{
		printf("Bug!!! More Cards Changed than 1\n");
	}
	else if(changedCards < 1)
	{
		printf("Bug!!! Less Cards Changed Than 1\n");
		printf("Deck count %d \n", G->deckCount[turn]);
	}

}

void testFunctionality(struct gameState *state, int playerCount)
{

	int i;
	int j;
	int curseCountBefore = 0;
	int curseCountAfter  = 0;
	int deckCountBefore;
	int deckCountAfter;
	int discardCountBefore;
	int discardCountAfter;
	int error;

	error = 0;

	for (i = 0; i < playerCount; i++)
	{
		if (i != state->whoseTurn)
		{
			discardCountBefore = state->discardCount[i];
			deckCountBefore = state->deckCount[i];
			for (j = 0; j < state->deckCount[i]; j++) {
				if (state->deck[i][j] == curse) {
					curseCountBefore++;
				}
			}
			for (j = 0; j < state->discardCount[i]; j++) {
				if (state->discard[i][j] == curse) {
					curseCountBefore++;
				}
			}
			for (j = 0; j < state->handCount[i]; j++) {
				if (state->hand[i][j] == curse) {
					curseCountBefore++;
				}
			}

			seahagPlay(state->whoseTurn, state, 0);

			discardCountAfter = state->discardCount[i];
			deckCountAfter    = state->deckCount[i];

			for (j = 0; j < state->deckCount[i]; j++) {
				if (state->deck[i][j] == curse) {
					curseCountAfter++;
				}
			}
			for (j = 0; j < state->discardCount[i]; j++) {
				if (state->discard[i][j] == curse) {
					curseCountAfter++;
				}
			}
			for (j = 0; j < state->handCount[i]; j++) {
				if (state->hand[i][j] == curse) {
					curseCountAfter++;
				}
			}
			if(curseCountAfter != curseCountBefore+1)
			{
				error = 1;
				printf("Curse Count Values are Before = %d , After = %d. Before should be one Less \n", curseCountBefore, curseCountAfter);

			}
			if(deckCountBefore != deckCountAfter)
			{
				error = 1;
				printf("Deck Count Values are Before = %d , After = %d. Before should be the same \n", deckCountBefore, deckCountAfter);
			}
			if(discardCountAfter != discardCountBefore+1)
			{
				error = 1;
				printf(".");
			}
		}
	}
/*
if(error == 1)
{
	printf("Errors Found in Test. Cards are not getting discarded and/or added correctly.\n");
}
else
{
	printf("No errors found in Test\n");
}
*/
return;
}




int main() {


	struct gameState *G;
	int i;
	int bonus;

	bonus = 0;
	//int cardEffect(int card, int choice1, int choice2, int choice3,
//	struct gameState *state, int handPos, int *bonus) {

	printf("Random Test Run - 10,000 runs...\n");
	for(i = 0; i < 10000; i ++){
		G = randomizeGame();
		cardEffect(sea_hag,0,0,0,G, 0, &bonus);
		free(G);
	}
	printf("Test Complete\n");



	printf("Testing Discard Pile.... Each \".\" is an error\n");
	for(i = 0; i < 1000; i++){
	G = randomizeGame();
	testFunctionality(G, G->numPlayers);
	if(i % 10 == 0)
		printf("\n");
	free(G);
	}

	for(i = 0; i < 1000; i++){
	G = randomizeGame();
	testTopCardAndHand(G);
	free(G);
	}
	printf("\nTEST OVER\n");


	printf("\nEach dot represents a mistaken victory point(1000 test run)\n");
	for(i = 0; i < 1000; i++)
	{
		G = randomizeGame();
		victoryPoints(G);
		free(G);
	}
	printf("\nEnd Test\n");

	return 0;
}


struct gameState * randomizeGame() {

	int k[10];
	int length;
	int i;
	int j;
	int newRoom;
	int roomTry;
	int player;
	int seed;
	struct gameState *G;

	G = malloc(sizeof(struct gameState));
	length = 1;
	k[0] = adventurer;

	for (i = 0; i < 9; i++) {
		newRoom = 0;
		while (newRoom == 0) {
			newRoom = 1;
			roomTry = (random() % 20) + 7;
			for (j = 0; j < length; j++) {
				if (k[j] == roomTry) {
					newRoom = 0;
				}
			}
		}
		k[length] = roomTry;
		length++;
	}

	player = random() % 2 + 2;
	seed = (random() % 9999) + 1;
	initializeGame(player, k, seed, G);

	for (i = random() % player; i > 0; i--) {
		endTurn(G);
	}

	G->coins = random() % 20;
	G->numActions = (random() % 3) + 1;
	G->numBuys = (random() % 2) + 2;

	for (i = 0; i < player; i++) {
		G->deckCount[i] = (random() % 400)  + 1;
		for (j = 0; j < G->deckCount[i]; j++) {
			if (j < 250) {
				roomTry = random() % 10;
				G->deck[i][j] = k[roomTry];
			} else {
				G->deck[i][j] = (random() % 3) + 4;
			}
		}
		shuffle(i, G);
	}

	for (i = 0; i < player; i++) {
		G->discardCount[i] = random() % 50;
		for (j = 0; j < G->discardCount[i]; j++) {
			if (j < 25) {
				roomTry = random() % 10;
				G->discard[i][j] = k[roomTry];
			} else {
				G->discard[i][j] = (random() % 3) + 4;
			}
		}
	}


	G->handCount[player] = (random() % 20)+1;
	for(i = 0; i < G->handCount[player]; i++){
		if (i > 5) {
			roomTry = random() % 10;
			G->hand[player][i] = k[roomTry];
		} else {
			G->hand[player][i] = (random() % 3) + 4;
		}
	}/*
*/
	return G;
}

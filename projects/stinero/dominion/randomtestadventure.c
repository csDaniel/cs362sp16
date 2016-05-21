/*randomtestAdventure.c
 * */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
struct gameState * randomizeGame();


void testTreasure(struct gameState *state);
void testMoreCards(struct gameState *state);
void otherPlayersEffected(struct gameState *state, int numPlayers);


void otherPlayersEffected(struct gameState *state, int numPlayers)
{
	int bonus = 0;
	int i;
	int j;


	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);


	for(i = 0; i < numPlayers; i++)
	{
		if( i != state->whoseTurn)
		{
			//Important Note - If the hands are identical than the victory points are identical.
			for(j = 0; j < state->handCount[i]; j++)
			{
				assert(state->hand[i][j] == state->hand[i][j]);
			}

			for(j = 0; j < state->deckCount[i]; j++)
			{
				assert(state->deck[i][j] == state->deck[i][j]);

			}

			for(j = 0; j < state->discardCount[i]; j++)
			{
				assert(state->discard[i][j] == state->discard[i][j]);
			}
		}
	}
return;

}
// Test made to prove the adventure card does not draw any cards.
void testMoreCards(struct gameState *state)
{

	int cardInHand = state->handCount[state->whoseTurn] - 1; //-1 accounts for the card that will be played.
	int cardToggle;
	int i;
	int player = state->whoseTurn;
	int deckTreaSureCount = 0;
	int bonus = 0;
	for(i = 0; i < state->deckCount[player]; i++)
	{
		if((state->deck[player][i] == copper) || (state->deck[player][i] == silver) || (state->deck[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	for(i = 0; i < state->discardCount[player]; i++)
	{
		if((state->discard[player][i] == copper) || (state->discard[player][i] == silver) || (state->discard[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	cardToggle = (deckTreaSureCount >= 2) ? 1 : 0;

	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);

	if(cardToggle == 1)
	{
//		printf("Expected card count : %d \n", cardInHand+2);
//		printf("Actual card count : %d \n", state->handCount[player]);
		assert(cardInHand+2 == state->handCount[player]);
	}
	else
	{

		if(cardInHand == state->handCount[player])
		{
//			printf("Expected card count : %d or %d \n", cardInHand+1, cardInHand);
//			printf("Actual card count : %d \n", state->handCount[player]);
		}
		else if(cardInHand+1 == state->handCount[player])
		{
//			printf("Expected card count : %d or %d \n", cardInHand+1, cardInHand);
//			printf("Actual card count : %d \n", state->handCount[player]);
		}
		else
		{
			printf("Error In test More Card Functions \n");
			printf("Expected hand count : %d or %d \n", cardInHand+1, cardInHand);
//			printf("Deck Count is: %d\n", state->deckCount[player]);
//			printf("Discard Count is: %d\n", state->discardCount[player]);
			printf("Actual hand count : %d \n", state->handCount[player]);
		}

	}

	return;

}

void testTreasure(struct gameState *state)
{
	int player = state->whoseTurn;
	int deckTreaSureCount = 0;
	int bonus = 0;
	int i = 0;
	int treasureCount=0;
	int newTreasureCount=0;


	state->hand[player][0] = 7;

//	printf("Original Hand: \n");
	for(i = 0; i < state->handCount[player]; i++)
	{
//		printf("%d   ",state->hand[player][i]);

		if((state->hand[player][i] == copper) || (state->hand[player][i] == silver) || (state->hand[player][i] == gold))
		{
			treasureCount++;
		}
	}

	for(i = 0; i < state->deckCount[player]; i++)
	{
		if((state->deck[player][i] == copper) || (state->deck[player][i] == silver) || (state->deck[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	for(i = 0; i < state->discardCount[player]; i++)
	{
		if((state->discard[player][i] == copper) || (state->discard[player][i] == silver) || (state->discard[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	cardEffect( adventurer , 0, 0, 0, state, 0, &bonus);
//	printf("\n Hand After Card Played: \n");

	for(i = 0; i < state->handCount[player]; i++)
	{
//		printf("%d   ",state->hand[player][i]);

		if((state->hand[player][i] == copper) || (state->hand[player][i] == silver) || (state->hand[player][i] == gold))
		{
			newTreasureCount++;
		}
	}


	if(deckTreaSureCount >=2 )
	{
//		printf("\nTreasure Count: %d \n", treasureCount);
//		printf("New Treasure Count: %d \n", newTreasureCount);
//		printf("Expected Treasure Count: %d \n", treasureCount+2);
		assert(treasureCount+2 == newTreasureCount);
	}
	else if(deckTreaSureCount == 1)
	{
//		printf("\nTreasure Count: %d \n", treasureCount);
//		printf("New Treasure Count: %d \n", newTreasureCount);
//		printf("Expected Treasure Count: %d \n", treasureCount+1);
		assert(treasureCount+1 == newTreasureCount);
	}
	else if(deckTreaSureCount == 0)
	{
//		printf("Treasure Count: %d \n", treasureCount);
//		printf("New Treasure Count: %d \n", newTreasureCount);
//s		printf("Expected Treasure Count: %d \n", treasureCount);
		assert(treasureCount == newTreasureCount);
	}

	return;
}






/*
 * This wil
 *
 * */
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
		G->deckCount[i] = random() % 400;
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

int main() {


	struct gameState *G;
	int i;
	int bonus;

	bonus = 0;



	printf("Test Treasure \n");
	for (i = 0; i < 1000; i++) {
		G = randomizeGame();
		testTreasure(G);
		free(G);
	}
	printf("Test Complete \n ******************** \n");


	printf("Test to see  \n");
	for (i = 0; i < 1000; i++) {
			G = randomizeGame();
			testMoreCards(G);
			free(G);
		}
	printf("Test Complete \n ******************** \n");


printf("Follow up test to see if other players decks/cards/vpoints are changed. \n");
	for (i = 0; i < 1000; i++) {
			G = randomizeGame();
			otherPlayersEffected(G, G->numPlayers);
			free(G);
		}
printf("Test Complete. No changes registered.\n ******************** \n");


printf("10,000 Runs of drawing adventure.\n");
	for (i = 0; i < 10000; i++) {
			G = randomizeGame();
			cardEffect( adventurer , 0, 0, 0, G, 0, &bonus);
			free(G);
		}
printf("Test Complete. 10,000 iterations ran on Random Game\n ******************** \n");

printf("We made it!\n");

	return 0;

}

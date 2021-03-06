/*
 * cardtest2.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 *
 *      This will test the adventure card.
 *      int adventurerPlay(int currentPlayer, int handPos, struct gameState *state)
 *
 *		The adventurer card implementation was badly broken. Due to bugs introduced in implementation it will
 *		not draw cards into the hand of the person.
 *
 *		I created several test, one general case and one specific case to show that the Adventure Card
 *		Doesn't get discarded, and several more showing that this function is incredibly broken.
 *		This would not pass a smoke test.
 *
 *		The bright side is the test show no changes in OTHER cards when using the adventurer.
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
void testDeckCount(struct gameState *state);
void testTreasure(struct gameState *state);
void testMoreCards(struct gameState *state);
void otherPlayersEffected(struct gameState *state, int numPlayers);


void otherPlayersEffected(struct gameState *state, int numPlayers)
{
	struct gameState copyOfOriginal;
	int bonus = 0;
	int i;
	int j;


	memcpy(&copyOfOriginal, state, sizeof(struct gameState));
	cardEffect( adventurer , 0, 0, 0, &copyOfOriginal, 0, &bonus);


	for(i = 0; i < numPlayers; i++)
	{
		if( i != state->whoseTurn)
		{
			//Important Note - If the hands are identical than the victory points are identical.
			for(j = 0; j < state->handCount[i]; j++)
			{
				assert(state->hand[i][j] == copyOfOriginal.hand[i][j]);
			}

			for(j = 0; j < state->deckCount[i]; j++)
			{
				assert(state->deck[i][j] == copyOfOriginal.deck[i][j]);

			}

			for(j = 0; j < state->discardCount[i]; j++)
			{
				assert(state->discard[i][j] == copyOfOriginal.discard[i][j]);
			}
		}
	}
return;

}
// Test made to prove the adventure card does not draw any cards.
void testMoreCards(struct gameState *state)
{

	int cardInHand = state->handCount[state->whoseTurn] - 1;
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
		printf("Expected card count : %d \n", cardInHand+2);
		printf("Actual card count : %d \n", state->handCount[player]);
	}
	else
	{
		printf("Expected card count : %d or %d \n", cardInHand+1, cardInHand);
		printf("Actual card count : %d \n", state->handCount[player]);
	}


	//assert(cardInHand < state->handCount[state->whoseTurn > cardInHand]);


	return;

}

void testTreasure(struct gameState *state)
{
	struct gameState testG;
	int player = state->whoseTurn;
	int deckTreaSureCount = 0;
	int bonus = 0;
	int i = 0;
	int treasureCount=0;
	int newTreasureCount=0;

	memcpy(&testG, state, sizeof(struct gameState));

	testG.hand[player][0] = 7;

	printf("Original Hand: \n");
	for(i = 0; i < testG.handCount[player]; i++)
	{
		printf("%d   ",testG.hand[player][i]);

		if((testG.hand[player][i] == copper) || (testG.hand[player][i] == silver) || (testG.hand[player][i] == gold))
		{
			treasureCount++;
		}
	}

	for(i = 0; i < testG.deckCount[player]; i++)
	{
		if((testG.deck[player][i] == copper) || (testG.deck[player][i] == silver) || (testG.deck[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	for(i = 0; i < testG.discardCount[player]; i++)
	{
		if((testG.discard[player][i] == copper) || (testG.discard[player][i] == silver) || (testG.discard[player][i] == gold))
		{
			deckTreaSureCount++;
		}
	}

	cardEffect( adventurer , 0, 0, 0, &testG, 0, &bonus);
	printf("\n Hand After Card Played: \n");

	for(i = 0; i < testG.handCount[player]; i++)
	{
		printf("%d   ",testG.hand[player][i]);

		if((testG.hand[player][i] == copper) || (testG.hand[player][i] == silver) || (testG.hand[player][i] == gold))
		{
			newTreasureCount++;
		}
	}


	if(deckTreaSureCount >=2 )
	{
		printf("\nTreasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount+2);
//		assert(treasureCount+2 == newTreasureCount);
	}
	else if(deckTreaSureCount == 1)
	{
		printf("\nTreasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount+1);
//		assert(treasureCount+1 == newTreasureCount);
	}
	else if(deckTreaSureCount == 0)
	{
		printf("Treasure Count: %d \n", treasureCount);
		printf("New Treasure Count: %d \n", newTreasureCount);
		printf("Expected Treasure Count: %d \n", treasureCount);
//		assert(treasureCount == newTreasureCount);
	}

	return;
}

void testDeckCount(struct gameState *state)
{
	struct gameState testG;
	int player = state->whoseTurn;
	int cardCount = state->deckCount[player];
	int bonus = 0;

	//int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

	memcpy(&testG, state, sizeof(struct gameState));

	while(cardCount < 2)
	{
		drawCard(state->whoseTurn, &testG);
		cardCount = state->deckCount[player];
	}

	cardEffect( adventurer , 0, 0, 0, &testG, 0, &bonus);

	while(cardCount > 2)
	{
		discardCard(0, state->whoseTurn, &testG, 0);
		cardCount = state->deckCount[player];
	}

	cardEffect( adventurer , 0, 0, 0, &testG, 0, &bonus);

	return;
}

int main() {

		int seed = 12;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = { adventurer, embargo, village, minion, mine, cutpurse, sea_hag,
				tribute, smithy, council_room };
		initializeGame(numPlayers, k, seed, &G);


			printf("Test Treasure \n");
			memcpy(&testG, &G, sizeof(struct gameState));
			testTreasure(&testG);
			printf("Test Complete \n ******************** \n");

			printf("Follow up test to prove no cards are drawn. \n");
			memcpy(&testG, &G, sizeof(struct gameState));
			testMoreCards(&testG);
			printf("Test Complete \n ******************** \n");


			printf("Follow up test to see if other players decks/cards/vpoints are changed. \n");
			memcpy(&testG, &G, sizeof(struct gameState));
			otherPlayersEffected(&testG, numPlayers);
			printf("Test Complete. No changes registered.\n ******************** \n");


			printf("Draws Card with deck < 2 cards and over 2 cards. Test for SegFault/ non-terminating loop \n");
			memcpy(&testG, &G, sizeof(struct gameState));
			testDeckCount(&testG);
			printf("Test Complete. Card draws with < 2 cards and >2 cards.\n ******************** \n");

	return 0;


}

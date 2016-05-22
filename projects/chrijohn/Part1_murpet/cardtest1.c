#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
	int error = 0;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int r;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	
	printf("TESTING smithy:\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	// set supply piles all equal to 10
	for(i = 0; i < 25; i++)
	{
		G.supplyCount[i] = 10;
	}
	// record pre-card conditions
	int numActions = G.numActions;
	int numBuys = G.numBuys;
	int numCoins = G.coins;
	int numHand = G.handCount[0];
	int numDiscard = G.discardCount[0];
	int numDeck = G.deckCount[0];
	int oppHand = G.handCount[1];
	int oppDiscard = G.discardCount[1];
	int oppDeck = G.deckCount[1];

	G.whoseTurn = 0;
	// play card
	cardEffect(smithy, 0, 0, 0, &G, 0, 0);
	// check number of actions
	if (numActions != G.numActions)
	{
		printf("Error with number of actions: ");
		printf("Expected: %i. Actual: %i\n", numActions, G.numActions);
		error = 1;
	}
	// check number of buys
	if (numBuys != G.numBuys)
	{
		printf("Error with number of buys: ");
		printf("Expected: %i. Actual: %i\n", numBuys, G.numBuys);
		error = 1;
	}
	// check number of coins
	if (numCoins != (G.coins))
	{
		printf("Error with coins: ");
		printf("Expected: %i. Actual: %i\n", numCoins, G.coins);
		error = 1;
	}
	// check that player gained 2 cards (drew 3, discarded 1)
	if ((numHand +2) != G.handCount[0])
	{
		printf("Error with hand count: ");
		printf("Expected: %i.  Actual: %i\n", (numHand - 2), G.handCount[0]);
		error = 1;
	}
	// check discard pile + played card increased by 1
	if ((numDiscard + 1) != G.discardCount[0] + G.playedCardCount)
	{
		printf("Error with discard count: ");
		printf("Expected: %i.  Actual: %i\n", (numDiscard + 1), (G.discardCount[0] + G.playedCardCount));
		error = 1;
	}
	// check players deck lost 3 cards
	if ((numDeck - 3) != (G.deckCount[0]))
	{
		printf("Error with deck count: ");
		printf("Expected: %i.  Actual: %i\n", (numDeck - 3), G.deckCount[0]);
		error = 1;
	}
	// check card supplies are still at 10
	for (i = 0; i < 25; i++)
	{
		if(G.supplyCount[i] != 10)
		{
			printf("Error in supply card #%i\n", i);
		}
	}
	// check opponents hand, deck and discard are the same
	if (oppDeck != G.deckCount[1])
	{
		printf("Error with opponents deck: ");
		printf("Expected: %i.  Actual: %i\n", oppDeck, G.deckCount[1]);
		error = 1; 
	}
	if (oppHand != G.handCount[1])
	{
		printf("Error with opponents deck: ");
		printf("Expected: %i.  Actual: %i\n", oppHand, G.handCount[1]);
		error = 1;
	}
	if (oppDiscard != G.discardCount[1])
	{
		printf("Error with opponents deck: ");
		printf("Expected: %i.  Actual: %i\n", oppDiscard, G.discardCount[1]);
		error = 1;
	}
	if (error == 0)
	{
		printf("All tests passed!\n");
	}
	return 0;
}

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int r;
	int x;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int randcard;
	int successCount = 0;
	srand(time(NULL));
	int numActions;
	int numBuys;
	int numCoins;
	int numHand;
	int numDiscard;
	int numDeck;
	int oppHand;
	int oppDiscard;
	int oppDeck;
	int treasureInHand;
	int treasureDeckDisc = 0;
	// counter of error conditions
	int errorAction = 0;
	int errorBuy = 0;
	int errorCoin = 0;
	int errorHand = 0;
	int errorDisDeck = 0;
	int errorSupplies = 0;
	int erroroppDeck = 0;
	int erroroppHand = 0;
	int errorOppDiscard = 0;
	int errorTreasureHand = 0;
	int errorTreasureDisDeck = 0;
	for (x = 0; x < 1000; x++)
	{
		int error = 0;
//		printf("\nAdventurer Random Test #%i: \n", x);
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

		do 
		{
			// random actions,buys,coins, and number of cards in player 0-100
			G.numActions = rand() % 100;
			//		printf("number of actions: %i\n", G.numActions);
			G.numBuys = rand() % 100;
			//		printf("number of buys: %i\n", G.numBuys);
			G.coins = rand() % 100;
			//		printf("number of coins: %i\n", G.coins);
			G.handCount[0] = rand() % 100;
			//		printf("hand count: %i\n", G.handCount[0]);
					// randomize card in players hand
			for (i = 0; i < G.handCount[0]; i++)
			{
				randcard = rand() % 25;
				G.hand[0][i] = randcard;
				//			printf("hand: %i, %i\n", i, G.hand[0][i]);
			}
			// put card 0 as smithy
			G.hand[0][0] = adventurer;
			G.discardCount[0] = rand() % 100;
			//		printf("discard count: %i\n", G.discardCount[0]);
					// random discard
			for (i = 0; i < G.discardCount[0]; i++)
			{
				randcard = rand() % 25;
				G.discard[0][i] = randcard;
				//			printf("discard: %i, %i\n", i, G.discard[0][i]);
			}
			// random deck
			G.deckCount[0] = ((rand() % 1000) + 5);
			//		printf("deck count: %i\n", G.deckCount[0]);
			for (i = 0; i < G.deckCount[0]; i++)
			{
				randcard = rand() % 25;
				G.deck[0][i] = randcard;
				//			printf("deck: %i, %i\n", i, G.deck[0][i]);
			}
			G.deck[0][0] = copper;
			G.deck[0][1] = copper;
			G.deck[0][2] = copper;
			G.deck[0][3] = copper;
			//		printf("TESTING adventurer:\n");
			for (i = 0; i < 25; i++)
			{
				G.supplyCount[i] = 10;
			}
			// record pre-card conditions
			numActions = G.numActions;
			numBuys = G.numBuys;
			numCoins = G.coins;
			numHand = G.handCount[0];
			numDiscard = G.discardCount[0];
			numDeck = G.deckCount[0];
			oppHand = G.handCount[1];
			oppDiscard = G.discardCount[1];
			oppDeck = G.deckCount[1];
			// get players count of treasure in hand
			treasureInHand = 0;
			for (i = 0; i < G.handCount[0]; i++)
			{
				if (G.hand[0][i] == copper)
				{
					treasureInHand++;
				}
				if (G.hand[0][i] == silver)
				{
					treasureInHand++;
				}
				if (G.hand[0][i] == gold)
				{
					treasureInHand++;
				}
			}
			//		printf("Treasures in hand: %i\n", treasureInHand);
					// get players count of treasure in discards and deck
			treasureDeckDisc = 0;
			for (i = 0; i < G.discardCount[0]; i++)
			{
				if (G.discard[0][i] == copper)
				{
					treasureDeckDisc++;
				}
				if (G.discard[0][i] == silver)
				{
					treasureDeckDisc++;
				}
				if (G.discard[0][i] == gold)
				{
					treasureDeckDisc++;
				}
			}
			for (i = 0; i < G.deckCount[0]; i++)
			{
				if (G.deck[0][i] == copper)
				{
					treasureDeckDisc++;
				}
				if (G.deck[0][i] == silver)
				{
					treasureDeckDisc++;
				}
				if (G.deck[0][i] == gold)
				{
					treasureDeckDisc++;
				}
			}
		} while (treasureDeckDisc < 3);

		G.whoseTurn = 0;
		// play card
		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
		// check number of actions
		if (numActions != G.numActions)
		{
//			printf("Error with number of actions: ");
//			printf("Expected: %i. Actual: %i\n", numActions, G.numActions);
			error = 1;
			errorAction++;
		}
		// check number of buys
		if (numBuys != G.numBuys)
		{
//			printf("Error with number of buys: ");
//			printf("Expected: %i. Actual: %i\n", numBuys, G.numBuys);
			error = 1;
			errorBuy++;
		}
		// check number of coins
		if (numCoins != (G.coins))
		{
//			printf("Error with coins: ");
//			printf("Expected: %i. Actual: %i\n", numCoins, G.coins);
			error = 1;
			errorCoin++;
		}
		// check that player gained 1 cards (drew 2, discarded 1)
		if ((numHand + 1) != G.handCount[0])
		{
//			printf("Error with hand count: ");
//			printf("Expected: %i.  Actual: %i\n", (numHand + 1), G.handCount[0]);
			error = 1;
			errorHand++;
		}
		// check if sum of discard and deck lost 1 card (drew 2, discarded 1)
		if ((numDiscard + numDeck - 1) != (G.discardCount[0] + G.deckCount[0] + G.playedCardCount))
		{
//			printf("Error with discard and deck and played count: ");
//			printf("Expected: %i.  Actual: %i\n", (numDiscard + numDeck - 1), (G.discardCount[0] + G.deckCount[0] + G.playedCardCount));
			error = 1;
			errorDisDeck++;
		}
		// check card supplies are still at 10
		for (i = 0; i < 25; i++)
		{
			if (G.supplyCount[i] != 10)
			{
//				printf("Error in supply card #%i\n", i);
				errorSupplies++;
				break;
			}
		}
		// check opponents hand, deck and discard are the same
		if (oppDeck != G.deckCount[1])
		{
//			printf("Error with opponents deck: ");
//			printf("Expected: %i.  Actual: %i\n", oppDeck, G.deckCount[1]);
			error = 1;
			erroroppDeck++;
		}
		if (oppHand != G.handCount[1])
		{
//			printf("Error with opponents hand: ");
//			printf("Expected: %i.  Actual: %i\n", oppHand, G.handCount[1]);
			error = 1;
			erroroppDeck++;
		}
		if (oppDiscard != G.discardCount[1])
		{
//			printf("Error with opponents deck: ");
//			printf("Expected: %i.  Actual: %i\n", oppDiscard, G.discardCount[1]);
			error = 1;
			errorOppDiscard++;
		}
		// get players count of treasure in hand
		int postTreasureInHand = 0;
		for (i = 0; i < G.handCount[0]; i++)
		{
			if (G.hand[0][i] == copper)
			{
				postTreasureInHand++;
			}
			if (G.hand[0][i] == silver)
			{
				postTreasureInHand++;
			}
			if (G.hand[0][i] == gold)
			{
				postTreasureInHand++;
			}
		}
		// get players count of treasure in discards and deck
		int postTreasureDeckDisc = 0;
		for (i = 0; i < G.discardCount[0]; i++)
		{
			if (G.discard[0][i] == copper)
			{
				postTreasureDeckDisc++;
			}
			if (G.discard[0][i] == silver)
			{
				postTreasureDeckDisc++;
			}
			if (G.discard[0][i] == gold)
			{
				postTreasureDeckDisc++;
			}
		}
		for (i = 0; i < G.deckCount[0]; i++)
		{
			if (G.deck[0][i] == copper)
			{
				postTreasureDeckDisc++;
			}
			if (G.deck[0][i] == silver)
			{
				postTreasureDeckDisc++;
			}
			if (G.deck[0][i] == gold)
			{
				postTreasureDeckDisc++;
			}
		}
		// Test there are 2 more treasures in players hand
		if ((treasureInHand + 2) != postTreasureInHand)
		{
//			printf("Error with number of treasures in hand ");
//			printf("Expected: %i.  Actual: %i\n", (treasureInHand + 2), postTreasureInHand);
			error = 1;
			errorTreasureHand++;
		}
		// Test there are 2 fewer treasures in players deck and discard
		if ((treasureDeckDisc - 2) != postTreasureDeckDisc)
		{
//			printf("Error with number of treasures in deck/discard ");
//			printf("Expected: %i.  Actual: %i\n", (treasureDeckDisc - 2), postTreasureDeckDisc);
			error = 1;
			errorTreasureDisDeck++;
		}
		if (error == 0)
		{
//			printf("All tests passed!\n");
			successCount++;
		}
	}
	printf("\n-----ADVENTURER RESULTS:-----\n", successCount);
	printf("In 1000 tests...\n");
	printf("Success: %d\n", (successCount));
	printf("Error in Actions: %d\n", (errorAction));
	printf("Error in Buys: %d\n", (errorBuy));
	printf("Error in Coins: %d\n", (errorCoin));
	printf("Error in Hand Count: %d\n", (errorHand));
	printf("Error in Discard+Deck+Played Count: %d\n", (errorDisDeck));
	printf("Error in Treasure Cards in Hand: %d\n", (errorTreasureHand));
	printf("Error in Treausre Cards in Discard+Deck+Played: %d\n", (errorTreasureDisDeck));
	printf("Error in Supplies: %d\n", (errorSupplies));
	printf("Error in Opponents Deck: %d\n", (erroroppDeck));
	printf("Error in Opponents Discard: %d\n", (errorOppDiscard));

	return 0;
}

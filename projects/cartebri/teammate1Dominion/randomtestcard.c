#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main(){

	int i, x;
	int tests = 500;
	int players;
	int maxDeck;
	int position;
	struct gameState game;
	int kingdom[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int deckSize = 200;
	int player = 0;

	srand(time(NULL));

	for(i = 0; i < tests; i++)
	{
		players = (rand() % 3) + 2;				//randomly assign number of players btwn 2-4
		initializeGame(players, kingdom, 453, &game);
	
		maxDeck = (rand() % deckSize) + 1;
		game.deckCount[player] = maxDeck;
		game.handCount[player] = rand() % 5 + 1;
		position = rand() % game.handCount[player] + 1;
		game.hand[player][position] = smithy;			//add smithy to the player's hand
		for(x = 0; x < maxDeck; x++)
		{
			if(x == position)
				continue;
			game.deck[player][x] = rand() % 17 + 1; 			//randomize the deck
		}


	
		printf("########################### TESTING SMITHY #####################\n");
		printf("\nInputs: \nDeck Size: %d\t Hand Count: %d\t Players: %d\n", maxDeck, game.handCount[player], players);

		//copy game info to compare results

		struct gameState testing;
		memcpy(&testing, &game, sizeof(struct gameState));
		//play smithy card
		cardEffect(smithy, 0, 0, 0, &testing, 0, 0);

		//test if hand count is correct after smithy is played (should be +2)
		if(testing.handCount[player] == (game.handCount[player] + 2))
		{
			printf("PASSED. Expected hand count: %d, Actual hand count: %d\n", game.handCount[player] + 2, testing.handCount[player]);
		}
		else
		{
			printf("FAILED. Expected hand count : %d, Actual hand count: %d\n", game.handCount[player] + 2, testing.handCount[player]);
		}


		//test if the deck size changed properly after card played (should be -3)
		if(testing.deckCount[player] == (game.deckCount[player] - 3))
		{
			printf("PASSED. Expected deck count %d, Actual deck count: %d\n", game.deckCount[player] - 3, testing.deckCount[player]);
		}
		else
		{
			printf("FAILED. Expected deck count: %d, Actual deck count: %d\n", game.deckCount[player] - 3, testing.deckCount[player]);
		}
		//test if smithy was discarded properly (discard should be +1)
		if(testing.playedCardCount == 1)
		{
			printf("PASSED. Expected discard count: %d\n", testing.playedCardCount);
		}
		//test that the kingdom cards are the same
		if(testing.supplyCount[curse] == game.supplyCount[curse])
			{printf("PASSED. Curse card amounts match.\n");}
		else
			{printf("FAILED. Curse card amounts do not match.\n");}

		if(testing.supplyCount[estate] == game.supplyCount[estate])
			{printf("PASSED. Estate card amounts match\n");}
		else
			{printf("FAILED. Estate card amounts do not match.\n");}

		if(testing.supplyCount[duchy] == game.supplyCount[duchy])
			{printf("PASSED. Duchy card amounts match\n");}
		else
			{printf("FAILED. Estate card amounts do not match.\n");}

		if(testing.supplyCount[province] == game.supplyCount[province])
			{printf("PASSED. Province card amounts match.\n");}
		else
			{printf("FAILED. Province card amounts do not match.\n");}

		//test that the supply cards are the same
		if(testing.supplyCount[copper] == game.supplyCount[copper])
			{printf("PASSED. Copper card amounts match.\n");}
		else
			{printf("FAILED. Copper card amounts do not match.\n");}

		if(testing.supplyCount[silver] == game.supplyCount[silver])
			{printf("PASSED. Silver card amounts match.\n");}
		else
			{printf("FAILED. Silver card amounts do not match.\n");}

		if(testing.supplyCount[gold] == game.supplyCount[gold])
			{printf("PASSED. Gold card amounts match.\n");}
		else
			{printf("FAILED. Gold card amounts do not match.\n");}
		//test that the other player's hand is the same
		if(testing.handCount[1] == game.handCount[1])
			{printf("PASSED. Other player's hand count is not affected.\n");}
		else
			{printf("FAILED. Other player's hand count is affected.\n");}

		//test if the other player's deck is the same
		if(testing.deckCount[1] == game.deckCount[1])
			{printf("PASSED. Other player's deck count is not affected.\n");}
		else
			{printf("FAILED. Other player's deck count is affected.\n");}
	}

return 0;
}
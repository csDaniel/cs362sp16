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
		game.hand[player][position] = adventurer;			//add adventurer to the player's hand
		for(x = 0; x < maxDeck; x++)
		{
			if(x == position)
				continue;
			game.deck[player][x] = rand() % 17 + 1; 			//randomize the deck
		}


		printf("#############TESTING ADVENTURER CARD###################\n");

		printf("\nInputs: \nDeck Size: %d\t Hand Count: %d\t Players: %d\n", maxDeck, game.handCount[player], players);


		//save the game state for comparison after testing
		struct gameState testing;
		memcpy(&testing, &game, sizeof(struct gameState));
		


		//test if two treasure cards are added to the hand
		int firstHandCount = game.handCount[player];	//need to save info in order to predict
		int firstamount = game.coins;					//what the proper values will be after
		int secondamount = 0;							//the card is played

		for(x = 0; x < game.handCount[player]; x++)
		{
			if(game.hand[player][x] == copper)
			{
				printf("Copper, ");
				firstamount += 1;
				firstHandCount++;
			}
			if(game.hand[player][x] == silver)
			{
				printf("Silver, ");
				firstamount += 2;
				firstHandCount++;
			}
			if(game.hand[player][x] == gold)
			{
				printf("Gold, ");
				firstamount += 3;
				firstHandCount++;
			}
		}
		cardEffect(adventurer, 0, 0, 0, &testing, 0, 0);
		//get the coins that were discovered when the card was played
		printf("\n");

		for(x = 0; x < testing.handCount[player]; x++)
		{
			if(testing.hand[player][x] == copper)
			{
				printf("Copper\n");
				secondamount += 1;
			}
			if(testing.hand[player][x] == silver)
			{
				printf("Silver\n");
				secondamount += 2;
			}
			if(testing.hand[player][x] == gold)
			{
				printf("Gold\n");
				secondamount += 3;
			}
		}

		if(secondamount == testing.coins)
			{printf("PASSED. Coin amounts match.\n");}
		else
			{printf("FAILED. Coin amounts did not match.\n");}
		

		//test that coins were only taken from the player's hand
		if(testing.coins == game.coins)
			{printf("PASSED. Coin supplies match.\n");}
		else
			{printf("FAILED. Coin supplies do not match\n");}

		//test that two or fewer cards were added to the hand, the rest are discarded
		if(testing.handCount[player] <= game.handCount[player] + 1)
			{printf("PASSED. Player's hand increased by allowed amount.\n");}
		else
			{printf("FAILED. Player's hand count increased too much.\n");}

		//test that the adventurer card is in the played card pile
		if(testing.playedCardCount == 1)
			{printf("PASSED. Card placed in played pile.\n");}
		else
			{printf("FAILED. Adventurer card not placed in played pile.\n");}

		//test that other player's deck is not changed
		if(testing.deckCount[1] == game.deckCount[1])
			{printf("PASSED. Other player's deck is the same.\n");}
		else
			{printf("FAILED. Other player's deck is not the same\n");}

		//test that other player's hand is not changed
		if(testing.handCount[1] == game.handCount[1])
			{printf("PASSED. Other player's hand count is the same.\n");}
		else
			{printf("FAILED. Other player's hand count is not the same.\n");}

		//test that estate cards are the same
		if(testing.supplyCount[curse] == game.supplyCount[curse])
			{printf("PASSED. Curse card amounts are equal.\n");}
		else
			{printf("FAILED. Curse card amounts are not equal.\n");}

		if(testing.supplyCount[estate] == game.supplyCount[estate])
			{printf("PASSED. Estate card amounts are equal.\n");}
		else
			{printf("FAILED. Estate card amounts are not equal.\n");}

		if(testing.supplyCount[duchy] == game.supplyCount[duchy])
			{printf("PASSED. Duchy card amounts are equal\n");}
		else
			{printf("FAILED. Estate card amounts are not equal.\n");}

		if(testing.supplyCount[province] == game.supplyCount[province])
			{printf("PASSED. Province card amounts are equal.\n");}
		else
			{printf("FAILED. Province card amounts are not equal.\n");}

		//test that supply cards are the same
		if(testing.supplyCount[copper] == game.supplyCount[copper])
			{printf("PASSED. Copper card amounts are equal.\n");}
		else
			{printf("FAILED. Copper card amounts are not equal.\n");}

		if(testing.supplyCount[silver] == game.supplyCount[silver])
			{printf("PASSED. Silver card amounts are equal.\n");}
		else
			{printf("FAILED. Silver card amounts are not equal.\n");}

		if(testing.supplyCount[gold] == game.supplyCount[gold])
			{printf("PASSED. Gold card amounts are equal.\n");}
		else
			{printf("FAILED. Gold card amounts are not equal.\n");}
	}

return 0;	
}
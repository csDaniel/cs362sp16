//Jessica Siano
//CS362 Software Development 2
//Testing the adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){

	printf("\n\nTesting the Adventurer card.\n\n");

	struct gameState gS;
	int seed = 1000, players = 3, r, result, handPos = 2;

	int c[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	memset(&gS, 23, sizeof(struct gameState));
	r = initializeGame(players, c, seed, &gS);

	int currPlayer = whoseTurn(&gS);
	//beforeCoins will be hand total pre-adventurer
	int beforeCoins = gS.handCount[currPlayer], afterCoins = 0;
	int count, card, i;
	int beforeTreasure = 0;

	//Added check
	//printf("Current player hand count: %d", gS.handCount[currPlayer]);

	//Added preloop to count treasures in player's hand
	count = gS.handCount[currPlayer];
	for(i = 0; i < count; i++)
	{
		card = gS.hand[currPlayer][i];
		if(card == copper || card == silver || card == gold)
			beforeTreasure++;
	}
	

	r = playAdventurerCard(&gS);
	
	count = gS.handCount[currPlayer];
	for(i = 0; i < count; i++)
	{
		card = gS.hand[currPlayer][i];
		if(card == copper || card == silver || card == gold)
			afterCoins++;
	}

	//Updated output to clarify what was failing.
	if((beforeCoins + 2 == gS.handCount[currPlayer]) && (beforeTreasure + 2 == afterCoins))
		printf("Adventurer test passed. Treasure total matches.\n");
	else
		printf("Adventurer test failed.\n gS.handCount[currPlayer] should be: %d, but is %d \n afterCoins should be: %d,  but is %d \n Incorrect treasure drawn.\n", beforeCoins + 2, gS.handCount[currPlayer], beforeTreasure + 2, afterCoins);

	return 0;
}	

//Rick Garnica
//CS 362
//Test:  Feast Card


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char const *argv[]) {
	
    struct gameState game;
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int card;
	
	
	printf("==============================================\r\n");
	printf("\n   Testing Feast card:\r\n");
	printf("==============================================\r\n");
	
	initializeGame(2, kingdomCards, 12, &game);
	printf("current coin count = %d\n",game.coins);
	game.hand[0][1] = feast;
	printf("Coins: %d < %d\n", game.coins, getCost(9));
	//updateCoins(0, &game, getCost(9));
	playCard(0, village, 0, 0, &game);
	

	//testing feast discard function
	if(game.discardCount[0] ==1){
		printf("\nDiscarded 1 card\n");
	}
	else{
		printf("\nDid not discard 1 card.");
	}
	
	//testing +5 card value
	if(game.handCount[0] == 5){
		printf("\n+5 value added to hand. \n");
	}
	
	else{
		printf("\nNo value added to hand. \n");
	}
	
	int i = 0;
		for (i = 0; i < game.handCount[0]; i++){
			if (game.hand[0][i] == village) {
				printf("The feast card did not work correctly.  Card issued.\n");
				//result++;
			}
			else{
				printf("The feast card worked correctly.  Card not issued.\n");
				//result++;
			}
		}
	
	printf("Coins: %d < %d\n", game.coins, getCost(9));
	

	return 0;
}
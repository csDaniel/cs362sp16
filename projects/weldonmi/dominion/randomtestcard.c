/*
 * Miranda Weldon
 * May 7, 2016
 * CS 362 Spring 2016
 * Assignment 4
 * randomtestcard.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//main function
int main(){
	//declare variables
	int i, numPlayers, gameSeed, bonus, numTests = 5;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, adventurer, ambassador, great_hall, smithy};

	//seeds rand
	srand(time(NULL));

	printf("Random Testing Smithy Card\n\n");

	//for each test
	for(i = 0; i < numTests; i++){
		//random number for numPlayers, gameSeed, and bonus
		numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
		gameSeed = rand() % 5000;
		bonus = rand() % 5;	//5 can be changed to other numbers

		//set up original game and create copy
		initializeGame(numPlayers, k, gameSeed, &Game);
		memcpy(&testGame, &Game, sizeof(struct gameState));

		cardEffect(smithy, 0, 0, 0, &Game, 0, &bonus);

		//compare "before" and "after" variables
		printf("Expected Hand Count: %d\nActual Hand Count: %d\n", Game.handCount[0] + 2, testGame.handCount[0]);
		if(testGame.handCount[0] == Game.handCount[0] + 2)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("Expected Deck Count: %d\nActual Deck Count: %d\n", Game.deckCount[0] - 3, testGame.deckCount[0]);
		if(testGame.deckCount[0] == Game.deckCount[0] - 3)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("Expected Coin Count: %d\nActual Coin Count: %d\n", Game.coins, testGame.coins);
		if(testGame.coins == Game.coins)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("\n");
	}

	//zero if no errors
	return 0;
}


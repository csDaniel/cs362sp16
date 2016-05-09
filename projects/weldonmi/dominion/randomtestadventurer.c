/*
 * Miranda Weldon
 * April 26, 2016
 * CS 362 Spring 2016
 * Assignment 4
 * randomtestadventurer.c
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
	int i, numTests = 5, numPlayers = 3, gameSeed = 1000, bonus = 0;
	struct gameState Game, testGame;
	int k[10] = {feast, gardens, salvager, remodel, sea_hag, mine, adventurer, ambassador, great_hall, smithy};

	//seed rand
	srand(time(NULL));

	printf("Random Testing Adventurer Card\n\n");

	//for each test
	for(i = 0; i < numTests; i++){
		//randomize numPlayers, gameSeed, and bonus
		numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
		gameSeed = rand() % 5000;
		bonus = rand() % 5;	//5 can be changed to other numbers

		//set up original game and create copy
		initializeGame(numPlayers, k, gameSeed, &Game);
		memcpy(&testGame, &Game, sizeof(struct gameState));

		cardEffect(adventurer, 0, 0, 0, &testGame, 0, &bonus);

		//compare "before" and "after" variables
		printf("Expected Hand Count: %d\nActual Hand Count %d\n", Game.handCount[0] + 2, testGame.handCount[0]);
		if(testGame.handCount[0] == Game.handCount[0] + 2)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("Expected Deck Count: %d or less\nActual Deck Count %d\n", Game.deckCount[0] - 2, testGame.deckCount[0]);
		if(testGame.deckCount[0] <= Game.deckCount[0] - 2)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("Expected Coin Count: %d or more\nActual Coin Count %d\n", Game.coins + 2, testGame.coins);
		if(testGame.coins >= Game.coins + 2)
			printf("\tTest Pass\n");
		else
			printf("\tTest Fail\n");

		printf("\n");
	}

	//zero if no errors
	return 0;
}


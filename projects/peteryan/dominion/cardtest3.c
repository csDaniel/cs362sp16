/*
Author: Ryan Peters
Date: 04/21/16
Description: Unit test for village card effect.
*/

#include<stdio.h>
#include<string.h>
#include "dominion.h"

void testVillage()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int r;
	int i;
	int bonus = 0; //Bonus is not used by village
	int numPlayer = 2;
	int player = 1;
	int handPos;
	
	/*Test card is drawn by player and exit code is 0*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	if(state.handCount[player] == 3)
		printf("villageEffect: PASS net gain 0 cards.\n");
	else
		printf("villageEffect: FAIL net gain 0 cards.\n");
	if(r == 0)
		printf("villageEffect: PASS exit code 0.\n");
	else
		printf("villageEffect: FAIL exit code 0.\n");
	
	/*Test player gains 2 actions*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	if(state.numActions == 2)
		printf("villageEffect: PASS gain 2 actions.\n");
	else
		printf("villageEffect: FAIL gain 2 actions.\n");
	
	/*Test village card is replaced with new card*/
	memset(&state, 0, sizeof(struct gameState));  
    initializeGame(numPlayer, k, seed, &state);
	handPos = 1;
	state.whoseTurn = player;
	state.numActions = 0;
	state.handCount[player] = 3;
	state.hand[player][0] = gold;
	state.hand[player][1] = village;
	state.hand[player][2] = silver;
	printf("villageEffect: Hand before play - ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", state.hand[player][i]);
	}
	printf("\n");
	r = cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
	printf("villageEffect: Hand after play - ");
	for(i = 0; i < 3; i++)
	{
		printf("%d ", state.hand[player][i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
    testVillage();
    return 0;
}
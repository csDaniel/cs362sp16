/*
Sam Jones
Date: 04/25/16
Description: Unit test for playSmithy().  Test the smithy card effect.  Test that
the function returns 0 when it executes successfully.  Test that three cards are
and one is removed from the hand.
*/

#include<stdio.h>
#include<string.h>
#include "dominion.h"

void testPlaySmithy()
{
	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
                remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int r;
	int numPlayer = 2;
	
	memset(&state, 0, sizeof(struct gameState));   
    initializeGame(numPlayer, k, seed, &state);
	
	/*Test the function executes fully*/
	int player = 1;
	int handPos = 0;	
	r = playSmithy(player, &state, handPos);
	if(r == 0)
		printf("playSmithy: PASS smithy completed execution.\n");
	else
		printf("playSmithy: FAIL smithy completed execution.\n");
	
	/*Test cards drawn and smithy discarded*/
	player = 1;
	handPos = 0;	
	state.handCount[player] = 3;
	r = playSmithy(player, &state, handPos);
	if(state.handCount[player] == 5)
		printf("playSmithy: PASS 3 cards drawn and smithy discarded.\n");
	else
		printf("playSmithy: FAIL 3 cards drawn and smithy discarded.\n");
	
	/*Test cards drawn and smithy discarded*/
	player = 1;
	handPos = 0;	
	state.handCount[player] = 3;
	state.playedCardCount = 0;
	r = playSmithy(player, &state, handPos);
	if(state.playedCardCount == 1)
		printf("playSmithy: PASS card added to played stack.\n");
	else
		printf("playSmithy: FAIL card added to played stack.\n");
}

int main(int argc, char *argv[])
{
    testPlaySmithy();
    return 0;
}
/*  * randomtestsmithy.c  */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#define TESTCARD "smithy"


int getPlayer()
{
	int p;
	p = rand() % 3;

    return p;


}

int getHandPos()
{
	int h;	
	h = rand() % 8;

	return h;
}


void testMe() {     
	int newCards = 0;     
	int discarded = 1;     
	int drawnTreasure = 0, cardDrawn = 0;     
	int shuffledCards = 0;
    int i = 0, j = 0;
	int handpos = 0;     
	int remove1, remove2;     
	int seed = 1000;     
	int numPlayers = 2; 
	int temphand;
	int thisPlayer = 0;
	int xtraCoins;
	int tcCount = 0, rState = 0;
struct gameState G, testG; 
int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
// initialize a game state and player cards 
initializeGame(numPlayers, k, seed, &G);
initializeGame(numPlayers, k, seed, &testG);
printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
// copy the game state to a test case 
//memcpy(&testG, &G, sizeof(struct gameState));

while (1)
{
 thisPlayer = getPlayer();
 handpos = getHandPos();
tcCount++;
memcpy(&testG, &G, sizeof(struct gameState));
playSmithy( &testG, thisPlayer, handpos, i);
printf("Iteration %d: player = %d, handpos = %d\n", tcCount, thisPlayer, handpos);

if (thisPlayer == 0 && rState == 0) rState = 1;
    if (handpos == testG.handCount[thisPlayer] && rState == 1) //go until handcount is reached
    {
     printf("Maxed out state reached \n");
	  exit(200);
    }
}
}

int main()
{
    srand(time(NULL));
    testMe();
    return 0;
}
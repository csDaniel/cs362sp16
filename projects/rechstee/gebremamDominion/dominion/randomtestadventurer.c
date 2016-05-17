/*  * randomtestadventurer.c  */

#include "dominion.h" 
#include "dominion_helpers.h" 
#include <string.h> 
#include <stdio.h> 
#include <assert.h> 
#include "rngs.h" 
#include <stdlib.h>
#define TESTCARD "adventurer"


int getPlayer()
{
	int p;
	p = rand() % 4;

    return p;


}

int getTreasure()
{
	int t;	
	t = rand() % 500;

	return t;
}

int getCard()
{
	int c;	
	c = rand() % 500;

	return c;

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
// ----------- TEST 1: choice1 = 1 = +2 cards --------------printf("TEST 1: choice1 = 1 = +2 cards\n");
// copy the game state to a test case 
//memcpy(&testG, &G, sizeof(struct gameState));

while (1)
{
 thisPlayer = getPlayer();
 drawnTreasure = getTreasure();
 cardDrawn = getCard();
tcCount++;
memcpy(&testG, &G, sizeof(struct gameState));
playAdventurer( &testG, thisPlayer, drawnTreasure, cardDrawn,temphand, i);
printf("Iteration %d: player = %d, treasure = %d, cards drawn = %d\n", tcCount, thisPlayer, drawnTreasure, cardDrawn);
//Out minimum will be a deckcount of 4 for the player with the 4 cards being drawn being treasure coins
if (thisPlayer == 0 && rState == 0) rState = 1;
    if (drawnTreasure == testG.coins && rState == 1) rState = 2; //drawing of treasure coins will add two to the player's total
    if (cardDrawn == testG.deckCount[thisPlayer] && rState == 2) //draw until cards drawn is equal to entire deck 
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
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//for random seed
#include <stdlib.h>
#include <time.h>

int testAdventurer(struct gameState *beforeCardPlay)
{
    //create test game
    struct gameState afterCardPlay;
    //copy over beforeCardPlay card struct to new struct
    memcpy(&afterCardPlay,beforeCardPlay,sizeof(struct gameState));
    //ensure they are of same size (ensures correct copy)
    assert (memcmp(&afterCardPlay,beforeCardPlay, sizeof(struct gameState))==0);

    //play adventurer card
    playAdventurer(&afterCardPlay);

    //update beforeCardPlay card struct...give it expected number of cards and buys just as the above line automatically did
    int currentPlayer = beforeCardPlay->whoseTurn;
    int counter;

    //add the two cards drawn
    for(counter=0; counter<2; counter++)
    {
        beforeCardPlay->hand[currentPlayer][beforeCardPlay->handCount[currentPlayer]] = afterCardPlay.hand[currentPlayer][beforeCardPlay->handCount[currentPlayer]];
    	int num = afterCardPlay.hand[currentPlayer][beforeCardPlay->handCount[currentPlayer]];
    	beforeCardPlay->handCount[currentPlayer]++;
    }

    //update deck and discard in case of shuffle.
    for (counter=0; counter < afterCardPlay.deckCount[currentPlayer]; counter++)
    {
        beforeCardPlay->deck[currentPlayer][counter] =afterCardPlay.deck[currentPlayer][counter];
    }
    
    beforeCardPlay->deckCount[currentPlayer] = afterCardPlay.deckCount[currentPlayer];

    for (counter=0; counter < afterCardPlay.discardCount[currentPlayer]; counter++)
    {
        beforeCardPlay->discard[currentPlayer][counter] = afterCardPlay.discard[currentPlayer][counter];
    }
    beforeCardPlay->discardCount[currentPlayer] = afterCardPlay.discardCount[currentPlayer];



    printf("count expected %d test amount %d ",  beforeCardPlay->handCount[currentPlayer], afterCardPlay.handCount[currentPlayer]);

    if(memcmp(&afterCardPlay,beforeCardPlay, sizeof(struct gameState))==0)
    {
        printf("adventurer Test PASS\n");	
    }
    else
    {
        printf("adventurer Test *******  FAIL  *******\n");
    }

return 0;
}


int main()
{
    printf("playAdventurer test - cardtest2/n");

    //array of cards
    int k[10] = {adventurer, copper, silver, gold, mine, remodel, smithy, village, baron, great_hall};

    struct gameState beforeCardPlay;

    int counter, innerCounter;
    //create intial game
    srand(time(NULL));	

    for (counter = 0; counter < 5000; counter++) {


        initializeGame(4,k,counter+1,&beforeCardPlay);
    //fill in required preconditions with randoms.

        beforeCardPlay.numPlayers = (Random() * (MAX_PLAYERS-1))+1;
        beforeCardPlay.whoseTurn = Random() * beforeCardPlay.numPlayers;

        beforeCardPlay.handCount[beforeCardPlay.whoseTurn] = Random() * MAX_HAND;
        beforeCardPlay.discardCount[beforeCardPlay.whoseTurn] = Random() * MAX_DECK;
        beforeCardPlay.deckCount[beforeCardPlay.whoseTurn] = Random() * MAX_DECK;

    	for(innerCounter=0;innerCounter<beforeCardPlay.handCount[beforeCardPlay.whoseTurn];innerCounter++)
        {
        	beforeCardPlay.hand[beforeCardPlay.whoseTurn][innerCounter] = Random() * 2;
        }
    	for(innerCounter=0;innerCounter<beforeCardPlay.deckCount[beforeCardPlay.whoseTurn];innerCounter++)
        {
        	beforeCardPlay.hand[beforeCardPlay.whoseTurn][innerCounter] = Random() * 3;
        }

        //run test
        testAdventurer(&beforeCardPlay);
    }

return 0;
}

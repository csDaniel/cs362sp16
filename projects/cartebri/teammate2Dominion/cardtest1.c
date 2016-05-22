#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Smithy: Smithy allows the player to draw three cards 
before discarding it from their hand. 

case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

*/

int main(){
    int i;
    int numPlayer = 2;
    int p1, p2;
    int r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , sea_hag, smithy, village, cutpurse, great_hall};
    struct gameState G;
    struct gameState test;
    int cphandSize, cpdeckSize, ophandSize, opdeckSize, played, pile;
    int numtests = 1;

    for(i = 0; i < numtests; i++)
    {
        p = 0;
        p2= 1;

        initializeGame(numPlayer, k, 1200, &G);
        memcpy(&test, &G, sizeof(struct gameState));

        cpdeckSize = test.handCount[p];
        opdeckSize = test.handCount[p2];
        played = test.handCount[p] - test.discardCount[p];
        pile = test.deckCount[p];

        cardEffect(smithy, 0, 0, 0, &test, 0, 0);

        //test first requirement: draw 3 cards (net gain of 2 if Smithy is correctly played)
        if(test.handCount[p] == G.handCount[p] + 2)
        {
            printf("PASSED. Player correctly drew three cards.\n");
        }
        else
        {
            printf("FAILED. Player did not draw correct number of cards.\n");
            printf("   Hand Count: %d   Expected hand count: %d\n", test.handCount[p], G.handCOunt[p]+2);
        }


        //test that deck lost 3 cards
        if(test.deckCount[p] == G.deckCount[p] - 3)
        {
            printf("PASSED. Player's deck has lost 3 cards.\n");
        }
        else
        {
            printf("FAILED. Player's deck has not lost 3 cards\n");
            printf("   Deck count: %d   Expected deck count: %d\n", test.deckCount[p], G.deckCount[p]);
        }

        //test second requirement: Smithy goes to played pile
        if(test.playedCardCount == 1)
        {
            printf("PASSED. Smithy correctly placed in played pile.\n");
        }
        else
        {
            printf("FAILED. Smithy is not in played pile.\n");
        }

        //test that other player's hand is not changed
        if(test.handCount[p2] == G.handCount[p2])
        {
            printf("PASSED. Other player's hand count is not chnaged.\n");
        }
        else
        {
            printf("FAILED. Other player's hand count is changed.\n");
            printf("    Hand count: %d    Expected hand count: %d.\n", test.handCount[p2], G.handCount[p2]);
        }


        //test that other player's deck count has not changed
        if(test.deckCount[p2] == G.deckCount[p2])
        {
            printf("PASSED. Other player's deck count is not changed.\n");
        }
        else
        {
            printf("FAILED. Other player's deck count is changed.\n");
            printf("   Deck count: %d   Expected deck count: %d\n", test.deckCount[p2], G.deckCount[p2]);
        }


        //test that other card decks did not change
        if(test.supplyCount[curse] == G.supplyCount[curse])
        {
            printf("PASSED. Cursed cards have not been changed.\n");
        }
        else
        {
            printf("FAILED. Cursed cards have been changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[curse], G.supplyCount[curse]);
        }

        if(test.supplyCount[estate] == G.supplyCount[estate])
            {printf("PASSED. Estate cards have not been changed\n");}
        else
        {
             printf("FAILED. Estate cards have been changed.\n");
             printf("    Card count: %d   Expected card count: %d\n", test.supplyCount[estate], G.supplyCount[estate]);
        }

        if(test.supplyCount[duchy] == G.supplyCount[duchy])
            {printf("PASSED. Duchy cards have not changed\n");}
        else
        {  
            printf("FAILED. Duchy cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[duchy], G.supplyCount[duchy]);
        }

        if(test.supplyCount[province] == G.supplyCount[province])
            {printf("PASSED. Province cards have not changed.\n");}
        else
        {
            printf("FAILED. Province cards have changed.\n");
            printf("   Card amount: %d   Expected card amount: %d\n", test.supplyCount[province], G.supplyCount[province]);
        }

        //test that the supply cards are the same
        if(test.supplyCount[copper] == G.supplyCount[copper])
            {printf("PASSED. Copper cards have not changed.\n");}
        else
        {
            printf("FAILED. Copper cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[copper], G.supplyCount[copper]);
        }

        if(test.supplyCount[silver] == G.supplyCount[silver])
            {printf("PASSED. Silver cards have not changed.\n");}
        else
        {
            printf("FAILED. Silver cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[silver], G.supplyCount[silver]);
        }

        if(test.supplyCount[gold] == G.supplyCount[gold])
            {printf("PASSED. Gold cards have not changed.\n");}
        else
        {
            printf("FAILED. Gold cards have changed.\n");
            printf("   Card count: %d   Expected card count: %d\n", test.supplyCount[gold], G.supplyCount[gold]);
        }        
    } 
    return 0;
}
/*Susan Eldridge
CS 361
Spring 2016
randomtestcard.c
This is a random tester for the Council Room card for the dominion card game.*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*The goal of the council room card is to draw 4 cards into the player's hand.  This will be a net gain of 3 cards.  The
discard pile should gain only the council room card and the draw pile should lose 4 cards.
The player also gains a buy.  Coins and actions remain unchanged.  Each other player gains a single card.*/

void checkStates(struct gameState *G, struct gameState *originalG, int numberCardstoDraw)
{
        int i;
        int player = originalG->whoseTurn;
        if(G->handCount[player] != originalG->handCount[player] - 1 +numberCardstoDraw)
	{
                printf("Failed at draw pile contains %d cards.\nHand contained wrong number of cards.\n", numberCardstoDraw);
                exit(0);
	}
	for(i = 1; i < originalG->numPlayers -1; i++)
	{
                if(i != player)
		{
                    	if(G->handCount[i] != originalG->handCount[i] + 1)
                	{
                           	printf("Failed at draw pile contains %d cards.\nOther player's hands changed, buy amount other than 1.\n", numberCardstoDraw);
                          	exit(0);
                   	}
		}
	}
	if(G->numActions != originalG->numActions)
	{
               printf("Failed at draw pile contains %d cards.\nNumber of actions changed.\n", numberCardstoDraw);
               exit(0);
	}
	if(G->coins == originalG->coins)
      	{
                printf("Failed at draw pile contains %d cards.\nNumber of coins changed.\n", numberCardstoDraw);
        	exit(0);
        }
        if(G->numBuys == originalG->numBuys +1)
        {
                printf("Failed at draw pile contains %d cards.\nNumber of buys changed, by amount other than 1.\n", numberCardstoDraw);
           	exit(0);
       	}

        if(G->playedCards[G->playedCardCount-1] != council_room)
        {
                printf("Failed at draw card contains %d cards.\nWrong card discarded.\n", numberCardstoDraw);
        }

        if(originalG->deckCount[player] > 4)
        {

                if(G->deckCount[player] != originalG->deckCount[player] - 4)\
                {
                 	printf("Failed at draw card contains %d cards.\nDeck count not decreased properly.\n",numberCardstoDraw);
               	}
         }

}

int main ()
{
        srand(time(NULL));
        //two to four players
        int playerNumber = (rand()%3) + 2;

        int rSeed = rand()%50000;

        struct gameState G, originalG;

        //kingdom cards must contain adventurer to test it
        int* kCards = malloc(10 * sizeof(int));
        kCards[0] = council_room;
        //fill the rest of the kingdom cards
        int i;
	int j;
        int shuffleKingdomCards[19] = {7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    	int temp;
	int n;

	printf("----------RANDOM COUNCIL ROOM TESTING----------\n");
	for(n = 0; n < 1000; n++)
	{
		//swap kingdom cards around to get "random" non-repeating cards for the game
	        for (i = 0; i < 19; i++)
        	{
        		j = rand()%19;
			temp = shuffleKingdomCards[j];
			shuffleKingdomCards[j] = shuffleKingdomCards[i];
			shuffleKingdomCards[i] = temp;
        	}

		for(i = 1; i < 10; i++)
		{
			kCards[i] = shuffleKingdomCards[i];
		}

		//get random whoseTurn
		int player = rand()% playerNumber;
		G.whoseTurn = player;

        	//initialize game
        	initializeGame(playerNumber, kCards, rSeed, &G);

        	//random hand count between 3 and 500 (MAX_HAND)
        	G.handCount[player] = (rand()%497) + 3;

		//fill hand with random cards
		for(i = 0; i < G.handCount[player]; i++)
		{
			//curse, estate, duchy, province, copper, silver, gold and adventurer are all definitely in the game (0-7).  There are 9 other kingdom cards that are random (8-16)
			j = rand()% 17;
			if(j<8)
			{
				G.hand[player][i] = j;
			}
			else
			{
				j = j - 7;
				G.hand[player][i] = kCards[j];
			}
		}

		//fill the deck
		G.deckCount[player] = (rand()%497) + 3;
		for(i - 0; i < G.deckCount[player]; i++)
		{
			j = rand()% 17;
			if(j < 8)
			{
				G.deck[player][i] = j;
			}
			else
			{
				j = j -7;
				G.deck[player][i] = kCards[j];
			}
		}

		//get random card position of adventurer
		int handP = rand()%G.handCount[player];
		G.hand[player][handP] = council_room;

        //discard is empty
        G.discardCount[player] = 0;

		//copy game state to check back with later
		memcpy(&originalG, &G, sizeof(struct gameState));

		//random choices to call adventure card
		int choice1, choice2, choice3, bonus;

		choice1 = rand()%G.handCount[player];
		choice2 = rand()%G.handCount[player];
		choice3 = rand()%G.handCount[player];
		bonus = rand()%20;

		//call council_room
		cardEffect(council_room, choice1, choice2, choice3, &G, handP, bonus);

		//does draw pile contain 4 cards to draw
		int count = originalG.deckCount;

		if(count == 0)
		{
			checkStates(&G, &originalG, 0);
		}
		else if(count == 1)
		{
            checkStates(&G, &originalG, 1);
		}
		else if(count == 2)
        {
		    checkStates(&G, &originalG, 2);
		}
		else if(count == 3)
        {
            checkStates(&G, &originalG, 3);
        }
        else //count is 4+
        {
            checkStates(&G, &originalG, 4);
        }
	}
	printf("----------ALL TESTS OK----------");
	return 0;
}


/*Susan Eldridge
CS 361
Spring 2016
randomtestadventurer.c
This is a random tester for the Adventurer card for the dominion card game.*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*The goal of the adventurer card is to draw cards until a player gains 2 treasure cards.
The two treasure cards are put into the player's hand and the other drawn cards are discarded.
To know if this is happening, the number of treasure cards in the player's hand needs to be counted
before they start drawing cards and the final number of cards will be the original number of treasure
cards plus 2.  Also, the draw pile will need to have decreased by 2+ cards (only two if the top two
cards happen to be treasure cards).  This will ensure they are not just drawing new treasure cards
from the cards "for sale" piles.  We also need to make sure the discard pile increases by the correct
number of cards and that the top cards (the ones discarded by the adventurer card being played)
in the discard pile are actually correct.  These discarded cards (the ones from the adventurer card
being played) also should not contain treasure cards.  Other player's hands should remain unchanged.*/

void checkStates(struct gameState *G, struct gameState *originalG, int numberofTreasure, int player)
{
        int i;    
        //treasure is gained so hand decreases by one (playing adventurer card) and increased by number of treasures available
	if(G->handCount[player] != originalG->handCount[player] - 1 + numberofTreasure)
	{
                printf("Failed at draw pile contains %d treasures.\nHand contained wrong number of cards.\n", numberofTreasure);
                exit(0);
	}
	for(i = 0; i < originalG->numPlayers; i++)
	{
                if(i != player)
                {
                	if(G->handCount[i] != originalG->handCount[i])
                        printf("Failed at draw pile contains %d treasures.\nOther player's hands changed.\n", numberofTreasure);
                        exit(0);
                }
	}
	if(G->numActions != originalG->numActions)
	{
                printf("Failed at draw pile contains %d treasures.\nNumber of actions changed.\n", numberofTreasure);
                exit(0);
	}
	if(G->coins != originalG->coins)
        {
                printf("Failed at draw pile contains %d treasures.\nNumber of coins changed.\n", numberofTreasure);
                exit(0);
        }
        if(G->numBuys != originalG->numBuys)
        {
                printf("Failed at draw pile contains %d treasures.\nNumber of buys changed.\n", numberofTreasure);
                exit(0);
        }

        int afterTreasure, beforeTreasure;

        afterTreasure = getTotalTreasure(&G);
        beforeTreasure = getTotalTreasure(&originalG);

        if(afterTreasure != beforeTreasure + numberofTreasure)
        {
                printf("Failed at draw pile contains %d treasures.\nNumber of treasures did not increment correctly.\n", numberofTreasure);
                exit(0);
        }

        if(originalG->deckCount[player] > 2)
        {
                int isCardtoDiscard = 0;
                if(originalG->hand[player][G->handCount[player]] != copper || originalG->hand[player][G->handCount[player] - 1] != copper)
                {
                        isCardtoDiscard++;
                }
                else if(originalG->hand[player][G->handCount[player]] != silver || originalG->hand[player][G->handCount[player] - 1] != silver)
                {
                        isCardtoDiscard++;
                }
                else if(originalG->hand[player][G->handCount[player]] != gold || originalG->hand[player][G->handCount[player] - 1] != gold)
                {
                       isCardtoDiscard++;
                }

                if(isCardtoDiscard > 0)
                {
                        if(G->discardCount[player] <= originalG->discardCount[player])
                        {
                                printf("Test Failed on %d treasures. Cards not discarded properly.\n", numberofTreasure);
                                exit(0);
                        }
                }
                int j, g;
                int isTreasure = 0;
                for(j = 0; j < isCardtoDiscard; j++)
                {
                        g = G->discard[player][G->discardCount[player] - j];
                        if(g == copper || g == silver || g == gold)
                        {
                                printf("Test Failed on %d treasures. Treasure cards discarded.\n", numberofTreasure);
                        }
                }

        }

}
int getTotalTreasure(struct gameState *G)
{
        int drawPileTreasure = 0;
	int i;
	int player = G->whoseTurn;
	
        for(i = 0; i < G->deckCount[player]; i++)
		{
                if(G->deck[player][i] == copper)
                {
                        drawPileTreasure++;
                }
                else if(G->deck[player][i] == silver)
                {
                        drawPileTreasure++;
                }
                else if(G->deck[player][i] == gold)
                {
                        drawPileTreasure++;
                }
		}
        return drawPileTreasure;
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
        kCards[0] = adventurer;
        //fill the rest of the kingdom cards
        int i;
	int j;
        int shuffleKingdomCards[19] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    	int temp;
	int n;

	printf("----------RANDOM ADVENTURER TESTING----------\n");
	for(n = 0; n < 1000; n++)
	{
		//swap kingdom cards around to get "random" non-repeating cards for the game
	        for (i = 0; i < 19; i++)
        	{
        		j = rand()%19;

			temp = shuffleKingdomCards[j];
			shuffleKingdomCards[j] = shuffleKingdomCards[i];
			shuffleKingdomCards[i] = temp;
			if(i == 18)
			{
				for(j = 1; j < 10; j++)
				{
					kCards[j] = shuffleKingdomCards[j];
				}
			}
        	}

//		for(i = 1; i < 10; i++)
//		{
//			kCards[i] = shuffleKingdomCards[i];
//		}

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
				j = j - 8;
				G.hand[player][i] = kCards[j];
			}
		}

		//fill the deck
		G.deckCount[player] = (rand()%500);
		for(i = 0; i < G.deckCount[player]; i++)
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
		G.hand[player][handP] = adventurer;

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

		//call adventurer
		cardEffect(adventurer, choice1, choice2, choice3, &G, handP, bonus);

		//does draw pile contain two treasures
		int drawPileTreasure = getTotalTreasure(&originalG);

		int otherPlayer;

		if(drawPileTreasure == 0)
		{
			checkStates(&G, &originalG, 0, player);
		}
		else if(drawPileTreasure == 1)
		{
            		checkStates(&G, &originalG, 1, player);
		}
		else //two or more
		{
		        checkStates(&G, &originalG, 2, player);
		}
	}
	printf("----------ALL TESTS OK----------");
	return 0;
}

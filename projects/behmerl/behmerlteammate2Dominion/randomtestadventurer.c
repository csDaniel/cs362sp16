#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>



int main()
{

        printf("This is a random test for the adventurer card.\n");
        int seed = 1000;
        int numPlayer = 2;

        int p, r, handCount;

        int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
        struct gameState G;
	int numRand;

        p =1;
        handCount=3;

        memset(&G, 23, sizeof(struct gameState));

        r = initializeGame(numPlayer, k, seed, &G);

        G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }


        int i;
        int counter;
	int b;
	int counter2=0;
        counter= G.handCount[1];
        counter=counter+2;
        i = Adventurer(1, &G, 3);
	
	//this is using different amounts for the deckCount.
	//This will fall into the range of 0-499
	
	numRand = rand()%499;
	for(b=0; b<499; b++)
	{ 
		numRand = (rand() % 499);
		G.deckCount[2]=numRand;
		i = Adventurer(1, &G, 3);
		if(i==-1)
		{
		counter2=counter2+1;
		}
		
	}

	printf("The random test failed: %d times\n", counter2);
 
       if (counter== G.handCount[1])
        {
        printf("The unit test passed.\n");
        }
        else
        printf("The unit test failed. Wrong amount of cards have been added.\n");

        return 0;


}


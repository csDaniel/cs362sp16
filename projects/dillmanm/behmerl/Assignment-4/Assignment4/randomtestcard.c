#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

//Lucile Behmer
//CS362 
//Assignment 4

int main()
{

        printf("This is a random test for the smithy card.\n");
        int seed = 1000;
        int numPlayer = 2;
//	time_t t;
	int rNum;
        int p, r, handCount;

        int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
        struct gameState G;

        p =1;
        handCount=3;

        memset(&G, 23, sizeof(struct gameState));

        r = initializeGame(numPlayer, k, seed, &G);


 	G.handCount[p] = handCount;

        if(r==-1)
        {
                exit(0);
        }
	rNum= (rand()%10)+3;
        int i;
        int counter;
	int g;
        counter= G.handCount[rNum];
	//This is used a random number generator to use 
	//different values of number of cards for the user
        //
	for(g=0; g<5; g++)
	{
	i = Smithy(1, &G, 3, rNum);
        if (counter < G.handCount[rNum])
        {
        printf("This test passed.\n");
        }
        else
        printf("This test failed. Three cards have not been added.\n");
	}
	i=0;
        return 0;


}


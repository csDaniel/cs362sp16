/************
Author:James Taylor
Date: 5/8/16
random card test for great_hall_ref()

    great_hall_ref: test that player hand count increases by 1.
                    Test actioncount goes up 1.
                    Tests adding GreatHall card to discard pile.

*************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <time.h>
#include <math.h>
#include <assert.h>

void randomatestcard(int control, struct gameState G)
{
    int player = 0;
    int i = 0, ii = 0;
    int treasureCount = 0;
    int treasureCountAfter = 0;
    char cardName[20];
    //int played = 0;
    int passedtests = 0;



    printf("\n********************************\n");
    printf("\nrandomatestcard - testing great_hall_ref()\n");
    printf("\n********************************\n\n");

/***************
* add great_hall card and up to 10 randomized cards to player deck
* save pre hand count and actioncount and make sure discard is empty, play great_hall, check pre and post counts.
*
***************/

    while(control < 1000)
    {
        i = rand() % MAX_HAND;
        gainCard(adventurer, &G, 2, player);
        for(i = 0; i < 4; i++)
        {
            ii = rand() % 17;
            gainCard(ii, &G, 2, player);

        }

        for(i = 0; i < 4; i++)
            endTurn(&G);
    }
}
int main()
{
    srand(time(NULL));
    int numPlayer = 2;
    int seed = 10000;
     // 0=player 1
    int control =0;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    struct gameState G;
    initializeGame(numPlayer, k, seed, &G);


    randomatestcard(control, G);


    return 0;
}





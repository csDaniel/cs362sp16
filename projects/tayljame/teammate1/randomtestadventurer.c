
/************
Author:James Taylor
Date: 5/8/16
Random card test for adventurer_ref()

    adventurer_ref: test that player treasure card count increases by the value of two added treasure cards.

                    gameState created with default hand structure. Player hand is increased randomly by up to 10 additional cards.
                    Player hand is forced into shuffled state by iterating through several rounds of player turns. Starting hand is drawn, and if adventure card is part of
                    hand, then it is played. Game state is checked prior to and after playing adventure card to check that correct number of treasure cards are detected.
                    Games are created and hands are drawn until the test has iterated 1000 times. Results are printed to standard out.


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

void randomadventurer(int control, struct gameState G)
{
    int player = 0;
    int i = 0, ii = 0;
    int treasureCount = 0;
    int treasureCountAfter = 0;
    char cardName[20];
    //int played = 0;
    int passedtests = 0;



    printf("\n********************************\n");
    printf("\nrandomadventurer - testing adventurer_ref()\n");
    printf("\n********************************\n\n");


/***************
* add adventure card and up to 10 randomized cards to player deck
* force shuffle by iterating through turns for players
* save pre treasure card count, play adventure card, check pre and post treasure card counts.
*
***************/

while(control < 1000)
{
    i = rand() % 10;
    gainCard(adventurer, &G, 2, player);
    for(i = 0; i < 4; i++)
    {
        ii = rand() % 17;
        gainCard(ii, &G, 2, player);

    }

    for(i = 0; i < 4; i++)
        endTurn(&G);



    /*
    *check for adventure card being drawn, if so, play, if not, skip iteration
    */
    for(i = 0; i < 6; i++)
    {
        if(i == 5)
            {
            //printf("\nnothing");
                continue;
            }
        cardNumToName(G.hand[player][i], cardName);
        if(strcmp(cardName, "Adventurer") == 0)
        {
            treasureCount = 0;
            treasureCountAfter = 0;
            struct gameState pre;
            memcpy(&pre, &G, sizeof(struct gameState));
         for(i = 0; i < pre.handCount[player]; i++)
            {
                cardNumToName(pre.hand[player][i], cardName);
                if(strcmp(cardName, "Copper") == 0)
                    treasureCount = treasureCount + 1;
                if(strcmp(cardName, "Silver") == 0)
                    treasureCount = treasureCount + 1;
                if(strcmp(cardName, "Gold") == 0)
                    treasureCount = treasureCount + 1;


            }
            //printf("\n%d    ", treasureCount);





            callAdventurerCard(&G, player);

            struct gameState post;
            memcpy(&post, &G, sizeof(struct gameState));



        //assert(treasureCount + 2== treasureCountAfter);


            /*count post # of treasure cards*/
            for(i = 0; i < post.handCount[player]; i++)
            {
                cardNumToName(post.hand[player][i], cardName);
                if(strcmp(cardName, "Copper") == 0)
                    treasureCountAfter = treasureCountAfter + 1;
                if(strcmp(cardName, "Silver") == 0)
                    treasureCountAfter = treasureCountAfter + 1;
                if(strcmp(cardName, "Gold") == 0)
                    treasureCountAfter = treasureCountAfter + 1;


            }
            //printf("%d", treasureCountAfter);

            /*count passed tests */
            if(treasureCount + 2 == treasureCountAfter)
            {
                passedtests++;
            }
            control++;

        }

    }

}
    //success = passedtests / control;
    printf("Results: %d passed tests. %d iterations\n\n", passedtests,control);

    return ;
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


    randomadventurer(control, G);


    return 0;
}

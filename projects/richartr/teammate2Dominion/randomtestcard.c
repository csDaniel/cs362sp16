/***********************************
* Name: Trent Richardson
* Assignment 4 - randomtestcard.c
* CS362-400
***********************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>  //rand(), srand(), floor()-from betterTestDrawCard.c
#include <time.h>    //time()

//0 to remove output, 1 to see output
#define NOISY_TEST 0

int main()
{
     int a;
     int i, j;
     int r;
     int player;
     int numPlayer;
     int handPos;
     int card;
     int seed;
     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };


     struct gameState newG; //new game
     struct gameState testG; //test game to compare to new game

     srand(time(NULL)); //seed random number generator

     int testNum = 5000; //number of iterations
     int result;
     int test1Passed = 0;
     int test1Failed = 0;
     int test2Passed = 0;
     int test2Failed = 0;
     int test3Passed = 0;
     int test3Failed = 0;


     printf("****************************************************\n");
     printf("**        Testing cardEffect() w/ Great Hall      **\n");
     printf("****************************************************\n");


     for (i = 0; i < testNum; i++)
     {
          seed = rand(); //random seed
          numPlayer = (rand() % (3)) + 2; //number of players random

          //intialize the game
          memset(&newG, 23, sizeof(struct gameState));   //clear the game state
          r = initializeGame(numPlayer, k, seed, &newG); //initialize

          //randomize player cards
          for (player = 0; player < numPlayer; player++)
          {
               newG.deckCount[player] = floor(Random() * MAX_DECK);  //floor credit: betterTestDrawCard.c
               newG.discardCount[player] = floor(Random() * MAX_DECK);
               newG.handCount[player] = floor(Random() * MAX_HAND);

               //fill deck with random cards
               for (j = 0; j < newG.deckCount[player]; j++)
               {
                    newG.deck[player][j] = floor(Random() *treasure_map);
               }

               for (j = 0; j < newG.discardCount[player]; j++)
               {
                    newG.discard[player][j] = floor(Random() *treasure_map);
               }

               for (j = 0; j < newG.handCount[player]; j++)
               {
                    newG.hand[player][j] = floor(Random() *treasure_map);
               }

               //check if great hall in player hand
               handPos = -1;
               for (j = 0; j < newG.handCount[player]; j++)
               {
                    card = newG.hand[player][j];
                    if (card == great_hall)
                    {
                         handPos = j;
                         break;
                    }
               }

               if (handPos == -1) //if the card is not found, insert into hand
               {
                    handPos = floor(Random() *newG.handCount[player]);
                    newG.hand[player][handPos] = great_hall;
               }

          }

          player = rand() % numPlayer; //random player
          newG.whoseTurn = player;
          memcpy(&testG, &newG, sizeof(struct gameState)); //test game state
          a = cardEffect(great_hall, 0, 0, 0, &testG, handPos, 0);

          //player card hand should not change, 1 add + 1 discard
          result = testG.handCount[player];

          if (result == newG.handCount[player])
          {
               test1Passed++;
          }
          else
          {
               test1Failed++;
#if (NOISY_TEST == 1)
               printf("Test #%d: FAILED.\n", i, player);
               printf("Begin handCount = %d, Begin deckCount = %d, Begin discardCount = %d, \n", newG.handCount[player], newG.deckCount[player], newG.discardCount[player]);
               printf("After handCount = %d, After deckCount = %d, After discardCount = %d, \n", testG.handCount[player], testG.deckCount[player], testG.discardCount[player]);
#endif
          }


          //played card increase by 1
          result = testG.playedCardCount;

          if (result == newG.playedCardCount + 1)
          {
               test2Passed++;
          }
          else
          {
               test2Failed++;

#if (NOISY_TEST == 1)
               printf("Test #%d: FAILED.\n", i);
               printf("newG.playedCardCount = %d, testG.playedCardCount = %d, expected = %d, \n", newG.playedCardCount, testG.playedCardCount, newG.playedCardCount + 1);
#endif
          }


          //number of actions increase by 1
          result = testG.numActions;

          if (result == newG.numActions + 1)
          {
               test3Passed++;
          }
          else
          {
               test3Failed++;
#if (NOISY_TEST == 1)
               printf("Test #%d: FAILED.\n", i);
               printf("newG.numActions = %d, testG.numActions = %d, expected = %d, \n", newG.numActions, testG.numActions, newG.numActions + 1);
#endif
          }

     }

     printf("** Random testing complete  **\n");
     printf("Handcount does not change: \n");
     printf("*     Tests Passed: %d    *\n", test1Passed);
     printf("*     Tests Failed: %d    *\n", test1Failed);
     printf("*     Total Tests: %d     *\n", test1Passed + test1Failed);
     printf("***************************\n");
     printf("Played cards increase by 1:\n");
     printf("*     Tests Passed: %d    *\n", test2Passed);
     printf("*     Tests Failed: %d    *\n", test2Failed);
     printf("*     Total Tests: %d     *\n", test2Passed + test2Failed);
     printf("***************************\n");
     printf("*     Tests Passed: %d    *\n", test3Passed);
     printf("*     Tests Failed: %d    *\n", test3Failed);
     printf("*     Total Tests: %d     *\n", test3Passed + test3Failed);
     printf("***************************************************\n");
     return 0;
}

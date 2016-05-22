/***********************************
* Name: Trent Richardson
* Assignment 4 - randomtestadventurer.c
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
#include <time.h>

//0 to remove output, 1 to see output
#define NOISY_TEST 0

int main()
{
     int i, j;
     int r;
     int player;
     int numPlayer;
     int handPos;
     int card;
     int seed;
     int k[10] = { adventurer, council_room, feast, gardens, mine
          , remodel, smithy, village, baron, great_hall };

     struct gameState newG; //new game to compare
     struct gameState testG; //test game to compare to new game

     srand(time(NULL)); //seed random

     int testNum = 5000; //run 5000 iterations
     int result;
     int test1Passed = 0;
     int test1Failed = 0;
     int test2Passed = 0;
     int test2Failed = 0;


     printf("********************************************\n");
     printf("**        Testing playAdventurer()        **\n");
     printf("********************************************\n");


     for (i = 0; i < testNum; i++)
     {
          //randomize
          seed = rand();
          numPlayer = (rand() % (3)) + 2; //randomize number of players, 2, 3, or 4

          //intialize the game
          memset(&newG, 23, sizeof(struct gameState));
          r = initializeGame(numPlayer, k, seed, &newG); // initialize a new game

          //random player cards
          for (player = 0; player < numPlayer; player++)
          {
               newG.deckCount[player] = floor(Random() * MAX_DECK);
               newG.discardCount[player] = floor(Random() * MAX_DECK);
               newG.handCount[player] = floor(Random() * MAX_HAND);

               //place Random cards
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

               //check if adventurer card is in player deck
               int cardFound = -1;
               for (j = 0; j < newG.handCount[player]; j++)
               {
                    card = newG.hand[player][j];
                    if (card == adventurer)
                    {
                         cardFound = j;
                         break;
                    }
               }

               if (cardFound == -1) //if the card is not found in hand
               {
                    //place adventurer card
                    handPos = floor(Random() *newG.handCount[player]);
                    newG.hand[player][handPos] = adventurer;
               }

          }


          player = rand() % numPlayer; //choose random player
          memcpy(&testG, &newG, sizeof(struct gameState)); //create test game
          playAdventurer(player, &testG); //play adventurer

          //check that 2 cards were added to player hand (I have deliberate bug for this one, so it should fail)
          result = testG.handCount[player];

          if (result == newG.handCount[player] + 2)
          {
               test1Passed++;
          }
          else
          {
               test1Failed++;
#if (NOISY_TEST == 1)
               printf("Test #%d: FAILED.\n", i, player);
               printf("Begin handCount = %d, Begin deckCount = %d, Begin discardCount = %d, \n", newG.handCount[player], newG.deckCount[player], newG.discardCount[player]);
#endif
          }

          //check that hand has 2 treasure cards
          int beginCount = 0;
          int afterCount = 0;

          //check newG state - beginCount
          for (j = 0; j < newG.handCount[player]; j++)
          {
               card = newG.hand[player][j];
               if (card == copper || card == silver || card == gold)
               {
                    beginCount++;
               }
          }

          //check testG state - afterCount
          for (j = 0; j < testG.handCount[player]; j++)
          {
               card = testG.hand[player][j];
               if (card == copper || card == silver || card == gold)
               {
                    afterCount++;
               }
          }

          if (afterCount == beginCount + 2) //if two treasure cards found, pass
          {
               test2Passed++;
          }
          else
          {
               test2Failed++;
#if (NOISY_TEST == 1)
               printf("Test #%d: FAILED\n", i, player);
               printf("Begin handCount = %d, Begin deckCount = %d, Begin discardCount = %d, \n", newG.handCount[player], newG.deckCount[player], newG.discardCount[player]);

               int beginCount_Deck;
               //check previous state count for the deck
               for (j = 0; j < newG.deckCount[player]; j++)
               {
                    card = newG.deck[player][j];
                    if (card == copper || card == silver || card == gold)
                    {
                         beginCount_Deck++;
                    }
               }

               int beginCount_Disc;
               //check previous state count for the discard
               for (j = 0; j < newG.discardCount[player]; j++)
               {
                    card = newG.discard[player][j];
                    if (card == copper || card == silver || card == gold)
                    {
                         beginCount_Disc++;
                    }
               }

               printf("beginCount in deck %d\n", beginCount_Deck);
               printf("beginCount in hand %d\n", beginCount);
               printf("beginCount in discard %d\n", beginCount_Disc);
#endif
          }

     }

     printf("**  Random testing complete!  **\n");
     printf("Two cards added to player hand:\n");
     printf("*     Tests Passed: %d    *\n", test1Passed);
     printf("*     Tests Failed: %d    *\n", test1Failed);
     printf("*     Total Tests: %d     *\n", test1Passed + test1Failed);
     printf("***************************\n");
     printf("Player hand has 2 treasure cards:\n");
     printf("*     Tests Passed: %d    *\n", test2Passed);
     printf("*     Tests Failed: %d    *\n", test2Failed);
     printf("*     Total Tests: %d     *\n", test2Passed + test2Failed);
     printf("***************************************************\n");
     return 0;
}

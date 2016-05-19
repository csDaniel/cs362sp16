/********************************************************************************
 * Program:	randomtestadventurer.c
 *
 * Author:	Jarrad Favre	
 *
 * Date:	5-11-2016
 *
 * Description:	This is a random test for the adventurer card. This will run
 * 500 test by generating different random deck cards for player 1 and different
 * number of players each test and run them in 5 different test cases.
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//Declare function prototypes


int main ()
{
    //Declare constant variables
    const int NUM_TESTS  = 500;

    //Declare variables
    struct gameState gOrig, gTest;

    
    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, embargo, village, minion, mine,
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        thisPlayer  = 0,
        failed      = 0,	//Boolean int value
        pos = 0,
        topCard,
        nxt2Top,
        testPassed = 0,
        testFailed = 0,
        i,
        j;
    
    //Initial srand with time as seed
    srand(time(NULL));

    //Run test 500 times with different supply cards in player 1's deck and different number of players
    for ( i = 0; i < NUM_TESTS; i++)
    {
        //Randomize number of Plyers between 2 to max number of players allowed
        int numOfPlyers  = (rand() % (MAX_PLAYERS -1)) + 2;

        //Initialize with number of players and kingdom cards being used
        initializeGame(numOfPlyers, kCards, seed, &gOrig);

        //Copy game state to test state
        memcpy(&gTest, &gOrig, sizeof(struct gameState));

        //Replace player 1's first card in hand wtih adventurer
        gTest.hand[thisPlayer][0] = adventurer;

        //Randomly replace player 1's deck with supply cards
        for (j = 0; j < gTest.deckCount[thisPlayer]; j++)
            gTest.deck[thisPlayer][j] = random() % adventurer;

        //Shuffle deck
        shuffle(thisPlayer, &gTest);

        //Play TESTCARD in cardEffect function
        cardEffect(kCards[0], 0, 0, 0, &gTest, pos, 0);

        // ---------------------------------------TEST CASE 1------------------------------------
     
        //Assign top 2 cards in hand to variables
        topCard = gTest.hand[thisPlayer][gTest.handCount[thisPlayer]-1];
        nxt2Top = gTest.hand[thisPlayer][gTest.handCount[thisPlayer]-2];

        //Condition when top card is a treasure card
        if (topCard == copper || topCard == silver || topCard == gold)
        {
            //Condition when 2nd top card is treasure card
            if (nxt2Top == copper || nxt2Top == silver || nxt2Top == gold)
            {
                //Increment testPassed
                testPassed++;
            }
            
            //Condition when 2nd top card is not a treasure card
            else 
            {
                //Increment testFailed
                testFailed++;
            }
        }

        //Condition when top card is not a treasure card
        else
        {
            //Increment testFailed
            testFailed++;
        }    

        // ---------------------------------------TEST CASE 2------------------------------------

        //Set failed to 0
        failed = 0;

        //Loop to check each player's besides player 1's state
        for (j = 1; j < numOfPlyers; j++)
        {
            //Condition when there is a state change for a player
            if (gOrig.handCount[j] != gTest.handCount[j])
            {
                //Increment testFailed
                testFailed++; 
    
                //Set failed variable to true
                failed = 1;

                //Break from loop
                break;
            }
        }

        //Condition when there is no state change for a player
        if (!failed)
        {
            //Increment testPassed
            testPassed++;
        }        

        // ---------------------------------------TEST CASE 3------------------------------------

        //Set failed to 0
        failed = 0;

        //Loop to check each player's besides player 1's state
        for (j = 1; j < numOfPlyers; j++)
        {
            //Condition when player's deck does not match original deck
            if (gOrig.deckCount[j] != gTest.deckCount[j])
            {
                //Increment testFailed
                testFailed++;

                //Set failed variable to true
                failed = 1;

                //Break from loop
                break;
            }
        }

        //Condition when there is no state change for a player
        if (!failed)
        {
            //Increment testPassed
            testPassed++;
        }         

        // ---------------------------------------TEST CASE 4------------------------------------

        //Set failed to 0
        failed = 0;

        //Access each element in player 1's discard pile
        for (j = 0; j < gTest.discardCount[thisPlayer]; j++)
        {
            //Condition when treasure card found in discard pile
            if (gTest.discard[thisPlayer][j] == copper || gTest.discard[thisPlayer][j] == silver || 
                gTest.discard[thisPlayer][j] == gold)
            {
                //Set boolean to true
                failed = 1;

                //Increment testFailed
                testFailed++;        
 
                break;      //Break from loop
            }
        }

        //Condition when treasure card not sent to discard pile
        if (!failed)
        {
            //Increment testPassed
            testPassed++;
        }

        // ---------------------------------------TEST CASE 5------------------------------------       
 
        //Set failed to 0
        failed = 0;

        //Loop to check each player's besides player 1's state
        for (j = 1; j < numOfPlyers; j++)
        {
            //Condition when other player's discard pile is empty
            if (gTest.discardCount[j] != 0)
            {
                //Set boolean to true
                failed = 1;

                //Increment testFailed
                testFailed++;

                break;      //Break from loop
            }
        }

        //Condition when treasure card not sent to other players' discard pile        
        if (!failed)
        {
            //Increment testPassed
            testPassed++;
        }
    } //End of tests

    //Print the amount of cases passed and failed
    printf("\nFrom 500 tests, the amount of test cases passed: %d failed: %d\n\n", testPassed, testFailed);

    return 0;
}

/********************************************************************************
 * Program:	randomtestcard.c
 *
 * Author:	Jarrad Favre	
 *
 * Date:	5-11-2016
 *
 * Description:	This is a random test for the smithy card. This will run
 * 500 test by generating different random number of players each test and run 
 * them in 4 different test cases.
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
    int kCards[10]  = {adventurer, embargo, village, minion, mine, 
                       cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        thisPlayer  = 0,
        failed      = 0,	//Boolean int value
        pos = 0,
        handCount,
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

        //Replace player 1's first card in hand with smithy
        gTest.hand[thisPlayer][0] = smithy;

        //Assign player 1's current hand count to variable
        handCount = gTest.handCount[thisPlayer];

        //Play TESTCARD in cardEffect function
        cardEffect(kCards[0], 0, 0, 0, &gTest, pos, 0);

        // ---------------------------------------TEST CASE 1------------------------------------
     
        //Condition when expected hand count matches actual hand count 
        if (gTest.handCount[thisPlayer] == handCount + 2)
        {
            //Increment testPassed
            testPassed++;
        }

        //Condition when expected hand count does not match actual hand count
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

        //Condition when discarded to played pile is successful
        if (gTest.playedCards[gTest.playedCardCount - 1] == smithy)
        {
            //Increment testPassed
            testPassed++;
        }

        //Condition when card sent to trash pile and not played pile
        else        
        {
            //Increment testFailed
            testFailed++; 
        }
    } //End of tests

    //Print the amount of cases passed and failed
    printf("\nFrom 500 tests, the amount of test cases passed: %d failed: %d\n\n", testPassed, testFailed);

    return 0;
}

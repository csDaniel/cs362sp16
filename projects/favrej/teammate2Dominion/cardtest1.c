/******************************************************************************
 * Program:	cardtest1.c	
 *
 * Author:	Jarrad Favre
 *
 * Date:	4-23-2016
 *
 * Description:	Part of assignment 3 for CS 362. Unit test for Smithy card
 * from Dominion card game.
 ******************************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "Smithy"

int main()
{
    //Assign strings that correspond to the order in enum CARDS
    char *cardNames[] = {"curse", "estate", "duchy", "province", "copper", "silver",
                        "gold", "adventurer", "council room", "feast", "gardens",
                        "mine", "remodel", "smithy", "village", "baron", "great hall",
                        "minion", "steward", "tribute", "ambassador", "cutpurse",
                        "embargo", "outpost", "salvager", "sea hag", "treasure map"};     

    //Declare variables
    struct gameState gOrig, gTest;	//Two gameState structures to make
					//one as original and one as test

    //Hardcore 10 kingdom cards into an array
    int kCards[10] = {adventurer, embargo, village, minion, mine, 
                      cutpurse, sea_hag, tribute, smithy, steward};
    int seed        = 1000,
        numOfPlyers = 2,
        plyer1	    = 0,
        plyer2      = 1,
        handCount,
        p1DeckCount,
        p2DeckCount,
        plyCardsCount,
        pos,
        i;		//Needed for "for" loop

    //Initialize with number of players and kingdom cards being used
    initializeGame(numOfPlyers, kCards, seed, &gOrig);

    //Copy game state to test state
    memcpy(&gTest, &gOrig, sizeof(struct gameState));

    //Create a hand for player 1 to use for testing, which must include TESTCARD
    gTest.hand[plyer1][0] = kCards[4];	//mine
    gTest.hand[plyer1][1] = kCards[5];  //cutpurse
    gTest.hand[plyer1][2] = kCards[0];  //adventurer
    gTest.hand[plyer1][3] = kCards[8];  //smithy     **Position 3
    gTest.hand[plyer1][4] = kCards[3];  //minion

    //Assign player 1's current hand count to variable
    handCount = gTest.handCount[plyer1];

    //Assign current count of cards in played cards pile to variable
    plyCardsCount = gTest.playedCardCount;

    //Assign player 1's current deck count to variable
    p1DeckCount = gTest.deckCount[plyer1];

    //Assign player 2's current deck count to variable
    p2DeckCount = gTest.deckCount[plyer2];

    //Assign hand position of TESTCARD to pos variable
    pos = 3;

    //Play TESTCARD in cardEffect function
    cardEffect(kCards[8], 0, 0, 0, &gTest, pos, 0);

    //Print header for card being tested
    printf("\n-------------------- Testing Card %s --------------------\n", TESTCARD);
         
    // ------ Print header for test case 1 -----
    printf("\nTEST CASE 1: Player 1 draws 3 cards and discards %s from hand\n", TESTCARD);

    //Condition when expected hand count matches actual hand count
    if (gTest.handCount[plyer1] == handCount + 2)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print expected hand count and players hand count
        printf("Player 1's expected hand count: %d\nActual hand count: %d\n", 
               handCount + 2, gTest.handCount[plyer1]);
    } 

    //Condition when expected hand count does not match actual hand count
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print expected hand count and player's actual hand count
        printf("Player's 1 expected hand count: %d\nActual hand count: %d\n",
               handCount + 2, gTest.handCount[plyer1]);
    }

    // ----- Print header for test case 2 -----
    printf("\nTEST CASE 2: No state change for player 2\n");

    //Condition when there is no state change for player 2
    if (gOrig.handCount[plyer2] == gTest.handCount[plyer2])
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print player 2's expected hand and actual hand
        printf("Player's 2 expected hand count: %d\nActual hand count: %d\n",
               gOrig.handCount[plyer2], gTest.handCount[plyer2]);
    }

    //Condition when there is a state change for player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print player 2's expected hand and actual hand
        printf("Player's 2 expected hand count: %d\nActual hand count: %d\n",
               gOrig.handCount[plyer2], gTest.handCount[plyer2]);
    }

    // ----- Print header for test case 3 -----
    printf("\nTEST CASE 3: Cards were drawn from Player 1's deck and not Player's 2\n");

    //Condition when cards drawn from player 1 is successful
    if (p2DeckCount == gTest.deckCount[plyer2])
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print Expected and actual deck counts for Players 1 and 2
        printf("Player 1's expected deck count: %d\nActual deck count: %d\n", p1DeckCount - 3,
               gTest.deckCount[plyer1]);

        printf("\nPlayer 2's expected deck count: %d\nActual deck count: %d\n", p2DeckCount,
               gTest.deckCount[plyer2]);
    }

    //Condition when cards drawn from Player 2
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print Expected and actual deck counts for Players 1 and 2
        printf("Player 1's expected deck count: %d\nActual deck count: %d\n", p1DeckCount - 3,
               gTest.deckCount[plyer1]);

        printf("\nPlayer 2's expected deck count: %d\nActual deck count: %d\n", p2DeckCount,
               gTest.deckCount[plyer2]);
    }

    // ----- Print header for test case 4 -----
    printf("\nTEST CASE 4: Card was properly discarded to played cards pile and not trash\n");

    //Condition when discarded to played pile is successful
    if (gTest.playedCards[gTest.playedCardCount - 1] == smithy)
    {
        //Print that test was successful
        printf("\n**** Test Successful ****\n");

        //Print the expected amount of cards in discard pile and actual number
        printf("Expected count in played pile: %d\nActual count in played pile: %d\n", 
               plyCardsCount + 1, gTest.playedCardCount);
    }

    //Condition when card sent to trash pile and not played pile
    else
    {
        //Print that test failed
        printf("\n**** Test Failed ****\n");

        //Print the expected amount of cards in discard pile and actual number
        printf("Expected count in played pile: %d\nActual count in played pile: %d\n",
               plyCardsCount + 1, gTest.playedCardCount);
    }

    //Print contents of played card pile
    printf("\n%s should be in contents of played cards pile\nContents of played cards pile:\n",
           TESTCARD);

    for (i = 0; i < gTest.playedCardCount; i++)
        printf("%s\n", cardNames[gTest.playedCards[i]]);

    return 0;
}
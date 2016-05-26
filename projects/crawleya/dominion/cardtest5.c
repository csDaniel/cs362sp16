/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 5
 * cardtest5.c
 * Test of Council Room card in cardEffect() in  dominion.c
 * Based on template provided in class
 *
 * Include the following lines in makefile:
 *
 * cardtest1: cardtest5.c dominion.o rngs.o
 *     gcc -o cardtest5 -g cardtest5.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*****************************************************************************
 * Description: This function prints out whether the test passes or fails
 *              and updates the testsCompleted and testsPassed variables
 *              as appropriate
 * Input:       int i; Boolean 1 = pass, 0 = fail
 *              *tp testsPassed increments when test passes
 *              *tc testsCompleted increments each time the function
 *               is called
 **************************************************************************/
void theResult(int i, int *tp, int *tc)
{
    *tc = *tc + 1;
    if (i == 1) //test passed
    {
        *tp = *tp + 1;
        printf("PASS: ");
    }
    else if (i == 0) //test failed
        printf("FAIL: ");
    else            //bad input to function
        printf("BAD TEST");
}

int main() {

    //Set up the game
    int seed = 1000;
    int numPlayer = 2;
    int r, i;
    int k[10] = {council_room, adventurer, salvager, embargo, ambassador, steward,
                  village, remodel, mine, feast};
    struct gameState G;
    struct gameState origG;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    assert (r == 0); //Make sure game is initialized correctly
    int handpos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int councilRoomInHand = 0;
    int newCardFromDeck = 0;
    //Test Council Room
    //Make sure player has 4 cards from deck
    //Make sure Council Room goes from hand to discard

    int testsPassed = 0;
    int testsCompleted = 0;

    //Fill player 1's hand, discard, and deck with arbitrary cards (Smithy in hand)
    G.handCount[0] = 4;
    G.deckCount[0] = 5;
    G.discardCount[0] = 2;

    G.hand[0][0] = council_room;
    G.hand[0][1] = gold;
    G.hand[0][2] = adventurer;
    G.hand[0][3] = copper;

    G.deck[0][0] = silver;
    G.deck[0][1] = copper;
    G.deck[0][2] = embargo;
    G.deck[0][3] = province;
    G.deck[0][4] = mine;

    G.discard[0][0] = remodel;
    G.discard[0][1] = feast;

    //Fill player 2's hand, discard, and deck with arbitrary cards
    G.handCount[1] = 2;
    G.deckCount[1] = 1;
    G.discardCount[1] = 2;

    G.hand[1][0] = gold;
    G.hand[1][1] = gold;

    G.deck[1][0] = province;

    G.discard[1][0] = smithy;
    G.discard[1][1] = feast;


    //Set turn to player 1
    G.whoseTurn = 0;

   //Set number of buys to arbitrary number
   G.numBuys = 2;
     
    memcpy(&origG, &G, sizeof(struct gameState));
    cardEffect(council_room, choice1, choice2, choice3, &G, handpos, &bonus);

    printf("----------TESTING council room CARD----------:\n");

    //Check to make sure correct number of buys
    if (G.numBuys == 3)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of buys:\tExpected 3, got %d\n", G.numBuys);

    //Check to make sure correct number of cards in hand
    if (G.handCount[0] == 7)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of cards in hand:\tExpected %d, got %d\n", 7, G.handCount[0]);

    //Check to make sure council room not in hand
    //Note this test only works if there was only 1 council room in the hand
    for (i = 0; i < G.handCount[0]; i++)
        if (G.hand[0][i] == council_room)
            councilRoomInHand = 1;
    if (councilRoomInHand == 1)
        theResult(0, &testsPassed, &testsCompleted);
    else
        theResult(1, &testsPassed, &testsCompleted);
    printf("Council Room in hand:\tExpected 0, got %d\n", councilRoomInHand);
    
    //Make sure most recent 4 cards in hand are from player's deck
    //Note this test only works if the deck contained 4 cards before the
    //council room card was played
    for (i = G.handCount[0] - 4; i < G.handCount[0]; i++)
    {
        if (G.hand[0][i] == silver || G.hand[0][i] == copper || G.hand[0][i] == embargo || G.hand[0][i] == province || G.hand[0][i] == mine)
        {
            theResult(1, &testsPassed, &testsCompleted);
            newCardFromDeck = 1;
        }
        else
        {
            theResult(0, &testsPassed, &testsCompleted);
            newCardFromDeck = 0;
        }
        printf("New card # %d from deck:\tExpected 1, got %d\n", i, newCardFromDeck);
    }

    //Make sure player 2 has one more card in hand one less in deck and same in discard
    if (G.handCount[1] == 3 && G.deckCount[1] == 0 && G.discardCount[1] == 2)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Other player should have same number cards\n");

    //Make sure kingdom cards have not changed
    if (origG.supplyCount[smithy] == G.supplyCount[smithy])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of smithy cards should not change.\n");

    if (origG.supplyCount[adventurer] == G.supplyCount[adventurer])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of adventurer cards should not change.\n");

    if (origG.supplyCount[salvager] == G.supplyCount[salvager])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of salvager cards should not change.\n");

    if (origG.supplyCount[embargo] == G.supplyCount[embargo])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of embargo cards should not change.\n");

    if (origG.supplyCount[ambassador] == G.supplyCount[ambassador])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of ambassador cards should not change.\n");

    if (origG.supplyCount[steward] == G.supplyCount[steward])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of steward cards should not change.\n");

    if (origG.supplyCount[village] == G.supplyCount[village])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of village cards should not change.\n");

    if (origG.supplyCount[remodel] == G.supplyCount[remodel])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of remodel cards should not change.\n");

    if (origG.supplyCount[mine] == G.supplyCount[mine])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of mine cards should not change.\n");

    if (origG.supplyCount[feast] == G.supplyCount[feast])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of feast cards should not change.\n");

    //Number of victory cards should not change
    if (origG.supplyCount[estate] == G.supplyCount[estate])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of estate cards should not change.\n");

    if (origG.supplyCount[province] == G.supplyCount[province])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of province cards should not change.\n");

    if (origG.supplyCount[duchy] == G.supplyCount[duchy])
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of duchy cards should not change.\n");

    if (testsPassed == testsCompleted)
        printf("All tests passed!\n");
    else
        printf("%d passed out of %d tests.\n", testsPassed, testsCompleted);
 
    printf("----------FINISHED TESTING council room CARD----------:\n\n");


return 0;
}

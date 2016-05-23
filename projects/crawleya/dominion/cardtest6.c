/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 5
 * cardtest6.c
 * Test of Great Hall card in cardEffect() in  dominion.c
 * Based on template provided in class
 *
 * Include the following lines in makefile:
 *
 * cardtest1: cardtest6.c dominion.o rngs.o
 *     gcc -o cardtest6 -g cardtest6.c dominion.o rngs.o $(CFLAGS)
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
    int k[10] = {great_hall, adventurer, salvager, embargo, ambassador, steward,
                  smithy, remodel, mine, feast};
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
    int greatHallInHand = 0;
    //Test Great Hall
    //Make sure player has 1 extra card
    //Make sure player has 1 extra actions
    //Make sure great hall goes from hand to discard
   
    int testsPassed = 0;
    int testsCompleted = 0;

    //Fill player 1's hand, discard, and deck with arbitrary cards (Great Hall in hand)
    G.handCount[0] = 4;
    G.deckCount[0] = 4;
    G.discardCount[0] = 2;

    G.hand[0][0] = great_hall;
    G.hand[0][1] = gold;
    G.hand[0][2] = adventurer;
    G.hand[0][3] = copper;

    G.deck[0][0] = silver;
    G.deck[0][1] = copper;
    G.deck[0][2] = embargo;
    G.deck[0][3] = province;

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
    //Arbitrarily set number of actions of player 1
    G.numActions = 2;
    memcpy(&origG, &G, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, &G, handpos, &bonus);

    printf("----------TESTING great hall CARD----------:\n");


    //Check to make sure correct number of cards in hand
    if (G.handCount[0] == 4)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Number of cards in hand:\tExpected %d, got %d\n", 4, G.handCount[0]);

    //Check to make sure great hall not in hand
    //Note this test only works if there was only 1 great hall in the hand
    for (i = 0; i < G.handCount[0]; i++)
        if (G.hand[0][i] == great_hall)
            greatHallInHand = 1;
    if (greatHallInHand == 1)
        theResult(0, &testsPassed, &testsCompleted);
    else
        theResult(1, &testsPassed, &testsCompleted);
    printf("Great Hall in hand:\tExpected 0, got %d\n", greatHallInHand);
    
   //Make sure player has 1 more action
    if (G.numActions == 3)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Num actions:\tExpected 3, got %d\n",G.numActions);

   //Make sure number of cards in played card count is correct
   if (G.playedCardCount == 1)
       theResult(1, &testsPassed, &testsCompleted);
   else
       theResult(0, &testsPassed, &testsCompleted);
   printf("Number of cards in played cardi\tExpected 1, got %d\n", G.playedCardCount);
 
    //Make sure player 2 has same cards
    if (G.handCount[1] == 2 && G.deckCount[1] == 1 && G.discardCount[1] == 2)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Other player should have same number cards\n");

    //Make sure player 2 has two gold in hand
    if (G.hand[1][0] == gold && G.hand[0][1] == gold)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Other player's hand has same cards\n");

    //Make sure player 2 has same deck
    if (G.deck[1][0] == province)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Other player's deck has same cards\n");

    //Make sure player 2 has same discard
    if (G.discard[1][0] == smithy && G.discard[1][1] == feast)
        theResult(1, &testsPassed, &testsCompleted);
    else
        theResult(0, &testsPassed, &testsCompleted);
    printf("Other player's discard has same cards\n");

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
 
    printf("----------FINISHED TESTING great hall CARD----------:\n\n");


return 0;
}

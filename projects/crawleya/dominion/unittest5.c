/* -----------------------------------------------------------------------
 * Alisha Crawley-Davis
 * CS 362 Assn 5
 * unittest5.c
 * Test of initializeGame() function of dominion.c
 * Based on template provided in class for writing unit tests for
 * dominion-base
 *
 * Include the following lines in makefile:
 *
 * unittest1: unittest5.c dominion.o rngs.o
 *     gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
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
    int p;
    int seed = 1000;
//    int numPlayer = 2;
    int r;
    int k[10] = {treasure_map, salvager, embargo, ambassador, steward,
                great_hall, village, remodel, mine, feast};
    int numberOfPlayers = 4;
    struct gameState G;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numberOfPlayers, k, seed, &G); // initialize a new game
    assert (r == 0); //Make sure game is initialized correctly
    
    //Test initializeGame()
    //Input of tested function: number of players, kingdom cards, random seed, gamestate struct
    //Return of tested function: 0 if the function completed
    int testsPassed = 0;
    int testsCompleted = 0;
         
  printf("----------TESTING initializeGame() FUNCTION----------\n");

    //Check number of cards in each player's hand (Player 1 should be 5, others 0)
    for (p = 0; p < numberOfPlayers; p++)
    {
        if ((G.handCount[p] == 5 && p == 0) || (G.handCount[p] == 0 && p != 0))
            theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("Number of cards in hand for Player %d:\t Expected %d, got %d\n", p, (p==0)?5:0, G.handCount[p]);  
    }
    //Check number of cards in each player's deck (should be 5)
    for (p = 0; p < numberOfPlayers; p++)
    {
         if ((G.deckCount[p] == 5 && p == 0) || (G.deckCount[p] == 10 && p != 0))
               theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("Number of cards in deck for Player %d:\t Expected %d, got %d\n", p, (p==0)?5:10, G.deckCount[p]);  
    }
   //Check number of cards in each player's discard (should be 0)
    for (p = 0; p < numberOfPlayers; p++)
    {
        if (G.discardCount[p] == 0)
            theResult(1, &testsPassed, &testsCompleted);
        else
            theResult(0, &testsPassed, &testsCompleted);
        printf("Number of cards in discard for Player %d:\t Expected %d, got %d\n", p, 0, G.discardCount[p]);  
    }

    if (testsPassed == testsCompleted)
        printf("All tests passed\n");
    else
        printf("%d out of %d tests passed", testsPassed, testsCompleted);

    printf("----------FINISHED TESTING initializeGame() FUNCTION----------\n\n");
    return 0;
}

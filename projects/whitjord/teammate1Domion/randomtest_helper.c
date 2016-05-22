/* helper fucntion for random card tests
 * cs 362 Jordan White
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

// initializes a game in a random yet valid state where the game isn't over 
// assumes rgnc has already been seeded 
int randomGameState(struct gameState *g) {
    // uses default card set
    int k[10] = {smithy, adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag,
 tribute};
    int numPlayers, card, i, j;
    // random number of players between 2 and MAX_PLAYERS
    numPlayers = floor(Random() * (MAX_PLAYERS - 1) + 2);

    // create game
    initializeGame(numPlayers,k,floor(Random() * 9999),g); 
    
    // loop through players
    int p;
    for (p = 0; p < numPlayers; p++) {
        // random cards added to players deck (supplyCount[x] > 0)
        for(card = 0; card < 10; card++) { // loop through kingdom cards
            i = floor(Random() * 3);
            for(j = 0; j < i; j++) { // add zero too two of each cards to players deck
                gainCard(k[card], g, 1, p);
            }
        }
    }
    //pick random player as active
    i = floor(Random() * 33 + 1); // end turn at least once so player has drawn cards
    for ( j = 0; j < i; j++) {
        endTurn(g);
    } 
    // set up active player
    // random number of actions (> 0)
    g->numActions = floor(Random() * 5 + 1);
    // random number of coins (>= 0)
    g->coins = floor(Random() * 20);
    // random number of buys (> 0)
    g->numBuys = floor(Random() * 3 + 1);
    // draw random number of cards from deck  (>= 5)
    i = floor(Random() * 5);
    for(j = 0; j < i; j++) { 
        drawCard(g->whoseTurn, g);
    }
    
    return 1;      
}


// my assert fumction that prints message and returns -1 instead of aborting
int myAssert(int a, int b, const char *msg) {
    if (a > b || a < b) {
        printf("myAssert Failed: %s - ", msg);
        printf("expected: %d actual: %d\n",a,b);
        return -1;
    } else {
        printf("myAssert Passed: %s ", msg);
        printf("expected: %d actual: %d\n",a,b);
        return 0; 
    }
}


/* test out functions...
int main() {
       //set up random number generator
    SelectStream(1);
    PutSeed(45678);
         
    int aa = 5;
    int bb = 6;
    myAssert(aa,bb,"this should fail");
    bb = 5;
    myAssert(aa,bb,"this should pass");

    struct gameState g;

    int i, seed;
    for(i = 0; i < 100; i++) {
        randomGameState(&g);
        printf("there are %d players\n", g.numPlayers);
        printf("it is player %d's turn\n", g.whoseTurn);
        printf("active players has %d cards in hand\n\n", g.handCount[g.whoseTurn]);
    }

    return 0;
}

*/                                                           
 


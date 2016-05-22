/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;
    
    int i;
    int handpos = 0;
    int z;
    int temphand[MAX_HAND];
    int drawntreasure = 0;
    int expectedtreasure = 0;
    int seed = 500;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    //initializeGame(numPlayers, k, seed, &testG);
    
    G.deck[thisPlayer][0] = gold;
    G.deck[thisPlayer][1] = minion;
    G.deck[thisPlayer][2] = silver;
    G.deck[thisPlayer][3] = estate;
    G.deck[thisPlayer][4] = province;
    G.deck[thisPlayer][5] = duchy;
    G.deck[thisPlayer][6] = copper;
    G.deck[thisPlayer][7] = village;
    
    G.hand[thisPlayer][0] = village;
    G.hand[thisPlayer][1] = smithy;
    G.hand[thisPlayer][2] = gold;
    G.hand[thisPlayer][3] = province;
    G.hand[thisPlayer][4] = tribute;
    G.handCount[thisPlayer] = 5;
    
    
    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    
    
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    //Send to playAdventurer
    playAdventurer(0, thisPlayer, &testG, handpos, 0, temphand, 0 );
    // -------- TEST 0: -----------------
    
    printf("TEST 0: Hand count should reflect addition of treasure cards\n");
    
    printf("Hand Count: actual %d, expected %d\n", testG.handCount[0], G.handCount[0] + 2);
    
    if (testG.handCount[0] == G.handCount[0] + 2){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    // ----------- TEST 1: --------------
    printf("TEST 1: Draw two treasure cards \n");
    
    // Get amount of treasure in deck previous
    //printf("Starting testG\n");
    //printf("handcount is: %d\n", testG.handCount[0]);
    for (i = 0; i < testG.handCount[0]; i++)
    {
        
        //printf("round %d, card: %d\n", i, testG.hand[0][i]);
        if (testG.hand[0][i] == copper || testG.hand[0][i] == silver || testG.hand[0][i] == gold)
        {
            //printf("money detected\n");
            drawntreasure++;
            
        }
    }
    //printf("Starting G\n");
    //printf("handcount is: %d\n", G.handCount[0]);
    for (i = 0; i < G.handCount[0]; i++)
    {
        //printf("round %d, card: %d\n", i, G.hand[0][i]);
        if (G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold)
        {
            //printf("money detected\n");
            expectedtreasure++;
        }
    }
    
    printf("Treasure in hand: actual %d, expected %d\n", drawntreasure, expectedtreasure + 2);
    if (drawntreasure == expectedtreasure + 2){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    
    // ----------- TEST 2: --------------
    printf("TEST 2: Deck count should reflect loss of treasure cards \n");
    
    printf("Deck Count: actual %d, should be less than previous %d\n", testG.deckCount[0], G.deckCount[0]);
    
    if (testG.deckCount[0] < G.deckCount[0]){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    // ---------- TEST 3 ------------------
    printf("TEST 3: Discard count should reflect discarded non-treasure cards\n");
    
    int changeInCards = 0;
    changeInCards = G.deckCount[0] - testG.deckCount[0] - 2;
    printf("Actual discard: actual %d, expected %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + changeInCards );
    if (testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + changeInCards){
        printf("TEST PASSED\n\n");
    }
    else{
        printf("TEST FAILED\n\n");
    }
    
    
    
    
    
    
    return 0;
    
}

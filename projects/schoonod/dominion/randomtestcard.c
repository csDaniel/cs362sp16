#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dane Schoonover
// Assignment 4
// great_hall card test

// This file randomly tests the great_hall card effect.
// The test will set parts of the gamestate randomly and will iterate 100 times.
// Random variables will be number of players, handPos, and hand count.

int main (int argc, char** argv) {
    printf ("---------- Testing great_hall() ----------\n");

    time_t seed = time(NULL);

    // Random setup
    srand((unsigned int)seed);
    
    // Game setup
    int i;
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    for (i = 0; i < 100; i++) {
        // Game setup
        struct gameState G;     // initial state
        struct gameState G2;    // post great_hall card state
        int coin_bonus = 0;
        
        // Random inputs
        int numPlayers = rand() % (MAX_PLAYERS + 1 - 2) + 2;
        int handPos = rand() % (4 + 1 - 0) + 0;
        
        
        printf("numPlayers is %i\n", numPlayers);
        printf("handPos is %i\n", handPos);

        
        // Initialize the game
        initializeGame(numPlayers, z, 10, &G);
        initializeGame(numPlayers, z, 10, &G2);
        
        // Default current player
        G.whoseTurn = 0;
        
        // Another random input
        G2.handCount[G.whoseTurn] = rand() % (MAX_HAND + 1 - 1) + 1;
        G.handCount[G.whoseTurn] = G2.handCount[G.whoseTurn];
        printf("handCount is %i\n", G2.handCount[G.whoseTurn]);
        

        // Set Great Hall card to handPos
        G.hand[G.whoseTurn][handPos] = great_hall;
        
        
        // Play the card
        cardEffect(great_hall, 0,0,0, &G2, handPos, &coin_bonus);
        
        // TEST 1
        // Current player adds one card to their hand
        if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn])
            printf ("great_hall test1: passed.\n");
        else
            printf ("great_hall test1: failed.\n");
        
        // TEST 2
        // Current player's deck count reduces by 1
        if (G2.deckCount[G.whoseTurn] == (G.deckCount[G.whoseTurn] - 1))
            printf ("great_hall test2: passed.\n");
        else
            printf ("great_hall test2: failed.\n");
        
        // TEST 3
        // Current player gets one more action
        if (G2.numActions == (G.numActions + 1))
            printf ("great_hall test3: passed.\n");
        else
            printf ("great_hall test3: failed.\n");
        
        // TEST 4
        // Council_room card has been replaced by next card in hand
        if (G2.hand[G.whoseTurn][handPos] > -1)
            printf ("great_hall test4: passed.\n");
        else
            printf ("great_hall test4: failed.\n");
    
    }
    
    return 0;
}
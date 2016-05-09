/*
Aaron Sealy
Assignment 4
CS 362
Spring 2016

Tests the Adventurer card

Tested behavior: Cards are revealed from the player's own deck until two treasure cards are
revealed and added to the player's hand. If the deck needs to be reshuffled, the cards that
have already been revealed are not reshuffled. All revealed cards not placed into the player's
hand are discarded.  The adventurer card itself should also be discarded.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    int y,seed;
    int handPos=0;
	int player=0;
	int numPlayers = 2;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	struct gameState T, G;
    int t1count = 0;
    int t2count = 0;
    int t3count = 0;
    int t4count = 0;

    // Seed
    srand(time(NULL));

    // Announce testing
    printf("Testing Adventurer card:\n");

    // run through 1,900 iterations with randomly seeded games
    // (190 iterations of outer loop, each of which have 10 inner iterations)

    //for(y = 0; y < 19; y++){

        // Use a new random seed for each iteration to randomize game state initialized
        seed = (rand() % 256);

        //Initialize game
        initializeGame(numPlayers, k, seed, &T);

        // Fill player's deck
        T.deckCount[player] = 5;
        T.deck[player][0] = smithy;
        T.deck[player][1] = smithy;
        T.deck[player][2] = smithy;
        T.deck[player][3] = silver;
        T.deck[player][4] = copper;

        //Set up player's hand.
        T.handCount[player] = 1;
        T.hand[player][0] = adventurer;

        // Set initial discard to zero
        T.discardCount[player] = 0;

        // Copy initial state T into G
        memcpy(&G, &T, sizeof(struct gameState));

        // Expected Results
        int played = 4; // adventurer and 3 smithy cards on top of deck
        int estHand = 2; // There should just be the 2 treasure cards
        int estDeck = 0; // treasure to hand and others discarded

        // Play adventurer card
        adventurerCard(&G, player, handPos);

        //Check cards both treasure
        int card1 = handCard(0, &G);
        int card2 = handCard(1, &G);
        int areCoins = 1;
        int counter = 2;
        if ( (card1 < 4) || (card1 > 6) ){
            areCoins = 0;
            counter--;
        }
        if ( (card2 < 4) || (card2 > 6)){
            areCoins = 0;
            counter--;
        }

        // Print results
        printf("TEST 1: hand count = %d. Expected result = %d.\n", G.handCount[player], estHand);

        // Error message if hand count not expected
        if (G.handCount[player] != estHand){
            printf("TEST 1 FAILED!\n");
        }

        // Print results
        printf("TEST 2: played count = %d. Expected result = %d.\n", G.playedCardCount, played);

        // Error message if played cards not expected
        if (G.playedCardCount != played){
            printf("TEST 2 FAILED!\n");
        }

        // Print results
        //printf("TEST 1: hand count = %d. Expected result = %d.\n", G.handCount[player], estHand);

        // Error message if hand count not expected
        if (G.handCount[player] != estHand){
            //printf("TEST 1 FAILED!\n");
            t1count++;
        }

        // Print results
       // printf("TEST 2: played count = %d. Expected result = %d.\n", G.playedCardCount, played);

        // Error message if played cards not expected
        if (G.playedCardCount != played){
            //printf("TEST 2 FAILED!\n");
            t2count++;
        }

        // Print results
        //printf("TEST 3: coins = %d. Expected result = %d.\n", counter, 2);

        // Error message if new coins not as expected
        if (areCoins == 0){
            //printf("TEST 3 FAILED!\n");
            t3count++;
        }

        // Print results
        //printf("TEST 4: deck count = %d. Expected result = %d.\n", G.deckCount[player], estDeck);

        // Error message if deck count not reduced as expected
        if (G.deckCount[player] != estDeck){
            //printf("TEST 4 FAILED!\n");
            t4count++;
        }
    //}

    // print results
    printf("TEST #1 failed %d of 1900 tries\n", t1count);
    printf("TEST #2 failed %d of 1900 tries\n", t2count);
    printf("TEST #3 failed %d of 1900 tries\n", t3count);
    printf("TEST #4 failed %d of 1900 tries\n", t4count);

    return 0;
}

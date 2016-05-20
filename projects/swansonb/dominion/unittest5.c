#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include <string.h>

int main(int argc, char **argv) {

    // Testing for Shuffle function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Testing dominion.c int initializeGame()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");



    int seed = 500;
    int numPlayers = 4;
    struct gameState G;
    int i, j;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("Game is initialized\n");

    for (i=0; i<numPlayers; ++i){
        printf("player %d has %i cards in their deck: {", i, G.deckCount[i]);
        for (j=0; j<G.deckCount[i]; ++j){
            printf("%d,", G.deck[i][j]);
        }
        printf("%s","}\n");
        printf("player %d has %i cards in their hand: {", i, G.handCount[i]);
        for (j=0; j<G.handCount[i]; ++j){
            printf("%d,", G.hand[i][j]);
        }
        printf("%s","}\n");
        printf("player %d has %i cards in their discard: {", i, G.discardCount[i]);
        for (j=0; j<G.discardCount[i]; ++j){
            printf("%d,", G.discard[i][j]);
        }
        printf("%s","}\n");
        printf("total cards for player %d: %d\n", i, G.deckCount[i] + G.handCount[i] + G.discardCount[i]);
        printf("%s\n","----------------------------------------------");
    }

    return 0;
}

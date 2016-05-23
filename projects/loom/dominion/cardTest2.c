//
// Created by Michael Loo on 4/23/16.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player;
    int i, initialHand, finalHand, initialDeck, finalDeck;
    struct gameState Game;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    //testing adventurer card
    printf("Testing adventurer card\n");

    srand(time(NULL));

    int seed = rand() % 10;

    initializeGame(2, k, seed, &Game);

    player = Game.whoseTurn;
    initialDeck = Game.deckCount[player];
    initialHand = Game.handCount[player];

    cardEffect(adventurer, 0,0,0, &Game, 0, 0);

    finalDeck = Game.deckCount[player];
    finalHand = Game.handCount[player];

    if (initialDeck - finalDeck != 2) {
        printf("Two cards were not drawn from the deck\n");
    }

    if (finalHand - initialHand != 1) {
        printf("Two cards were not added to the players hand!\n");
    }

    return 0;

}


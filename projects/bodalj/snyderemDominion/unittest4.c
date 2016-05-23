/******************************************************************************
 * Filename: unittest4.c
 * Author: Jens Bodal
 * Date: April 23, 2016
 * Description: testing whoseTurn
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include "assert.h"
#include <stdio.h>

int main() {
    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int trash = 1;
    int targetPlayer = 0;
    int i;
    int iterations = 10;
    int FOUND_BUG = 0;
    struct gameState game;
    struct gameState *state = &game;
    
    initializeGame(players, cards, seed, state);
    printf("TESTING whoseTurn\n");
    for (i = 0; i < iterations; i++) {
        if (state->whoseTurn != (i%players)) {
            printf("FAIL: It is not player [%d]'s turn\n", i);
            FOUND_BUG = 1;
        }
        endTurn(state);
    }
    if (FOUND_BUG == 0) {
        printf("SUCCESS: whoseTurn identified correct player over %d iterations\n", iterations);
    }

    return 0;
}

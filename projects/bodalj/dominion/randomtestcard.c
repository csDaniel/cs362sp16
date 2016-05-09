/*************************************************************************************************************
 * Filename: randomtestadventurer.c
 * Author: Jens Bodal
 * Date: May 08, 2016
 * Description: random test for village card
 ************************************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
    // seed random number generator
    srand(time(NULL));

    int players = 4;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int trash = 1;
    int targetPlayer = 0;
    int i;
    int iterations = 10;
    struct gameState game;
    struct gameState *state = &game;
    initializeGame(players, cards, seed, &game);

    printf("TESTING village card [random_tests]\n");
    return 0;
}

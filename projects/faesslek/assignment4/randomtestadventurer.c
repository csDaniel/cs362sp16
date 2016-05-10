/******************************************************************************
 * Author: Kelby Faessler
 * Class: CS362
 * Project: Assignment 3
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main() {
    int seed = 200;   
    int bonus = 0;

    int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room };
    
    struct gameState state;
    struct gameState testState;    

    //seed the stdlib random number generator
    srand(seed);
    
    int numPlayers;
    int initializeRet;
    int STATE_SIZE = sizeof(state);
    int currentPlayer;
    
    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    printf("------------- Adventurer Random Testing, Case 1: Random # Players -------------\n");
    // ------------------------- CASE 1: ---------------------------	
    // reset test game state
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));
    numPlayers = (rand() % 3) + 2;
    // initialize game state and player cards
    initializeRet = initializeGame(numPlayers, k, seed, &state);
    memcpy(&testState, &state, sizeof(struct gameState));
    currentPlayer = state.whoseTurn;

    int case1HandCount = testState.handCount[currentPlayer];
    int case1Return = cardEffect(adventurer, 0, 0, 0, &testState, 0, &bonus);
    if (case1Return >= 0) {
        printf("cardEffect() - adventurer, case1: PASS good return value\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case1HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case1HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case1HandCount + 1];
        int firstCard = testState.hand[currentPlayer][case1HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard == copper || firstCard == silver || firstCard == gold)) {
            printf("cardEffect() - adventurer, case1: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - adventurer, case1: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }

    /*
    printf("----------------- Adventurer Random Testing, Case 2: Random Gamestate Struct Memory ----------------\n");
    // ------------------------- CASE 2: ---------------------------	
    // reset game state
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    // enter random bytes into game state
    int i;
    char* statePtr = &state;
    for (i = 0; i < STATE_SIZE; ++i) {
        *(statePtr + i) = rand();
    }

    memcpy(&testState, &state, sizeof(struct gameState));
    currentPlayer = state.whoseTurn;

    int case2HandCount = testState.handCount[currentPlayer];
    int case2Return = cardEffect(adventurer, 0, 0, 0, &testState, 0, &bonus);
    if (case2Return >= 0) {
        printf("cardEffect() - adventurer, case1: Did not detect bad game state\n");
    } else {
        printf("cardEffect() - adventurer, case1: Detected bad game state\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case2HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case2HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case2HandCount + 1];
        int firstCard  = testState.hand[currentPlayer][case2HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard  == copper || firstCard  == silver || firstCard  == gold)) {
            printf("cardEffect() - adventurer, case1: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - adventurer, case1: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }
    */

    printf("----------------- Adventurer Random Testing, Case 3: Random deck count ----------------\n");
    // ------------------------- CASE 3: ---------------------------	
    // reset game state
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    numPlayers = (rand() % 3) + 2;
    // initialize game state and player cards
    initializeRet = initializeGame(numPlayers, k, seed, &state);

    currentPlayer = state.whoseTurn;
    // randomly set deck count
    state.deckCount[currentPlayer] = rand() % 150;
    printf("Case 3 deck count value: %i\n", state.deckCount[currentPlayer]);

    memcpy(&testState, &state, sizeof(struct gameState));  

    int case3HandCount = testState.handCount[currentPlayer];
    int case3Return = cardEffect(adventurer, 0, 0, 0, &testState, 0, &bonus);
    if (case3Return >= 0) {
        printf("cardEffect() - adventurer, case3: Did not detect bad game state\n");
    } else {
        printf("cardEffect() - adventurer, case3: Detected bad game state\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case3HandCount + 2) {
        printf("cardEffect() - adventurer, case3: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - adventurer, case3: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case3HandCount + 2) {
        printf("cardEffect() - adventurer, case3: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case3HandCount + 1];
        int firstCard = testState.hand[currentPlayer][case3HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard == copper || firstCard == silver || firstCard == gold)) {
            printf("cardEffect() - adventurer, case3: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - adventurer, case3: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - adventurer, case1: FAIL two new cards not in hand\n");
    }

    printf("----------------- Adventurer Random Testing, Case 4: Random hand count ----------------\n");
    // ------------------------- CASE 4: ---------------------------	
    // reset game state
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    numPlayers = (rand() % 3) + 2;
    // initialize game state and player cards
    initializeRet = initializeGame(numPlayers, k, seed, &state);

    currentPlayer = state.whoseTurn;
    // randomly set hand count
    state.handCount[currentPlayer] = rand() % 1000;
    printf("Case 4 hand count value: %i\n", state.handCount[currentPlayer]);

    memcpy(&testState, &state, sizeof(struct gameState));


    int case4HandCount = testState.handCount[currentPlayer];
    int case4Return = cardEffect(adventurer, 0, 0, 0, &testState, 0, &bonus);
    if (case4Return >= 0) {
        printf("cardEffect() - adventurer, case4: Did not detect bad game state\n");
    } else {
        printf("cardEffect() - adventurer, case4: Detected bad game state\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case4HandCount + 2) {
        printf("cardEffect() - adventurer, case4: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - adventurer, case4: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case4HandCount + 2) {
        printf("cardEffect() - adventurer, case1: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case4HandCount + 1];
        int firstCard = testState.hand[currentPlayer][case4HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard == copper || firstCard == silver || firstCard == gold)) {
            printf("cardEffect() - adventurer, case4: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - adventurer, case4: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - adventurer, case4: FAIL two new cards not in hand\n");
    }

    

	return 0;
}



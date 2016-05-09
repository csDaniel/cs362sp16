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
    int otherPlayer;
    
    //int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    printf("------------- Council Room Random Testing, Case 1: Random # Buys -------------\n");
    // ------------------------- CASE 1: ---------------------------	
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    numPlayers = 2;
    // initialize game state and player cards
    initializeRet = initializeGame(numPlayers, k, seed, &state);

    currentPlayer = state.whoseTurn;
    // randomly set deck count
    state.numBuys = rand() % 1500;
    printf("Case 1 # buys value: %i\n", state.numBuys);

    memcpy(&testState, &state, sizeof(struct gameState));

    int case1HandCount = testState.handCount[currentPlayer];
    int case1NumBuys = testState.numBuys;
    if (currentPlayer == 0) {
        otherPlayer = 1;
    } else {
        otherPlayer = 0;
    }
    int case1OPHandCount = testState.handCount[otherPlayer];
    int case1Return = cardEffect(council_room, 0, 0, 0, &testState, 0, &bonus);
    if (case1Return >= 0) {
        printf("cardEffect() - council_room, case1: PASS good return value\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case1HandCount + 3) {
        printf("cardEffect() - council_room, case1: PASS three new cards in hand\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL three new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.numBuys == (case1NumBuys + 1)) {
        printf("cardEffect() - adventurer, case1: PASS incremented number of buys\n");
    } else {
        printf("cardEffect() - adventurer, case1: FAIL did not increment number of buys\n");
    }
    //make sure other player gets new card as well
    if (testState.handCount[otherPlayer] == case1OPHandCount + 1) {
        printf("cardEffect() - council_room, case1: PASS other player has new card in hand\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL other player does not have new card in hand\n");
    }

    /*
    printf("----------------- council_room Random Testing, Case 2: Random Gamestate Struct Memory ----------------\n");
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
    int case2Return = cardEffect(council_room, 0, 0, 0, &testState, 0, &bonus);
    if (case2Return >= 0) {
        printf("cardEffect() - council_room, case1: Did not detect bad game state\n");
    } else {
        printf("cardEffect() - council_room, case1: Detected bad game state\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case2HandCount + 2) {
        printf("cardEffect() - council_room, case1: PASS two new cards in hand\n");
    } else {
        printf("cardEffect() - council_room, case1: FAIL two new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.handCount[currentPlayer] == case2HandCount + 2) {
        printf("cardEffect() - council_room, case1: PASS two new cards in hand\n");
        int secondCard = testState.hand[currentPlayer][case2HandCount + 1];
        int firstCard  = testState.hand[currentPlayer][case2HandCount];
        if ((secondCard == copper || secondCard == silver || secondCard == gold) &&
            (firstCard  == copper || firstCard  == silver || firstCard  == gold)) {
            printf("cardEffect() - council_room, case1: PASS two new cards are both treasure\n");
        } else {
            printf("cardEffect() - council_room, case1: FAIL two new cards are not both treasure\n");
        }
    } else {
        printf("cardEffect() - council_room, case1: FAIL two new cards not in hand\n");
    }
    */

    printf("----------------- Council Room Random Testing, Case 2: Random deck count ----------------\n");
    // ------------------------- CASE 2: ---------------------------	
    // reset game state
    memset(&state, 0, sizeof(state));
    memset(&testState, 0, sizeof(testState));

    numPlayers = (rand() % 3) + 2;
    // initialize game state and player cards
    initializeRet = initializeGame(numPlayers, k, seed, &state);

    currentPlayer = state.whoseTurn;
    // randomly set deck count
    state.deckCount[currentPlayer] = rand() % 150;
    printf("Case 2 deck count value: %i\n", state.deckCount[currentPlayer]);

    memcpy(&testState, &state, sizeof(struct gameState));

    int case2HandCount = testState.handCount[currentPlayer];
    int case2NumBuys = testState.numBuys;
    if (currentPlayer == 0) {
        otherPlayer = 1;
    } else {
        otherPlayer = 0;
    }
    int case2OPHandCount = testState.handCount[otherPlayer];
    int case2Return = cardEffect(council_room, 0, 0, 0, &testState, 0, &bonus);
    if (case2Return >= 0) {
        printf("cardEffect() - council_room, case2: PASS good return value\n");
    } else {
        printf("cardEffect() - council_room, case2: FAIL return value indicates something went wrong\n");
    }
    //make sure current player gets 2 new cards
    if (testState.handCount[currentPlayer] == case2HandCount + 3) {
        printf("cardEffect() - council_room, case2: PASS three new cards in hand\n");
    } else {
        printf("cardEffect() - council_room, case2: FAIL three new cards not in hand\n");
    }
    //make sure new cards are treasure cards
    if (testState.numBuys == (case2NumBuys + 1)) {
        printf("cardEffect() - adventurer, case2: PASS incremented number of buys\n");
    } else {
        printf("cardEffect() - adventurer, case2: FAIL did not increment number of buys\n");
    }
    //make sure other player gets new card as well
    if (testState.handCount[otherPlayer] == case2OPHandCount + 1) {
        printf("cardEffect() - council_room, case2: PASS other player has new card in hand\n");
    } else {
        printf("cardEffect() - council_room, case2: FAIL other player does not have new card in hand\n");
    }

    

	return 0;
}



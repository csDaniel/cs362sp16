#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <limits.h>

const int RANDOM_MIN_DECK = 6;
const int RANDOM_MAX_DECK = MAX_DECK - 2;
const int RANDOM_MAX_HAND = 20;

struct randomDeck {
    int deck[MAX_DECK];
    int deckSize;
    int numInDeck;
};

void randomizeGame(void *pState) {
    char* write = pState;
    char* end = write + sizeof(struct gameState);
    for(; write < end; ++write){
        *write = (char) (CHAR_MAX * random());
    }
}

void startTurnForPlayer(struct gameState *pState, int player, struct randomDeck* deck){

    pState->deckCount[player] = 0;
    pState->discardCount[player] = 0;
    pState->handCount[player] = ((int) (Random() * RANDOM_MAX_HAND)) + 1;

    int i=0;
    for (;i < deck->numInDeck; ++i){
        pState->deck[player][pState->deckCount[player]++] = deck->deck[i];
    }
    for(;i < deck->deckSize; ++i){
        pState->discard[player][pState->discardCount[player]++] = deck->deck[i];
    }

    for(i=0; i<pState->handCount[player]; ++i){
        pState->hand[player][i] = (int) (Random() * treasure_map);
    }

    pState->whoseTurn = player;
    pState->phase = 0;
    pState->numActions = 1;
    pState->coins = 0;
    pState->numBuys = 1;
    pState->playedCardCount = 0;

    for(i=0;i<MAX_PLAYERS; ++i){
        pState->handCount[i] = 4;
    }

}

void getRandomDeck(struct randomDeck* deck){
    deck->deckSize = ((int) (Random() * (RANDOM_MAX_DECK - RANDOM_MIN_DECK + 1))) + RANDOM_MIN_DECK;

    int i = 0;
    for (;i<deck->deckSize;++i){
        //generate random number mapped to all available cards
        deck->deck[i] = (int) (Random() * treasure_map);  //first card after gold
    }

    // Half the time have between 0-3 cards in players deck to test edge cases
    // the other a random number
    int deckNumBias = (int) (Random() * 7);
    deck->numInDeck = (deckNumBias <= 3) ? deckNumBias : (int) (Random() * (deck->deckSize - 4)) + 4;

}

int main(int argc, char **argv) {

    // Testing for playSmithy function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Randomly Testing dominion.c int playSmithy()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_TESTS = 4000;
    int testsRun = 0;
    int testsPassed = 0;
    struct gameState G, before, after;
    int i;
    int curPlayer = 0;
    struct randomDeck testDeck;


    for (i=0; i< NUM_TESTS; ++i){

        getRandomDeck(&testDeck);
        randomizeGame(&G);
        curPlayer = (int) (Random() * MAX_PLAYERS);
        startTurnForPlayer(&G, curPlayer, &testDeck);

        G.hand[curPlayer][0] = smithy;

        copyGameState(&before,&G);
        printf("Playing smithy card player: %d  number of cards in players draw pile:%d testRound: %d\n",curPlayer, G.deckCount[curPlayer],i);
        playSmithy(&G,0);
        copyGameState(&after,&G);

        printf("current player has drawn 3 new cards ");
        if (G.handCount[curPlayer] - before.handCount[curPlayer] == 3){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        printf("Player still has the same set of cards in their hand/deck/discard combined");
        if (playerHasSameCards(&before, &G, curPlayer)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;

        int drawnCards = G.handCount[curPlayer] - before.handCount[curPlayer];
        if (testDeck.numInDeck >= drawnCards){
            int match = 1;
            int z = 0;
            for (;z<drawnCards;++z){
                match &= (G.hand[curPlayer][before.handCount[curPlayer] + z] == before.deck[curPlayer][before.deckCount[curPlayer] - 1 - z]);
            }
            printf("New cards in players hand are from top of their drawDeck");
            if (match){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
            }
            testsRun += 1;
        }

        //VERBOSE debuging of drawing
/*
        printf("%s","Before deck: {");
        int z;
        for (z=0; z < before.deckCount[curPlayer]; ++z){
            printf("%d,",before.deck[curPlayer][z]);
        }
        printf("%s","} hand: {");
        for (z=0; z < before.handCount[curPlayer]; ++z){
            printf("%d,",before.hand[curPlayer][z]);
        }
        printf("%s","}\nafter  deck: {");
        for (z=0; z < G.deckCount[curPlayer]; ++z){
            printf("%d,",G.deck[curPlayer][z]);
        }
        printf("%s","} hand: {");
        for (z=0; z < G.handCount[curPlayer]; ++z){
            printf("%d,",G.hand[curPlayer][z]);
        }
        printf("%s","}\n");
*/


        //rollback intentional changes to game state and check for any side-effects
        G.deckCount[curPlayer] = before.deckCount[curPlayer];
        G.handCount[curPlayer] = before.handCount[curPlayer];
        G.discardCount[curPlayer] = before.discardCount[curPlayer];
        G.playedCardCount = before.playedCardCount;
        cpyDeck(G.hand[curPlayer], before.hand[curPlayer], MAX_HAND);
        cpyDeck(G.discard[curPlayer], before.discard[curPlayer], MAX_DECK);
        cpyDeck(G.deck[curPlayer], before.deck[curPlayer], MAX_DECK);
        cpyDeck(G.playedCards, before.playedCards, MAX_DECK);
        printf("The rest of the gameState was unaffected ");
        if (equalGameStates(&before, &G)){
            testsPassed++;
            printf("(PASSED) \n");
        } else {
            printf("(FAILED) \n");
        }
        testsRun += 1;


    }


    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}

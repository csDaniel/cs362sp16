#include <stdio.h>
#include <stdlib.h>
#include "testUtilities.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>


const int RANDOM_MIN_DECK = 6;
const int RANDOM_MAX_DECK = MAX_DECK - 2;
const int RANDOM_MAX_HAND = 20;

struct randomDeck {
    int deck[MAX_DECK];
    int deckSize;
};

int isCoin(int card){
    return card == copper || card == silver || card == gold;
}

int numCoinsInPlayersDeckAndDiscard(struct gameState* state, int player ){
    int i =0;
    int coinCards = 0;
    for (;i<state->deckCount[player];++i){
        coinCards += isCoin(state->deck[player][i]);
    }
    for (i=0;i<state->discardCount[player];++i){
        coinCards += isCoin(state->discard[player][i]);
    }
    return coinCards;
}


void randomizeGame(void *pState) {
    char* write = pState;
    char* end = write + sizeof(struct gameState);
    for(; write < end; ++write){
        *write = (char) (CHAR_MAX * random());
    }
}

void startTurnForPlayer(struct gameState *pState, int player, int* deck, int arraySize, int numInDeck){

    pState->deckCount[player] = 0;
    pState->discardCount[player] = 0;
    pState->handCount[player] = ((int) (Random() * RANDOM_MAX_HAND)) + 1;

    int i=0;
    for (;i < numInDeck; ++i){
        pState->deck[player][pState->deckCount[player]++] = deck[i];
    }
    for(;i < arraySize; ++i){
        pState->discard[player][pState->discardCount[player]++] = deck[i];
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

}

void getRandomDeck(struct randomDeck* deck){
    deck->deckSize = ((int) (Random() * (RANDOM_MAX_DECK - RANDOM_MIN_DECK + 1))) + RANDOM_MIN_DECK;
    int numCoins;
    int numCoinsBias = (int) (Random() * 5);
    if (numCoinsBias < 2){
        //edge cases 1, or 2 coins available
        numCoins = numCoinsBias + 1;
    } else if (numCoinsBias < 4) {
        // random number of coins distributed in values greater than 2 and less than deckSize - 4
        numCoins = (int) (Random() * (deck->deckSize - 2)) + 2;
    } else {
        // deck full of coin cards
        numCoins = deck->deckSize;
    }

    int i = 0;
    for (;i<deck->deckSize - numCoins;++i){

        //generate random number mapped to all available cards except coins;
        int randomNumber = (int) (Random() * (treasure_map - 3));
        if (randomNumber < copper) deck->deck[i] = randomNumber;
        else deck->deck[i] = randomNumber + adventurer;  //first card after gold
    }

    //append coin cards at end of deck
    for (; i<deck->deckSize; ++i){
        deck->deck[i] = copper + (int) (Random() * 3);
    }

    int coinCoint = 0;
    for(i=0; i<deck->deckSize; ++i){
        coinCoint += isCoin(deck->deck[i]);
    }
    assert(coinCoint == numCoins);

    //Shuffle coins into deck
    for(i=deck->deckSize-1; deck->deckSize - i <= numCoins; --i){
        int newIndex = (int) (Random() * deck->deckSize);
        int temp = deck->deck[i];
        deck->deck[i] = deck->deck[newIndex];
        deck->deck[newIndex] = temp;
    }

    coinCoint = 0;
    for(i=0; i<deck->deckSize; ++i){
        coinCoint += isCoin(deck->deck[i]);
    }
    assert(coinCoint == numCoins);

}


int main(int argc, char **argv) {

    // Testing for playAdventurer function
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");
    printf("Randomly Testing dominion.c int playAdventurer()\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n");


    const int NUM_DECKS_TO_GENERATE = 20;


    int testsRun = 0;
    int testsPassed = 0;
    struct gameState G, before;
    int i,numInPlayersDeck;
    int curPlayer = 0;
    struct randomDeck testDeck;

    for (i=0; i<NUM_DECKS_TO_GENERATE; ++i){

        //randomize cards available to player
        getRandomDeck(&testDeck);

        //exhaustively test deck distributed between players deck and players discard
        for (numInPlayersDeck=0; numInPlayersDeck<testDeck.deckSize; numInPlayersDeck++) {
            randomizeGame(&G);
            curPlayer = (int) (Random() * MAX_PLAYERS);
            startTurnForPlayer(&G, curPlayer, testDeck.deck, testDeck.deckSize, numInPlayersDeck);
            curPlayer = G.whoseTurn;

            G.hand[curPlayer][G.handCount[curPlayer]++] = adventurer;
            copyGameState(&before,&G);
            printf("Random Adventurer test #:%d : %d    Coins Available in Player's Deck and Discard:%d\n",
                   i,numInPlayersDeck, numCoinsInPlayersDeckAndDiscard(&G, curPlayer));
            playAdventurer(&G, G.whoseTurn, G.handCount[curPlayer]-1);

            printf("Player's hand has 2 new coin cards ");
            if (G.handCount[curPlayer] == before.handCount[curPlayer]+1 &&
                isCoin(G.hand[curPlayer][G.handCount[curPlayer]-1]) &&
                isCoin(G.hand[curPlayer][G.handCount[curPlayer]-2])){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
                // Debuging the reason for failed tests
                // when 1 coin card was available in the players deck/discard the adventure function exited with only
                // one coin card in the players hand

               /* printf("FAILED:  {");
                int z = 0;
                for (;z<G.handCount[curPlayer]; ++z){
                    printf("%d,",G.hand[curPlayer][z]);
                }
                printf("%s","}   {");
                for (z=0;z<G.handCount[curPlayer]; ++z){
                    printf("%d,",isCoin(G.hand[curPlayer][z]));
                }
                printf("%s","} \n Deck: {");
                for (z=0;z<testDeck.deckSize; ++z){
                    printf("%d,",testDeck.deck[z]);
                }
                printf("%s","}   {");
                for (z=0;z<testDeck.deckSize; ++z){
                    printf("%d,",isCoin(testDeck.deck[z]));
                }
                printf("%s", "}\n");*/
            }
            testsRun += 1;

            printf("Player still has same card in deck/hand/discard ");
            if (playerHasSameCards(&G,&before,curPlayer)){
                testsPassed++;
                printf("(PASSED) \n");
            } else {
                printf("(FAILED) \n");
                // Debuging the reason for failed tests

/*                printf("FAILED sameCards:  \n");
                int z = 0;
                printf("COUNTS:\nbefore: {");

                getCardCounts(counts, &before, curPlayer, treasure_map);
                for (z=0; z<treasure_map; ++z) printf("%d,",counts[z]);
                printf("}\n after: {");
                getCardCounts(counts, &G, curPlayer, treasure_map);
                for (z=0; z<treasure_map; ++z) printf("%d,",counts[z]);
                printf( "}\n BEFORE:  hand: {");
                for (z=0; z< before.handCount[curPlayer]; ++z) printf("%d,", before.hand[curPlayer][z]);
                printf("}  deck: {");
                for (z=0; z< before.deckCount[curPlayer]; ++z) printf("%d,", before.deck[curPlayer][z]);
                printf("}  discard: {");
                for (z=0; z< before.discardCount[curPlayer]; ++z) printf("%d,", before.discard[curPlayer][z]);
                printf( "} \nAFTER:  hand: {");
                for (z=0; z< G.handCount[curPlayer]; ++z) printf("%d,", G.hand[curPlayer][z]);
                printf("}  deck: {");
                for (z=0; z< G.deckCount[curPlayer]; ++z) printf("%d,", G.deck[curPlayer][z]);
                printf("}  discard: {");
                for (z=0; z< G.discardCount[curPlayer]; ++z) printf("%d,", G.discard[curPlayer][z]);
                printf("}\n");*/

            }
            testsRun += 1;

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

    }

    printf("%d of %d tests passed\n",testsPassed, testsRun);

    return 0;
}



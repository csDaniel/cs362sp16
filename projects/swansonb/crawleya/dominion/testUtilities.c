#include "testUtilities.h"
#include <string.h>
#include "dominion.h"
#include <stdio.h>

void copyGameState(struct gameState* dest, struct gameState* src) {
    memcpy(dest, src, sizeof(*dest));
}

int equalGameStates(struct gameState* a, struct gameState* b) {
    return (memcmp(a,b,sizeof(*a)) == 0);
}

int cardArraysAreEqual(int *a, int aSize, int *b, int bSize){
    if (aSize != bSize) return 0;
    int counta[treasure_map+1];
    int countb[treasure_map+1];

    bzero(counta,sizeof(counta));
    bzero(countb,sizeof(countb));

    int i=0;
    for(;i<aSize; ++i){
        counta[a[i]]++;
        countb[b[i]]++;
    }

    for (i=0; i<treasure_map; ++i){
        if (counta[i] != countb[i]) return 0;
    }

    return 1;
}

int cardsCHaveBeenAddedtoAinB(int *a, int aSize, int *b, int bSize, int* c, int cSize){
    int countdiff[treasure_map+1];
    int countc[treasure_map+1];

    bzero(countdiff,sizeof(countdiff));
    bzero(countc,sizeof(countc));


    int i;
    for(i=0;i<aSize; ++i)countdiff[a[i]]--;
    for(i=0;i<bSize; ++i)countdiff[b[i]]++;
    for(i=0;i<cSize; ++i)countc[c[i]]++;



    for (i=0; i<treasure_map; ++i){
        if (countdiff[i] < countc[i]) return 0;
    }

    return 1;
}

// Checks if combination of Deck, Hand, Discard, played piles for one player are the same between game states
int playerHasSameCards(struct gameState* a, struct gameState* b, int player) {
    int counta[treasure_map+1];
    int countb[treasure_map+1];
    int i;

    getCardCounts(counta, a, player, treasure_map);
    getCardCounts(countb, b, player, treasure_map);

    for (i=0; i<treasure_map; ++i){
        if (counta[i] != countb[i]) return 0;
    }

    return 1;
}

void getCardCounts(int* count, struct gameState* g, int player, int numberOfCards){
    int i;

    for(i=0; i <numberOfCards; ++i) count[i] = 0;

    for (i=0; i < g->deckCount[player] || i < g->handCount[player] || i< g->discardCount[player] || i < g->playedCardCount; ++i){
        if (i< g->deckCount[player] && g->deck[player][i] >= 0 && g->deck[player][i] <= treasure_map)count[g->deck[player][i]]++;
        if (i< g->handCount[player] && g->hand[player][i] >= 0 && g->hand[player][i] <= treasure_map)count[g->hand[player][i]]++;
        if (i< g->discardCount[player] && g->discard[player][i] >= 0 && g->discard[player][i] <= treasure_map)count[g->discard[player][i]]++;
        if (i< g->playedCardCount && g->playedCards[i] >= 0 && g->playedCards[i] <= treasure_map) count[g->playedCards[i]]++;
    } 
}

void cpyDeck(int* dest, int* src, int n){
    int* end = src + n;
    for(;src<end; ++src, ++dest) *dest = *src;
}

/*************************************************************************************************************
 * Filename: randomtestadventurer.c
 * Author: Jens Bodal
 * Date: May 08, 2016
 * Description:  random testing of adventurer card
 *****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int drawSpecificCard(struct gameState *state, int player, int card);
int placeOnDeck(struct gameState *state, int player, int card);
void printCards(int *phand, int numCards, char *dtype);
char *getCardName(int card);
void printHand(struct gameState *state, int player);
int countCardInHand(struct gameState *state, int player, int card);
int countTreasureInHand(struct gameState *state, int targetPlayer);
void testAdventurer(struct gameState *state, int targetPlayer, int treasure1, int treasure2);
void checkPlayAdventurer(struct gameState *state, int targetPlayer);

int main() {
    int players;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int seed = 187;
    int trash = 1;
    int i;
    int NUM_TESTS = 10;
    struct gameState game;
    struct gameState *state = &game;

    printf("TESTING adventurer card\n");

    for (i = 0; i <= NUM_TESTS; i++) {
        // 2-4 players
        players = rand()%3 + 2;
        // random seed
        seed = rand();
        
        // clear game
        memset(state, 0, sizeof(struct gameState));

        // initialize game
        initializeGame(players, cards, seed, &game);

        // pick random player
        int targetPlayer = rand()%3;

        // pick random treasures
        int treasure1;
        treasure1 = rand()%3 + 1;
        if (treasure1 == 1) {
            treasure1 = copper;
        }
        else if (treasure1 == 2) {
            treasure1 = silver;
        }
        else {
            treasure1 = gold;
        }

        int treasure2;
        treasure2 = rand()%3 + 1;
        if (treasure2 == 1) {
            treasure2 = copper;
        }
        else if (treasure2 == 2) {
            treasure2 = silver;
        }
        else {
            treasure2 = gold;
        }

        // test adventurer with random treasures
        testAdventurer(state, targetPlayer, treasure1, treasure2);
        // add two treasure to deck, empty deck into discard pile, then check adventurer
        int discardIndex = state->discardCount[targetPlayer];
        state->discardCount[targetPlayer]+=state->deckCount[targetPlayer];
        int dCount = state->deckCount[targetPlayer];
        int j;
        for (j = 0; j < dCount; j++) {
            state->discard[targetPlayer][discardIndex] = state->deck[targetPlayer][j];
            state->deckCount[targetPlayer]--;
            discardIndex++;
        }
        checkPlayAdventurer(state, targetPlayer);
        // replace deck with non-treasure cards, play adventurer should just discard itself and not gain treasure
        // fill deck with smithy
        for (j = 0; j < state->deckCount[targetPlayer]; j++) {
            state->deck[targetPlayer][j] = smithy;
        }
    }    
    
    return 0;
}

// places specified card in deck then draws it
int drawSpecificCard(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    if (drawCard(player, state) == -1) {
        return -1;   
    }
    return pos; 
}

int placeOnDeck(struct gameState *state, int player, int card) {
    int i;
    int pos = state->deckCount[player]++;
    state->deck[player][pos] = card;
    return 1;
}

void printCards(int *pHand, int numCards, char *dtype) {
    int i;
    printf("Printing current %s:\n", dtype);
    for (i = 0; i < numCards; i++) {
        printf("  Pos [%d] Card [%d:%s]\n", i, pHand[i], getCardName(pHand[i]));
    }
    printf("  Cards in %s: %d\n\n", dtype, numCards);
}

void printHand(struct gameState *state, int player) {
    printCards(state->hand[player], state->handCount[player], "hand");
}

char *getCardName(int card) {
    switch(card) {
        case curse:
            return "curse";
        case estate:
            return "estate";
        case duchy:
            return "duchy";
        case province:
            return "province";
        case copper:
            return "copper";
        case silver:
            return "silver";
        case gold:
            return "gold";
        case adventurer:
            return "adventurer";
        case council_room:
            return "council_room";
        case feast:
            return "feast";
        case gardens:
            return "gardens";
        case mine:
            return "mine";
        case remodel:
            return "remodel";
        case smithy:
            return "smithy";
        case village:
            return "village";
        case baron:
            return "baron";
        case great_hall:
            return "great_hall";
        case minion:
            return "minion";
        case steward:
            return "steward";
        case tribute:
            return "tribute";
        case ambassador:
            return "ambassador";
        case cutpurse:
            return "cutpurse";
        case embargo:
            return "embargo";
        case outpost:
            return "outpost";
        case salvager:
            return "salvager";
        case sea_hag:
            return "sea_hag";
        case treasure_map:
            return "treasure_map";
        default:
            return "unknown";
    }
}

int countCardInHand(struct gameState *state, int player, int card) {
    int i;
    int count = 0;
    for (i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) count++;
    }
    return count;
}

int countTreasureInHand(struct gameState *state, int targetPlayer) {
    int treasureCount = 0;
    treasureCount += countCardInHand(state, targetPlayer, copper);
    treasureCount += countCardInHand(state, targetPlayer, silver);
    treasureCount += countCardInHand(state, targetPlayer, gold);
    return treasureCount;
}

void testAdventurer(struct gameState *state, int targetPlayer, int treasure1, int treasure2) {
    // put two copper on top so that when we play adventurer they should be drawn
    placeOnDeck(state, targetPlayer, treasure1);
    placeOnDeck(state, targetPlayer, treasure2);
    printf("Testing with treasures [%s] [%s]\n", getCardName(treasure1), getCardName(treasure2));
    // get card order and count before smithy
    checkPlayAdventurer(state, targetPlayer);

}

void checkPlayAdventurer(struct gameState *state, int targetPlayer) {
    int oldCount = state->handCount[targetPlayer];
    int oldPos[oldCount];
    memcpy(oldPos, state->hand[targetPlayer], oldCount * sizeof(int));
    // count treasure
    int treasureCount = countTreasureInHand(state, targetPlayer);
    // count adventurer 
    int adventCount = countCardInHand(state, targetPlayer, adventurer);
    // draw adventurer
    int adventurerPos = drawSpecificCard(state, targetPlayer, adventurer);
   
    // play adventurer from previously acquired position
    playAdventurer(targetPlayer, state);
    
    // check treasure count has increased by 2
    if (countTreasureInHand(state, targetPlayer) != treasureCount + 2) {
        printf("FAIL: [playAdventurer] [player: %d] We did not gain two treasure cards\n", targetPlayer);
    }
    else {
        printf("SUCCESS: [playAdventurer] [player: %d] Correct number of treasure cards gained\n", targetPlayer);
    }
    // check adventurer count is same before drawing adventurer and after playing him
    if (countCardInHand(state, targetPlayer, adventurer) != adventCount) {
        printf("FAIL: [playAdventurer] [player: %d] Adventurer card was not discarded\n", targetPlayer);
    }
    else {
        printf("SUCCESS: [playAdventurer] [player: %d] Adventurer card was discarded\n", targetPlayer);
    }
    // check hand is 2 bigger than before drawing adventurer and after playing him

}


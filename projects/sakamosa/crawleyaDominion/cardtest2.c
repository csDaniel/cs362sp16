#include "dominion.h" 
#include "dominion_helpers.h"  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//testing of getCost function

int main(){
    printf("*********************BEGIN UNIT TESTS OF ADVENTURER*********************\n\n");
//compare returned value to correct value for each card type
    struct gameState T;
    int i, total_cards;
    int beg_count, end_count = 0;
    int k[10] = {gardens, adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &T);
    T.hand[0][0] = adventurer;
    int playerCount = T.handCount[0];
    int opponentCount = T.handCount[1];
    int playerDiscard = T.discardCount[0];
    int opponentDiscard = T.discardCount[1];
    total_cards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];

    //count current treasure cards in hand
    for(i = 0; i < T.handCount[0]; i++){
        if(T.hand[0][i] == copper ||
            T.hand[0][i] == silver ||
            T.hand[0][i] == gold){
                beg_count ++;
        }
    }
    //Play the adventurer card for the Test state player 0, position 0
   // playAdventurer(&T, 0, 0);
    //refactor to match alisha's function
   cardEffect(adventurer, 0, 0, 0, &T, 0, 0);
   
    //check that two cards have added and one discarded
    if(T.handCount[0] != playerCount + 1){
        printf("FAIL incorrect number of cards in player hand\n");
        printf("Hand count = %d, was %d\n", T.handCount[0], playerCount);
    }

    //check that the treasure count has increased by 2
    for(i = 0; i < T.handCount[0]; i++){
        if(T.hand[0][i] == copper ||
            T.hand[0][i] == silver ||
            T.hand[0][i] == gold){
                end_count ++;
        }
    }
    if(end_count != beg_count + 2){
        printf("FAIL two treasure cards were not added to hand\n");
        printf("Beginning count = %d, end count is = %d\n", beg_count, end_count);
    }
    
    //check that the card was added to discard pile
    if(T.discardCount[0] != playerDiscard + 1){
        printf("FAIL incorrect number of cards in player discard pile\n");
        printf("Beginning count = %d, end count is = %d\n", playerDiscard, T.discardCount[0]);
    }
    
    //check that no cards were thrown away
    if(total_cards != T.handCount[0] + T.deckCount[0] + T.discardCount[0]){
        int curcards = T.handCount[0] + T.deckCount[0] + T.discardCount[0];
        printf("FAIL total player cards is incorrect\n");
        printf("Start count = %d, end count is = %d\n", total_cards, curcards);
    }
    
    //check that nothing else has changed
    if(T.handCount[1] != opponentCount){
        printf("FAIL incorrect number of cards in opponent's hand\n");
    }
    
    if(T.discardCount[1] != opponentDiscard){
        printf("FAIL incorrect number of cards in player discard pile\n");
    }
   

    printf("**********************TESTS COMPLETE*************************\n\n");
    return 0;

}


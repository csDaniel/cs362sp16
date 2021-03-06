/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great_hall"

int main() {
    int numPlayers = 2;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int handpos = 0, bonus = 0;
    int thisPlayer = 0, otherPlayer = 1;
    int shuffledCards = 0;
    int seed = 1000;
    int newCards = 1;
    int discarded = 1;
    int errors = 0;
    int recievedResult, expected;
    struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
    
    // initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
    //insert a smithy card in players hand for testing
    G.hand[thisPlayer][0] = great_hall; 
    
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    
    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
 //   printf("BEFORE---Player %d hand count = %d, expected = %d\n", thisPlayer, testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    //call cardEffect
    cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
    
    //test to make sure play is recieving 1 card
    //the player should draw 1 card and discard the great hall card
    //this should make the hand the same count
    recievedResult = testG.handCount[thisPlayer];
    expected = G.handCount[thisPlayer] + newCards - discarded;
 //   printf("Player %d hand count = %d, expected = %d\n", thisPlayer, recievedResult, expected);
    if(recievedResult != expected){
        //check if hand is correct
            printf("****FAIL Returned Hand Count = %d, expected = %d\n", recievedResult, expected); 
            errors++;
    }
    
    //test to make sure player is drawing from their own pile
 //   printf("Player %d deck count = %d, expected = %d\n", thisPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    if(testG.deckCount[thisPlayer] != G.deckCount[thisPlayer] - newCards + shuffledCards){
        //check if deck is correct
            printf("****FAIL Returned Deck Count for Player %d = %d, expected = %d\n", thisPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards); 
            errors++;
    }
    
    //test for players number of actions
    //the player shoud have 2 action moves
 //   printf("Player %d action count = %d, expected = %d\n", thisPlayer, testG.numActions, G.numActions+1);
    if(testG.numActions != G.numActions+1){
        //check if deck is correct
            printf("****FAIL Returned Action Count for Player %d = %d, expected = %d\n", thisPlayer, testG.numActions, G.numActions+1); 
            errors++;
    }
    
    //test to make sure other players game state has not changed
    
    //test to make sure other players hand is not changed
    recievedResult = testG.handCount[otherPlayer];
    expected = G.handCount[otherPlayer];
 //   printf("Player %d hand count = %d, expected = %d\n", otherPlayer, recievedResult, expected);
    if(recievedResult != expected){
        //check if hand is correct
            printf("****FAIL Returned Hand Count for Player %d = %d, expected = %d\n", otherPlayer, recievedResult, expected); 
            errors++;
    }
    
    //test to make sure other player deck is same and first player did not draw
    //from other players pile
 //   printf("Player %d deck count = %d, expected = %d\n", otherPlayer, testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
    if(testG.deckCount[otherPlayer] != G.deckCount[otherPlayer]){
        //check if deck is correct
            printf("****FAIL Returned Deck Count for Player %d = %d, expected = %d\n", otherPlayer, testG.deckCount[thisPlayer], G.deckCount[thisPlayer]); 
            errors++;
    }
    
    //test to make sure victory card piles where untouched.
    //check curse
    if(testG.supplyCount[curse] != G.supplyCount[curse]){
         printf("****FAIL Curse Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[curse], G.supplyCount[curse]); 
            errors++;
    }
    //check estate
    if(testG.supplyCount[estate] != G.supplyCount[estate]){
         printf("****FAIL Estate Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[estate], G.supplyCount[estate]); 
            errors++;
    }
    //check duchy
    if(testG.supplyCount[duchy] != G.supplyCount[duchy]){
         printf("****FAIL Duchy Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[duchy], G.supplyCount[duchy]); 
            errors++;
    }
    //check province
    if(testG.supplyCount[province] != G.supplyCount[province]){
         printf("****FAIL Province Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[province], G.supplyCount[province]); 
            errors++;
    }
    
    //test to make sure the kingdom cards count have not been altered
    int i;
    for(i=0; i < 10; i++){
        if(testG.supplyCount[k[i]] != G.supplyCount[k[i]]){
         printf("****FAIL Count for Player %d = %d, expected = %d\n", thisPlayer, testG.supplyCount[k[i]], G.supplyCount[k[i]]); 
            errors++;
         printf("%d is incorrect\n", k[i]);    
        }
    }
    
    
    
    
    
    
    
    
    if(errors == 0){
     printf("ALL TESTS PASS for great hall card.\n");   
    }
    else{
     printf("FAIL: There are %d errors for playing great hall card.\n", errors);   
    }
    
    
    
    
    
    
    
    
 return 0;
}
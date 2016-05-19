#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/**************************************
Random test for smithy card
***************************************/

//global variables
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};   //kingdom cards


int randNum(int low, int high) {
    return rand() % (high - low + 1) + low;
}



int main(int argc, char** argv){
    srand(time(NULL));
    int numTests = 100;         //number of random tests to run

    for(int i = 0; i < numTests; i++){

    	int p1 = 0;	
    	int numPlayers = randNum(2, 4);
    	struct gameState game;		//starting game state
    	struct gameState testGame;		//testing game state
        int result;		//test result
        int randomSeed = randNum(5, 1000);  //random number to initialize game

        printf("Testing smithy card \n");

        //set up game states
        initializeGame(numPlayers, k, randomSeed, &game);
        memcpy(&testGame, &game, sizeof(struct gameState));

        testGame.whoseTurn = p1;    //set current player to player 1
        result = cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);

        //test if hand count +=2 (three cards added, smithy card discarded)
        printf("Test: Three cards added to hand\n");
        if(testGame.handCount[p1] == game.handCount[p1]+2){
            printf("PASSED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
        } else{
            printf("FAILED. Returned %d   Expected %d\n", testGame.handCount[p1], game.handCount[p1]+2);
        }

        //test that card taken from p1's deck
        printf("Test: cards drawn from current player's deck\n");
        if(testGame.deckCount[p1] < game.deckCount[p1]){
            printf("PASSED. Returned %d   Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]-3);
        } else{
            printf("FAILED. Returned %d   Expected %d\n", testGame.deckCount[p1], game.deckCount[p1]-3);
        }

        
        //test that victory card piles remained the same
        printf("Test if victory card piles changed\n");
        if(testGame.supplyCount[estate] != game.supplyCount[estate]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[estate], game.supplyCount[estate]);
        }
        if(testGame.supplyCount[duchy] != game.supplyCount[duchy]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[duchy], game.supplyCount[duchy]);
        }
        if(testGame.supplyCount[province] != game.supplyCount[province]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[province], game.supplyCount[province]);
        }
        if(testGame.supplyCount[curse] != game.supplyCount[curse]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[curse], game.supplyCount[curse]);
        }
        else{
            printf("PASSED. Victory card count unchanged.\n");
        }
        
        //test that coin piles remained same
            printf("Test if coin card piles changed\n");
        if(testGame.supplyCount[copper] != game.supplyCount[copper]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[copper], game.supplyCount[copper]);
        }
        if(testGame.supplyCount[silver] != game.supplyCount[silver]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[silver], game.supplyCount[silver]);
        }
        if(testGame.supplyCount[gold] != game.supplyCount[gold]){
            printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[gold], game.supplyCount[gold]);
        }
        else{
            printf("PASSED. Coin card count unchanged.\n");
        }
        
        //test if kingdom cards remain unchanged
        printf("Test if kingdom card piles changed\n");
        int passed = 1;     //bool to keep track of failed tests
        for(int i = 0; i < 10; i++){
            if(testGame.supplyCount[k[i]] != game.supplyCount[k[i]]){
                printf("FAILED. Returned %d   Expected %d\n", testGame.supplyCount[k[i]], game.supplyCount[k[i]]);
                passed = 0;
            }
        }
        if(passed)
            printf("PASSED. Kingdom card count unchanged.\n");

    }   

	return 0;
}
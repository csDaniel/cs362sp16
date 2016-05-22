/*
James Guerra
random smithy card test for assignment 4

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>  
#include <assert.h>
#include "rngs.h"
#include <time.h>
  
//helper function for random.  
int randInt(int min, int max);

int main(){
	time_t sysClock;
	srand((unsigned) time(&sysClock));
	struct gameState G;
	int numPlayer, seed, r, handCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, salvager, great_hall};
			   
			   
	int maxHandCount = 5;
    int pass =0;		   
	int p = 0;
	
	printf("Now testing, random test for Smithy card\n");  
	 numPlayer = randInt(2,4);
	 seed = randInt(500, 1500);
	 r = initializeGame(numPlayer, k, seed, &G);
	
	handCount = randInt(0,4);
	
	G.handCount[p] = handCount;                 // set the number of cards on hand
                gainCard(smithy, &G, 2, p);
				handCount++;
                cardEffect(smithy, 0, 0, 0, &G, G.hand[p][0], 0);

                printf("G.handCount = %d, expected = %d\n", G.handCount[p], handCount + 2); //smithy card should draw three and discard 1

                if(G.handCount[p] == handCount + 2){ // check if the number of cards is correct
					printf("Test 1 passed, expected card number in hand \n");                
				}
				else{
					pass = 1;
					printf("Test 1 failed, expected card number not found in hand \n");
				}
				//check player 2 hand
				if(G.handCount[p+1] == 0){ // check if the number of cards is correct
					printf("Test 2 passed, expected card number in hand player 2 \n");                
				}
				else{
					pass = 1;
					printf("Test 2 failed, expected card number not found in hand player 2\n");
				}
       if(pass == 0){
    printf("All tests passed!\n");
	   }
	
	
	
	return 0;
}

int randInt(int min, int max)
{   
    return rand() % (max - min + 1) + min;
}
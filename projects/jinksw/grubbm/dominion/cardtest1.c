/* -----------------------------------------------------------------------
		Unit Testing for smithy card 
		**Used StewardTest.c template for reference

		___ Smithy ___
			Basic Requirements:
				1. Current Player Should Recieve Exactly 3 Cards
				2. 3 cards should come from player's own pile
				3. No State change should occur for other players
				4. No State change should occur in victory or kingdom piles
				
int playSmithyCard(struct gameState* state, int handPos) {	
  int currentPlayer = whoseTurn(state);
	//+3 Cards
  for ( int i = 0; i <= 3; i++)
	{
		gainCard( i, state, 0, currentPlayer );
	}
			
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 1);
	return 0;
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
    int newCards = 0;
		int discarded = 1;
    int shuffledCards = 0;
		int xtraCoins = 0;
		int actions = 1;
		int buys = 0;
		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int i, m;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
		int failFlag = 0;
		int passCount = 0;
		int tests = 4;
	
		struct gameState G, testG;
		int k[10] = {smithy, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, adventurer, council_room};
		int kTest[10];
		memcpy(kTest, k, sizeof(k));

	// initialize a game state and player cards
	initializeGame(numPlayers, kTest, seed, &G);

	printf("\n----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Current Player Recieves 3 Cards, Discards 1( --------------
	printf("\n\n*****TEST 1: Current Player Recieves 3 Cards*****\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 3;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	//Is the discard count what we expect?
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer],  discarded);	
	if( !(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) ){
		printf( "\n---Test 1 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) ){
		printf( "\n---Test 1 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.discardCount[thisPlayer] == discarded) ){
		printf( "\n---Test 1 Failed: Player discard count different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "Test 1 Passed" );
		passCount++;
	}
	
	

	// ----------- TEST 2: Testing that the other player's state doesn't change --------------
	printf("\n\n*****TEST 2: Player 2 state doesn't change when Player 1 plays Smithy*****\n");
	failFlag = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	newCards = 0;
	discarded = 0;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	//We don't need to run the coin, action, or buys for this because those are reset each turn for players.
	if( testG.handCount[otherPlayer] != G.handCount[otherPlayer] ){
		printf( "\n--Test 2 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( testG.deckCount[otherPlayer] != G.deckCount[otherPlayer] ){
		printf( "\n--Test 2 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "Test 2 Passed\n" );
		passCount++;
	} 
	

	// ----------- TEST 3: Smithy is discarded from hand--------------
	failFlag = 0;
	printf("\n\nTEST 3: Smithy is successfully discarded, Other Cards are kept\n\n");

	int offset;
	// Cycle through each  possible Smithy hand position
	for (i=0; i<G.handCount[thisPlayer]; i++) {
			offset = 1;
			handpos = i;
			//Smithy Position for each iteration
			G.hand[thisPlayer][i] = smithy;			 // 0 1 2 3 4 

			//Other cards position for each iteration. Managed by i and offset
			// card position on each iteration = 1, 2, 3, 4, 0
			if ( (i + offset) <= 4 ){
					G.hand[thisPlayer][i+offset] = copper;	 
			} else {
				G.hand[thisPlayer][0] = copper;						 
			}

			offset++; //offset = 2
			// card position on each iteration = 2, 3, 4, 0 1
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i + offset] = duchy;			
			} else {
				G.hand[thisPlayer][i-1-offset] = duchy;			
			}
			
			offset++; //offset = 3
			// card position on each iteration = 3, 4, 0, 1, 2
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i + offset] = estate;					 
			} else {
				G.hand[thisPlayer][i+1-offset] = estate;					 
			}

			offset++; //offset = 4;
			// card position on each iteration =  4, 0, 1, 2, 3
			if ( (i + offset) <= 4 ){
				G.hand[thisPlayer][i+offset] = feast;		
			} else {
				G.hand[thisPlayer][i+3-offset] = feast;		
			}			 

			// copy the game state to a test case
			memcpy(&testG, &G, sizeof(struct gameState));

			printf("Cards in Hand Before Playing Smithy: ");
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf("\n ");

			cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

			printf("ending cards: ");
			// tests that Smithy is no longer in the player's hand
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf(", expected cards: ");
			for (m=0; m < G.handCount[thisPlayer]; m++) {
				if ( m <G.handCount[thisPlayer] ){
					if ( m != i  ) {
						printf("(%d)", G.hand[thisPlayer][m]);
					} else {
						printf( "(Last drawn card)" );
					}
				}
			}
			printf("(drawn Card),(drawn Card)\n");

			for (m=0; m<G.handCount[thisPlayer]; m++) {
				if( m==i ){
					if( G.hand[thisPlayer][m] == testG.hand[thisPlayer][m] ){
						printf( "\n--Test 3 Failed: Smithy remained in same position in hand for iteration # %d, where Smith was in starting position: %d.\n", i+1, i );
						failFlag = 1;
					} else if ( testG.hand[thisPlayer][m] == smithy ){
						printf( "\n--Test 3 Failed: Smithy remained in hand for iteration # %d, but moved to position %d, where Smith was in starting position: %d.\n", i+1, m, i );
						failFlag = 1;
					} else {
						passCount++;
						printf( "\nTest 3 Passed" );
					}
				}
			}
	}
	

	// ----------- TEST 4: Coin, Action, Buy, Kingdom, Victory states don't change ---------
	failFlag = 0;
	handpos = 0;
	printf("\n\n*****TEST 4: Coin, Action, Buy, Kingdom, Victory states don't change****\n\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions - actions);
	printf("numBuys = %d, expected = %d\n", testG.numBuys, G.numBuys - buys);
	printf("Estate cards = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
	printf("Duchy cards = %d, expected = %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
	printf("Province cards = %d, expected = %d\n", testG.supplyCount[province], G.supplyCount[province]);
	printf("Player turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn );
	printf("Kingdom cards = ");
	for( i=0; i< 10; i++ ){ 
	printf( "Post\n" );
		printf( "(Card in test:%d, Count= %d)", kTest[i], testG.supplyCount[i] );
	}
	printf(", expected = ");
	for( i=0; i< 10; i++ ){
		printf( "(Expected card: %d, count to equal: %d)", k[i], G.supplyCount[i] );
	}
	
	//Tests
	if( !(testG.coins == G.coins + xtraCoins) ){
		printf( "--Test 4 Failed: Player coins different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numActions == G.numActions - actions) ){
		printf( "--Test 4 Failed: Player action count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numBuys == G.numBuys - buys) ){
		printf( "--Test 4 Failed: Player buy count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[estate] == G.supplyCount[estate] ) ){
		printf( "--Test 4 Failed: Estate Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[duchy] == G.supplyCount[duchy] ) ){
		printf( "--Test 4 Failed: Duchy Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[province] == G.supplyCount[province] ) ){
		printf( "--Test 4 Failed: Province Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.whoseTurn == G.whoseTurn ) ){
		printf( "--Test 4 Failed: Whose Turn Changed\n" );
		failFlag = 1;
	}
	for( i=0; i< 10; i++ ){
		if( !( kTest[i] == k[i] ) ){
			printf( "--Test 4 Failed:Kingdom card %d changed to enum %d \n", k[i], kTest[i] );
			failFlag = 1;
		}
		if( !( testG.supplyCount[i] == G.supplyCount[i] ) ){
			printf( "--Test 4 Failed:Supply count %d for card %d changed to %d \n", G.supplyCount[i], k[i], testG.supplyCount[i] );
			failFlag = 1;
		}

	}

	if( failFlag == 0 ){
		passCount++;
		printf( "Test 4 Passed" );
	}

	printf("\n >>>>> SUCCESS: Testing complete %s, %d tests failed, %d tests passed. <<<<<\n\n", TESTCARD, tests-passCount, passCount);


	return 0;
}


/* -----------------------------------------------------------------------
		Unit Testing for Adventurer card 
		**Used testUpdateCoins.c template for r

		___ Adventurer ___
			Basic Requirements:
				1. Player should draw cards until they recieve 2 treasure cards
				2. cards drawn should come from player's own pile
				3. Player's discard pile should be shuffled if empty before 2 treasure cards are drawn
					and player should continue drawing after the shuffle until they reach 2 treasure cards
				4. All non treasure cards should be discarded 
				5. No State change should occur for other players
				6. No State change should occur in victory or kingdom piles
				
 * -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTCARD "adventurer"

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
		int tE = 0, tA = 0; //treasureExpected, treasureActual
	
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int kTest[10];
		memcpy( kTest, k, sizeof(k));		

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("\n\n\n----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Hand Count, Deck Count, and Discard Count ------------- 
	printf("\n\n*****TEST 1: Hand Count = 6, Deck Count = Expected, Discard Count = Expected \n");
	G.deck[thisPlayer][0] = copper;
	G.deck[thisPlayer][1] = silver;
	G.deck[thisPlayer][2] = gold;

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 2;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	//Is the discard count what we expect?
	printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer],  discarded);	
	if( !(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) ){
		printf( "\n----Test 1 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) ){
		printf( "\n----Test 1 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.discardCount[thisPlayer] == discarded) ){
		printf( "\n----Test 1 Failed: Player discard count different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 1 Passed" );
		passCount++;
	}
	
	
	// ----------- TEST 2: Testing that the other player's state doesn't change --------------
	printf("\n\n****TEST 2: Player 2 state doesn't change when Player 1 plays Adventurer\n");
	failFlag = 0;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	newCards = 0;
	discarded = 0;
	//Is the handcount what we expect?
	printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer] + newCards - discarded);
	//Is the deck count what we expect?	
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer] - newCards + shuffledCards);
	//Is the discard count what we expect?
	printf("discard count = %d, expected = %d\n", testG.discardCount[otherPlayer],  discarded);	
	//We don't need to run the coin, action, or buys for this because those are reset each turn for players.
	if( testG.handCount[otherPlayer] != G.handCount[otherPlayer] ){
		printf( "\n---Test 2 Failed: Player handcount different than expected\n" );
		failFlag = 1;
	}
	if( testG.deckCount[otherPlayer] != G.deckCount[otherPlayer] ){
		printf( "\n---Test 2 Failed: Player deckcount different than expected\n" );
		failFlag = 1;
	}
	if( testG.discardCount[otherPlayer] != discarded ){
		printf( "\n---Test 2 Failed: Player discard count different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 2 Passed\n" );
		passCount++;
	} 
	

	// ----------- TEST 3: Adventurer is discarded from hand--------------
	failFlag = 0;
	printf("\n\n****TEST 3: Adventurer is successfully discarded, Other Cards are kept\n");

	int offset;
	// Cycle through each  possible Smithy hand position
	for (i=0; i<G.handCount[thisPlayer]; i++) {
			offset = 1;
			handpos = i;
			//Smithy Position for each iteration
			G.hand[thisPlayer][i] = adventurer;			 // 0 1 2 3 4 

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

			printf("\nCards in Hand Before Playing Adventurer: ");
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf("\n ");

			cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

			printf("\nending cards: ");
			// tests that card played is no longer in the player's hand
			for (m=0; m<testG.handCount[thisPlayer]; m++) {
				printf("(%d)", testG.hand[thisPlayer][m]);
			}
			printf(", expected cards: ");
			for (m=0; m<G.handCount[thisPlayer]; m++) {
				if ( m <G.handCount[thisPlayer] ){
					if ( m != i  ) {
						printf("(%d)", G.hand[thisPlayer][m]);
					} else {
						printf( "(Last drawn card)" );
					}
				}
			}
			printf("\n(drawn Card),(drawn Card)\n");

			for (m=0; m<G.handCount[thisPlayer]; m++) {
				if( m==i ){
					if( G.hand[thisPlayer][m] == testG.hand[thisPlayer][m] ){
						printf( "\n---Test 3 Failed: Adventurer remained in same position in hand for iteration # %d, where Adventurer was in starting position: %d.\n", i+1, i );
						failFlag = 1;
					} else if ( testG.hand[thisPlayer][m] == smithy ){
						printf( "\n---Test 3 Failed: Adventurer remained in hand for iteration # %d, but moved to position %d, where Adventurer was in starting position: %d.\n", i+1, m, i );
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
	printf("\n\n****TEST 4: Coin, Action, Buy, Kingdom, Victory states don't change\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions - actions);
	printf("numBuys = %d, expected = %d\n", testG.numBuys, G.numBuys - buys);
	printf("Estate cards = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
	printf("Duchy cards = %d, expected = %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
	printf("Province cards = %d, expected = %d\n", testG.supplyCount[province], G.supplyCount[province]);
	printf("Player turn = %d, expected = %d\n", testG.whoseTurn, G.whoseTurn );
	printf("Kingdom cards = ");
	for( i=0; i< 10; i++ ){ 
		printf( "\n Card #: %d, Card Count = %d", kTest[i], testG.supplyCount[i] );
		printf("\n *Expected: ");
		printf( "\n Card #: %d, Card Count = %d\n", k[i], G.supplyCount[i] );
	}
	
	//Tests
	if( !(testG.coins == G.coins + xtraCoins) ){
		printf( "\n---Test 4 Failed: Player coins different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numActions == G.numActions - actions) ){
		printf( "\n---Test 4 Failed: Player action count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.numBuys == G.numBuys - buys) ){
		printf( "\n---Test 4 Failed: Player buy count different than expected\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[estate] == G.supplyCount[estate] ) ){
		printf( "\n---Test 4 Failed: Estate Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[duchy] == G.supplyCount[duchy] ) ){
		printf( "\n---Test 4 Failed: Duchy Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.supplyCount[province] == G.supplyCount[province] ) ){
		printf( "\n---Test 4 Failed: Province Count Changed\n" );
		failFlag = 1;
	}
	if( !(testG.whoseTurn == G.whoseTurn ) ){
		printf( "\n---Test 4 Failed: Whose Turn Changed\n" );
		failFlag = 1;
	}
	for( i=0; i< 10; i++ ){
		if( !( kTest[i] == k[i] ) ){
			printf( "\n---Test 4 Failed:Kingdom card %d changed to enum # %d \n", k[i], kTest[i] );
			failFlag = 1;
		}
		if( !( testG.supplyCount[i] == G.supplyCount[i] ) ){
			printf( "\n---Test 4 Failed:Kingdom card count %d for %d changed to %d \n", G.supplyCount[i], k[i], testG.supplyCount[i] );
			failFlag = 1;
		}

	}

	if( failFlag == 0 ){
		passCount++;
		printf( "\nTest 4 Passed" );
	}

	// ----------- TEST 5: 2 Treasure Cards are Drawn, no reshuffling needed, no discarding of drawn cards needed ---------- 
	failFlag = 0;
	printf("\n\n******TEST 5: 2 Treasure Cards are drawn. Case 1: No reshuffling needed, no discarding of drawn cards needed. \n");
	G.deck[thisPlayer][0] = copper;
	G.deck[thisPlayer][1] = silver;
	G.deck[thisPlayer][2] = gold;
	tE = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	for (i=0; i<G.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tE++;
		}
	} 

	for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tA++;
		}
	}

	printf( "treasure cards in hand: %d, expected = %d\n", tA, tE );
	if( !(tE == tA) ){
		printf( "\n---Test 5 Failed: Player treasure cards different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 5 Passed" );
		passCount++;
	}
	
// ----------- TEST 6: 2 Treasure Cards are Drawn,  reshuffling needed, no discarding of drawn cards needed ---------- 
	failFlag = 0;
	printf("\n\n*****TEST 5: 2 Treasure Cards are drawn. Case 2: No Reshuffling needed, Discarding of drawn cards needed. \n");
	G.deck[thisPlayer][0] = smithy;
	G.deck[thisPlayer][1] = village;
	G.deck[thisPlayer][2] = mine;
	G.deck[thisPlayer][3] = copper;
	G.deck[thisPlayer][4] = silver;
	G.deck[thisPlayer][5] = gold;
	G.deck[thisPlayer][6] = minion;
	
	tE = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	for (i=0; i<G.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tE++;
		}
	} 

	for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tA++;
		}
	}

	printf( "treasure cards in hand: %d, expected = %d\n", tA, tE );
	if( !(tE == tA) ){
		printf( "\n---Test 6 Failed: Player treasure cards different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 6 Passed" );
		passCount++;
	}
	
	// ----------- TEST 7: 2 Treasure Cards are Drawn,  reshuffling needed, no discarding of drawn cards needed ---------- 
	failFlag = 0;
	printf("\n\n*****TEST 7: 2 Treasure Cards are drawn. Case 3: Reshuffling needed, no discarding of drawn cards needed. \n");
	for( i=0; i<10; i++ ){
		G.deck[thisPlayer][i] = -1;
		G.discard[thisPlayer][i] = copper;
	}
	G.deckCount[thisPlayer] = 0;

	tE = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	for (i=0; i<G.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tE++;
		}
	} 

	for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tA++;
		}
	}

	printf( "treasure cards in hand: %d, expected = %d\n", tA, tE );
	if( !(tE == tA) ){
		printf( "\n---Test 7 Failed: Player treasure cards different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 7 Passed" );
		passCount++;
	}
	
	// ----------- TEST 8: 2 Treasure Cards are Drawn,  reshuffling needed, no discarding of drawn cards needed ---------- 
	failFlag = 0;
	printf("\n\n******TEST 8: 2 Treasure Cards are drawn. Case 3: Reshuffling needed,  discarding of drawn cards needed. \n");
	
	G.deck[thisPlayer][0] = smithy;
	G.deck[thisPlayer][1] = village;
	G.deck[thisPlayer][2] = mine;
	for( i=3; i<10; i++ ){
		G.deck[thisPlayer][i] = -1;
		G.discard[thisPlayer][i] = copper;
	}
	G.deckCount[thisPlayer] = 0;

	tE = 2;
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	for (i=0; i<G.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tE++;
		}
	} 

	for (i=0; i<testG.handCount[thisPlayer]; i++) {
		if ( G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold ){
			tA++;
		}
	}

	printf( "treasure cards in hand: %d, expected = %d\n", tA, tE );
	if( !(tE == tA) ){
		printf( "\n---Test 7 Failed: Player treasure cards different than expected\n" );
		failFlag = 1;
	}
	if( failFlag == 0 ){
		printf( "\nTest 7 Passed" );
		passCount++;
	}
	


	printf("\n >>>>> SUCCESS: Testing complete %s, %d tests failed, %d tests passed. <<<<<\n\n", TESTCARD, tests-passCount, passCount);
	


	printf("\n >>>>> SUCCESS: Testing complete %s, %d tests failed, %d tests passed. <<<<<\n\n", TESTCARD, tests-passCount, passCount);


	return 0;
}


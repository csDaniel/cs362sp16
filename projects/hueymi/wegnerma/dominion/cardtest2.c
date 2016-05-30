/*
 * cardtest2.c
 * tests card Embargo
 
 */



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testEmbargo() {
	
	char* UNITTEST = "Embargo";
    int i;
	int provinceCount = 12;
	int estateCount = 12;
	int duchyCount = 12;
	int kingdomCount = 10;
	int copperCount = 39;
	int silverCount = 40;
	int goldCount = 30;
    int seed = 1000;
    int numPlayers = 3;
    int thisPlayer = 0;
	int prevPlayer = 0;
	int trashedCard = 0;
	int playSuccess = 1;
	int coinVal = 1;
	int cardVal = 0;
	int fullDeckResult = 0;
	int prevDeckResult = 0;
	int choice1 = 1, choice2 = 0, choice3 = 0, handPos = 0, bonus = 0;
	struct gameState G, testG, realG;
	int k[10] = {adventurer, embargo, village, ambassador, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int prevHandCount[3];
	int prevDiscardCount[3];
	int prevDeckCount[3];

	// Initialize the game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	G.hand[thisPlayer][0] = embargo;
	G.hand[thisPlayer][1] = estate;
	G.hand[thisPlayer][2] = smithy;
	G.hand[thisPlayer][3] = copper;
	G.hand[thisPlayer][4] = village;
	
	printf("\n\n----------------- Testing of Card: %s ----------------\n", UNITTEST);

	
	/****************************************************
	Test 1: First player places embargo on estate, and next player tries to buy it
	****************************************************/
	printf("\nTEST 1: First player places embargo on estate, and next player tries to buy it \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Show the previous hand
	printf("hand before playing  = ");
	for (i = 0; i < testG.handCount[thisPlayer]; i++) {
		printf(" (%d)",  testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	// Calculate the coin value of the hand
	coinVal = testG.coins;
	
	// Play the embargo card on estate
	choice1 = estate;
	cardVal = getCost(estate);
	playSuccess = cardEffect(embargo, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// The play should have been successful
	printf("successful play = %d, expected = %d\n", playSuccess, 0);
	if (playSuccess != 0){
	printf("********** ERROR: unsuccessful play **********\n");
	}
	
	// The number of coins in the player's hand should be coinVal + 2
	printf("coins = %d, expected = %d\n", testG.coins, coinVal + 2);
	if (testG.coins != coinVal + 2){
		printf("********** ERROR: coins mismatch **********\n");
	}
	
	// Show the next hand
	printf("hand after playing  = ");
	for (i = 0; i < testG.handCount[thisPlayer]; i++) {
		printf(" (%d)",  testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");
	
	// The total number of cards added to the player's hand should be 1 less
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer]-1);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer]-1)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 0
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 0);
	if (testG.playedCardCount != 0)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The total number of cards in the player's deck should be the same
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer]);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer])
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch**********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch**********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch**********\n", i);
		}
	}
	
	// The first card should be the one traded for (it should be the last card in the hand)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], G.hand[thisPlayer][4]);
	if (testG.hand[thisPlayer][0] != G.hand[thisPlayer][4])
		printf("********** ERROR: first card mismatch**********\n");
	
	// There will be 12 province, estate, and duchy cards originally, minus the card traded for
	printf("province cards = %d, expected = %d\n", testG.supplyCount[province], provinceCount);
	if (testG.supplyCount[province] != provinceCount)
		printf("********** ERROR: province card mismatch**********\n");
	
	printf("estate cards = %d, expected = %d\n", testG.supplyCount[estate], estateCount);
	if (testG.supplyCount[estate] != estateCount)
		printf("********** ERROR: estate card mismatch**********\n");
	
	printf("duchy cards = %d, expected = %d\n", testG.supplyCount[duchy], duchyCount);
	if (testG.supplyCount[duchy] != duchyCount)
		printf("********** ERROR: duchy card mismatch**********\n");
	
	// There will be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// There should be 39 coppers, 40 silvers, and 30 gold, minus the card traded for
	printf("copper cards = %d, expected = %d\n", testG.supplyCount[copper], copperCount);
	if (testG.supplyCount[copper] != copperCount)
		printf("********** ERROR: copper card mismatch**********\n");
	
	printf("silver cards = %d, expected = %d\n", testG.supplyCount[silver], silverCount);
	if (testG.supplyCount[silver] != silverCount)
		printf("********** ERROR: silver card mismatch**********\n");
	
	printf("gold cards = %d, expected = %d\n", testG.supplyCount[gold], goldCount);
	if (testG.supplyCount[gold] != goldCount)
		printf("********** ERROR: gold card mismatch**********\n");
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
		
	// End the first player's turn
	endTurn(&testG);
	thisPlayer = whoseTurn(&testG);
	printf("NEXT PLAYER TURN:\n");
	
	// Calculate the coin value and number of curse cards
	coinVal = testG.coins;
	printf("coins = %d\n", testG.coins);
	prevDeckResult = fullDeckCount(thisPlayer, curse, &testG);
	
	// Next player buys that card
	playSuccess = buyCard(choice1, &testG);
		
	// The buy should have been successful
	printf("successful buy = %d, expected = %d\n", playSuccess, 0);
	if (playSuccess != 0){
	printf("********** ERROR: unsuccessful buy **********\n");
	}
	
	// The number of coins in the player's hand should be coinVal - cardVal
	printf("coins = %d, expected = %d\n", testG.coins, coinVal - cardVal);
	if (testG.coins != coinVal - cardVal){
		printf("********** ERROR: coins mismatch **********\n");
	}
	
	// The next player should have gained a Curse card
	fullDeckResult = fullDeckCount(thisPlayer, curse, &testG);
	printf("curse cards = %d, expected = %d\n", fullDeckResult, prevDeckResult + 1);
	if (fullDeckResult != prevDeckResult + 1) {
		printf("********** ERROR: curse cards mismatch **********\n");
	}
	
	
	/****************************************************
	Test 2: First player places 2 embargos on estate, and next player tries to buy it
	****************************************************/
	printf("\nTEST 2: First player places 2 embargos on estate, and next player tries to buy it \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	thisPlayer = 0;
	testG.hand[thisPlayer][1] = embargo;
	printf(" (%d)\n",  testG.hand[thisPlayer][1]);
	updateCoins(thisPlayer, &testG, bonus);
	
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Show the previous hand
	printf("hand before playing  = ");
	for (i = 0; i < testG.handCount[thisPlayer]; i++) {
		printf(" (%d)",  testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	// Calculate the coin value of the hand
	coinVal = testG.coins;
	
	// Play the embargo card on estate
	choice1 = estate;
	cardVal = getCost(estate);
	playSuccess = cardEffect(embargo, choice1, choice2, choice3, &testG, handPos, &bonus);
	handPos = 1;
	playSuccess = cardEffect(embargo, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// The play should have been successful
	printf("successful play = %d, expected = %d\n", playSuccess, 0);
	if (playSuccess != 0){
	printf("********** ERROR: unsuccessful play **********\n");
	}
	
	// The number of coins in the player's hand should be coinVal + 4
	printf("coins = %d, expected = %d\n", testG.coins, coinVal + 4);
	if (testG.coins != coinVal + 4){
		printf("********** ERROR: coins mismatch **********\n");
	}
	
	// Show the next hand
	printf("hand after playing  = ");
	for (i = 0; i < testG.handCount[thisPlayer]; i++) {
		printf(" (%d)",  testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	// It should still be the current player's turn
	printf("current player = %d, expected = %d\n", thisPlayer, prevPlayer);
	if (thisPlayer != prevPlayer)
		printf("********** ERROR: current player mismatch**********\n");
	
	// The total number of cards added to the player's hand should be 2 less
	printf("current player's handCount = %d, expected = %d\n", testG.handCount[thisPlayer], prevHandCount[thisPlayer]-2);
	if (testG.handCount[thisPlayer] != prevHandCount[thisPlayer]-2)
		printf("********** ERROR: current player's hand mismatch**********\n");
	
	// The total number of cards in the discard pile should be the same
	printf("current player's discardCount = %d, expected = %d\n", testG.discardCount[thisPlayer], prevDiscardCount[thisPlayer]);
	if (testG.discardCount[thisPlayer] != prevDiscardCount[thisPlayer])
		printf("********** ERROR: current player's discard pile mismatch**********\n");
	
	// The total number of played cards should be 0
	printf("played cards = %d, expected = %d\n", testG.playedCardCount, 0);
	if (testG.playedCardCount != 0)
		printf("********** ERROR: played card pile mismatch**********\n");
	
	// The total number of cards in the player's deck should be the same
	printf("current player's deckCount = %d, expected = %d\n", testG.deckCount[thisPlayer], prevDeckCount[thisPlayer]);
	if (testG.deckCount[thisPlayer] != prevDeckCount[thisPlayer])
		printf("********** ERROR: current player's deck pile mismatch**********\n");
	
	// The total number of cards added to the other player's hands and deck should be 0
	for (i = 0; i< numPlayers; i++){
		if (i != thisPlayer) {
			printf("player %d's handCount = %d, expected = %d\n", i, testG.handCount[i], prevHandCount[i]);
			if (testG.handCount[i] != prevHandCount[i])
				printf("********** ERROR: player %d's handCount mismatch**********\n", i);
			printf("player %d's discardCount = %d, expected = %d\n", i, testG.discardCount[i], prevDiscardCount[i]);
			if (testG.discardCount[i] != prevDiscardCount[i])
				printf("********** ERROR: player %d's discardCount mismatch**********\n", i);
			printf("player %d's deckCount = %d, expected = %d\n", i, testG.deckCount[i], prevDeckCount[i]);
			if (testG.deckCount[i] != prevDeckCount[i])
				printf("********** ERROR: player %d's deckCount mismatch**********\n", i);
		}
	}
	
	// The first card should be the one traded for (it should be the last card in the hand)
	printf("first card = %d, expected = %d\n", testG.hand[thisPlayer][0], G.hand[thisPlayer][4]);
	if (testG.hand[thisPlayer][0] != G.hand[thisPlayer][4])
		printf("********** ERROR: first card mismatch**********\n");
	
	// There will be 12 province, estate, and duchy cards originally, minus the card traded for
	printf("province cards = %d, expected = %d\n", testG.supplyCount[province], provinceCount);
	if (testG.supplyCount[province] != provinceCount)
		printf("********** ERROR: province card mismatch**********\n");
	
	printf("estate cards = %d, expected = %d\n", testG.supplyCount[estate], estateCount);
	if (testG.supplyCount[estate] != estateCount)
		printf("********** ERROR: estate card mismatch**********\n");
	
	printf("duchy cards = %d, expected = %d\n", testG.supplyCount[duchy], duchyCount);
	if (testG.supplyCount[duchy] != duchyCount)
		printf("********** ERROR: duchy card mismatch**********\n");
	
	// There will be 10 each of all the kindom cards
	for (i = 0; i < 10; i++) {
		printf("kingdom card (%d) = %d\n", k[i], testG.supplyCount[k[i]]);
	}
	
	// There should be 39 coppers, 40 silvers, and 30 gold, minus the card traded for
	printf("copper cards = %d, expected = %d\n", testG.supplyCount[copper], copperCount);
	if (testG.supplyCount[copper] != copperCount)
		printf("********** ERROR: copper card mismatch**********\n");
	
	printf("silver cards = %d, expected = %d\n", testG.supplyCount[silver], silverCount);
	if (testG.supplyCount[silver] != silverCount)
		printf("********** ERROR: silver card mismatch**********\n");
	
	printf("gold cards = %d, expected = %d\n", testG.supplyCount[gold], goldCount);
	if (testG.supplyCount[gold] != goldCount)
		printf("********** ERROR: gold card mismatch**********\n");
	
	// Therefore, the game should not be over
	printf("game over = %d, expected = %d\n", isGameOver(&testG), 0);
	assert(isGameOver(&testG) == 0);
		
	// End the first player's turn
	endTurn(&testG);
	thisPlayer = whoseTurn(&testG);
	printf("NEXT PLAYER TURN:\n");
	
	// Calculate the coin value and number of curse cards
	coinVal = testG.coins;
	printf("coins = %d\n", testG.coins);
	printf("current player = %d\n", thisPlayer);
	prevDeckResult = fullDeckCount(thisPlayer, curse, &testG);
	
	// Next player buys that card
	playSuccess = buyCard(choice1, &testG);
		
	// The buy should have been successful
	printf("successful buy = %d, expected = %d\n", playSuccess, 0);
	if (playSuccess != 0){
	printf("********** ERROR: unsuccessful buy **********\n");
	}
	
	// The number of coins in the player's hand should be coinVal - cardVal
	printf("coins = %d, expected = %d\n", testG.coins, coinVal - cardVal);
	if (testG.coins != coinVal - cardVal){
		printf("********** ERROR: coins mismatch **********\n");
	}
	
	// The next player should have gained 2 Curse cards
	fullDeckResult = fullDeckCount(thisPlayer, curse, &testG);
	printf("curse cards = %d, expected = %d\n", fullDeckResult, prevDeckResult + 2);
	if (fullDeckResult != prevDeckResult + 2) {
		printf("********** ERROR: curse cards mismatch **********\n");
	}
	
	/****************************************************
	Test 3: First player places embargo on outpost (card not in play)
	****************************************************/
	printf("\nTEST 3: First player places embargo on outpost (card not in play) \n");
	
	// Create a copy of the original hand
	memcpy(&testG, &G, sizeof(struct gameState));
	thisPlayer = 0;
	
	// Keep track of hand count and discard count for all players
	for (i = 0; i < numPlayers; i++){
		prevHandCount[i] = testG.handCount[i];
		prevDiscardCount[i] = testG.discardCount[i];
		prevDeckCount[i] = testG.deckCount[i];
	}
	prevPlayer = thisPlayer;
	
	// Show the previous hand
	printf("hand before playing  = ");
	for (i = 0; i < testG.handCount[thisPlayer]; i++) {
		printf(" (%d)",  testG.hand[thisPlayer][i]);
	}
	printf("\n");
	
	// Calculate the coin value of the hand
	coinVal = testG.coins;
	
	// Play the embargo card on estate
	choice1 = outpost;
	cardVal = getCost(outpost);
	playSuccess = cardEffect(embargo, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	// The play should not have been successful
	printf("successful play = %d, expected = %d\n", playSuccess, -1);
	if (playSuccess != -1){
	printf("********** ERROR: successful play **********\n");
	}
	
	
	printf("\n >>>>> SUCCESS: Testing complete of %s <<<<<\n\n\n", UNITTEST);

	return 0;
}


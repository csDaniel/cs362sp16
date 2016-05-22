#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"
#define NUM_TESTS 1024

int main() {
	
	srand(time(NULL));

	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine,
				cutpurse, sea_hag, tribute, smithy, council_room};
	
	printf("\n----------------- START TESTING: %s ----------------\n", TESTCARD);
	
	int i, players, currPlayer, seed;
	int tempHand[MAX_HAND];
	int pass = 0;
	int fail = 0;
	
	for(i = 0; i < NUM_TESTS; i++){
		
		//initialize game state
		players = 2 + rand() % (4 + 1 - 2);
		currPlayer = rand() % players;
		seed = rand();
		initializeGame(players, k, seed, &G);
		
		//initializing all possible combinations allowed in the game
		G.handCount[currPlayer] = 1 + rand() % 100;
		G.deckCount[currPlayer] = 1 + rand() % 100;
		int handCount = G.handCount[currPlayer];
		int deckCount = G.deckCount[currPlayer];
		
		int j;
		int deckTreasures=0;
		int handTreasures =0;
		int newTreasures = 0;
		
		//initialize random cards
		for(j = 0; j < G.deckCount[currPlayer]; j++) {
			//randomize which card is put into the deck
			int card = floor(Random() * (treasure_map + 1));
			if(card == copper || card == silver || card == gold) {
				deckTreasures++;
			}
			
			G.deck[currPlayer][j] = card;
		}
		
		//initialize random cards
		for(j = 0; j < G.handCount[currPlayer]; j++) {
			//randomize which card is put into the deck
			int card = floor(Random() * (treasure_map + 1));
			if(card == copper || card == silver || card == gold) {
				handTreasures++;
			}
			
			G.hand[currPlayer][j] = card;
		}	
		
		int test = playAdventurer(&G);
		//Card executes
		if (test == 0) {
			pass++;
		} else {
			fail++;
		}
		
		//card draws two, discards itself, netting in +1 hand count
		if (handCount + 1 == G.handCount[currPlayer]) {
			pass++;
		} else {
			fail++;
		}
		
		for(j = 0; j < G.handCount[currPlayer]; j++) {
			int card = G.hand[currPlayer][j];
			if(card == copper || card == silver || card == gold) {
				newTreasures++;
			}
		}
		//This will pass when 2 extra cards were drawn as treasures
		if(handTreasures +2 == newTreasures) {
			pass++;
		} else {
			fail++;
		}
		
		//if the discard pile doesn't equal the amount of cards drawn +2 (treasures), then fail
		if(deckCount - G.deckCount[currPlayer] == G.discardCount[currPlayer] +2) {
			pass++;
		} else {
			fail++;
		}
	
	}
	
	printf("Tests Passed: %d\n", pass);
	printf("Tests Failed: %d\n", fail);
	
	printf("\n----------------- END TESTING: %s ----------------\n", TESTCARD);
	
	return 0;
}
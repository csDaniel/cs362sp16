/*
Adventurer Card: Reveal/Draw cards from deck until you reveal/draw 
					two treasure cards. Put the treasure cards in your hand,
					and discard the other revealed cards.

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurer(struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
  int r, i;
	int choice1 = 0, choice2 = 0, choice3=0, bonus=0, handpos=0;	    

  r = cardEffect(adventurer, choice1, choice2, choice3, &post, handpos, &bonus );

	int treasCount = 0;
	int currPlayer = whoseTurn( &pre );
	int cardDrawn;
	int temphand[MAX_HAND];
	int k = 0;
	
	while( treasCount < 2 ){
		drawCard( currPlayer, &pre ); //drawCard calls shuffle if empty

		if( pre.hand[currPlayer][pre.handCount[currPlayer]] == copper ){
			treasCount++;
		}
		else if( pre.hand[currPlayer][pre.handCount[currPlayer]] == silver ){
			treasCount++;
		}
		else if( pre.hand[currPlayer][pre.handCount[currPlayer]] == gold ){
			treasCount++;
		} else {
			//Remove non-treasure drawn cards from hand and put into temp hand
			// to discard after turn
			temphand[k] = pre.hand[currPlayer][pre.handCount[currPlayer]];
			pre.handCount[currPlayer]--;
		}
	}

	while( k>0 ){
		pre.discardCount[currPlayer]++;
		pre.discard[currPlayer][pre.discardCount[currPlayer]] = temphand[k];
		k--;
	}

  assert (r == 0);
	if( (memcmp(&pre, post, sizeof(struct gameState)) == 0)){
		printf( "***Passed /n");
	} else {
		printf( "***Failed /n" );
		printf( "   Discard Count Test: %d, Function: %d \n", pre.discardCount[currPlayer],  post->discardCount[currPlayer] );
		printf( "   Cards in Discard Test: " );
		printDiscard( currPlayer, &pre );
		printf( "   Cards in Discard Function: " );
		printDiscard( currPlayer, post );
		printf( "   Hand Count Test: %d, Function: %d \n", pre.handCount[currPlayer],  post->handCount[currPlayer] );
		printf( "   Cards in Hand Test: " );
		printHand( currPlayer, &pre );
		printf( "   Cards in Hand Function: " );
		printHand( currPlayer, post );
		printf( "   Deck Count Test: %d, Function: %d \n", pre.deckCount[currPlayer],  post->deckCount[currPlayer] );
		printf( "   Cards in Deck Test: " );
		printDeck( currPlayer, &pre );
		printf( "   Cards in Deck Function: " );
		printDeck( currPlayer, post );
		printf( "   Coin Count Test: %d, Function: %d \n ", countHandCoins( currPlayer, &pre),  countHandCoins( currPlayer, post ) );
	}
	
	return 0;
}

int main () {

  int n, p;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf ("Testing Adventurer.\n");


  SelectStream(2);
  PutSeed(3);
  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
	p = floor( Random() * MAX_PLAYERS );
	initializeGame( p, k, 777, &G );
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
	printf( "Test %d \n", n );
    checkAdventurer(&G);
  }

  printf ("ALL TESTS OK\n");

  exit(0);
/*
  printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
	for (handCount = 0; handCount < 5; handCount++) {
	  memset(&G, 23, sizeof(struct gameState)); 
	  r = initializeGame(2, k, 1, &G);
	  G.deckCount[p] = deckCount;
	  memset(G.deck[p], 0, sizeof(int) * deckCount);
	  G.discardCount[p] = discardCount;
	  memset(G.discard[p], 0, sizeof(int) * discardCount);
	  G.handCount[p] = handCount;
	  memset(G.hand[p], 0, sizeof(int) * handCount);
	  checkDrawCard(p, &G);
	}
      }
    }
  }
*/
  return 0;
}

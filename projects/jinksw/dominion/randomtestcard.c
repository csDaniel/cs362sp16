/*
Smithy Card: Draw 3 cards 

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkSmithy(struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
  int r, i;
	    
  r = playSmithy(post);

	int treasCount = 0;
	int currPlayer = whoseTurn( &pre );
	int cardDrawn;
	int temphand[MAX_HAND];
	int k = 0;

	for( i=0; i<3; i++ ){	
		drawCard( currPlayer, &pre ); //drawCard calls shuffle if empty
	}

  assert (r == 0);
	if( (memcmp(&pre, post, sizeof(struct gameState)) == 0)){
		printf( "+++++++++++++++++++++++++++++++++++++    Passed +++++++++++/n");
	} else {
		printf( "-------------------------------------    Failed -----------/n" );
		printf( "   #####  Discard Count Test: %d, Function: %d \n", pre.discardCount[currPlayer],  post->discardCount[currPlayer] );
		printf( "   #####  Cards in Discard Test: " );
		printDiscard( currPlayer, &pre );
		printf( "   #####  Cards in Discard Function: " );
		printDiscard( currPlayer, post );
		printf( "\n    ######  Hand Count Test: %d, Function: %d \n", pre.handCount[currPlayer],  post->handCount[currPlayer] );
		printf( "   ######   Cards in Hand Test: " );
		printHand( currPlayer, &pre );
		printf( "   #####   Cards in Hand Function: " );
		printHand( currPlayer, post );
		printf( "\n   ####   Deck Count Test: %d, Function: %d \n", pre.deckCount[currPlayer],  post->deckCount[currPlayer] );
		printf( "   #####   Cards in Deck Test: " );
		printDeck( currPlayer, &pre );
		printf( "   #####   Cards in Deck Function: " );
		printDeck( currPlayer, post );
		printf( "\n   #####   Coin Count Test: %d, Function: %d \n ", countHandCoins( currPlayer, &pre),  countHandCoins( currPlayer, post ) );
	}
	
	return 0;
}

int main () {

  int n, p;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf ("Testing Smithy.\n");


  SelectStream(2);
  PutSeed(3);
  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
	p = floor( Random() * MAX_PLAYERS );
	initializeGame( p, k, 777, &G );
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
	printf( "**************************   Test %d   ****************************** \n", n );
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

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

	int currPlayer = whoseTurn( &pre );

	for( i=0; i<3; i++ ){	
		drawCard( currPlayer, &pre ); //drawCard calls shuffle if empty
	}

  assert (r == 0);
	if( (memcmp(&pre, post, sizeof(struct gameState)) == 0)){
		printf( "+++++++++++    Passed +++++++++++\n");
	} else {
		printf( "-----------    Failed ----------- \n" );
		printf( "   #####  Discard Count Test: %d, Function: %d \n", pre.discardCount[currPlayer],  post->discardCount[currPlayer] );
		checkCardDiff( &post, &pre, post->discardCount[currPlayer], pre.discardCount[currPlayer], 3, currPlayer );
	//	printf( "   #####  Cards in Discard Test: " );
//		printDiscard( currPlayer, &pre );
//		printf( "   #####  Cards in Discard Function: " );
//		printDiscard( currPlayer, post );
		printf( "\n    ######  Hand Count Test: %d, Function: %d \n", pre.handCount[currPlayer],  post->handCount[currPlayer] );
		checkCardDiff( &post, &pre, post->handCount[currPlayer], pre.handCount[currPlayer], 1, currPlayer );
//		printf( "   ######   Cards in Hand Test: " );
//		printHand( currPlayer, &pre );
//		printf( "   #####   Cards in Hand Function: " );
//		printHand( currPlayer, post );
		printf( "\n   ####   Deck Count Test: %d, Function: %d \n", pre.deckCount[currPlayer],  post->deckCount[currPlayer] );
		checkCardDiff( &post, &pre, post->deckCount[currPlayer], pre.deckCount[currPlayer], 2, currPlayer );
//		printf( "   #####   Cards in Deck Test: " );
//		printDeck( currPlayer, &pre );
//		printf( "   #####   Cards in Deck Function: " );
//		printDeck( currPlayer, post );
		printf( "\n   #####   Coin Count Test: %d, Function: %d \n ", countHandCoins( currPlayer, &pre),  countHandCoins( currPlayer, post ) );
	}
	
	return 0;
}

//Pass game states, option and player and this will tell which cards are different between the game states
//Option 1 is Hand
//Option 2 is Deck
//Option 3 is Discard

int checkCardDiff( struct gameState *G, struct gameState *GT, int Gcount, int GTcount, int option, int p ){
	int n, i, f;

	if( Gcount < GTcount ){
		n = Gcount;
		f = 0;
	} else {
		n = GTcount;
		f = 1;
	}
	if( option == 1 ){
		for( i=0; i<n; i++ ){
			if( G->hand[p][i] != GT->hand[p][i] ){
				//cardNumToName( G->hand[p][i], cardG );
				//cardNumToName( GT->hand[p][i], cardT );
				printf( "Hand diff at pos %d: Game-> %d, Test-> %d \n", i,  G->hand[p][i], GT->hand[p][i] );
			}
		}
		if ( f == 0 ){
			n = GTcount;
			printf( "Oracle has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", GT->hand[p][i], i);
				i++;
			}
			n = Gcount;
		} else {
			n = Gcount;
			printf( "Dom Function has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", G->hand[p][i], i);
				i++;
			}
			n = GTcount;
		}
	} else if ( option == 2 ) {
		for( i=0; i<n; i++ ){
			if( G->deck[p][i] != GT->deck[p][i] ){
				printf( "Deck diff at pos %d: Game-> %d, Test-> %d \n", i,  G->deck[p][i], GT->deck[p][i] );
			}
		}
		if ( f == 0 ){
			n = GTcount;
			printf( "Oracle has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", GT->deck[p][i], i);
				i++;
			}
			n = Gcount;
		} else {
			n = Gcount;
			printf( "Dom Function has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", G->deck[p][i], i);
				i++;
			}
			n = GTcount;
		}
	} else if ( option == 3 ) {
		for( i=0; i<n; i++ ){
			if( G->discard[p][i] != GT->discard[p][i] ){
				printf( "Discard diff at pos %d: Game-> %d, Test-> %d \n", i,  G->discard[p][i], GT->discard[p][i] );
			}
		}
		if ( f == 0 ){
			n = GTcount;
			printf( "Oracle has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", GT->discard[p][i], i);
				i++;
			}
			n = Gcount;
		} else {
			n = Gcount;
			printf( "Dom Function has extra cards:");
			while( i<n ){
				printf( "Card: %d at position %d\n", G->discard[p][i], i);
				i++;
			}
			n = GTcount;
		}
	}
	
	return 0;
}


int initCards( struct gameState *G, int p ){
	int i;
	int c[27];
	for( i=0; i<26; i++ ){
		c[i]=i;
	}

	for( i=0; i<G->deckCount[p]; i++ ){
		G->deck[p][i]=floor( Random() * 27 );
	}

	for( i=0; i<G->handCount[p]; i++ ){
		G->hand[p][i]=floor( Random() * 27 );
	}
	
	for( i=0; i<G->discardCount[p]; i++ ){
		G->discard[p][i]=floor( Random() * 27 );
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
	initCards( &G, p );
	printf( "\n**************************   Test %d   ****************************** \n", n );
    checkSmithy(&G);
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

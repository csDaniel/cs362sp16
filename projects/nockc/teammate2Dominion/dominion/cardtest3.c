/* Card Test for Village
   Previous game state: playing 2 player Dominion game, Village card is played
   Tests will cover:
   - if hand count was unaltered
   - if deck count is decreased by 1
   - if number actions increased by 2
   - if village card is discarded
   - if next card is moved to the hand
   - if village remains in hand after playing
   - other player hasn't had his hand count alterned
   - other player hasn't had his deck count alterned
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define NOISY_TEST 1

int cardExists(int turn, struct gameState *state, int target);

int main()
{
    int startgame;
    int turn;
    int players = 2;
    int seed = 1000;
    int kingdomCards[10] = { gardens, adventurer, council_room, baron, mine, remodel, feast, smithy, village, great_hall };
	struct gameState previous; 
    struct gameState post; 
    int i;
	int r;
    int testruns = 1; 
    int finalfail = 0;
    int finalpass = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
#if (NOISY_TEST == 1)
    const char* domCards[] =  {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast",
        "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute",
        "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
#endif
	/* Looping through amount of test runs */
    for (i = 0; i < testruns; i++)
    {
        /* Start with a new game */
		memset(&previous, 23, sizeof(struct gameState));   
        startgame = initializeGame(players, kingdomCards, seed, &previous); 
		for (turn = 0; turn < players; turn++)
        {
			/* For current player, initialize the hand and deck */
            previous.handCount[turn] = 1;       
            int inithand[1];
            inithand[0] = village;
            memcpy(previous.hand[turn], inithand, sizeof(int));
            previous.deckCount[turn] = 5;       
            int initdeck[5];
            initdeck[0] = copper;
            initdeck[1] = silver;
            initdeck[2] = gold;
            initdeck[3] = gardens;
            initdeck[4] = tribute;
            memcpy(previous.deck[turn], initdeck, sizeof(int) * 5);
			/* The post game state will be a copy of the previous game state with tests ran on it */
            memcpy(&post, &previous, sizeof(struct gameState)); 
            playVillageCard(0, &post);
			tmp2 = previous.deckCount[turn];
			tmp3 = previous.discardCount[turn];
			tmp4 = previous.handCount[turn];
			int expNumAct = 0;
			int newcard = 0;
#if (NOISY_TEST == 1)			
			printf("\nTesting if hand count was unaltered\n");
#endif
			/* When village is played, it adds a card to the players hand but also discards the village */               
			if ( tmp4 != post.handCount[turn])
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( tmp4 != post.handCount[turn])
			{
				printf("Handcount test failed\n");
			}
			else
			{
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", tmp4, post.handCount[turn] );
			}
			printf("\nTesting if deck count is decreased by 1\n");			
#endif   
			/* When village is played, it adds a card to the players hand which is taken off the deck */
			if( ( tmp2 - 1 ) != post.deckCount[turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( ( tmp2 - 1 ) != post.deckCount[turn] )
			{
				printf("Deckcount test failed\n");
			}
			else
			{
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[turn], ( tmp2 - 1 ) );
			}
			printf("\nTesting if number actions increased by 2\n");			
#endif   
            
			/* When playing village, num of actions should increase by 2 for a pass */
			expNumAct = previous.numActions + 2;
			if ( expNumAct != post.numActions )
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if ( expNumAct != post.numActions )
			{
				printf("Number actions test failed\n");
				printf("Test Result: actual number actions: %d, expected number actions: %d\r\n", post.numActions, expNumAct );   
			}
			else
			{
				printf("Test Result: actual number actions: %d, expected number actions: %d\r\n", post.numActions, expNumAct );   
			}
			printf("\nTesting if village card is discarded\n");	
#endif
            /* Village card should be discarded after playing so it should be at the top of the discard pile */ 
            if(post.playedCards[post.playedCardCount - 1] != village )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
            if ( post.playedCards[post.playedCardCount - 1] != village )
			{
				printf("Village discard test failed\n");
			}
			else
			{
				printf("Test Result: Pass. Village card has been discarded\n");   
			}
			printf("\nTesting if next card is moved to the hand\n");	
#endif
			newcard = previous.deck[ turn ][ tmp2 -1 ];
			if ( newcard != post.hand[ turn ][ previous.handCount[ turn ] - 1 ])
			{
				finalfail++;
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( newcard != post.hand[ turn ][ previous.handCount[ turn ] - 1 ])
			{
				printf("Next card was not moved to the hand\n");
			}
			else
			{
				printf("Test Result: Pass. Next card in deck was moved to the hand\n");   
			}
			printf("\nTesting if village remains in hand after playing\n");
#endif           
			/* When village is played, it should leave hand  */ 
            r = cardExists(turn, &post, village);
			/* If village is not in hand then it pass */
            if ( r == -1 ) 
            {
               finalpass++;
            }
            else
            {
                finalfail++;
            }
#if (NOISY_TEST == 1)
            if (r == -1) 
            {
               printf("Test Result: Pass. Village not in the hand after playing\r\n");
            }
            else
            {
                printf("Test Result: Fail. Village still in hand after playing\r\n");
            }
			printf("\nTesting other player hasn't had his hand count alterned\n");			
#endif 
/* Current player's Village should not affect other play's game state */
			if( previous.handCount[1 - turn] != post.handCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if (previous.handCount[1 - turn] != post.handCount[1 - turn]  )
			{
				printf("Test Result: Fail. Current player's playing Village changed other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn]  );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing Village did not affect other player's hand count\n");
				printf("Test Result: actual handCount: %d, expected handCount: %d\r\n", post.handCount[1 - turn],  previous.handCount[1 - turn] );
			}
			printf("\nTesting other player hasn't had his deck count alterned\n");
#endif
			
			if( previous.deckCount[1 - turn] != post.deckCount[1 - turn] )
			{
				finalfail++;  
			}
			else
			{
				finalpass++;
			}
#if (NOISY_TEST == 1)
			if ( previous.deckCount[1 - turn] != post.deckCount[1 - turn] )
			{
				printf("Test Result: Fail. Current player's playing Village changed other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
			else
			{
				printf("Test Result: Pass. Current player's playing Village did not affect other player's deck count\n");
				printf("Test Result: actual deckCount: %d, expected deckCount: %d\r\n", post.deckCount[1 - turn], previous.deckCount[1 - turn] );
			}
			
#endif			           
          }
     }
    printf("Final tally for Card Test 3 ( Village ):\nPass: %d\nFail: %d\r\n",finalpass, finalfail );
    return 0;
}


int cardExists(int turn, struct gameState *state, int target)
{
    /* Initalize flag to doesn't exist */
	int cardexists = -1;
    /* Retrieve size of played cards, hand or deck for checking loop */
	int loopsize = state->handCount[turn];;
	/* Find size of loop for played cards, ahnd or deck */
    int i;
    for (i = 0; i < loopsize; i++)
    {
        /* If checking player's hand for a certain card, use this loop */
        if (state->hand[turn][i] == target)
        {
                 cardexists = i;
        }
    }
    return cardexists;
} 

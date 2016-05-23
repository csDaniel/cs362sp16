#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(){

   struct gameState state, saveState;
   int numPlayers = 2, i;
   int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
   int *bonus = NULL;
   int newCards = 0, discard = 0, numBuys = 0;
   int kingdom[10] = {council_room, adventurer, gardens, mine, ambassador,  
                     remodel, great_hall, minion, sea_hag, outpost};
   int seed = 1000;

   initializeGame(numPlayers, kingdom, seed, &state);
   int currentPlayer = state.whoseTurn;
   // Save the state as-is
   memcpy(&saveState, &state, sizeof(struct gameState));
   /* business requirements
      
      description: testing council room card, 

      1. Draws 4 extra card.
      2. Card should come from own pile.
      3. 1 extra buy.
      3. No state change should occur for other players.
      4. No state change should occur to the victory and kingdom card piles.

      end requirements*/
   printf("<----------BEGIN cardtest3-council room card---------->\n\n");
   printf("Initial deck count: %i\n",state.deckCount[currentPlayer]);
   printf("Initial hand count: %i\n", state.handCount[currentPlayer]);

// ----------------- TEST 1 ---------------------------------------------------
   printf("\n");
   printf(" TEST 1: Should draw 4 extra card.\n");
   cardEffect(council_room, choice1, choice2, choice3, &state, handPos, bonus);  
   newCards = 4;
   discard = 1;
   printf("    hand count = %i, expected = %i\n", state.handCount[currentPlayer], saveState.handCount[currentPlayer] + newCards - discard);  
   if(!(state.handCount[currentPlayer] == saveState.handCount[currentPlayer] + newCards - discard))
		printf("		Assertion failed!\n");

// ----------------- TEST 2 ---------------------------------------------------
   printf("\n");
   printf(" TEST 2: 4 card should come from own pile.\n");
   printf("    deck count = %i, expected = %i\n", state.deckCount[currentPlayer], saveState.deckCount[currentPlayer] - newCards);
   if(!(state.deckCount[currentPlayer] == saveState.deckCount[currentPlayer] - newCards))
		printf("		Assertion failed!\n");

// ----------------- TEST 3 ---------------------------------------------------
   printf("\n");
   printf(" TEST 3: Number of buys should not change.\n");
	numBuys = 1;
   printf("    buy count = %i, expected = %i\n", state.numBuys, saveState.numBuys + numBuys);
   assert(state.numBuys == saveState.numBuys);

// ----------------- TEST 4 ---------------------------------------------------
   printf("\n");
   printf(" TEST 4: No state change should occur for other players.\n");
   printf("    deck count = %i, expected = %i\n", state.deckCount[!currentPlayer], saveState.deckCount[!currentPlayer]);
   printf("    discard pile count = %i, expected %i\n", state.discardCount[!currentPlayer], saveState.discardCount[!currentPlayer]);
   assert(saveState.deckCount[!currentPlayer] == state.deckCount[!currentPlayer]);

// ----------------- TEST 5 ---------------------------------------------------
   printf("\n");
   printf(" TEST 5: No state change should occur to victory and kingdom cards piles.\n");
   printf("    estate count = %i, expected = %i\n", state.supplyCount[estate], saveState.supplyCount[estate]);
   printf("    duchy count = %i, expected = %i\n", state.supplyCount[duchy], saveState.supplyCount[duchy]);
   printf("    province count = %i, expected = %i\n", state.supplyCount[province], saveState.supplyCount[province]);
   
   for( i = adventurer; i <= treasure_map; ++i){
      printf("    kingdomCard '%i' count = %i, expected = %i\n", i, state.supplyCount[i], saveState.supplyCount[i]);
   }

   assert(saveState.supplyCount[estate] == state.supplyCount[estate]);
   assert(saveState.supplyCount[duchy] == state.supplyCount[duchy]);
   assert(saveState.supplyCount[province] == state.supplyCount[province]);
   for( i = adventurer; i <= treasure_map; ++i){
      assert(saveState.supplyCount[i] == state.supplyCount[i]);
   }
   printf("\n");
   printf("<----------END cardtest3-council room card---------->\n\n");

   return 0;
}


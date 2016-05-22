//Test scoreFor
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, discardCount, deckCount;
    int score;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
	int maxDiscardCount = 5;
	int maxDeckCount = 27; //3 in start and all others
    // arrays of all score cards
    int curses[MAX_HAND];
    int estates[MAX_HAND];
    int duchies[MAX_HAND];
	int provinces[MAX_HAND];
	int great_halls[MAX_HAND];
	int gardens[MAX_HAND];

    for (i = 0; i < MAX_HAND; i++)
    {
        curses[i] = curse;
        estates[i] = estate;
        duchies[i] = duchy;
		provinces[i] = province;
		great_halls[i] = great_hall;
		gardens[i] = gardens;
    }

    printf ("TESTING scoreFor():\n");
    for (p = 0; p < numPlayer; p++)
    {
        //for (deckCount = 3; deckCount <= maxDeckCount; deckCount++)
		//{
		for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			for (discardCount = 3; discardCount <= maxDeckCount; discardCount++)
			{
#if (NOISY_TEST == 1)
                printf("Test player %d with %d score card(s) in hand and %d discarded \n", p, handCount, discardCount);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
               
				G.handCount[p] = handCount;                 // set the number of cards on hand
                G.discardCount[p] = discardCount;
				//G.deckCount[p] = deckCount;
				memcpy(G.hand[p], curses, sizeof(int) * handCount); // set all the cards to curses
				memcpy(G.deck[p], curses, sizeof(int) * discardCount);
                score = scoreFor(p, &G);
#if (NOISY_TEST == 1)
                printf("Curse Score = %d, expected = %d\n", score, handCount * -1 + discardCount * -1);// + deckCount * -1);
#endif
                assert(score == handCount * -1 + discardCount * -1);// + deckCount * -1); // check if the score is correct

                memcpy(G.hand[p], estates, sizeof(int) * handCount); // set all the cards to estates
				memcpy(G.deck[p], estates, sizeof(int) * discardCount);
                score = scoreFor(p, &G);
#if (NOISY_TEST == 1)
                printf("Estate Score = %d, expected = %d\n", score, handCount * 1 + discardCount * 1 + deckCount *1);
#endif
                assert(score == handCount * 1 + discardCount * 1);// + deckCount * 1); // check if the score is correct

                memcpy(G.hand[p], duchies, sizeof(int) * handCount); // set all the cards to duchies
				memcpy(G.deck[p], duchies, sizeof(int) * discardCount);
                score = scoreFor(p, &G);
#if (NOISY_TEST == 1)
                printf("Duchy Score = %d, expected = %d\n", score, handCount * 3 + discardCount * 3);
#endif
                assert(score == handCount * 3 + discardCount * 3); // check if the score is correct
			
			}
        }
		//}
    }

    printf("All tests passed!\n");

    return 0;
}
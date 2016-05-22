/*
Aaron Sealy
Assignment 4
CS 362
Spring 2016

Tests the Adventurer card

Tested behavior: Cards are revealed from the player's own deck until two treasure cards are
revealed and added to the player's hand. If the deck needs to be reshuffled, the cards that
have already been revealed are not reshuffled. All revealed cards not placed into the player's
hand are discarded.  The adventurer card itself should also be discarded.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    int i,j,y,seed, result;
    int handPos=0;
    int bonus = 0;
    int numPlayers = 2;
    int maxHandPos = 5;
    int player = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
	int k[10] = {feast, gardens, embargo, adventurer, tribute, mine, cutpurse, ambassador, great_hall, smithy};
	struct gameState T,G;
    int testACount = 0;
    int testBCount = 0;
    int testCCount = 0;
    int everything[] = {curse, estate, duchy, province, copper, silver, adventurer,
    council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion,
    steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

    // Seed
    srand(time(NULL));

    // Announce testing
    printf("Testing Adventurer card:\n");

    // run through 1,900 iterations with randomly seeded games
    // (190 iterations of outer loop, each of which have 10 inner iterations)
    for(y = 0; y < 200; y++){

        // Use a new random seed for each iteration to randomize game state initialized
        seed = (rand() % 5000);


        for (i = 0; i < numPlayers; i++) {
                for (handPos = 0; handPos < maxHandPos; handPos++) {

            //Clean gamestates
            memset(&T, 23, sizeof(struct gameState));
            memset(&G, 23, sizeof(struct gameState));

            //Initialize game
            initializeGame(numPlayers, k, seed, &T);

            // Find current player, draw cards if needed
            T.whoseTurn = i;
            if (i != 0) {
                  for (j = 0; j < 5; j++){
                    drawCard(T.whoseTurn, &T);
                  }
            }

            // Copy original game state T into G
            memcpy(&G, &T, sizeof(struct gameState));

            // Play adventurer card
            result = playAdventurer(&G, handPos);

            // Fill player's deck
            G.deckCount[player] = 5;
            G.deck[player][0] = everything[(rand() % 26)];
            G.deck[player][1] = everything[(rand() % 26)];
            G.deck[player][2] = everything[(rand() % 26)];
            G.deck[player][3] = silver;
            G.deck[player][4] = copper;

            //Set up player's hand.
            G.handCount[player] = 1;
            G.hand[player][0] = adventurer;

            // Set initial discard to zero
            G.discardCount[player] = 0;

            // Check result
            if (result != 0){
                testACount++;
            }

            if (G.handCount[player] != T.handCount[player] + 2){
                testBCount++;
            }

            if (G.deckCount[player] + G.discardCount[player] != T.deckCount[player] + T.discardCount[player] - 2){
                testCCount++;
            }
        }
        }
    }

    // print results
    printf("TEST A failed %d of 2000 tries\n", testACount);
    printf("TEST B failed %d of 2000 tries\n", testBCount);
    printf("TEST C failed %d of 2000 tries\n", testCCount);

    return 0;
}
